%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../lib/MAST.hpp"
#include "../lib/SymbolTable.hpp"
#include <string>

using namespace std;
#define YYDEBUG 1
int yylex(); 
int yyerror(const char *s) { printf ("\nError: %s\n", s); }

extern "C" FILE *yyin;


SymbolTable *st= new SymbolTable;
MAST *asTree= new MAST;


%}

%code requires{
#include "../lib/CompuestoVisitante.hpp"

}

/*Aquí van las uniones*/
%union {
	int entero;
	double flotante;
	char caracter;
	char* cadena;
	Node* nodo;
}

/*Aquí van los tokens*/
%token <flotante> FLOATNUMBER
%token <entero> INTEGER
%token <cadena> STRING
%token <cadena> NAME
%token DEDENT INDENT NEWLINE 
%token MAS MENOS POR ENTRE MOD DIV POT FALSE CLASS FINALLY IS RETURN NONE CONTINUE FOR LAMBDA TRY TRUE DEF FROM WHILE AND DEL NOT WITH AS ELIF IF OR ELSE IMPORT PASS BREAK EXCEPT IN PRINT COMMA DOT ASSIGN TWODOTS DOTCOMMA BINLEFT  BINRIGHT ANDPAND PIPE EXP TILDE LESSTHAN MORETHAN LESSEQUAL MOREEQUAL EQUALS DIFFERENT PICOPARENTESIS OPENPAR CLOSEPAR OPENCOR CLOSECOR OPENKEY CLOSEKEY AT RIGHT MASIGUAL MENOSIGUAL PORIGUAL ENTREIGUAL DIVIGUAL MODIGUAL ANDIGUAL ORIGUAL EXPIGUAL BINRIGHTIGUAL BINLEFTIGUAL POTIGUAL GLOBAL APOSTROFE

/*Aquí van los tipos*/
/*
%type <nodo> file_input filein epsilon test old_test or_test or_andtest and_test and_nottest not_test comparison comp_op_expr_kleene comp_op expr pipexor_expr xor_expr andxor_expr and_expr andpandshift_expr shift_expr leftright_shift_expr arithmetic_expr sign_term term factor_operation factor power trailer_kleene trailer arglist argument_comma argument_multiple comma_argument argument comp_for comp_iter comp_if subscriptlist comma_subscript subscript sliceop exprlist expr_kleene atom boolean dictorsetmaker dictor_set_help dictor_set_help2 testlist1 string_plus listmaker testlist_comp list_for list_iter testlist_safe comma_old_test_plus list_if compound_stmt if_stmt elif_test_td_suite_kleene while_stmt for_stmt suite stmt_plus stmt simple_stmt small_stmt more_simple_stmt expr_stmt expr_stmt_at assign_testlist_kleene augassign print_stmt print_stmt1 comma_test_kleene print_stmt2 comma_one comma_test_plus testlist del_stmt pass_stmt flow_stmt break_stmt continue_stmt return_stmt funcdef parameters varargslist a b d fpdef fplist fpdef_kleene
*/
%type <nodo> file_input filein epsilon test old_test or_test or_andtest and_test and_nottest not_test comparison comp_op_expr_kleene comp_op expr pipexor_expr xor_expr andxor_expr and_expr andpandshift_expr shift_expr leftright_shift_expr arithmetic_expr sign_term term factor_operation factor power trailer_kleene trailer arglist argument_comma argument_multiple comma_argument argument comp_for comp_iter comp_if subscriptlist comma_subscript subscript sliceop exprlist expr_kleene atom boolean dictorsetmaker dictor_set_help dictor_set_help2 testlist1 string_plus listmaker testlist_comp list_for list_iter testlist_safe comma_old_test_plus list_if compound_stmt if_stmt elif_test_td_suite_kleene while_stmt for_stmt suite stmt_plus stmt simple_stmt small_stmt more_simple_stmt expr_stmt expr_stmt_at assign_testlist_kleene augassign print_stmt print_stmt1 comma_test_kleene print_stmt2 comma_one comma_test_plus testlist del_stmt pass_stmt flow_stmt break_stmt continue_stmt return_stmt funcdef parameters varargslist d fpdef fplist fpdef_kleene

