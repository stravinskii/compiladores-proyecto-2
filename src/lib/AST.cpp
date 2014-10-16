/*
 * Implementación de clases para un AST con los patrones Builder, Composite y Visitor.
 * La implementación de los patrones de diseño se hacen con AST.cpp, NodeList.cpp y ASTNodes.cpp
 *
 * Definición de AST y NodeVisitor, así como la implementación de MAST (AST en memoria) y PrintVisitor.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <list>
#include <string>
#include "NodeList.cpp"
#include "ASTNodes.cpp"

 using namespace std;

 // Constructor
 class AST
 {
 public:

 	virtual Node* bStmtListNode()=0;
 	virtual Node* bSStmtListNode()=0;
 	virtual Node* bExprNode()=0;

 	// virtual Node* bFuncNode()=0;

 	virtual Node* bStrNode()=0;
 	virtual Node* bIntNode()=0;
 	virtual Node* bFloatNode()=0;

 	virtual Node* bPlusNode()=0;
 	virtual Node* bMultNode()=0;
 	virtual Node* bDiviNode()=0;
 	virtual Node* bMinusNode()=0;

 	virtual Node* bIfNode()=0;
 	virtual Node* bForNode()=0;
 	virtual Node* bWhileNode()=0;
 };

 // Constructor Concreto
 class MAST : public AST
 {
 public:
 	// MAST(arguments);
 	~MAST();

 	Node* bStrNode();
 	Node* bIntNode();
 	Node* bFloatNode();

 	Node* bPlusNode();
 	Node* bMultNode();
 	Node* bDiviNode();
 	Node* bMinusNode();

 	Node* bIfNode();
 	Node* bForNode();
 	Node* bWhileNode();
 };

 Node* MAST::bStrNode()
 {
 	return new StrNode();
 }
 Node* MAST::bIntNode()
 {
 	return new IntNode();
 }
 Node* MAST::bFloatNode()
 {
 	return new FloatNode();
 }

 Node* MAST::bPlusNode()
 {
 	return new PlusNode();
 }

 Node* MAST::bMultNode()
 {
 	return new MultNode();
 }

 Node* MAST::bDiviNode()
 {
 	return new DiviNode();
 }

 Node* MAST::bMinusNode()
 {
 	return new MinusNode();
 }

 Node* MAST::bIfNode()
 {
 	return new IfNode();
 }

 Node* MAST::bForNode()
 {
 	return new ForNode();
 }

 Node* MAST::bWhileNode()
 {
 	return new WhileNode();
 }

 class Node
 {
 public:
 	// Node(arguments);
 	// ~Node();
 };

 class INode : public Node
 {	
 public:
 	INode(int n);
 	// ~INode();

 	virtual void addFChild(Node child)=0;
 	virtual void addLChild(Node child)=0;

 	virtual void setFChild(Node first)=0;
 	virtual void setSChild(Node second)=0;
 private:
 	NodeList children;
 };

 INode::INode()
 {
 	children = new LNodeList();
 }

 INode::INode(int n)
 {
 	children = new VNodeList(n);
 }

 void INode::setFChild(Node first)
 {
 	throw "Operation not supported for Node";
 }

 void INode::setSChild(Node second)
 {
 	throw "Operation not supported for Node";
 }

 class BinNode : public INode
 {
 public:
 	// BinNode(arguments);
 	// ~BinNode();

 	void addFChild(Node child);
 	void addLChild(Node child);

 	void setFChild(Node first);
 	void setSChild(Node second);
 private:
 	NodeList children;
 };

 BinNode::BinNode()
 {
 	children = new VNodeList(2);
 }

 void BinNode::addFChild(Node first)
 {
 	throw "Operation not supported for Node";
 }

 void BinNode::addLChild(Node second)
 {
 	throw "Operation not supported for Node";
 }

 void BinNode::setFChild(Node first)
 {
 	children
 }

 void BinNode::setSChild(Node second)
 {
 	children
 }

 class LeafNode : public Node
 {
 public:
 	// LeafNode(arguments);
 	// ~LeafNode();
 	virtual values getValue()=0;
 private:
 	union values {
 		int i;
 		float f;
 		String str;
 	};
 	values value;
 };

 /* Visitor */
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

 class PrintVisitor : public NodeVisitor
 {
 public:
 	void visit(IntNode node);
 	void visit(PlusNode node);
 	void visit(MinusNode node);
 	void visit(ExprNode node);
 	void visit(SStmtListNode node);
 	void visit(StmtListNode node);
 };

 void visit(IntNode node)
 {
 	cout << node.getValue();
 }
 void visit(PlusNode node)
 {
 	cout << "(+ " << node.leftChild() << "	" << node.rightChild() << ")";
 }
 void visit(MinusNode node)
 {
 	cout << "(- " << node.leftChild() << "	" << node.rightChild() << ")";
 }
 void visit(ExprNode node)
 {
 	cout << "(ExprNode " << ")";
 }
 void visit(SStmtListNode node)
 {
 	cout << "(SStmtListNode " << ")";
 }
 void visit(StmtListNode node)
 {
 	cout << "(StmtListNode " << ")";
 }

 /* END Visitor 