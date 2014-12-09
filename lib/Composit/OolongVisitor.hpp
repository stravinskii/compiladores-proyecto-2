/**
 * Visitor generar código en lenguaje Oolong
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */
#include <map>
#include <fstream>
//#include "TableVisitor.hpp"

using namespace std;

class OolongVisitor : public Visitor{
public:

	/*
	 * Archivo de salida para la generación de código
	 */
	ofstream output;
	/*
	 * Tipo del último nodo visitado
	 */
	char currentType;
	/*
	 * Bandera para saber si estamos del lado izquierdo de un asignación o del lado derecho
	 * Esto nos sirve para saber si hay que emitir código de carga o guardado de variable
	 */
	bool inAssignation;
	/*
	 * Variable para una instrucción general de clase para utilizar un sólo espacio de memoria
	 */
	string instruction;
	/*
	 * Número de variable a asignar a una variable encontrada
	 */
	int currentVariable;
	/*
	 * Bandera para saber si se encuentra dentro del main o de una función el visitor
	 */
	bool inMainFunction;
	/*
	 * Cadena para encolar instrucciones que van en el main de la generación de código
	 */
	string mainOutputQueue;
	/*
	 * Número de variable a la que se le está asignando en un nodo AssigNode
	 */
	string currentAssignation;
	/*
	 * Mapeo de nombre de variable => número de variable ** temporal workaround **
	 */
	map<string, string> variables;

	VisitorNode* tableVisitor;
	SymbolTable* symbolTable;
	vector<Simbolo>* arreglo_de_variables;
	
	~OolongVisitor(){};
	OolongVisitor() {
		inAssignation = false;
		inMainFunction = true;
		output.open("prueba.j");
	};

	OolongVisitor(VisitorNode *tv) {
		tableVisitor = new VisitorNode(*tv);
		symbolTable = tv->symbolTable;
		arreglo_de_variables = new vector<Simbolo>(symbolTable->getOrderedTable());
		//cout<<"CREADO EL OOLONG VISITOR\ntamanio = "<<endl<<tableVisitor->symbolTable->tamanio()<<endl;
		inAssignation = false;
		inMainFunction = true;
		output.open("prueba.j");
	}

	int getIndice(int lexLevel, string name) {
		int i = 0;
		for (auto& x: *arreglo_de_variables) {
			string* nombre = x.getName();
			if (*nombre == name) {
				return i;
			}
			i++;
		}
		return i;
	}

	/**
	 * Función que encola instrucciones que van a ser escritas en el main
	 */
	void enqueue(string iinstruction) {
		mainOutputQueue += iinstruction + "\n";
	}

	/**
	 * Función que escribe en el archivo de código generado una instrucción
	 */
	void print(string iinstruction) {
		output << iinstruction << endl;
	}

	/**
	 * Función que manda a llamar enqueue si la instrucción va dentro del main, 
	 * en otro caso, la instrucción es parte de una función y se escribe al archivo
	 */
	void emit(string iinstruction) {
		inMainFunction ? enqueue(iinstruction) : print(iinstruction);
	}

	/**
	 * Función que parsea un tipo de variable al tipo mnemonic de Oolong
	 */
	string parseCurrentType() {
		switch (currentType)
		{
			case 'Z':
				return "Z";
			case 'I':
				return "I";
			case 'F':
				return "F";
			case 'S':
				return "Ljava/lang/String;";
		}
	}
 
 	void visit(Node* node){
	 	cout << "(Node ";
	 	visit(node);
	 	cout << ")";
 	}

 	/* LeafNode's */
 	void visit(IdentNode* node){
		cout << "(IdentNode " << node->getValue();
		string name = node->getValue();
		// if (variables.count(name) > 0) {
		if (symbolTable->lookup(name) != NULL) {
			// string id = variables[name];
			string idtable = to_string(getIndice(0, name));
			if (inAssignation) {
				// currentAssignation = id;
				currentAssignation = idtable;
			} else {
				// emit("iload " + id);
				emit("iload " + idtable);
			}
		} else {
			throw "Fatal error: Undeclared variable found";
			// if (inAssignation) {
			// 	currentAssignation = to_string(currentVariable);
			// } else {
			// 	throw "Undeclared variable";
			// }
			// variables.insert(pair<string, string>(name, to_string(currentVariable++)));
		}
		cout << ")";
 	}

