/*
 * Definición de un AST en memoria (MAST) y la interfaz del patrón Visitor con NodeVisitor
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include "AST.hpp"
#include "CompuestoVisitante.hpp"

 using namespace std;

/*
 class ForNode;
 class WhileNode;
 class IfNode;
 class AssignNode;

 class StmtNode;
 class SStmtNode;

 class StmtListNode;
 class SStmtListNode;
 class ExprNode;
 class PlusNode;
 class MinusNode;
 class DiviNode;
 class MultNode;
 class IdentNode;
 class IntNode;
 class FloatNode;
 class StrNode;
 class BoolNode;
 class MAST;
 class Visitor;
 class NodeVisitor;
 */

 class Visitor
 {
 public:
 	virtual void visit(ForNode*);
 	virtual void visit(WhileNode*);
 	virtual void visit(IfNode*);
 	virtual void visit(AssignNode*);

 	virtual void visit(FuncNode*);
 	virtual void visit(ArgsNode*);
 	virtual void visit(StmtNode*);
 	virtual void visit(SStmtNode*);

 	virtual void visit(StmtListNode*);
 	virtual void visit(SStmtListNode*);
 	virtual void visit(ExprNode*);

 	virtual void visit(AndNode*);
 	virtual void visit(OrNode*);
 	virtual void visit(XorNode*);
 	virtual void visit(NotNode*);
 	virtual void visit(PotNode*);

 	virtual void visit(PlusNode*);
 	virtual void visit(MinusNode*);
 	virtual void visit(DiviNode*);
 	virtual void visit(MultNode*);
 	virtual void visit(IdentNode*);
 	virtual void visit(IntNode*);
 	virtual void visit(FloatNode*);
 	virtual void visit(StrNode*);
 	virtual void visit(BoolNode*);
 };

 class AndNode : public BinNode
 {
 public:
 	AndNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class OrNode : public BinNode
 {
 public:
 	OrNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class XorNode : public BinNode
 {
 public:
 	XorNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class NotNode : public BinNode
 {
 public:
 	NotNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class ArgsNode : public INode
 {
 public:
 	ArgsNode() : INode() {};
 	
 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class FuncNode : public INode
 {
 public:
 	FuncNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class ForNode : public INode
 {
 public:
 	ForNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class WhileNode : public INode
 {
 public:
 	WhileNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class IfNode : public INode
 {
 public:
 	IfNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class AssignNode : public INode
 {
 public:
 	AssignNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class StmtNode : public INode
 {
 public:
 	StmtNode() : INode() {};
 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class SStmtNode : public INode
 {
 public:
 	SStmtNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class StmtListNode : public INode
 {
 public:
 	StmtListNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 }; 

 class SStmtListNode : public INode
 {
 public:
 	SStmtListNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 }; 

 class ExprNode : public INode
 {
 public:
 	ExprNode() : INode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class PlusNode : public BinNode
 {
 public:
 	PlusNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MinusNode : public BinNode
 {
 public:
 	MinusNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class DiviNode : public BinNode
 {
 public:
 	DiviNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MultNode : public BinNode
 {
 public:
 	MultNode() : BinNode() {};

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class IdentNode : public LeafNode
 {
 public:
 	IdentNode(string val) : LeafNode()
 	{
 		value.str = &val;
 	}

 	NValue getValue()
 	{
 		return value;
 	}

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class IntNode : public LeafNode
 {
 public:
 	IntNode(int i)
 	{
 		value.i = i;
 	}

 	NValue getValue()
 	{
 		return value;
 	}

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class FloatNode : public LeafNode
 {
 public:
 	FloatNode(float f) : LeafNode()
 	{
 		value.f = f;
 	}

 	NValue getValue()
 	{
 		return value;
 	}

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };


 class StrNode : public LeafNode
 {
 public:

 	StrNode(string str) : LeafNode()
 	{
 		value.str = &str;
 	}

 	NValue getValue()
 	{
 		return value;
 	}

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class BoolNode : public LeafNode
 {
 public:
 	BoolNode(bool boolean) : LeafNode()
 	{
 		value.b = &boolean;
 	}

 	NValue getValue()
 	{
 		return value;
 	}

 	void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MAST : public AST
 {
 public:
 	MAST() : AST() {};

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

 	IntNode* bIntNode(int val)
 	{
 		return new IntNode(val);
 	}

 	StrNode* bStrNode(string val)
 	{
 		return new StrNode(val);
 	}

 	FloatNode* bFloatNode(float val)
 	{
 		return new FloatNode(val);
 	}

 	BoolNode* bBoolNode(bool val)
 	{
 		return new BoolNode(val);
 	}

 	IdentNode* bIdentNode(string name)
 	{
 		return new IdentNode(name);
 	}

 	PlusNode* bPlusNode()
 	{
 		return new PlusNode();
 	}

 	MultNode* bMultNode()
 	{
 		return new MultNode();
 	}

 	DiviNode* bDiviNode()
 	{
 		return new DiviNode();
 	}

 	MinusNode* bMinusNode()
 	{
 		return new MinusNode();
 	}

 	IfNode* bIfNode()
 	{
 		return new IfNode();
 	}

 	ForNode* bForNode()
 	{
 		return new ForNode();
 	}

 	WhileNode* bWhileNode()
 	{
 		return new WhileNode();
 	}

 	StmtNode* bStmtNode()
 	{
 		return new StmtNode();
 	}

 	SStmtNode* bSStmtNode()
 	{
 		return new SStmtNode();
 	}

 	StmtListNode* bStmtListNode()
 	{
 		return new StmtListNode();
 	}

 	SStmtListNode* bSStmtListNode()
 	{
 		return new SStmtListNode();
 	}

 	ExprNode* bExprNode()
 	{
 		return new ExprNode();
 	}

 	AssignNode* bAssignNode()
 	{
 		return new AssignNode();
 	}
 };

 class NodeVisitor : public Visitor
 {
 public:

 	void visit(AndNode* node)
 	{
 		// pass
 	}

 	void visit(OrNode* node)
 	{
 		// pass
 	}

 	void visit(XorNode* node)
 	{
 		// pass
 	}

 	void visit(NotNode* node)
 	{
 		// pass
 	}

 	void visit(PotNode* node)
 	{
 		// pass
 	}


 	void visit(FuncNode* node)
 	{
 		// pass 
 	}

 	void visit(ArgsNode* node)
 	{
 		// pass 
 	}

 	void visit(PlusNode* node)
 	{
 		Node* left = node->getLeftChild();
 		Node* right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 	}

 	void visit(StmtNode*)
 	{
 		// pass
 	}

 	void visit(SStmtNode*)
 	{
 		// pass
 	}

 	void visit(ForNode* node)
 	{
 		// pass 
 	}

 	void visit(WhileNode* node)
 	{
 		// pass 
 	}

 	void visit(IfNode* node)
 	{
 		// pass 
 	}

 	void visit(AssignNode* node)
 	{
 		// pass 
 	}

 	void visit(StmtListNode* node)
 	{
 		// pass 
 	}

 	void visit(SStmtListNode* node)
 	{
 		// pass 
 	}

 	void visit(ExprNode* node)
 	{
 		// pass 
 	}

 	void visit(MinusNode* node)
 	{
 		Node* left = node->getLeftChild();
 		Node* right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 	}

 	void visit(DiviNode* node)
 	{
 		Node* left = node->getLeftChild();
 		Node* right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 	}

 	void visit(MultNode* node)
 	{
 		Node* left = node->getLeftChild();
 		Node* right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 	}

 	void visit(IdentNode* node)
 	{
 		node->accept(*this);
 	}

 	void visit(IntNode* node)
 	{
 		node->accept(*this);
 	}

 	void visit(FloatNode* node)
 	{
 		node->accept(*this);
 	}

 	void visit(StrNode* node)
 	{
 		node->accept(*this);
 	}

 	void visit(BoolNode* node)
 	{
 		node->accept(*this);
 	}
 };

 //int main(int argc,char* argv[]){
  // Node* nodo = new Node;
 	// MAST* astTree = new MAST;
 	// IntNode* nodoInt = astTree->bIntNode(4);
 	// int value = nodoInt->getValue().i;
 	// std::cout << value << std::endl;

 	// StrNode* nodoString = astTree->bStrNode("something");
 	// nodoString->getValue();

  // NodeVisitor vs;
  // nodo->accept(vs);
 // }