%%
file_input: /* (NEWLINE | stmt)* ENDMARKER*/
	filein	{
				Node *sstmtln = asTree->bSStmtListNode();
				sstmtln->addFChild($1);
				$$ = sstmtln;
				cout<<"\nCOMPILATION COMPLETE :)\n";
			};
	
filein:epsilon
	|filein NEWLINE		{
							Node *stmtln = asTree->bStmtListNode();
							stmtln->addFChild($1);
							$$ = stmtln;
							cout<<"\n";
						}
	|filein stmt 		{
							Node *stmtn = asTree->bExprNode();
							stmtn->addFChild($1);

							Node *stmtln = asTree->bStmtListNode();
							stmtln->addFChild($1);
							$$ = stmtln;
						};
	
/*Aquí va la gramática*/
/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

test:/*or_test ['if' or_test 'else' test] */
	or_test							{$$ = $1;}
	|or_test IF or_test ELSE test	{cout<<"IF __ ELSE __ ";};	
	
old_test: or_test 	{$$ = $1;};

or_test: 	/*and_test (OR and_test)*		{};*/
		and_test or_andtest			{
										Node *orn = $2;
										orn->setFChild($1);
										$$ = orn;
									};
		
or_andtest:	epsilon 				{
										Node *orn = asTree->bOrNode();
										$$ = orn;
									}
		|or_andtest OR and_test		{
										Node *orn = $1;
										orn->setSChild($3);
										$$ = orn;
										cout<<"OR";
									};
		
and_test: 	/*not_test (AND not_test)*		{};*/
		not_test and_nottest			{$$ = $2;};
		
and_nottest:	epsilon 				{
											Node *andn = asTree->bAndNode();
											$$ = andn;
										}
		|and_nottest AND not_test		{
											Node *andn = $1;
											andn->setSChild($3);
											$$ = andn;
											cout<<"AND";
										};
		
not_test: 	/*'not' not_test | comparison*/
	NOT not_test			{
								Node *notn = asTree->bNotNode();
								notn->setFChild($2);
								$$ = notn;
								cout<<"NOT";
							}
	|comparison				{$$ = $1;};

		
comparison: /*expr (comp_op expr)*			{};*/
	expr comp_op_expr_kleene 	{
									Node *compn = $2;
									compn->setFChild($1);
									$$ = compn;
								};

comp_op_expr_kleene: 
	comp_op_expr_kleene comp_op expr 	{
											Node *compn = $2;
											compn->setSChild($3);
											$$ = compn;
										}
	| epsilon;
	
comp_op: /*'<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'*/
	LESSTHAN			{
							Node *compn = asTree->bLTNode();
							$$ = compn;
							cout<<"<";
						}
	|MORETHAN			{
							Node *compn = asTree->bGTNode();
							$$ = compn;
							cout<<">";
						}
	|EQUALS				{
							Node *compn = asTree->bEqNode();
							$$ = compn;
							cout<<"==";
						}
	|MOREEQUAL			{
							Node *compn = asTree->bGTEqNode();
							$$ = compn;
							cout<<">=";
						}
	|LESSEQUAL			{
							Node *compn = asTree->bLTEqNode();
							$$ = compn;
							cout<<"<=";
						}
	|DIFFERENT			{
							Node *compn = asTree->bNEqNode();
							$$ = compn;
							cout<<"!=";
						}
	|PICOPARENTESIS		{cout<<"<>";}
	|IN					{cout<<"IN";}
	|NOT IN				{cout<<"NOT IN";}
	|IS					{cout<<"IS";}
	|IS NOT				{cout<<"IS NOT";};


expr: /*xor_expr ('|' xor_expr)*				{};*/
	xor_expr pipexor_expr 		{
									Node *orn = $2;
									orn->setFChild($1);
									$$ = orn;
								};
	
