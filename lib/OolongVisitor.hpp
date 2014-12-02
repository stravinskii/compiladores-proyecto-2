/**
 * Visitor para imprimir en lenguaje Oolong
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <list>
#include "AST.hpp"
#include "Nodos.hpp"
#include "MAST.hpp"
#include <string>
#include <fstream>

using namespace std;

class OolongVisitor : public Visitor{
public:
	ofstream output;
	~OolongVisitor(){};
	OolongVisitor() {
		output.open("oolong.j");
	}
 
 	void visit(Node* node){
	 	output << "(Node ";
	 	visit(node);
	 	output << ")";
 	}
	
 	void visit(ForNode* node){
		output << "(ForNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		output << ")";
 	}

 	void visit(WhileNode* node){
		output << "(WhileNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		} 
		output << ")";
 	}

 	void visit(IfNode* node){
		output << "(IfNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		
		output << ")";
 	}

 	void visit(AssignNode* node){
		output << "(AssignNode ";
		// output << "visite un assignode" << endl;
		IdentNode* c = dynamic_cast<IdentNode*> (node->getLeftChild());
		if(c != 0){
			Node *left = node->getLeftChild();
			Node *right = node->getRightChild();
			Visitor *v=this;
			left->accept(*v);
			right->accept(*v);
		}else{
			throw "Assignment operation is only for variables";
			output<<"Assignment operation is only for variables"<<endl;
		}
			
		output << ")";
 	}

 	void visit(StmtListNode* node){
		output << "(StmtListNode ";
		Visitor *v=this;
		node->accept(*v);
		output << ")";
 	}

 	void visit(SStmtListNode* node){
		output << "(SStmtListNode ";
		Visitor *v=this;
		node->accept(*v);
		output << ")";
 	}
 	
 	void visit(FuncNode* node){
		output << "(FuncNode ";
		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);	
		}	
		output << ")";
	}

 	void visit(ArgsNode* node){
 		output << "(ArgsNode ";
 		for (list<Node*>::iterator it= node->getChildren().begin(); it != node->getChildren().end(); ++it){
			Visitor* v = this;
			(*it)->accept(*v);
		}
		output << ")";
 	}

 	void visit(ExprNode* node){
		output << "(ExprNode ";
		Visitor *v=this;
		node->accept(*v);
		output << ")";
 	}
 	
 	void visit(StmtNode* node){
		output << "(StmtNode ";
		Visitor *v=this;
		output << ")";
		node->accept(*v);
	}
 	void visit(SStmtNode* node){
		output << "(SStmtNode ";
		Visitor *v=this;
		node->accept(*v);
		output << ")";
	}
 	
 	void visit(AndNode* node){
 		output << "(AndNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(OrNode* node){
 		output << "(OrNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(XorNode* node){
 		output << "(XorNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(NotNode* node){
 		output << "(NotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(PotNode* node){
 		output << "(PotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(LTNode* node){
 		output << "(LTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(GTNode* node){
 		output << "(GTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(EqNode* node){
 		output << "(EqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(NEqNode* node){
 		output << "(NEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(LTEqNode* node){
 		output << "(LTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(GTEqNode* node){
 		output << "(GTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}
 	
 	void visit(PlusNode* node){
 		output << "(PlusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(MinusNode* node){
 		output << "(MinusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(DiviNode* node){
 		output << "(DiviNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	void visit(MultNode* node){
 		output << "(MultNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		Visitor *v=this;
 		left->accept(*v);
 		right->accept(*v);
 		output << ")";
 	}

 	/**
 	 * OJO:
 	 * Los nodos hojas no tiene porque llamarse a sí mismos el accept, se ciclaría,
 	 * además de que teoricamente ya esos nodos ya los llamó el visit de un nodo que los tiene como hijos.
 	 */

 	void visit(IdentNode* node){
		output << "(IdentNode "<<node->getValue();
		string name = node->getValue();
		output << ")";
 	}

 	void visit(IntNode* node){
		output << "(IntNode "<<node->getValue();
		output << ")";
 	}

 	void visit(FloatNode* node){
 		output << "(FloatNode "<<node->getValue();
		output << ")";
 	}

 	void visit(StrNode* node){
 		output << "(StrNode "<<node->getValue();
		output << ")";
 	}

 	void visit(BoolNode* node){
		output << "(BoolNode "<<node->getValue();
		output << ")";
 	}
 };
