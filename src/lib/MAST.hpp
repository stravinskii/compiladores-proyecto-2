/**
 * Definición de un AST en memoria (MAST) y la interfaz del patrón Visitor con NodeVisitor
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include "SymbolTable.hpp"
#include <list>
#include "AST.hpp"
#ifndef COMPUESTOVISITANTE_HPP
#define COMPUESTOVISITANTE_HPP

 class VisitorNode;
 class INode;
 class LeafNode;
 class BinNode;

#endif

 using namespace std;
/**
 * Implementación de la clase abstracta Visitor
 */
 class Visitor{
 public:
	//Node
 	virtual void visit(Node*);
 	virtual void visit(INode*);
 	virtual void visit(BinNode*);

	//INode
 	virtual void visit(ForNode*);
 	virtual void visit(WhileNode*);
 	virtual void visit(IfNode*);
 	virtual void visit(StmtListNode*);
 	virtual void visit(SStmtListNode*);
 	virtual void visit(ExprNode*);

 	virtual void visit(FuncNode*);
 	virtual void visit(ArgsNode*);
 	virtual void visit(StmtNode*);
 	virtual void visit(SStmtNode*);

 	//BinNode
 	virtual void visit(AssignNode*);
 	virtual void visit(PlusNode*);
 	virtual void visit(MinusNode*);
 	virtual void visit(DiviNode*);
 	virtual void visit(MultNode*);

 	virtual void visit(AndNode*);
 	virtual void visit(OrNode*);
 	virtual void visit(XorNode*);
 	virtual void visit(NotNode*);
 	virtual void visit(PotNode*);

 	virtual void visit(LTNode*);
 	virtual void visit(GTNode*);
 	virtual void visit(EqNode*);
 	virtual void visit(NEqNode*);
 	virtual void visit(LTEqNode*);
 	virtual void visit(GTEqNode*);

	//LeafNode
 	virtual void visit(IdentNode*);
 	virtual void visit(IntNode*);
 	virtual void visit(FloatNode*);
 	virtual void visit(StrNode*);
 	virtual void visit(BoolNode*);
 protected:
 	Visitor();
	//SymbolTable* symbolTable;

 };
 
