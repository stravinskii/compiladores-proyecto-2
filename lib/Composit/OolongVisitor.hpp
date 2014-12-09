/**
 * Visitor generar código en lenguaje Oolong
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */
// #include <list>
// #include "AST.hpp"
// #include "Nodos.hpp"
// #include "MAST.hpp"
// #include <string>
#include <fstream>

using namespace std;

class OolongVisitor : public Visitor{
public:

	ofstream output;
	char currentType;
	string instruction;
	bool inMainFunction;
	string mainOutputQueue;
	
	~OolongVisitor(){};
	OolongVisitor() {
		inMainFunction = true;
		output.open("prueba.j");
	};

	void enqueue(string iinstruction) {
		mainOutputQueue += iinstruction + "\n";
	}

	void print(string iinstruction) {
		output << iinstruction << endl;
	}

	void emit(string iinstruction) {
		inMainFunction ? enqueue(iinstruction) : print(iinstruction);
	}

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
 	
 	/**
 	 * OJO:
 	 * Los nodos hojas no tiene porque llamarse a sí mismos el accept, se ciclaría,
 	 * además de que teoricamente ya esos nodos ya los llamó el visit de un nodo que los tiene como hijos.
 	 */

 	void visit(IdentNode* node){
		cout << "(IdentNode " << node->getValue();
		// string* name = new string();
		// *name = node->getValue();
		// Simbolo *s = symbolTable->lookUp(*name);
		// if(s == 0) {
			// cout<<"Insertando nueva variable en la tabla"<<endl;
			// string *cad = new string();
			// s=new Simbolo(name,cad);
			// symbolTable->insertName(s);
			// symbolTable->printTable();
		// }
		cout << ")";
 	}

 	void visit(IntNode* node){
		cout << "(IntNode " << node->getValue() << ")";
		char istr[21];
		sprintf(istr, "%d", node->getValue());
		instruction = "bipush ";
		instruction += istr;
		emit(instruction);
		currentType = 'I';
 	}

 	void visit(FloatNode* node){
 		cout << "(FloatNode "<< node->getValue() << ")";
 		char fstr[21];
		sprintf(fstr, "%f", node->getValue());
 		instruction = "ldc ";
 		instruction += fstr;
		emit(instruction);
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
 		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
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
		list<Node*> children = args->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			emit("getstatic java/lang/System/out Ljava/io/PrintStream;");
			(*it)->accept(*this);
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
		node->getLeftChild()->accept(*this);
		node->getRightChild()->accept(*this);
		cout << ")";
 	}

 	void visit(AndNode* node){
 		cout << "(AndNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(OrNode* node){
 		cout << "(OrNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(XorNode* node){
 		cout << "(XorNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(NotNode* node){
 		cout << "(NotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(PotNode* node){
 		cout << "(PotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
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
 		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
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
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){

 			IdentNode* name = dynamic_cast<IdentNode*> (*it);
 			ArgsNode* argslist = dynamic_cast<ArgsNode*> (*it);
 			StmtListNode* suite = dynamic_cast<StmtListNode*> (*it);

 			if (name != 0)
 			{
 				instruction += name->getValue();
 			}

 			if (argslist != 0)
 			{
				instruction += "(";
 				list<Node*> args = argslist->getChildren();
 				for (list<Node*>::iterator it = args.begin(); it != args.end(); it++){
 					/* Parse argument type */
 					// instruction += 
 				}
				instruction += ")";
 			}

 			if (suite != 0)
 			{
 				string returnType;
 				list<Node*> stmts = suite->getChildren();
 				for (list<Node*>::iterator it = stmts.begin(); it != stmts.end(); it++){
 					/* Parse argument type */
 					ReturnNode* returnn = dynamic_cast<ReturnNode*> (*it);
 					if (returnn != 0) {
 						/* Parse return type and append */
 					} else {
 						(*it)->accept(*this);
 					}
 				}
 			}

			(*it)->accept(*this);
		}	
		inMainFunction = true;
		cout << ")";
	}

	void visit(CallNode* node) {
		cout << "(CallNode ";
 		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
 		cout << ")";
	}

 	void visit(IfNode* node){
		cout << "(IfNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}

 	void visit(WhileNode* node){
		cout << "(WhileNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		} 
		cout << ")";
 	}

 	void visit(ForNode* node){
		cout << "(ForNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}
 	
	void visit(ExprListNode* node) {
		cout << "(ExprListNode ";
 		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
 		cout << ")";
	}

 	void visit(StmtListNode* node){
		cout << "(StmtListNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}
	
 	void visit(SStmtListNode* node){
		cout << "(SStmtListNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}

 	void visit(ArgsNode* node){
 		cout << "(ArgsNode ";
 		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}

 	void visit(ExprNode* node){
		cout << "(ExprNode ";			
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
 	}
 	
 	void visit(StmtNode* node){
		cout << "(StmtNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
	}
 	void visit(SStmtNode* node){
		cout << "(SStmtNode ";
		list<Node*> children = node->getChildren();
 		for (list<Node*>::iterator it = children.begin(); it != children.end(); it++){
			(*it)->accept(*this);
		}
		cout << ")";
	}
 };