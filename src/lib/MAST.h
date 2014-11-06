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
#include "AST.h"

 using namespace std;

 class ForNode;
 class WhileNode;
 class IfNode;
 class AssignNode;
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
 class MAST;
 class Visitor;
 class NodeVisitor;

 class Visitor
 {
 public:
 	virtual void visit(ForNode*);
 	virtual void visit(WhileNode*);
 	virtual void visit(IfNode*);
 	virtual void visit(AssignNode*);
 	virtual void visit(StmtListNode*);
 	virtual void visit(SStmtListNode*);
 	virtual void visit(ExprNode*);
 	virtual void visit(PlusNode*);
 	virtual void visit(MinusNode*);
 	virtual void visit(DiviNode*);
 	virtual void visit(MultNode*);
 	virtual void visit(IdentNode*);
 	virtual void visit(IntNode*);
 	virtual void visit(FloatNode*);
 	virtual void visit(StrNode*);
 };


 class ForNode : public INode
 {
 public:
 	ForNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class WhileNode : public INode
 {
 public:
 	WhileNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class IfNode : public INode
 {
 public:
 	IfNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class AssignNode : public INode
 {
 public:
 	AssignNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class StmtListNode : public INode
 {
 public:
 	StmtListNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 }; 

 class SStmtListNode : public INode
 {
 public:
 	SStmtListNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 }; 

 class ExprNode : public INode
 {
 public:
 	ExprNode() : INode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class PlusNode : public BinNode
 {
 public:
 	PlusNode() : BinNode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MinusNode : public BinNode
 {
 public:
 	MinusNode() : BinNode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class DiviNode : public BinNode
 {
 public:
 	DiviNode() : BinNode() {};

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MultNode : public BinNode
 {
 public:
 	MultNode() : BinNode() {};

 	virtual void accept(Visitor& v)
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

 	virtual void accept(Visitor& v)
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

 	virtual void accept(Visitor& v)
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

 	virtual void accept(Visitor& v)
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

 	virtual void accept(Visitor& v)
 	{
 		v.visit(this);
 	}
 };

 class MAST : public AST
 {
 public:
 	MAST() : AST() {};


 	virtual Node* bIntNode(int val)
 	{
 		return new IntNode(val);
 	}

 	virtual Node* bStrNode(string val)
 	{
 		return new StrNode(val);
 	}

 	virtual Node* bFloatNode(float val)
 	{
 		return new FloatNode(val);
 	}

 	virtual Node* bIdentNode(string name)
 	{
 		return new IdentNode(name);
 	}

 	virtual Node* bPlusNode()
 	{
 		return new PlusNode();
 	}

 	virtual Node* bMultNode()
 	{
 		return new MultNode();
 	}

 	virtual Node* bDiviNode()
 	{
 		return new DiviNode();
 	}

 	virtual Node* bMinusNode()
 	{
 		return new MinusNode();
 	}

 	virtual Node* bIfNode()
 	{
 		return new IfNode();
 	}

 	virtual Node* bForNode()
 	{
 		return new ForNode();
 	}

 	virtual Node* bWhileNode()
 	{
 		return new WhileNode();
 	}

 	virtual Node* bStmtListNode()
 	{
 		return new StmtListNode();
 	}

 	virtual Node* bSStmtListNode()
 	{
 		return new SStmtListNode();
 	}

 	virtual Node* bExprNode()
 	{
 		return new ExprNode();
 	}
 };

 class NodeVisitor : public Visitor
 {
 public:

 	virtual void visit(PlusNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(*this);
		right.accept(*this);
 	}

 	virtual void visit(ForNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(WhileNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(IfNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(AssignNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(StmtListNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(SStmtListNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(ExprNode* node)
 	{
 		// pass 
 	}

 	virtual void visit(MinusNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(*this);
		right.accept(*this);
 	}

 	virtual void visit(DiviNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(*this);
		right.accept(*this);
 	}

 	virtual void visit(MultNode* node)
 	{
 		Node left = node->getLeftChild();
		Node right = node->getRightChild();
		left.accept(*this);
		right.accept(*this);
 	}

 	virtual void visit(IdentNode* node)
 	{
 		node->accept(*this);
 	}

 	virtual void visit(IntNode* node)
 	{
 		node->accept(*this);
 	}

 	virtual void visit(FloatNode* node)
 	{
 		node->accept(*this);
 	}

 	virtual void visit(StrNode* node)
 	{
 		node->accept(*this);
 	}
 };


int main(int argc,char* argv[]){
  // Node* nodo = new Node;
  MAST* astTree = new MAST;

  // NodeVisitor vs;
  // nodo->accept(vs);
}
