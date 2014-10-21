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
 
 class Node
 {
 public:
 	Node() {}
 };

 class VNodeList
 {
 private:
 	vector<Node> children;
 public:
 	VNodeList(int n)
 	{
 		children.resize(n);
 	}

 	void setLeftChild(Node node)
 	{
 		children.front() = node;
 	}

 	void setRightChild(Node node)
 	{
 		children.back() = node;
 	}
 	
 	Node getLeftChild()
 	{
 		return children.front();
 	}

 	Node getRightChild()
 	{
 		return children.back();
 	}
 };


 class LNodeList
 {
 private:
 	list<Node> children;
 public:
 	LNodeList() {}

 	void addFirst(Node node)
 	{
 		children.push_front(node);
 	}

 	void addLast(Node node)
 	{
 		children.push_back(node);
 	}
 };

 class NodeList
 {
 private:
 	union NList {
 		LNodeList* listas;
 		VNodeList* vectores;
 	};

 public:
 	NList children;
 	NodeList()
 	{
 		children.listas = new LNodeList();
 	}

 	NodeList(int n)
 	{
 		children.vectores = new VNodeList(n);
 	}
 };


 class INode : public Node
 {	
 public:
 	INode();
 	INode(int n);

 	virtual void addFChild(Node* child);
 	virtual void addLChild(Node* child);

 	virtual void setFChild(Node* first);
 	virtual void setSChild(Node* second);
 private:
 	LNodeList* children;
 };

 INode::INode() : Node()
 {
 	// children = new NodeList();
 	children = new LNodeList();
 }

 void INode::setFChild(Node* first)
 {
 	throw "Operation not supported for Node";
 }

 void INode::setSChild(Node* second)
 {
 	throw "Operation not supported for Node";
 }

 class BinNode : public INode
 {
 public:
 	BinNode() : INode()
 	{
 		nodes = new VNodeList(2);
 	}

 	void addFChild(Node* first)
 	{
 		throw "Operation not supported for Node";
 	}

 	void addLChild(Node* second)
 	{
 		throw "Operation not supported for Node";
 	}

 	void setFChild(Node first)
 	{
 		nodes->setLeftChild(first);
 	}

 	void setSChild(Node second)
 	{
 		nodes->setRightChild(second);
 	}

 	Node getLeftChild()
 	{
 		return nodes->getLeftChild();
 	}

 	Node getRightChild()
 	{
 		return nodes->getRightChild();
 	}

 private:
 	VNodeList* nodes;
 };


 class LeafNode : public Node
 {
 protected:
 	union NValue {
 		int i;
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

 	virtual Node* bStmtListNode()=0;
 	virtual Node* bSStmtListNode()=0;
 	virtual Node* bExprNode()=0;

 	virtual Node* bStrNode()=0;
 	virtual Node* bIntNode()=0;
 	virtual Node* bFloatNode()=0;
 	virtual Node* bIdentNode()=0;

 	virtual Node* bPlusNode()=0;
 	virtual Node* bMultNode()=0;
 	virtual Node* bDiviNode()=0;
 	virtual Node* bMinusNode()=0;

 	virtual Node* bIfNode()=0;
 	virtual Node* bForNode()=0;
 	virtual Node* bWhileNode()=0;
 };