pipexor_expr: 	epsilon 			{
										Node *orn = asTree->bOrNode();
										$$ = orn;
									}
	|pipexor_expr PIPE xor_expr 	{
										Node *orn = $1;
										orn->setSChild($3);
										$$ = orn;
									};
		
xor_expr: /*and_expr ('^' and_expr)*			{};*/
	and_expr andxor_expr 	{
								Node *andn = $2;
								andn->setFChild($1);
								$$ = andn;
							};

andxor_expr: 	epsilon 		{
									Node *andn = asTree->bAndNode();
									$$ = andn;
								}
	|andxor_expr EXP and_expr 	{
									Node *andn = $1;
									andn->setSChild($3);
									$$ = andn;
								};
		
and_expr: /*shift_expr ('&' shift_expr)*			{};*/
	shift_expr andpandshift_expr			{
												Node *andn = $2;
												andn->setFChild($1);
												$$ = andn;
											};

andpandshift_expr: epsilon 					{
												Node *andn = asTree->bAndNode();
												$$ = andn;
											}
	|andpandshift_expr ANDPAND shift_expr 	{
												Node *andn = $1;
												andn->setSChild($3);
												$$ = andn;
											};

shift_expr: /*arith_expr (('<<'|'>>') arith_expr)*	{};*/
	arithmetic_expr leftright_shift_expr			{$$ = $1;};

leftright_shift_expr: epsilon
	|leftright_shift_expr BINRIGHT arithmetic_expr 	{$$ = $3; cout<<">>";}
	|leftright_shift_expr BINLEFT arithmetic_expr	{$$ = $3; cout<<"<<";};

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term					{
										// Node *exprn = asTree->bExprNode();
										Node *termn = $2;
										termn->setFChild($1);
										$$ = termn;
									};

sign_term:epsilon					{}
	|sign_term MAS term			{
									Node *plusn = asTree->bPlusNode();
									plusn->setFChild($1);
									plusn->setSChild($3);
									$$ = plusn;
									cout<<"Suma";
								}

	|sign_term MENOS term		{
									Node *minusn = asTree->bMinusNode();
									minusn->setFChild($1);
									minusn->setSChild($3);
									$$ = minusn;
									cout<<"Resta";
								};

term: /*factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;*/
	factor factor_operation		{
									Node *exprn = asTree->bExprNode();
									exprn->addFChild($2);
								};
	
factor_operation: epsilon				{}
	|factor_operation POR factor 			{
												Node *multn = asTree->bMultNode();
												multn->setFChild($1);
												multn->setSChild($3);
												$$ = multn;
												cout<<"Multiplicacion";
											}
	|factor_operation ENTRE factor 			{
												Node *divn = asTree->bDiviNode();
												divn->setFChild($1);
												divn->setSChild($3);
												$$ = divn;
												cout<<"Division";
											}
	|factor_operation MOD factor 			{
												cout<<"Modulo";
											}
	|factor_operation DIV factor 			{
												Node *divn = asTree->bDiviNode();
												divn->setFChild($1);
												divn->setSChild($3);
												$$ = divn;
												cout<<"Division Entera";
											};

factor: /*'+' factor;
	| '-' factor;
	| '~' factor;
	| power;*/
	MAS factor			{
							Node *plusn = asTree->bPlusNode();
							plusn->setSChild($2);
							$$ = plusn;
							cout<<"SUMA";
						}
	|MENOS factor		{
							Node *minusn = asTree->bMinusNode();
							minusn->setSChild($2);
							$$ = minusn;
							cout<<"RESTA";
						}
	|TILDE factor 		{$$ = $2;}
	|power 				{$$ = $1;};

power: /*atom trailer* ['**' factor];*/
	atom trailer_kleene					{$$ = $1;}
	|atom trailer_kleene POT factor		{$$ = $1;};

trailer_kleene: epsilon					{}
	|trailer_kleene trailer 			{};
	
trailer: /*'(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME*/
	OPENPAR CLOSEPAR					{cout<<"()";}
	|OPENPAR arglist CLOSEPAR			{$$ = $2; cout<<"(ARGLIST)";}
	|OPENCOR subscriptlist CLOSECOR		{$$ = $2; cout<<"(SUBSCRIPTLIST)";}
	|DOT NAME							{Node *identn = asTree->bIdentNode($2); $$=identn; cout<<".NAME";};
		
