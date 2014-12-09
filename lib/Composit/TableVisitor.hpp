/**
 * Definición de Visitante concreto para llenar la tabla de símbolos
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include "MAST.hpp"

class VisitorNode : public Visitor{
public:
	~VisitorNode(){};
	VisitorNode():Visitor(){
		 // symbolTable= new SymbolTable;
	}
	
	// VisitorNode(SymbolTable *ts):Visitor(){
	// 	symbolTable=ts;
	// }
 
 	void visit(Node* node){
	 	cout << "(Node ";
	 	visit(node);
	 	cout << ")";
 	}
	
 	void visit(ForNode* node){
		cout << "(ForNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}

 	void visit(WhileNode* node){
		cout << "(WhileNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}

 	void visit(IfNode* node){
		cout << "(IfNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}

 	void visit(AssignNode* node){
		cout << "(AssignNode ";
		node->getLeftChild()->accept(*this);
		node->getRightChild()->accept(*this);

		// IdentNode* left = dynamic_cast<IdentNode*> (node->getLeftChild());
		// if (left != 0) {
		// 	Node* right = node->getRightChild();
		// 	Visitor *v = this;
		// 	node->insertInTable(left, right, v);
		// } else {
		// 	cout<<endl<<"ERROR: Assignment operation is only for variables"<<endl;
		// 	throw "Assignment operation is only for variables";
		// }

		cout << ")";
		// cout<<endl<<"Actualizando variable en la tabla"<<endl;
		// symbolTable->printTable();
 	}

 	void visit(StmtListNode* node){
		cout << "(StmtListNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}

 	void visit(SStmtListNode* node){
		cout << "(SStmtListNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}
 	
 	void visit(FuncNode* node){
		cout << "(FuncNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}

 	void visit(ArgsNode* node){
 		cout << "(ArgsNode ";
 		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}

 	void visit(ExprNode* node){
		cout << "(ExprNode ";			
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}
 	
 	void visit(StmtNode* node){
		cout << "(StmtNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}
 	void visit(SStmtNode* node){
		cout << "(SStmtNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}
 	
 	void visit(AndNode* node){
 		cout << "(AndNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(OrNode* node){
 		cout << "(OrNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(XorNode* node){
 		cout << "(XorNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(NotNode* node){
 		cout << "(NotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(PotNode* node){
 		cout << "(PotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(LTNode* node){
 		cout << "(LTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(GTNode* node){
 		cout << "(GTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(EqNode* node){
 		cout << "(EqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(NEqNode* node){
 		cout << "(NEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(LTEqNode* node){
 		cout << "(LTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(GTEqNode* node){
 		cout << "(GTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}
 	
 	void visit(PlusNode* node){
 		cout << "(PlusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		if (left != NULL)
 		{
 			left->accept(*v);
 		}
 		if (right != NULL)
 		{
 			right->accept(*v);
 		}
 		cout << ")";
 	}

 	void visit(MinusNode* node){
 		cout << "(MinusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		if (left != NULL)
 		{
 			left->accept(*v);
 		}
 		if (right != NULL)
 		{
 			right->accept(*v);
 		}
 		cout << ")";
 	}

 	void visit(DiviNode* node){
 		cout << "(DiviNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		if (left != NULL)
 		{
 			left->accept(*v);
 		}
 		if (right != NULL)
 		{
 			right->accept(*v);
 		}
 		cout << ")";
 	}

 	void visit(MultNode* node){
 		cout << "(MultNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		if (left != NULL)
 		{
 			left->accept(*v);
 		}
 		if (right != NULL)
 		{
 			right->accept(*v);
 		}
 		cout << ")";
 	}

 	/**
 	 * OJO:
 	 * Los nodos hojas no tiene porque llamarse a sí mismos el accept, se ciclaría,
 	 * además de que teoricamente ya esos nodos ya los llamó el visit de un nodo que los tiene como hijos.
 	 */

 	void visit(IdentNode* node){
		string* name = new string(node->getValue());
		cout << "(IdentNode "<<*name;
		// cout << "(IdentNode "<<*name<<endl;
		// Simbolo *s = symbolTable->lookUp(*name);
		//  if(s == 0) {
		// 	 cout<<"Insertando nueva variable en la tabla"<<endl;
		// 	 s=new Simbolo(name);
		// 	 symbolTable->insertName(s);
		// 	 //symbolTable->printTable();
		//  }
		cout << ")";
 	}

 	void visit(IntNode* node){
		cout << "(IntNode "<<node->getValue();
		// cout<<"Visite un entero "<<endl;
 		// Visitor *v=this;
		// node->accept(*v);
		cout << ")";
 	}

 	void visit(FloatNode* node){
 		cout << "(FloatNode "<<node->getValue();
 		// Visitor *v=this;
		// node->accept(*v);
		cout << ")";
 	}

 	void visit(StrNode* node){
 		cout << "(StrNode "<<node->getValue();
 		// Visitor *v=this;
		// node->accept(*v);
		cout << ")";
 	}

 	void visit(BoolNode* node){
		cout << "(BoolNode "<<node->getValue();
		// Visitor *v=this;
		// node->accept(*v);
		cout << ")";
 	}

 	/* Implementación de visit de nuevos nodos */
 	void visit(ReturnNode* node){
 		cout << "(ReturnNode ";
 		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
 	}
	void visit(PrintNode* node){
		cout << "(PrintNode ";
		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}
	void visit(BreakNode* node){
		cout << "(BreakNode)";
	}
	void visit(ContinueNode* node){
		cout << "(ContinueNode)";
	}
	
	void visit(FileNode* node) {
		cout << "(FileNode ";
 		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}

	void visit(CallNode* node) {
		cout << "(CallNode ";
 		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";
	}

	void visit(ExprListNode* node) {
		cout << "(ExprListNode ";
 		Visitor* v = this;
		for (auto& it: node->getChildren()){
			(*it).accept(*v);
		}
		cout << ")";	
	}
	
 };
