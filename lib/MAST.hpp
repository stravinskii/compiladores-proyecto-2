/**
 * Definición de un AST en memoria (MAST) y la interfaz del patrón Visitor con NodeVisitor
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

//#include "SymbolTable.hpp"
#include <list>
#include "AST.hpp"
#include "Nodos.hpp"
#include <string>

using namespace std;
/**
 * Implementación de la clase abstracta Visitor
 */
class Visitor{
public:
	virtual ~Visitor(){};
	//SymbolTable* symbolTable;
	//Node
	virtual void visit(Node*)=0;

	//INode
	virtual void visit(ForNode*)=0;
 	virtual void visit(WhileNode*)=0;
 	virtual void visit(IfNode*)=0;
 	virtual void visit(StmtListNode*)=0;
 	virtual void visit(SStmtListNode*)=0;
 	virtual void visit(ExprNode*)=0;
 	virtual void visit(FuncNode*)=0;
 	virtual void visit(ArgsNode*)=0;
 	virtual void visit(StmtNode*)=0;
 	virtual void visit(SStmtNode*)=0;
 	
 	//BinNode
 	virtual void visit(AssignNode*)=0;
 	virtual void visit(PlusNode*)=0;
 	virtual void visit(MinusNode*)=0;
 	virtual void visit(DiviNode*)=0;
 	virtual void visit(MultNode*)=0;
 	virtual void visit(AndNode*)=0;
 	virtual void visit(OrNode*)=0;
 	virtual void visit(XorNode*)=0;
 	virtual void visit(NotNode*)=0;
 	virtual void visit(PotNode*)=0;
 	virtual void visit(LTNode*)=0;
 	virtual void visit(GTNode*)=0;
 	virtual void visit(EqNode*)=0;
 	virtual void visit(NEqNode*)=0;
 	virtual void visit(LTEqNode*)=0;
 	virtual void visit(GTEqNode*)=0;
 	
	//LeafNode
	virtual void visit(IdentNode*)=0;
 	virtual void visit(IntNode*)=0;
 	virtual void visit(FloatNode*)=0;
 	virtual void visit(StrNode*)=0;
 	virtual void visit(BoolNode*)=0;
	
protected:
	Visitor(){};
	//SymbolTable* symbolTable;

};
 
/**
 * Implementación de los nodos que heredan de INode
 * 
 */
