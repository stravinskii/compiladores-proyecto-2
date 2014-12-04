#include "../lib/MAST.hpp"

using namespace std;
int main(){
	MAST *asTree;
	asTree= new MAST;
	
	VisitorNode *visitor;
	visitor = new VisitorNode;
	string s ="VARNAME";
	string x ="VARNAME_X";
	string y ="VARNAME_Y";

	Node* id1 = asTree->bIdentNode(s);
	Node* id2 = asTree->bIdentNode(x);
	Node* id3 = asTree->bStrNode(y);

	Node* m1 = asTree->bMultNode();
	Node* i1 = asTree->bIntNode(1);
	Node* i2 = asTree->bIntNode(3);
	Node* i3 = asTree->bIntNode(5);
	
	m1->setFChild(i2);
	m1->setSChild(i3);

	Node* a = asTree->bAssignNode();	
	a->setFChild(id1);
	a->setSChild(id3);

	Node* b = asTree->bAssignNode();
	Node* exprn = asTree->bExprNode();
	b->setFChild(id1);
	b->setSChild(exprn);
	
	a->accept(*visitor);
	std::cout<<std::endl;

	Node* fn = asTree->bForNode();
	fn->addFChild(id2);
	fn->addLChild(m1);
	return 0;
}
