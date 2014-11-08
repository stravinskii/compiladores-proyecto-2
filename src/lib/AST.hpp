/*
 * Implementación de clases para un AST con los patrones Builder, Composite y Visitor.
 * La implementación de los patrones de diseño se hacen con las clases Node, NodeList y AST.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>

 using namespace std;

 class Visitor;
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
 class StmtNode;
 class SStmtNode;

 class Node
 {
 public:
 	Node() {}
 	virtual void accept(Visitor& v);

 	virtual void addFChild(Node* child);
	virtual void addLChild(Node* child);
	virtual void setFChild(Node* first);
	virtual void setSChild(Node* second);
 };


 class NodeList
 {
 private:
 	union NList {
 		list<Node*> *listas;
 		vector<Node*> *vectores;
 	};

 public:
 	NList children;

 	virtual Node* getLeftChild();
 	virtual Node* getRightChild();
 	virtual void setLeftChild(Node* node);
 	virtual void setRightChild(Node* node);

 	virtual void addFirst(Node* node);
 	virtual void addLast(Node* node);
 };


 class VNodeList : public NodeList
 {
 private:
 	vector<Node*> children;
 public:
 	VNodeList(int n)
 	{
 		children.resize(n);
 	}

 	void setLeftChild(Node* node)
 	{
 		children.front() = node;
 	}

 	void setRightChild(Node* node)
 	{
 		children.back() = node;
 	}
 	
 	Node* getLeftChild()
 	{
 		return children.front();
 	}

 	Node* getRightChild()
 	{
 		return children.back();
 	}
 };

 class LNodeList : public NodeList
 {
 private:
 	list<Node*> children;
 public:
 	LNodeList() {}

 	void addFirst(Node* node)
 	{
 		children.push_front(node);
 	}

 	void addLast(Node* node)
 	{
 		children.push_back(node);
 	}
 };


 class INode : public Node
 {	
 public:
 	
 	INode() : Node()
 	{
 		children = new LNodeList();
 	}

 	INode(int n);

 	void addFChild(Node* child)
 	{
 		children->addFirst(child);
 	}

 	void addLChild(Node* child)
 	{
 		children->addLast(child);
 	}

 	void setFChild(Node* first)
 	{
 		throw "Operation not supported for Node";
 	}

 	void setSChild(Node* second)
 	{
 		throw "Operation not supported for Node";
 	}

 protected:
 	NodeList* children;
 };


 class BinNode : public INode
 {
 public:
 	BinNode()
 	{
 		children = new VNodeList(2);
 	}

 	void addFChild(Node* first)
 	{
 		throw "Operation not supported for Node";
 	}

 	void addLChild(Node* second)
 	{
 		throw "Operation not supported for Node";
 	}

 	void setFChild(Node* first)
 	{
 		children->setLeftChild(first);
 	}

 	void setSChild(Node* second)
 	{
 		children->setRightChild(second);
 	}

 	Node* getLeftChild()
 	{
 		return children->getLeftChild();
 	}

 	Node* getRightChild()
 	{
 		return children->getRightChild();
 	}
 };


 class LeafNode : public Node
 {
 protected:
 	union NValue {
 		int i;
 		bool b;
 		float f;
 		string* str;
 	};
 	NValue value;
 public:
 	LeafNode() : Node() {};
 	virtual NValue getValue()=0;
 };

 // Constructor
 class AST
 {
 public:

 	// BinNode's
 	virtual PlusNode* bPlusNode()=0;
 	virtual MultNode* bMultNode()=0;
 	virtual DiviNode* bDiviNode()=0;
 	virtual MinusNode* bMinusNode()=0;
 	virtual AssignNode* bAssignNode()=0;

 	// INode's

 	virtual StmtNode* bStmtNode()=0;
 	virtual SStmtNode* bSStmtNode()=0;
 	
 	virtual StmtListNode* bStmtListNode()=0;
 	virtual SStmtListNode* bSStmtListNode()=0;
 	virtual ExprNode* bExprNode()=0;

 	virtual IfNode* bIfNode()=0;
 	virtual ForNode* bForNode()=0;
 	virtual WhileNode* bWhileNode()=0;

 	// LeafNode's
 	virtual IntNode* bIntNode(int val)=0;
 	virtual StrNode* bStrNode(string val)=0;
 	virtual FloatNode* bFloatNode(float val)=0;
 	virtual IdentNode* bIdentNode(string name)=0;
 	virtual BoolNode* bBoolNode(bool val)=0;
 };