arglist: /*(argument ',')* (argument [','] |'*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument_comma argument_multiple 	{$$ = $2;};
	
argument_comma: epsilon
	|argument_comma argument COMMA 		{$$ = $2; cout<<",";};
	
argument_multiple: argument 					{$$ = $1;}
	|argument COMMA								{$$ = $1; cout<<",";}
	|POR test comma_argument					{$$ = $2; cout<<"*";}
	|POR test comma_argument COMMA POT test		{$$ = $2; cout<<"*";}
	|POT test									{$$ = $2; cout<<"**";};		
	
comma_argument: epsilon
	|comma_argument COMMA argument 	{$$ = $3;};
	
argument: /*test [comp_for] | test '=' test*/
	test comp_for 			{$$ = $1;}
	|test 					{$$ = $1;}
	|test ASSIGN test 		{
								Node *assignn = asTree->bAssignNode();
								assignn->setFChild($1);
								assignn->setFChild($3);
								$$ = assignn;
							};
	
comp_for: /*'for' exprlist 'in' or_test [comp_iter]*/
	FOR exprlist IN or_test comp_iter	{
											Node *forn = asTree->bForNode();
											forn->addFChild($2);
											forn->addFChild($4);
											cout<<"FOR";
										}
	| FOR exprlist IN or_test			{
											Node *forn = asTree->bForNode();
											forn->addFChild($2);
											forn->addFChild($4);
											cout<<"FOR";
										};
	
comp_iter: /*comp_for | comp_if */
	comp_for 	{$$ = $1;}
	| comp_if 	{$$ = $1;};
	
comp_if: /*'if' old_test [comp_iter] */
	IF old_test					{
									Node *ifn = asTree->bIfNode();
									ifn->addFChild($2);
									cout<<"IF";
								}
	|IF old_test comp_iter 		{
									Node *ifn = asTree->bIfNode();
									ifn->addFChild($2);
									cout<<"IF";
								};
		
subscriptlist: /*subscript (',' subscript)* [',']*/
	subscript comma_subscript 			{$$ = $1;}
	|subscript comma_subscript COMMA 	{$$ = $1;};

comma_subscript: comma_subscript COMMA subscript 	{$$ = $3;}
	|epsilon;
	
subscript: /*'.' '.' '.' | test | [test] ':' [test] [sliceop] */
	DOT DOT DOT
	| test 							{$$ = $1;}
	| test TWODOTS test sliceop		{$$ = $1;}
	| test TWODOTS test				{$$ = $1;}
	| test TWODOTS					{$$ = $1;}
	| test TWODOTS sliceop			{$$ = $1;}
	| TWODOTS test sliceop			{$$ = $2;}
	| TWODOTS test					{$$ = $2;}
	| TWODOTS sliceop				{$$ = $2;}
	| TWODOTS						{cout<<":";};

sliceop: /*':' [test];*/
	TWODOTS test				{cout<<":";}
	|TWODOTS				{cout<<":";};
	
exprlist: /*expr (',' expr)* [',']*/
	expr expr_kleene COMMA
	|expr expr_kleene;

expr_kleene: expr_kleene COMMA expr
	| epsilon;

atom:/* ('(' [testlist_comp] ')' 
	| '[' [listmaker] ']' 
	| '{' [dictorsetmaker] '}' 
	|  '`' testlist1 '`' 
	| NAME | NUMBER | STRING+)*/
	OPENPAR CLOSEPAR					{$$=NULL;}
	|OPENCOR CLOSECOR					{$$=NULL;}
	|OPENPAR testlist_comp CLOSEPAR		{$$=$2;}
	|OPENCOR listmaker CLOSECOR			{$$=$2;}
	|OPENKEY CLOSEKEY					{$$=NULL;}
	|OPENKEY dictorsetmaker CLOSEKEY	{$$=$2;}
	|APOSTROFE testlist1 APOSTROFE		{$$=$2;}
	|NAME								{Node *identn = asTree->bIdentNode($1); $$=identn;}
	|INTEGER							{Node *intn = asTree->bIntNode($1); $$=intn;}
	|FLOATNUMBER						{Node *floatn = asTree->bFloatNode($1); $$=floatn;}
	|string_plus						{$$=$1;}
	|NONE								{$$=NULL;}
	|boolean							{$$=$1;};
	