class ForNode : public INode{
public:
	~ForNode(){};
	ForNode():INode(){};
 	void accept(Visitor &v){
		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
			
 	}
 };

 class WhileNode : public INode{
 public:
 	~WhileNode(){};
 	WhileNode():INode(){};
 	void accept(Visitor &v){
		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };
 
 class StmtListNode : public INode{
 public:
	~StmtListNode(){};
	StmtListNode():INode(){};
 	void accept(Visitor &v)	{
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 }; 

 class SStmtListNode : public INode{
 public:
	~SStmtListNode(){};
	SStmtListNode():INode(){};
 	void accept(Visitor &v){
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 }; 

 class ExprNode : public INode{
 public:
	~ExprNode(){};
	ExprNode():INode(){};
 	void accept(Visitor &v){
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };
 
 
 class IfNode : public INode{
 public:
	~IfNode(){};
	IfNode():INode(){};
 	void accept(Visitor &v){
		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };
 
class ArgsNode : public INode{
public:
	~ArgsNode(){};
	ArgsNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };

 class FuncNode : public INode{
 public:
	~FuncNode(){};
	FuncNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };
 
 class StmtNode : public INode{
 public:
	~StmtNode(){};
	StmtNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };

 class SStmtNode : public INode{
 public:
	~SStmtNode(){};
	SStmtNode():INode(){};
 	void accept(Visitor& v){
		v.visit(this);
 		/*for (list<Node*>::iterator it= getChildren().begin(); it != getChildren().end(); ++it)
 			v.visit(*it);*/
 	}
 };

 
 
 
 
 /**
  * Implementación de los nodos que heredan de BinNode
  * 
  */

 class AssignNode : public BinNode{
 public:
	~AssignNode(){};
	AssignNode():BinNode(){};
	
 	void accept(Visitor &v){
 		v.visit(this);
	}
 };

 
 class PlusNode : public BinNode{
 public:
	~PlusNode(){};
	PlusNode():BinNode(){};
 	void accept(Visitor &v){
 		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
 	}
 };

class MinusNode : public BinNode{
public:
	~MinusNode(){};
	MinusNode():BinNode(){};
	
 	void accept(Visitor &v){
		v.visit(this);
 		//v.visit(getLeftChild());
		//v.visit(getRightChild());
 	}
 };

 class DiviNode : public BinNode{
 public:
	~DiviNode(){};
	DiviNode():BinNode(){};
 	void accept(Visitor &v){
		v.visit(this);
 		//v.visit(getLeftChild());
		//v.visit(getRightChild());
 	}
 };

class MultNode : public BinNode{
public:
	~MultNode(){};
	MultNode():BinNode(){};
	
 	void accept(Visitor &v){
		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
		
 	}
 };
 
class LTNode : public BinNode{
public:
	~LTNode(){};
	LTNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

class GTNode : public BinNode{
public:
	~GTNode(){};
	GTNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

class EqNode : public BinNode{
  public:
  ~EqNode(){};
  EqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

  class NEqNode : public BinNode{
  public:
	~NEqNode(){};
	NEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

class LTEqNode : public BinNode{
  public:
	~LTEqNode(){};
	LTEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

class GTEqNode : public BinNode{
  public:
  ~GTEqNode(){};
  GTEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

  class PotNode : public BinNode{
  public:
	~PotNode(){};
	PotNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

class AndNode : public BinNode{
public:
	~AndNode(){};
	AndNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

  class OrNode : public BinNode{
  public:
	~OrNode(){};
	OrNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

  class XorNode : public BinNode{
  public:
  ~XorNode(){};
  XorNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };

  class NotNode : public BinNode
  {
  public:
  ~NotNode(){};
  NotNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
		//v.visit(getLeftChild());
		//v.visit(getRightChild());
  	}
  };
 
 
 
 
 
 /**
  * 
  * Implementación de los nodos que heredan de LeafNode
  */

 class IdentNode : public LeafNode{
 public:
	IdentNode():LeafNode(){};
	~IdentNode(){};
 	IdentNode(string val) : LeafNode(){
 		value.str = &val;
 	}

 	string getValue(){
 		return *value.str;
 	}

 	void accept(Visitor &v)	{
 		v.visit(this);
 		//Aguas!
 	}
 };

 class IntNode : public LeafNode{
 public:
	~IntNode(){};
 	IntNode(int i){
 		value.i = i;
 	}

 	int getValue(){
 		return value.i;
 	}

 	void accept(Visitor &v){
 		// cout<<"int aceptado"<<endl;
 		v.visit(this);
 	}
 };

 class FloatNode : public LeafNode{
 public:
	~FloatNode(){};
 	FloatNode(float f){
 		value.f = f;
 	}

 	float getValue(){
 		return value.f;
 	}

 	void accept(Visitor &v){
 		// cout<<"float aceptado"<<endl;
 		v.visit(this);
 	}
 };


 class StrNode : public LeafNode{
 public:
	~StrNode(){};
 	StrNode(string str){
 		value.str = &str;
 	}

 	string getValue(){
 		return *value.str;
 	}

 	void accept(Visitor &v){
 		// cout<<"String aceptado"<<endl;
 		v.visit(this);
 	}
 };

 class BoolNode : public LeafNode{
 public:
	~BoolNode(){};
 	BoolNode(bool boolean) : LeafNode(){
 		value.b = &boolean;
 	}

	bool getValue(){
		return value.b;
	}

	void accept(Visitor &v){
 		// cout<<"Boolean aceptado"<<endl;
 		v.visit(this);
 	}
 };

 class MAST : public AST{
 public:
	~MAST(){};
	MAST():AST(){cout<<"MAST creado"<<endl;};
	//LeafNode
 	IntNode* bIntNode(int val){
 		cout << "bIntNode" << endl;
 		return new IntNode(val);
 	}

 	StrNode* bStrNode(string val){
 		cout << "bStrNode" << endl;
 		return new StrNode(val);
 	}

 	FloatNode* bFloatNode(float val){
 		cout << "bFloatNode" << endl;
 		return new FloatNode(val);
 	}

 	BoolNode* bBoolNode(bool val){
 		cout << "bBoolNode" << endl;
 		return new BoolNode(val);
 	}

 	IdentNode* bIdentNode(string name){
 		cout << "bIdentNode" << endl;
 		return new IdentNode(name);
 	}
 	
	//BinNode
 	PlusNode* bPlusNode(){
 		cout << "bPlusNode" << endl;
 		return new PlusNode;
 	}

 	MultNode* bMultNode(){
 		cout << "bMultNode" << endl;
 		return new MultNode;
 	}

 	DiviNode* bDiviNode(){
 		cout << "bDiviNode" << endl;
 		return new DiviNode;
 	}

 	MinusNode* bMinusNode(){
 		cout << "bMinusNode" << endl;
 		return new MinusNode;
 	}
 	
 	AssignNode* bAssignNode(){
 		cout << "bAssignNode" << endl;
		return new AssignNode;
	}
	
	AndNode* bAndNode(){
		cout << "bAndNode" << endl;
  		return new AndNode;
  	}

  	OrNode* bOrNode(){
  		cout << "bOrNode" << endl;
  		return new OrNode;
  	}

  	XorNode* bXorNode(){
  		cout << "bXorNode" << endl;
  		return new XorNode;
  	}

  	NotNode* bNotNode(){
  		cout << "bNotNode" << endl;
  		return new NotNode;
  	}
  	
  	LTNode* bLTNode(){
  		cout << "bLTNode" << endl;
  		return new LTNode;
  	}
  	
  	GTNode* bGTNode(){
  		cout << "bGTNode" << endl;
  		return new GTNode;
  	}

  	EqNode* bEqNode(){
  		cout << "bEqNode" << endl;
  		return new EqNode;
  	}

  	NEqNode* bNEqNode(){
  		cout << "bNEqNode" << endl;
  		return new NEqNode;
  	}

  	LTEqNode* bLTEqNode(){
  		cout << "bLTEqNode" << endl;
  		return new LTEqNode();
  	}

  	GTEqNode* bGTEqNode(){
  		cout << "bGTEqNode" << endl;
  		return new GTEqNode;
  	}

  	PotNode* bPotNode(){
  		cout << "bPotNode" << endl;
  		return new PotNode;
  	}
  	
  	//INode
  	StmtNode* bStmtNode(){
  		cout << "bStmtNode" << endl;
		return new StmtNode;
	}
	
	SStmtNode* bSStmtNode(){
		cout << "bSStmtNode" << endl;
		return new SStmtNode;
	}
  	
  	StmtListNode* bStmtListNode(){
  		cout << "bStmtListNode" << endl;
 		return new StmtListNode;
 	}

 	SStmtListNode* bSStmtListNode(){
 		cout << "bSStmtListNode" << endl;
 		return new SStmtListNode;
 	}
  	ExprNode* bExprNode(){
  		cout << "bExprNode" << endl;
 		return new ExprNode;
 	}
 	
 	IfNode* bIfNode(){
 		cout << "bIfNode" << endl;
 		return new IfNode;
 	}

 	ForNode* bForNode(){
 		cout << "bForNode" << endl;
 		return new ForNode;
 	}

 	WhileNode* bWhileNode(){
 		cout << "bWhileNode" << endl;
 		return new WhileNode;
 	}

  	ArgsNode* bArgsNode(){
  		cout << "bArgsNode" << endl;
  		return new ArgsNode;
  	}

  	FuncNode* bFuncNode(){
  		cout << "bFuncNode" << endl;
  		return new FuncNode;
  	}
 };


class VisitorNode : public Visitor{
public:
	~VisitorNode(){};
	VisitorNode():Visitor(){
		// symbolTable= new SymbolTable;
	}
	
	// VisitorNode(SymbolTable *ts):Visitor(){
		// symbolTable=ts;
	// }
 
 	void visit(Node* node){
	 	cout << "(Node ";
	 	visit(node);
	 	cout << ")";
 	}
	
 	void visit(ForNode* node){
		cout << "(ForNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		cout << ")";
 	}

 	void visit(WhileNode* node){
		cout << "(WhileNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		} 
		cout << ")";
 	}

 	void visit(IfNode* node){
		cout << "(IfNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		
		cout << ")";
 	}

 	void visit(AssignNode* node){
		cout << "(AssignNode ";
		// cout << "visite un assignode" << endl;
		IdentNode* c = dynamic_cast<IdentNode*> (node->getLeftChild());
		if(c != 0){
			Node *left = node->getLeftChild();
			Node *right = node->getRightChild();
			Visitor *v=this;
			left->accept(*v);
			right->accept(*v);
		}else{
			throw "Assignment operation is only for variables";
			cout<<"Assignment operation is only for variables"<<endl;
		}
			
		cout << ")";
 	}

 	void visit(StmtListNode* node){
		cout << "(StmtListNode ";
		Visitor *v=this;
		node->accept(*v);
		cout << ")";
 	}

 	void visit(SStmtListNode* node){
		cout << "(SStmtListNode ";
		Visitor *v=this;
		node->accept(*v);
		cout << ")";
 	}
 	
 	void visit(FuncNode* node){
		cout << "(FuncNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);	
		}	
		cout << ")";
	}

 	void visit(ArgsNode* node){
 		cout << "(ArgsNode ";
 		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		cout << ")";
 	}

 	void visit(ExprNode* node){
		cout << "(ExprNode ";
		Visitor *v=this;
		node->accept(*v);
		cout << ")";
 	}
 	
 	void visit(StmtNode* node){
		cout << "(StmtNode ";
		Visitor *v=this;
		cout << ")";
		node->accept(*v);
	}
 	void visit(SStmtNode* node){
		cout << "(SStmtNode ";
		Visitor *v=this;
		node->accept(*v);
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
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(MinusNode* node){
 		cout << "(MinusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(DiviNode* node){
 		cout << "(DiviNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	void visit(MultNode* node){
 		cout << "(MultNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		cout << ")";
 	}

 	/**
 	 * OJO:
 	 * Los nodos hojas no tiene porque llamarse a sí mismos el accept, se ciclaría,
 	 * además de que teoricamente ya esos nodos ya los llamó el visit de un nodo que los tiene como hijos.
 	 */

 	void visit(IdentNode* node){
		cout << "(IdentNode "<<node->getValue();
		// cout << "visite una variable" << endl;
		string name = node->getValue();
		// Simbolo *s = symbolTable->lookUp(&name);
		// if(s==0){
		// 	cout<<"Es nulo"<<endl;
		// 	string cad = "";
		// 	s=new Simbolo(name,&cad);
		// 	symbolTable->insertName(s);
		// 	symbolTable->printTable();
		// }
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
 };