/*
 * Implementación de clases de nodos para la clase MAST para la construcción del árbol de sintáxis abstracta.
 * Los nodos pueden implementar las clases INode, BinNode o LeafNode dependiendo su uso.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <list>
#include <string>

 using namespace std;

 /* Nodos INode */

 class ForNode : public INode
 {
 public:
 	// ForNode(arguments);
 	// ~ForNode();
 };

 class WhileNode : public INode
 {
 public:
 	// WhileNode(arguments);
 	// ~WhileNode();
 };

 class IfNode : public INode
 {
 public:
	// IfNode(arguments);
	// ~IfNode();
 };

 class AssignNode : public INode
 {
 public:
 	// AssignNode(arguments);
 	// ~AssignNode();
 };

 class StmtListNode : public INode
 {
 public:
 	StmtListNode(arguments);
 	~StmtListNode();
 }; 
 
 class SStmtListNode : public INode
 {
 public:
 	SStmtListNode(arguments);
 	~SStmtListNode();
 }; 

 class ExprNode : public INode
 {
 public:
 	ExprNode(arguments);
 	~ExprNode();
 };
 /* END Nodos INode */

 /* Nodos BinNode */
 class PlusNode : public BinNode
 {
 public:
 	// PlusNode(arguments);
 	// ~PlusNode();
 };

 class MinusNode : public BinNode
 {
 public:
 	// MinusNode(arguments);
 	// ~MinusNode();

 };

 class DiviNode : public BinNode
 {
 public:
 	// DiviNode(arguments);
 	// ~DiviNode();
 };

 class MultNode : public BinNode
 {
 public:
 	// MultNode(arguments);
 	// ~MultNode();
 };

 /*
 class ModulusNode : public BinNode
 {
 public:
 	// ModulusNode(arguments);
 	// ~ModulusNode();
 };
 */
 /* END Nodos BinNode */

 /* Nodos LeafNode */
 class IntNode : public LeafNode
 {
 public:
 	IntNode(int i);
 	int getValue();
 private:
 	int value;
 };

 IntNode::IntNode(int i)
 {
 	value = i;
 }

 int IntNode::getValue()
 {
 	return value;
 }

 class FloatNode : public LeafNode
 {
 public:
 	FloatNode(float f);
 	float getValue();
 private:
 	float value;
 };

 FloatNode::FloatNode(float f)
 {
 	value = f;
 }

 float FloatNode::getValue()
 {
 	return value;
 }

 class StrNode : public LeafNode
 {
 public:
 	StrNode(String str);
 	String getValue();
 private:
 	String value;
 };

 StrNode::StrNode(String str)
 {
 	value = str;
 }

 String StrNode::getValue()
 {
 	return value;
 }
 /* END Nodos LeafNode */