boolean: TRUE {Node *booln = asTree->bIntNode(1); $$=booln;} 
		|FALSE {Node *booln = asTree->bIntNode(0); $$=booln;};
	
dictorsetmaker: /*( (test ':' test (comp_for | (',' test ':' test)* [','])) |
                  (test (comp_for | (',' test)* [','])) )*/
                  test TWODOTS test dictor_set_help		{$$ = $1; cout<<":";}
                  |test comp_for 						{$$ = $1;}
                  |test comma_test_kleene COMMA 		{$$ = $1;}
                  |test comma_test_kleene				{$$ = $1;};
                  
dictor_set_help: /*(comp_for | (',' test ':' test)* [','])*/
	comp_for 					{$$ = $1;}
	|dictor_set_help2 COMMA 	{$$ = $1;}
	|dictor_set_help2 			{$$ = $1;};
	
dictor_set_help2: epsilon 							{$$ = $1;}
	| dictor_set_help2 COMMA test TWODOTS test		{$$ = $1; cout<<":";};

testlist1: /*test (',' test)**/
	test comma_test_kleene 	{$$ = $1;};
	
string_plus: 
	STRING					{Node *strn = asTree->bStrNode($1); $$=strn;}
	|STRING string_plus		{$$ = $2;};

/*LO QUE ESTA ARRIBA ES DE ARITHMETIC EXP*/
listmaker: 	/*test ( list_for | (',' test)* [','] )*/
	test list_for							{$$ = $1;}
	|test comma_test_kleene comma_one		{$$ = $1;};
		
testlist_comp: /* test ( comp_for | (',' test)* [','] )*/
	test comp_for 						{$$ = $1;}
	|test comma_test_kleene comma_one 	{$$ = $1;};
		
list_for: /* 'for' exprlist 'in' testlist_safe [list_iter]*/
	FOR exprlist IN testlist_safe 				{
													Node *forn = asTree->bForNode();
													forn->addFChild($2);
													forn->addLChild($4);
													cout<<"FOR";
												}
	|FOR exprlist IN testlist_safe list_iter	{
													Node *forn = asTree->bForNode();
													forn->addFChild($2);
													forn->addLChild($4);
													cout<<"FOR";
												};

list_iter: /*list_for | list_if*/
	list_for 	{$$ = $1;}
	|list_if 	{$$ = $1;};

testlist_safe: /*old_test [(',' old_test)+ [',']];*/
	old_test 								{$$ = $1;}
	|old_test comma_old_test_plus 			{$$ = $1;}
	|old_test comma_old_test_plus COMMA 	{$$ = $1;};
	
comma_old_test_plus: COMMA old_test 		{$$ = $2;}
	|comma_old_test_plus COMMA old_test 	{$$ = $3;};

list_if: /*'if' old_test [list_iter]*/
	IF old_test					{
									Node *ifn = asTree->bIfNode();
									ifn->addFChild($2);
									$$ = ifn;
									cout<<"IF___";
								}
	|IF old_test list_iter		{
									Node *ifn = asTree->bIfNode();
									ifn->addFChild($2);
									$$ = ifn;
									cout<<"IF___";
								};
	
compound_stmt: /*if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated*/
	if_stmt			{$$ = $1;}
	| while_stmt	{$$ = $1;}
	| for_stmt		{$$ = $1;}
	| funcdef		{$$ = $1;};

