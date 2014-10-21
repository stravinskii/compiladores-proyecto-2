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

 class ForNode : public INode
 {
 public:
 	ForNode() : INode() {};
 };

 class WhileNode : public INode
 {
 public:
 	WhileNode() : INode() {};
 };

 class IfNode : public INode
 {
 public:
 	IfNode() : INode() {};
 };

 class AssignNode : public INode
 {
 public:
 	AssignNode() : INode() {};
 };

 class StmtListNode : public INode
 {
 public:
 	StmtListNode() : INode() {};
 }; 

 class SStmtListNode : public INode
 {
 public:
 	SStmtListNode() : INode() {};
 }; 

 class ExprNode : public INode
 {
 public:
 	ExprNode() : INode() {};
 };

 class PlusNode : public BinNode
 {
 public:
 	PlusNode() : BinNode() {};
 };

 class MinusNode : public BinNode
 {
 public:
 	MinusNode() : BinNode() {};
 };

 class DiviNode : public BinNode
 {
 public:
 	DiviNode() : BinNode() {};
 };

 class MultNode : public BinNode
 {
 public:
 	MultNode() : BinNode() {};
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
 };

 class MAST : public AST
 {
 public:
 	MAST() : AST() {};


 	Node* bIntNode(int val)
 	{
 		return new IntNode(val);
 	}

 	Node* bStrNode(string val)
 	{
 		return new StrNode(val);
 	}

 	Node* bFloatNode(float val)
 	{
 		return new FloatNode(val);
 	}

 	Node* bIdentNode(string name)
 	{
 		return new IdentNode(name);
 	}

 	Node* bPlusNode()
 	{
 		return new PlusNode();
 	}

 	Node* bMultNode()
 	{
 		return new MultNode();
 	}

 	Node* bDiviNode()
 	{
 		return new DiviNode();
 	}

 	Node* bMinusNode()
 	{
 		return new MinusNode();
 	}

 	Node* bIfNode()
 	{
 		return new IfNode();
 	}

 	Node* bForNode()
 	{
 		return new ForNode();
 	}

 	Node* bWhileNode()
 	{
 		return new WhileNode();
 	}
 };

 class NodeVisitor
 {
 public:
 	virtual void visit(IntNode node);
 	virtual void visit(PlusNode node);
 	virtual void visit(MinusNode node);
 	virtual void visit(ExprNode node);
 	virtual void visit(SStmtListNode node);
 	virtual void visit(StmtListNode node);
 };