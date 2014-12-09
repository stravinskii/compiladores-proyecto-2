/**
 * Definición de un AST en memoria (MAST) y la interfaz del patrón Visitor con NodeVisitor
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

// #include "../SymbolTable/SymbolTable.hpp"
#include "AST.hpp"

using namespace std;
/**
 * Implementación de la clase abstracta Visitor
 */
class Visitor{
public:
	virtual ~Visitor(){};
	// SymbolTable* symbolTable;
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

 	//New Nodes
 	virtual void visit(ReturnNode*)=0;
 	virtual void visit(PrintNode*)=0;
 	virtual void visit(BreakNode*)=0;
 	virtual void visit(ContinueNode*)=0;
 	
 	virtual void visit(FileNode*)=0;
 	virtual void visit(CallNode*)=0;
 	virtual void visit(ExprListNode*)=0;
	
protected:
	Visitor(){};
};


 /**
  * Implementación de los nodos que heredan de LeafNode
  */
  
 class IdentNode : public LeafNode{
 public:
 	string value;
	IdentNode():LeafNode(){};
	~IdentNode(){};
 	IdentNode(string* val) : LeafNode(){
 		value = *val;
 	}

 	string getValue(){
 		return value;
 	}

 	void accept(Visitor &v)	{
 		v.visit(this);
 	}
 };

 class IntNode : public LeafNode{
 public:
 	int value;
	~IntNode(){};
 	IntNode(int i){
 		value = i;
 	}

 	int getValue(){
 		return value;
 	}

 	void accept(Visitor &v){
 		// cout<<"int aceptado"<<endl;
 		v.visit(this);
 	}
 };

 class FloatNode : public LeafNode{
 public:
 	float value;
	~FloatNode(){};
 	FloatNode(float f){
 		value = f;
 	}

 	float getValue(){
 		return value;
 	}

 	void accept(Visitor &v){
 		// cout<<"float aceptado"<<endl;
 		v.visit(this);
 	}
 };


 class StrNode : public LeafNode{
 public:
 	string value;
	~StrNode(){};
 	StrNode(string* str){
 		value = *str;
 	}

 	string getValue(){
 		return value;
 	}

 	void accept(Visitor &v){
 		// cout<<"String aceptado"<<endl;
 		v.visit(this);
 	}
 };

 class BoolNode : public LeafNode{
 public:
 	bool value;
	~BoolNode(){};
 	BoolNode(bool boolean) : LeafNode(){
 		value = boolean;
 	}

	bool getValue(){
		return value;
	}

	void accept(Visitor &v){
 		// cout<<"Boolean aceptado"<<endl;
 		v.visit(this);
 	}
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
 	}
 };

 class WhileNode : public INode{
 public:
 	~WhileNode(){};
 	WhileNode():INode(){};
 	void accept(Visitor &v){
		v.visit(this);
 	}
 };
 
 class StmtListNode : public INode{
 public:
	~StmtListNode(){};
	StmtListNode():INode(){};
 	void accept(Visitor &v)	{
 		v.visit(this);
 	}
 }; 

 class SStmtListNode : public INode{
 public:
	~SStmtListNode(){};
	SStmtListNode():INode(){};
 	void accept(Visitor &v){
 		v.visit(this);
 	}
 }; 

 class ExprNode : public INode{
 public:
	~ExprNode(){};
	ExprNode():INode(){};
 	void accept(Visitor &v){
 		v.visit(this);
 	}
 };
 
 
 class IfNode : public INode{
 public:
	~IfNode(){};
	IfNode():INode(){};
 	void accept(Visitor &v){
		v.visit(this);
 	}
 };
 