 	void visit(IntNode* node){
		cout << "(IntNode " << node->getValue() << ")";
		emit("bipush " + to_string(node->getValue()));
		currentType = 'I';
 	}

 	void visit(FloatNode* node){
 		cout << "(FloatNode "<< node->getValue() << ")";
		emit("ldc " + to_string(node->getValue()));
		currentType = 'F';
 	}

 	void visit(StrNode* node){
 		cout << "(StrNode "<< node->getValue() << ")";
		emit("ldc \"" + node->getValue() + "\"");
		currentType = 'S';
 	}

 	void visit(BoolNode* node){
		cout << "(BoolNode "<< node->getValue() << ")";
		node->getValue() ? emit("iconst_1") : emit("iconst_0");
		currentType = 'Z';
 	}

 	void visit(ReturnNode* node){
 		cout << "(ReturnNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
 		cout << ")";

		switch (currentType)
		{
			case 'Z':
				emit("ireturn");
				break;
			case 'I':
				emit("ireturn");
				break;
			case 'F':
				emit("freturn");
				break;
			case 'S':
				emit("areturn");
				break;
			default:
				emit("areturn");
				break;
		}
 	}
	
	void visit(PrintNode* node){
		cout << "(PrintNode ";
		ArgsNode* args = dynamic_cast<ArgsNode*> ((node->getChildren()).front());
 		for (auto& it: args->getChildren()){
			emit("getstatic java/lang/System/out Ljava/io/PrintStream;");
			(*it).accept(*this);
			emit("invokevirtual java/io/PrintStream/println");
			emit("(" + parseCurrentType() + ")V");
		}
		cout << ")";
	}

	void visit(BreakNode* node){
		cout << "(BreakNode)";
		emit("goto break");
	}

	void visit(ContinueNode* node){
		cout << "(ContinueNode)";
	}

	/* END LeafNode's */

 	/* BinNode's */
 	void visit(AssignNode* node){
		cout << "(AssignNode ";
		inAssignation = true;
		node->getLeftChild()->accept(*this);
		inAssignation = false;
		node->getRightChild()->accept(*this);
		emit("istore " + currentAssignation);
		cout << ")";
 	}

 	void visit(AndNode* node){
 		cout << "(AndNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		emit("land");
 		cout << ")";
 	}

 	void visit(OrNode* node){
 		cout << "(OrNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		emit("lor");
 		cout << ")";
 	}

 	void visit(XorNode* node){
 		cout << "(XorNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		emit("lxor");
 		cout << ")";
 	}

 	void visit(NotNode* node){
 		cout << "(NotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		emit("lneg");
 		cout << ")";
 	}

