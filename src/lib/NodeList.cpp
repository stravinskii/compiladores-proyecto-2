/*
 * Definición de la clase NodeList para representación interna de los hijos de un nodo.
 * Implementación de las clases VNodeList y LNodeList. Ambas implementando a NodeList.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <list>
#include <string>

 using namespace std;

 class NodeList
 {
 private:
 	union children {
 		std::list<Node> l;
 		std::vector<Node> v;
 	}
 };

 class VNodeList : public NodeList
 {
 public:
 	VNodeList(int n);
 	void setLeftChild(Node node);
 	void setRightChild(Node node);
 private:
 	std::vector<Node> children;
 };

 VNodeList::VNodeList(int n)
 {
 	children.resize(n);
 }

 void VNodeList::setLeftChild(Node node)
 {
 	children.front() = node;
 }
 void VNodeList::setRightChild(Node node)
 {
 	children.back() = node;
 }

 class LNodeList : public NodeList
 {
 public:
 	LNodeList(int n);
 	~LNodeList();
 	void addFirst(Node node);
 	void addLast(Node node);
 private:
 	std::list<Node> children;
 };

 LNodeList::LNodeList(int n)
 {
 	children.resize(n);
 }

 void LNodeList::addFirst(Node node)
 {
 	children.push_front(node);
 }

 void LNodeList::addLast(Node node)
 {
 	children.push_back(node);
 }