/**
 * Implementación de los nodos que heredan de INode
 * 
 */

 class ArgsNode : public INode
 {
 public:
 	ArgsNode() : INode() {};
 	
 	void accept(Visitor& v)
 	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };

 class FuncNode : public INode
 {
 public:
 	FuncNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };


 class ForNode : public INode{
 public:
 	ForNode() : INode() {};

 	void accept(Visitor &v)
 	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);

 	}
 };

 class WhileNode : public INode{
 public:
 	WhileNode() : INode() {};

 	void accept(Visitor &v){
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };
 
 class StmtListNode : public INode{
 public:
 	StmtListNode() : INode() {};

 	void accept(Visitor &v)	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 }; 

 class SStmtListNode : public INode{
 public:
 	SStmtListNode() : INode() {};

 	void accept(Visitor &v){
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 }; 

 class ExprNode : public INode{
 public:
 	ExprNode() : INode() {};

 	void accept(Visitor &v){
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };
 
 
 class IfNode : public INode{
 public:
 	IfNode() : INode() {};

 	void accept(Visitor &v){
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };

 class StmtNode : public INode
 {
 public:
 	StmtNode() : INode() {};
 	void accept(Visitor& v)
 	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };

 class SStmtNode : public INode
 {
 public:
 	SStmtNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);
 	}
 };


 
 /**
  * Implementación de los nodos que heredan de BinNode
  * 
  */

  class LTNode : public BinNode
  {
  public:
  	LTNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class GTNode : public BinNode
  {
  public:
  	GTNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class EqNode : public BinNode
  {
  public:
  	EqNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class NEqNode : public BinNode
  {
  public:
  	NEqNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class LTEqNode : public BinNode
  {
  public:
  	LTEqNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class GTEqNode : public BinNode
  {
  public:
  	GTEqNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class PotNode : public BinNode
  {
  public:
  	PotNode() : BinNode() {};
  	
  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class AndNode : public BinNode
  {
  public:
  	AndNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class OrNode : public BinNode
  {
  public:
  	OrNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class XorNode : public BinNode
  {
  public:
  	XorNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class NotNode : public BinNode
  {
  public:
  	NotNode() : BinNode() {};

  	void accept(Visitor& v)
  	{
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class AssignNode : public BinNode{
  public:
  	AssignNode() : BinNode() {};

  	void accept(Visitor &v){
  		IdentNode* c = dynamic_cast<IdentNode*>(getLeftChild());
  		if(c != 0) {
  			throw "Assignment operation is only for variables";
  		}else{
  			v.visit(getLeftChild());
  			v.visit(getRightChild());
  		}
  	}
  };

  class PlusNode : public BinNode{
  public:
  	PlusNode() : BinNode() {};

  	void accept(Visitor &v){
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class MinusNode : public BinNode{
  public:
  	MinusNode() : BinNode() {};

  	void accept(Visitor &v){
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class DiviNode : public BinNode{
  public:
  	DiviNode() : BinNode() {};

  	void accept(Visitor &v){
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

  class MultNode : public BinNode{
  public:
  	MultNode() : BinNode() {};

  	void accept(Visitor &v){
  		v.visit(getLeftChild());
  		v.visit(getRightChild());
  	}
  };

 /**
  * 
  * Implementación de los nodos que heredan de LeafNode
  */

  class IdentNode : public LeafNode{
  public:
  	IdentNode(string val) : LeafNode(){
  		value.str = &val;
  	}

  	NValue getValue(){
  		return value.str;
  	}

  	void accept(Visitor &v)	{
  		Simbolo *s=v.symbolTable->lookUp(*value.str);
  		if(s==NULL)
  			s=new Simbolo(value.str,(int*)NULL);

  		symbolTable.insertName(s);
 		//Aguas!
  	}
  };

  class IntNode : public LeafNode{
  public:
  	IntNode(int i){
  		value.i = i;
  	}

  	NValue getValue(){
  		return value.i;
  		return value.i;
  	}

  	void accept(Visitor &v){
  		cout<<"int aceptado";
  	}
  };

  class FloatNode : public LeafNode{
  public:
  	FloatNode(float f) : LeafNode(){
  		value.f = f;
  	}

  	NValue getValue(){
  		return value.f;
  	}

  	void accept(Visitor &v){
  		cout<<"float aceptado";
  	}
  };


  class StrNode : public LeafNode{
  public:

  	StrNode(string str) : LeafNode(){
  		value.str = &str;
  	}

  	NValue getValue(){
  		return value.str;
  	}

  	void accept(Visitor &v){
  		cout<<"String aceptado";
  	}
  };

  class BoolNode : public LeafNode{
  public:
  	BoolNode(bool boolean) : LeafNode(){
  		value.b = &boolean;
  	}

  	NValue getValue(){
  		return value.b;
  	}

  	void accept(Visitor &v){
  		cout<<"Boolean aceptado";
  	}
  };

  class MAST : public AST{
  public:
  	MAST() : AST() {};


  	IntNode* bIntNode(int val){
  		return new IntNode(val);
  	}

  	StrNode* bStrNode(string val){
  		return new StrNode(val);
  	}

  	FloatNode* bFloatNode(float val){
  		return new FloatNode(val);
  	}

  	BoolNode* bBoolNode(bool val){
  		return new BoolNode(val);
  	}

  	IdentNode* bIdentNode(string name){
  		return new IdentNode(name);
  	}

  	PlusNode* bPlusNode(){
  		return new PlusNode();
  	}

  	MultNode* bMultNode(){
  		return new MultNode();
  	}

  	DiviNode* bDiviNode(){
  		return new DiviNode();
  	}

  	MinusNode* bMinusNode(){
  		return new MinusNode();
  	}

  	IfNode* bIfNode(){
  		return new IfNode();
  	}

  	ForNode* bForNode(){
  		return new ForNode();
  	}

  	WhileNode* bWhileNode(){
  		return new WhileNode();
  	}

  	StmtListNode* bStmtListNode(){
  		return new StmtListNode();
  	}

  	SStmtListNode* bSStmtListNode(){
  		return new SStmtListNode();
  	}

  	ExprNode* bExprNode(){
  		return new ExprNode();
  	}

  	LTNode* bLTNode()
  	{
  		return new LTNode();
  	}

  	GTNode* bGTNode()
  	{
  		return new GTNode();
  	}

  	EqNode* bEqNode()
  	{
  		return new EqNode();
  	}

  	NEqNode* bNEqNode()
  	{
  		return new NEqNode();
  	}

  	LTEqNode* bLTEqNode()
  	{
  		return new LTEqNode();
  	}

  	GTEqNode* bGTEqNode()
  	{
  		return new GTEqNode();
  	}

  	AndNode* bAndNode()
  	{
  		return new AndNode();
  	}

  	OrNode* bOrNode()
  	{
  		return new OrNode();
  	}

  	XorNode* bXorNode()
  	{
  		return new XorNode();
  	}

  	NotNode* bNotNode()
  	{
  		return new NotNode();
  	}

  	PotNode* bPotNode()
  	{
  		return new PotNode();
  	}

  	ArgsNode* bArgsNode()
  	{
  		return new ArgsNode();
  	}

  	FuncNode* bFuncNode()
  	{
  		return new FuncNode();
  	}

  };


  class VisitorNode : public Visitor{
  public:
  	SymbolTable* symbolTable;

  	VisitorNode(){
  		symbolTable= new SymbolTable;
  	}

  	VisitorNode(SymbolTable *ts){
  		symbolTable=ts;
  	}

  	void visit(Node* node){
  		INode* inode = dynamic_cast<INode*>(node);
  		if(inode != 0) {
  			visit(inode);
  			return;
  		}

  		LeafNode* lnode= dynamic_cast<LeafNode*>(node);
  		if(lnode!=0){
  			visit(lnode);
  			return;
  		}

  	}

  	void visit(LeafNode* node){
  		IntNode* inode = dynamic_cast<IntNode*> inode;
  		if(inode!=0){
  			visit(inode);
  			return;
  		}
  		StrNode* stnode = dynamic_cast<StrNode*>stnode;
  		if(stnode!=0){
  			visit(stnode);
  			return;
  		}
  		FloatNode* flnode= dynamic_cast<FloatNode*>flnode;
  		if(flnode!=0){
  			visit(flnode);
  			return;
  		}
  		IdentNode* idnode= dynamic_cast<IdentNode*>idnode;
  		if(idnode!=0){
  			visit(idnode);
  		}
  	}

  	void visit(INode* node){
  		BinNode* bnode=dynamic_cast<BinNode*>(node);
  		if(bnode!=0){
  			visit(bnode);
  			return;
  		}

  		StmtNode* stmtnode = dynamic_cast<StmtNode*>(node);
  		if(stmtnode!=0){
  			visit(stmtNode);
  			return;
  		}

  		SStmtNode* sstmtnode = dynamic_cast<SStmtNode*>(node);
  		if(sstmtnode!=0){
  			visit(sstmtNode);
  			return;
  		}

  		StmtListNode* stmtlistnode = dynamic_cast<StmtListNode*>(node);
  		if(stmtlistnode!=0){
  			visit(stmtlistnode);
  			return;
  		}

  		SStmtListNode* sslnode = dynamic_cast<SStmtListNode*>(node);
  		if(sslnode!=0){
  			visit(sslnode);
  			return;
  		}
  		ExprNode* expnode = dynamic_cast<ExprNode*>(node);
  		if(expnode!=0){
  			visit(expnode);
  		}

  		IfNode* ifnode = dynamic_cast<IfNode*>(node);
  		if(ifnode!=0){
  			visit(ifnode);
  			return;
  		}
  		ForNode* fnode) = dynamic_cast<ForNode*>(node);
		if(fnode!=0){
			visit(fnode);
			return;
		}
		WhileNode* wnode = dynamic_cast<WhileNode*>(node);
		if(wnode!=0){
			visit(wnode);
			return;
		}

		FuncNode* funcn = dynamic_cast<FuncNode*>(node);
		if(funcn!=0) {
			visit(funcn);
			return;
		}

		ArgsNode* argsn = dynamic_cast<ArgsNode*>(node);
		if (argsn!=0)
		{
			visit(argsn);
			return;
		}
	}

	void visit(BinNode* node){
		PlusNode* plnode= dynamic_cast<PlusNode*>(node);
		if(plnode!=0){
			visit(plnode);
			return;
		}
		MultNode* mulnode= dynamic_cast<MultNode*>(node);
		if(mulnode!=0){
			visit(mulnode);
			return;
		}
		DiviNode* divnode= dynamic_cast<DiviNode*>(node);
		if(divnode!=0){
			visit(divnode);
			return;
		}

		MinusNode* minnode= dynamic_cast<MinusNode*>(node);
		if(minnode!=0){
			visit(minnode);
			return;
		}

		AssignNode* assnode= dynamic_cast<AssignNode*>(node);
		if(assnode!=0){
			visit(assnode);
			return;
		}

		AndNode* andnode = dynamic_cast<AndNode*>(node);
		if (andnode!=0) {
			visit(andnode);
			return;
		}
	 	OrNode* ornode = dynamic_cast<OrNode*>(node);
	 	if (ornode!=0) {
	 		visit(ornode);
	 		return;
	 	}
	 	XorNode* xornode = dynamic_cast<XorNode*>(node);
	 	if (xornode!=0) {
	 		visit(xornode);
	 		return;
	 	}
	 	NotNode* notnode = dynamic_cast<NotNode*>(node);
	 	if (notnode!=0) {
	 		visit(notnode);
	 		return;
	 	}
	 	PotNode* potnode = dynamic_cast<PotNode*>(node);
	 	if (potnode!=0) {
	 		visit(potnode);
	 		return;
	 	}
	 	LTNode* ltnode = dynamic_cast<LTNode*>(node);	
	 	if (ltnode!=0) {
	 		visit(ltnode);
	 		return;
	 	}
	 	GTNode* gtnode = dynamic_cast<GTNode*>(node);	
	 	if (gtnode!=0) {
	 		visit(gtnode);
	 		return;
	 	}
	 	EqNode* eqnode = dynamic_cast<EqNode*>(node);	
	 	if (eqnode!=0) {
	 		visit(eqnode);
	 		return;
	 	}
	 	NEqNode* neqnode = dynamic_cast<NEqNode*>(node);	
	 	if (neqnode!=0) {
	 		visit(neqnode);
	 		return;
	 	}
	 	LTEqNode* lteqnode = dynamic_cast<LTEqNode*>(node);	
	 	if (lteqnode!=0) {
	 		visit(lteqnode);
	 		return;
	 	}
	 	GTEqNode* gteqnode = dynamic_cast<GTEqNode*>(node);	
	 	if (gteqnode!=0) {
	 		visit(gteqnode);
	 		return;
	 	}
	}

	void visit(ForNode* node){
		for (list<Node>::iterator it=node->children->children.listas->begin(); it != node->children->children.listas->end(); ++it)
			it.accept(this);
	}

	void visit(WhileNode* node){
		for (list<Node>::iterator it=node->children->children.listas->begin(); it != node->children->children.listas->end(); ++it)
			it->accept(this); 
	}

	void visit(IfNode* node){
		for (list<Node>::iterator it=node->children->children.listas->begin(); it != node->children->children.listas->end(); ++it)
			it->accept(this);

	}

	void visit(FuncNode* node)
	{
		for (list<Node>::iterator it=node->children->children.listas->begin(); it != node->children->children.listas->end(); ++it)
			it->accept(this);		
	}

 	void visit(ArgsNode* node)
 	{
 		for (list<Node>::iterator it=node->children->children.listas->begin(); it != node->children->children.listas->end(); ++it)
			it->accept(this);
 	}

	void visit(AssignNode* node){
		node->accept(this);
	}

	void visit(StmtListNode* node){
		node->accept(this);
	}

	void visit(SStmtListNode* node){
		node->accept(this);
	}

	void visit(ExprNode* node){
		node->accept(this);
	}
	void visit(AndNode* node)
	{
		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
	}

 	void visit(OrNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(XorNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(NotNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(PotNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(LTNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(GTNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(EqNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(NEqNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(LTEqNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

 	void visit(GTEqNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
 	}

	void visit(PlusNode* node){
		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(this);
		right.accept(this);
	}

	void visit(MinusNode* node){
		Node *left = node->getLeftChild();
		Node *right = node->getRightChild();
		left->accept(this);
		right->accept(this);
	}

	void visit(DiviNode* node){
		Node *left = node->getLeftChild();
		Node *right = node->getRightChild();
		left->accept(this);
		right->accept(this);
	}

	void visit(MultNode* node){
		Node *left = node->getLeftChild();
		Node *right = node->getRightChild();
		left->accept(this);
		right->accept(this);
	}

	void visit(IdentNode* node){
		node->accept(this);
	}

	void visit(IntNode* node){
		node->accept(this);
	}

	void visit(FloatNode* node){
		node->accept(this);
	}

	void visit(StrNode* node){
		node->accept(this);
	}

	void visit(BoolNode* node){
		node->accept(this);
	}
};


/*int main(int argc,char* argv[]){
	Node* nodo = new Node;
 	MAST* astTree = new MAST;
 	IntNode* nodoInt = astTree->bIntNode(4);
 	int value = nodoInt->getValue().i;
 	std::cout << value << std::endl;

 	StrNode* nodoString = astTree->bStrNode("something");
 	nodoString->getValue();
 	NodeVisitor *vs;
 	nodo->accept(vs);
}*/

