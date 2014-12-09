/**
 * Definición de Visitante concreto para imprimir el árbol
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

class PrintVisitor : public Visitor {
public:
	~PrintVisitor(){};
	PrintVisitor() : Visitor(){};
 
 	void visit(Node* node){
	 	cout << "(Node ";
	 	visit(node);
	 	cout << ")";
 	}
	
 	void visit(ForNode* node){
		cout << "(ForNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(WhileNode* node){
		cout << "(WhileNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(IfNode* node){
		cout << "(IfNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(AssignNode* node){
		cout << "(AssignNode ";
		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
		cout << ")";
 	}

 	void visit(StmtListNode* node){
		cout << "(StmtListNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(SStmtListNode* node){
		cout << "(SStmtListNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
 	
 	void visit(FuncNode* node){
		cout << "(FuncNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}

 	void visit(ArgsNode* node){
 		cout << "(ArgsNode ";
 		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}

 	void visit(ExprNode* node){
		cout << "(ExprNode ";			
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
 	
 	void visit(StmtNode* node){
		cout << "(StmtNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}
 	void visit(SStmtNode* node){
		cout << "(SStmtNode ";
		
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}
 	
 	void visit(AndNode* node){
 		cout << "(AndNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(OrNode* node){
 		cout << "(OrNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(XorNode* node){
 		cout << "(XorNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(NotNode* node){
 		cout << "(NotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(PotNode* node){
 		cout << "(PotNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(LTNode* node){
 		cout << "(LTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(GTNode* node){
 		cout << "(GTNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(EqNode* node){
 		cout << "(EqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(NEqNode* node){
 		cout << "(NEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(LTEqNode* node){
 		cout << "(LTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}

 	void visit(GTEqNode* node){
 		cout << "(GTEqNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		left->accept(*this);
 		right->accept(*this);
 		cout << ")";
 	}
 	
 	void visit(PlusNode* node){
 		cout << "(PlusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		
 		if (left != NULL)
 		{
 			left->accept(*this);
 		}
 		if (right != NULL)
 		{
 			right->accept(*this);
 		}
 		cout << ")";
 	}

 	void visit(MinusNode* node){
 		cout << "(MinusNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
		left->accept(*this);
		right->accept(*this);
 		cout << ")";
 	}

 	void visit(DiviNode* node){
 		cout << "(DiviNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
		right->accept(*this);
 		cout << ")";
 	}

 	void visit(MultNode* node){
 		cout << "(MultNode ";
 		Node *left = node->getLeftChild();
 		Node *right = node->getRightChild();
 		left->accept(*this);
		right->accept(*this);
 		cout << ")";
 	}

 	void visit(IdentNode* node){
		cout << "(IdentNode " << node->getValue() << ")";
 	}

 	void visit(IntNode* node){
		cout << "(IntNode " << node->getValue() << ")";
 	}

 	void visit(FloatNode* node){
 		cout << "(FloatNode " << node->getValue() << ")";
 	}

 	void visit(StrNode* node){
 		cout << "(StrNode " << node->getValue() << ")";
 	}

 	void visit(BoolNode* node){
		cout << "(BoolNode " << node->getValue() << ")";
 	}

 	void visit(ReturnNode* node){
 		cout << "(ReturnNode ";
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
 	}
	void visit(PrintNode* node){
		cout << "(PrintNode ";
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}
	void visit(BreakNode* node){
		cout << "(BreakNode)";
	}
	void visit(ContinueNode* node){
		cout << "(ContinueNode)";
	}
	
	void visit(FileNode* node) {
		cout << "(FileNode ";
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}

	void visit(CallNode* node) {
		cout << "(CallNode ";
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";
	}

	void visit(ExprListNode* node) {
		cout << "(ExprListNode ";
		for (auto& it: node->getChildren()){
			(*it).accept(*this);
		}
		cout << ")";	
	}
	
 };