if_stmt: /*'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite]*/
	IF test TWODOTS suite elif_test_td_suite_kleene ELSE TWODOTS suite {
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild($2);
																			ifn->addLChild($4);
																			ifn->addLChild($5);
																			ifn->addLChild($8);
																			$$ = ifn;
																			cout<<"IF___:___ELSE:";
																		}
	|IF test TWODOTS suite elif_test_td_suite_kleene 					{
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild($2);
																			ifn->addLChild($4);
																			ifn->addLChild($5);
																			$$ = ifn;
																			cout<<"IF___:___";
																		};
	
elif_test_td_suite_kleene: epsilon
	|elif_test_td_suite_kleene ELIF test TWODOTS suite		{
																Node *ifn = asTree->bIfNode();
																ifn->addFChild($3);
																ifn->addLChild($5);
																ifn->addLChild($1);
																$$ = ifn;
																cout<<"ELIF___:";
															};

while_stmt: /*'while' test ':' suite ['else' ':' suite] */
	WHILE test TWODOTS suite ELSE TWODOTS suite 	{
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild($2);
														whilen->addLChild($4);
														whilen->addLChild($7);
														$$ = whilen;
														cout<<"WHILE___:___ ELSE :";
													}
	|WHILE test TWODOTS suite						{
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild($2);
														whilen->addLChild($4);
														$$ = whilen;
														cout<<"WHILE___:";
													};

for_stmt: /*'for' exprlist 'in' testlist ':' suite ['else' ':' suite]*/
	FOR exprlist IN testlist TWODOTS suite ELSE TWODOTS suite 	{
																	Node *forn = asTree->bForNode();
																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	forn->addLChild($6);
																	forn->addLChild($9);
																	$$ = forn;
																	cout<<"FOR";
																}
	|FOR exprlist IN testlist TWODOTS suite						{
																	Node *forn = asTree->bForNode();
																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	$$ = forn;
																	cout<<"FOR";
																};

suite: /*simple_stmt | NEWLINE INDENT stmt+ DEDENT*/
	simple_stmt 							{Node* stmtn = asTree->bExprNode(); stmtn->addFChild($1); $$ = stmtn;}
	|NEWLINE INDENT stmt_plus DEDENT		{$$ = $3; cout<<"\nINDENT___DEDENT";};
		
stmt_plus: stmt_plus stmt 	{Node* stmtln = $1; stmtln->addLChild($2); $$ = stmtln;}
	| stmt 					{Node* stmtln = asTree->bStmtListNode(); stmtln->addFChild($1); $$ = stmtln;};

stmt: /*simple_stmt | compound_stmt*/
	simple_stmt 		{$$ = $1;}
	| compound_stmt 	{$$ = $1;};
	
simple_stmt: /*small_stmt (';' small_stmt)* [';'] NEWLINE */
	small_stmt more_simple_stmt DOTCOMMA NEWLINE	{
														Node* sstmtln = $2;
														sstmtln->addFChild($1);
														$$ = sstmtln;
														cout<<";\n";
													}

	|small_stmt more_simple_stmt NEWLINE			{
														Node* sstmtln = $2;
														sstmtln->addFChild($1);
														$$ = sstmtln;
														cout<<"\n";
													};

more_simple_stmt:
		more_simple_stmt DOTCOMMA small_stmt 	{Node* sstmtln = $1; sstmtln->addLChild($3); $$ = sstmtln;}
		| epsilon 								{Node* sstmtn = asTree->bSStmtListNode(); $$ = sstmtn;};
				
small_stmt: /*(expr_stmt | print_stmt  | del_stmt | pass_stmt | flow_stmt |
             import_stmt | global_stmt | exec_stmt | assert_stmt)*/
	expr_stmt 		{$$ = $1;}
	| print_stmt 	{$$ = $1;}
	| del_stmt		{$$ = $1;}
	| pass_stmt 	{$$ = $1;}
	| flow_stmt 	{$$ = $1;}
	/*| global_stmt 	{$$ = $1;};*/


expr_stmt: /*testlist (augassign (yield_expr|testlist) |('=' (yield_expr|testlist))*)*/
	testlist expr_stmt_at 	{
								Node* assignn = $1;
								assignn->addFChild($1);
								Node* stmtn = asTree->bStmtNode();
								stmtn->addFChild(assignn);
								$$ = stmtn;
							};