class ArgsNode : public INode{
public:
	~ArgsNode(){};
	ArgsNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 	}
 };

 class FuncNode : public INode{
 public:
	~FuncNode(){};
	FuncNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 	}
 };
 
 class StmtNode : public INode{
 public:
	~StmtNode(){};
	StmtNode():INode(){};
 	void accept(Visitor& v){
 		v.visit(this);
 	}
 };

 class SStmtNode : public INode{
 public:
	~SStmtNode(){};
	SStmtNode():INode(){};
 	void accept(Visitor& v){
		v.visit(this);
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
	
	void insertInTable(IdentNode* left, Node* r, Visitor* v){
		// ExprNode* right = static_cast<ExprNode*> (r);
		//  string* var = new string(left->getValue());
		 
		//  Simbolo* s= v->symbolTable->lookUp(*var);
		//  IntNode* entero = dynamic_cast<IntNode*> (right->getChildren().front());
		//  FloatNode* flotante = dynamic_cast<FloatNode*> (right);
		//  StrNode* cadena = dynamic_cast<StrNode*> (right);
		//  BoolNode* booleano = dynamic_cast<BoolNode*> (right);
		
		//  if (entero!=0) {
		//  	cout<<"Es un entero"<<endl;
		// 	cout<<"cambiando valor del apuntador"<<endl;
		// 	s->valor->integer=entero->getValue();
		 	
		//  } else if (flotante!=0) {
		//  	cout<<"Es un flotante"<<endl;
		//  	cout<<"cambiando valor del apuntador"<<endl;
		// 	s->valor->float_number=flotante->getValue();
		 	
		//  } else if (cadena!=0) {
		//  	cout<<"Es una cadena"<<endl;
		//  	cout<<"cambiando valor del apuntador"<<endl;
		// 	s->valor->cadena=cadena->getValue();
		//  } else if (booleano!=0) {
		//  	cout<<"Es un booleano"<<endl;
		//  	cout<<"cambiando valor del apuntador"<<endl;
		// 	s->valor->integer=booleano->getValue();
		//  } else {
		// 	 cout<<"Es una Expresion!"<<endl;
		//  	string* val= new string("OPERACION AUN NO EVALUADA, HASTA T. de E.");
		//  	s= new Simbolo(var,val);
		//  	v->symbolTable->insertName(s);
		//  }
		// left->accept(*v);
		// right->accept(*v);
	}
 };

 
 class PlusNode : public BinNode{
 public:
	~PlusNode(){};
	PlusNode():BinNode(){};
 	void accept(Visitor &v){
 		v.visit(this);
 	}
 };

class MinusNode : public BinNode{
public:
	~MinusNode(){};
	MinusNode():BinNode(){};
	
 	void accept(Visitor &v){
		v.visit(this);
 	}
 };

 class DiviNode : public BinNode{
 public:
	~DiviNode(){};
	DiviNode():BinNode(){};
 	void accept(Visitor &v){
		v.visit(this);
 	}
 };

class MultNode : public BinNode{
public:
	~MultNode(){};
	MultNode():BinNode(){};
	
 	void accept(Visitor &v){
		v.visit(this);
		
 	}
 };
 
class LTNode : public BinNode{
public:
	~LTNode(){};
	LTNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

class GTNode : public BinNode{
public:
	~GTNode(){};
	GTNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

class EqNode : public BinNode{
  public:
  ~EqNode(){};
  EqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

  class NEqNode : public BinNode{
  public:
	~NEqNode(){};
	NEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

class LTEqNode : public BinNode{
  public:
	~LTEqNode(){};
	LTEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

class GTEqNode : public BinNode{
  public:
  ~GTEqNode(){};
  GTEqNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

  class PotNode : public BinNode{
  public:
	~PotNode(){};
	PotNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

class AndNode : public BinNode{
public:
	~AndNode(){};
	AndNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

  class OrNode : public BinNode{
  public:
	~OrNode(){};
	OrNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

  class XorNode : public BinNode{
  public:
  ~XorNode(){};
  XorNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };

  class NotNode : public BinNode
  {
  public:
  ~NotNode(){};
  NotNode():BinNode(){};
  	void accept(Visitor& v){
  		v.visit(this);
  	}
  };
 
 /* Implementación de nuevos nodos */

class ReturnNode : public INode {
public:
	~ReturnNode(){};
	ReturnNode():INode(){};
	void accept(Visitor &v){
 		v.visit(this);
 	}
};

class PrintNode : public INode {
public:
	~PrintNode(){};
	PrintNode():INode(){};
	void accept(Visitor &v){
 		v.visit(this);
 	}
};

class BreakNode : public LeafNode {
public:
	~BreakNode(){};
	BreakNode():LeafNode(){};
	void accept(Visitor &v){
 		v.visit(this);
 	}
};

class ContinueNode : public LeafNode {
public:
	~ContinueNode(){};
	ContinueNode():LeafNode(){};
	void accept(Visitor &v){
 		v.visit(this);
 	}
};


class FileNode : public INode {
public:
	~FileNode(){};
	FileNode():INode(){};
	void accept(Visitor &v){
 		v.visit(this);
 	}
};

class CallNode : public INode {
public:
	~CallNode(){};
	CallNode():INode(){};

	void accept(Visitor &v) {
		v.visit(this);
	}
};

class ExprListNode : public INode {
public:
	ExprListNode():INode(){};
	~ExprListNode(){};
	void accept(Visitor &v) {
		v.visit(this);
	}
};

 class MAST : public AST{
 public:
	~MAST(){};
	MAST():AST(){
		cout<<"MAST creado"<<endl;
	}
	//LeafNode
 	IntNode* bIntNode(int val){
 		cout << "bIntNode" << endl;
 		return new IntNode(val);
 	}

 	StrNode* bStrNode(string* val){
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

 	IdentNode* bIdentNode(string* name){
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

  	/* Implementación del b de nuevos nodos */
  	ReturnNode* bReturnNode(){
  		cout << "bReturnNode" << endl;
  		return new ReturnNode;
  	}
  	
 	PrintNode* bPrintNode(){
 		cout << "bPrintNode" << endl;
 		return new PrintNode;
 	}
 	
 	BreakNode* bBreakNode(){
 		cout << "bBreakNode" << endl;
 		return new BreakNode;
 	}
 	
 	ContinueNode* bContinueNode(){
 		cout << "bContinueNode" << endl;
 		return new ContinueNode;
 	}
 	
 	FileNode* bFileNode() {
 		cout << "bFileNode" << endl;
 		return new FileNode;
 	}

 	CallNode* bCallNode() {
 		cout << "bCallNode" << endl;
 		return new CallNode;
 	}

 	ExprListNode* bExprListNode() {
 		cout << "bExprListNode" << endl;
 		return new ExprListNode;
 	}
 	
 };
