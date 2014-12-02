/**
 * Implementación de clases para un AST con los patrones Builder, Composite y Visitor.
 * La implementación de los patrones de diseño se hacen con las clases Node, NodeList y AST.
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include "Nodos.hpp"

using namespace std;

class Node {
public:
	virtual ~Node(){};
	virtual void accept(Visitor&)=0;
	virtual void addFChild(Node*)=0;
	virtual void addLChild(Node*)=0;
	virtual void setFChild(Node*)=0;
	virtual void setSChild(Node*)=0;
protected:
	Node(){};
};


// typedef union NList NList_t;

class NodeList {
public:
	NodeList(){};
	~NodeList(){};
	
	/* BinNode */
	virtual Node* getLeftChild(){};
	virtual Node* getRightChild(){};
	virtual void setLeftChild(Node* node){};
	virtual void setRightChild(Node* node){};

	/* INode */
	virtual void addFirst(Node* node){};
	virtual void addLast(Node* node){};
	virtual list<Node*> getChildren(){};
};


class VNodeList : public NodeList {
private:
	vector<Node*> children;
public:
	~VNodeList(){};
 	VNodeList(int n) {
		children.reserve(n);
 	}

 	void setLeftChild(Node* node){
 		children.insert(children.begin(), node);
 	}

 	void setRightChild(Node* node){
 		children.insert((children.begin())+1, node);
 	}
 	
 	Node* getLeftChild(){
 		return children[0];
 	}

 	Node* getRightChild(){
 		return children[1];
 	}

	list<Node*> getChildren(){
		throw "Operation not supported for VNodeList";
	}
 };

class LNodeList : public NodeList {
private:
	list<Node*> children;
public:
	~LNodeList(){};
	LNodeList() {};

 	void addFirst(Node* node){
		children.push_front(node);
 	}

 	void addLast(Node* node){
 		children.push_back(node);
 	}
 	
 	list<Node*> getChildren(){
		return children;
	}
 };


class INode : public Node {	
protected:
 	NodeList* children;
 		 
public:
	~INode(){};
	INode() {
 		children = new LNodeList();
 	}
 	
 	// INode(int n);

 	void addFChild(Node* child){
 		children->addFirst(child);
 	}

 	void addLChild(Node* child){
 		children->addLast(child);
 	}

 	void setFChild(Node* first)	{
 		throw "Operation not supported for Node";
 	}

 	void setSChild(Node* second){
 		throw "Operation not supported for Node";
 	}

 	list<Node*> getChildren(){
 		// return getChildren();
 		return children->getChildren();
 	}
 };


 class BinNode : public INode {
 public:
	~BinNode(){};
 	BinNode() {
 		children = new VNodeList(2);
 	}

 	void addFChild(Node* first)	{
 		throw "Operation not supported for Node";
 	}

 	void addLChild(Node* second){
 		throw "Operation not supported for Node";
 	}

 	void setFChild(Node* first){
 		children->setLeftChild(first);
 		cout<<"Se agrego hijo izq"<<endl;
 	}

 	void setSChild(Node* second){
 		children->setRightChild(second);
 		cout<<"Se agrego hijo der"<<endl;
 	}

 	Node* getLeftChild(){
 		return children->getLeftChild();
 	}

 	Node* getRightChild(){
 		return children->getRightChild();
 	}
 };


 class LeafNode : public Node{
public:
	~LeafNode(){};
 	union NValue {
 		int i;
 		bool b;
 		float f;
 		string *str;
 	};
 	NValue value;
 	virtual void addFChild(Node*){
 		throw "Operation not supported for Node";
 	}
	virtual void addLChild(Node*){
 		throw "Operation not supported for Node";
 	}
	virtual void setFChild(Node*){
 		throw "Operation not supported for Node";
 	}
	virtual void setSChild(Node*){
 		throw "Operation not supported for Node";
 	}
 	
 	// virtual NValue getValue()=0;
 protected:
	LeafNode(){};
 };

// Constructor
class AST{
protected: 
	AST(){};
 public:
	virtual ~AST(){};

 	// BinNode's
 	virtual PlusNode* bPlusNode()=0;
 	virtual MultNode* bMultNode()=0;
 	virtual DiviNode* bDiviNode()=0;
 	virtual MinusNode* bMinusNode()=0;
 	virtual AssignNode* bAssignNode()=0;
 	virtual AndNode* bAndNode()=0;
 	virtual OrNode* bOrNode()=0;
 	virtual XorNode* bXorNode()=0;
 	virtual NotNode* bNotNode()=0;
 	virtual LTNode* bLTNode()=0;
 	virtual GTNode* bGTNode()=0;
 	virtual EqNode* bEqNode()=0;
 	virtual NEqNode* bNEqNode()=0;
 	virtual LTEqNode* bLTEqNode()=0;
 	virtual GTEqNode* bGTEqNode()=0;
 	virtual PotNode* bPotNode()=0;
 	

 	// INode's
 	virtual StmtNode* bStmtNode()=0;
 	virtual SStmtNode* bSStmtNode()=0;
 	virtual StmtListNode* bStmtListNode()=0;
 	virtual SStmtListNode* bSStmtListNode()=0;
 	virtual ExprNode* bExprNode()=0;
 	virtual IfNode* bIfNode()=0;
 	virtual ForNode* bForNode()=0;
 	virtual WhileNode* bWhileNode()=0;
 	virtual ArgsNode* bArgsNode()=0;
 	virtual FuncNode* bFuncNode()=0;
 	

 	// LeafNode's
 	virtual IntNode* bIntNode(int val)=0;
 	virtual StrNode* bStrNode(string val)=0;
 	virtual FloatNode* bFloatNode(float val)=0;
 	virtual IdentNode* bIdentNode(string name)=0;
 	virtual BoolNode* bBoolNode(bool val)=0;
 };