 	void visit(PotNode* node){
 		cout << "(PotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(LTNode* node){
 		cout << "(LTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(GTNode* node){
 		cout << "(GTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(EqNode* node){
 		cout << "(EqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(NEqNode* node){
 		cout << "(NEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(LTEqNode* node){
 		cout << "(LTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(GTEqNode* node){
 		cout << "(GTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}
 	
 	void visit(PlusNode* node){
 		cout << "(PlusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
		left->accept(*this);
		right->accept(*this);

 		switch (currentType)
		{
			case 'Z':
				emit("iadd");
				break;
			case 'I':
				emit("iadd");
				break;
			case 'F':
				emit("fadd");
				break;
			case 'S':
				throw "Unsupported operation + for String type";
				break;
			default:
				emit("iadd");
				break;
		}
 		cout << ")";
 	}

 	void visit(MinusNode* node){
 		cout << "(MinusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
		right->accept(*this);
		switch (currentType)
		{
			case 'Z':
				emit("isub");
				break;
			case 'I':
				emit("isub");
				break;
			case 'F':
				emit("fsub");
				break;
			case 'S':
				throw "Unsupported operation + for String type";
				break;
			default:
				emit("isub");
				break;
		}
 		cout << ")";
 	}

 	void visit(DiviNode* node){
 		cout << "(DiviNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
		right->accept(*this);
		switch (currentType)
		{
			case 'Z':
				emit("idiv");
				break;
			case 'I':
				emit("idiv");
				break;
			case 'F':
				emit("fdiv");
				break;
			case 'S':
				throw "Unsupported operation + for String type";
				break;
			default:
				emit("idiv");
				break;
		}
 		cout << ")";
 	}

 	void visit(MultNode* node){
 		cout << "(MultNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
		right->accept(*this);
		switch (currentType)
		{
			case 'Z':
				emit("imul");
				break;
			case 'I':
				emit("imul");
				break;
			case 'F':
				emit("fmul");
				break;
			case 'S':
				throw "Unsupported operation + for String type";
				break;
			default:
				emit("imul");
				break;
		}
 		cout << ")";
 	}
 	/* END BinNode's */
 	
 	/* INode's */
 	void visit(FileNode* node) {
		cout << "(FileNode ";
		print(".class public prueba");
		print(".super java/lang/Object");
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}

		/* Generate main at the end */
		print(".method public static main([Ljava/lang/String;)V");
		print(mainOutputQueue);
		print("return");
		print(".end method");
		/* END main function */

		print(".end class");
		output.close();
 		cout << ")";
	}
	
 	void visit(FuncNode* node){
		cout << "(FuncNode ";
		inMainFunction = false;
		instruction = ".method public static ";
 		for (auto& it: node->getChildren()){

 			IdentNode* name = dynamic_cast<IdentNode*> (it);
 			ArgsNode* argslist = dynamic_cast<ArgsNode*> (it);
 			StmtListNode* suite = dynamic_cast<StmtListNode*> (it);

 			if (name != 0)
 			{
 				instruction += name->getValue();
 				emit(".method public static " +  name->getValue() + "()V");
 			}

 			if (argslist != 0)
 			{
				instruction += "(";
 				for (auto& it: argslist->getChildren()) {
 					/* Parse argument type */
 					// instruction += 
 				}
				instruction += ")";
 			}

 			if (suite != 0)
 			{
 				string returnType;
 				for (auto& it: suite->getChildren()){
 					/* Parse argument type */
					(*it).accept(*this);
 					// ReturnNode* returnn = dynamic_cast<ReturnNode*> (*it);
 					// if (returnn != 0) {
 					// 	/* Parse return type and append */
 					// } else {
 					// 	(*it).accept(*this);
 					// }
 				}
 			}

			// (*it).accept(*this);
		}
		emit("return");
		emit(".end method");
		inMainFunction = true;
		cout << ")";
	}

	void visit(CallNode* node) {
		cout << "(CallNode ";
		instruction = "invokestatic prueba/";
 		for (auto& it: node->getChildren()){
			IdentNode* name = dynamic_cast<IdentNode*> (it);
			ArgsNode* argslist = dynamic_cast<ArgsNode*> (it);
			if (name != 0)
			{
				instruction += name->getValue();
			}

			if (argslist != 0)
			{
 				for (auto& it: argslist->getChildren()){
 					(*it).accept(*this);
 				}
			}
		}
		emit(instruction + "()V");
 		cout << ")";
	}

 	void visit(IfNode* node){
		cout << "(IfNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(WhileNode* node){
		cout << "(WhileNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		} 
		cout << ")";
 	}

 	void visit(ForNode* node){
		cout << "(ForNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
 	
 	/**
 	 * *******************************************************
 	 * Nodos que no requieren acciones de generación de código
 	 * *******************************************************
 	 */

	void visit(ExprListNode* node) {
		cout << "(ExprListNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
 		cout << ")";
	}

 	void visit(StmtListNode* node){
		cout << "(StmtListNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
	
 	void visit(SStmtListNode* node){
		cout << "(SStmtListNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(ArgsNode* node){
 		cout << "(ArgsNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(ExprNode* node){
		cout << "(ExprNode ";			
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
 	
 	void visit(StmtNode* node){
		cout << "(StmtNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}

 	void visit(SStmtNode* node){
		cout << "(SStmtNode ";
 		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}
 };