expr_stmt_at: 
		augassign testlist 			{Node* assignn = $1; assignn->addLChild($2); $$ = assignn;}
		|assign_testlist_kleene 	{$$ = $1;};

assign_testlist_kleene: 
		assign_testlist_kleene ASSIGN testlist	{
													Node* assignn = asTree->bAssignNode();
													assignn->addFChild($1);
													// assignn->addLChild($2);
													assignn->addLChild($3);
													$$ = assignn;
													cout<<"=";
												}
		| epsilon								{
													Node* assignn = asTree->bAssignNode();
													$$ = assignn;
												}; 

augassign: /*('+=' | '-=' | '*=' | '/=' | '%=' | '&=' | '|=' | '^=' |
            '<<=' | '>>=' | '**=' | '//=')*/
	/*MASIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"+=";}*/
	MASIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"+=";}
	/*|MENOSIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"-=";}*/
	|MENOSIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"-=";}
	/*|PORIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"*=";}*/
	|PORIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"*=";}
	/*|ENTREIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"/=";}*/
	|ENTREIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"/=";}
	/*|MODIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"%=";}*/
	|MODIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"%=";}
	/*|ANDIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"&=";}*/
	|ANDIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"&=";}
	/*|ORIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"|=";}*/
	|ORIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"|=";}
	/*|EXPIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"^=";}*/
	|EXPIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"^=";}
	/*|BINRIGHTIGUAL	{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<">>=";}*/
	|BINRIGHTIGUAL	{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<">>=";}
	/*|BINLEFTIGUAL	{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"<<=";}*/
	|BINLEFTIGUAL	{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"<<=";}
	/*|POTIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"**=";}*/
	|POTIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"**=";}
	/*|DIVIGUAL		{Node* assignn = asTree->bAssignNode(); assignn->addFChild($1); $$ = assignn; cout<<"//=";};*/
	|DIVIGUAL		{Node* assignn = asTree->bAssignNode(); $$ = assignn; cout<<"//=";};
	
print_stmt: /*'print' ( [ test (',' test)* [','] ] | '>>' test [ (',' test)+ [','] ] )*/
	PRINT print_stmt1		{$$ = $2; cout<<"PRINT";}
	|PRINT print_stmt2		{$$ = $2; cout<<"PRINT";};
	
print_stmt1: epsilon 					{$$ = NULL;}
	|test comma_test_kleene comma_one 	{Node* stmtn = $2; stmtn->addFChild($1); $$ = stmtn;};

comma_test_kleene: epsilon			{Node* stmtn = asTree->bStmtNode(); $$ = stmtn;}
	|comma_test_kleene COMMA test	{Node* stmtn = $1; stmtn->addFChild($3); $$ = stmtn; cout<<",";};

print_stmt2: BINRIGHT test		{cout<<">>";}
	|BINRIGHT test comma_test_plus comma_one {cout<<">>";};
	
comma_one: epsilon
	|COMMA		{cout<<",";};

comma_test_plus: COMMA test 		{Node* stmtn = asTree->bStmtNode(); stmtn->addFChild($2); $$ = stmtn;}
	| comma_test_plus COMMA test 	{Node* stmtn = $1; stmtn->addLChild($3); $$ = stmtn;};

testlist: /*test (',' test)* [','];*/
	test comma_test_kleene comma_one	{Node* stmtn = $2; stmtn->addFChild($1); $$ = stmtn;};
	

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: DEL exprlist 	{Node* stmtn = asTree->bStmtNode(); stmtn->addFChild($2); $$ = stmtn;};

pass_stmt: PASS 		{Node* stmtn = asTree->bStmtNode(); $$ = stmtn;};

flow_stmt: /*break_stmt | continue_stmt | return_stmt | raise_stmt | yield_stmt*/
	break_stmt 			{$$ = $1;}
	| continue_stmt 	{$$ = $1;}
	| return_stmt 		{$$ = $1;}; 

break_stmt: BREAK 			{Node* stmtn = asTree->bStmtNode(); $$ = stmtn;};

continue_stmt: CONTINUE 	{Node* stmtn = asTree->bStmtNode(); $$ = stmtn;};

return_stmt: 
	RETURN testlist		{Node* stmtn = asTree->bStmtNode(); stmtn->addFChild($2); $$ = stmtn; cout<<"RETURN __";}
	|RETURN				{Node* stmtn = asTree->bStmtNode(); $$ = stmtn; cout<<"RETURN";};

/* global me parece innecesario pero en tema de registros plantea algo importante - 'global' NAME (',' NAME) */
/*
global_stmt:
	GLOBAL NAME global_stmt_name 	{Node *identn = asTree->bIdentNode($2); $$=identn;};
	
global_stmt_name:
	global_stmt_name COMMA NAME 	{Node *identn = asTree->bIdentNode($3); $$=identn;}
	| epsilon;
*/

/* Funciones */
funcdef: /*'def' NAME parameters ':' suite*/
	DEF NAME parameters TWODOTS suite	{
											Node *funcn = asTree->bFuncNode();
											Node *identn = asTree->bIdentNode($2);
											funcn->addFChild(identn);
											funcn->addLChild($3);
											funcn->addLChild($5);
											$$ = funcn;
											cout<<"DEF NAME(_):_\n";
										};

parameters: /*'(' [varargslist] ')'*/
	OPENPAR CLOSEPAR 				{Node *argsn = asTree->bArgsNode(); $$ = argsn;}
	| OPENPAR varargslist CLOSEPAR 	{$$ = $2;};
		
varargslist: /*
	  ((fpdef ['=' test] ',')* ('*' NAME [',' '**' NAME] | '**' NAME) | fpdef ['=' test] (',' fpdef ['=' test])* [',']) */
	/*
	a b
	|fpdef ASSIGN test d
	*/
	fpdef ASSIGN test d 			{
										Node *argsn = $4;
										argsn->addFChild($1);
										$$ = argsn;
									}
	|fpdef ASSIGN test d COMMA 		{
										Node *argsn = $4;
										Node *identn = $1;
										identn->setSChild($3);
										argsn->addFChild(identn);
										$$ = argsn;
									}
	|fpdef d COMMA 					{
										Node *argsn = $2;
										argsn->addFChild($1);
										$$ = argsn;
									}
	|fpdef d 						{
										Node *argsn = $2;
										argsn->addFChild($1);
										$$ = argsn;
									};

/*
a: a fpdef COMMA
	|a fpdef ASSIGN test COMMA
	|epsilon;
	
b: POR NAME 
|POR NAME COMMA POT NAME
| POT NAME;
*/

d: d COMMA fpdef 				{
									Node *argsn = $1;
									argsn->addLChild($3);
									$$ = $3;
								}
| d COMMA fpdef ASSIGN test 	{
									Node *argsn = $1;
									Node *identn = $3;
									identn->setSChild($5);
									argsn->addLChild(identn);
									$$ = argsn;
								}
|epsilon						{
									Node *argsn = asTree->bArgsNode();
									$$ = argsn;
								};
	
fpdef: 	/*NAME | '(' fplist ')';*/
	NAME 						{
									Node *identn = asTree->bIdentNode($1);
									$$ = identn;
								}
	|OPENPAR fplist CLOSEPAR	{$$ = $2;};

fplist: /*fpdef (',' fpdef)* [',']*/
	fpdef fpdef_kleene COMMA 	{
									Node *argsn = $2;
									argsn->addLChild($1);
									$$ = argsn;
								}
	|fpdef fpdef_kleene 		{
									Node *argsn = $2;
									argsn->addLChild($1);
									$$ = argsn;
								};
	
fpdef_kleene: fpdef_kleene COMMA fpdef 	{
											Node *argsn = $1;
											argsn->addLChild($3);
											$$ = argsn;
										}
	| epsilon							{
											Node *argsn = asTree->bArgsNode();
											$$ = argsn;
										};

%%