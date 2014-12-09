%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
// #include "../lib/Composit/MAST.hpp"
#include "../lib/Composit/TableVisitor.hpp"
#include "../lib/Composit/PrintVisitor.hpp"
// #include "../lib/Composit/OolongVisitor.hpp"
#include <string>

using namespace std;
#define YYDEBUG 1
int yylex(); 
int yyerror(const char *s) { printf ("\nError: %s\n", s); }

extern "C" FILE *yyin;

//SymbolTable *st = new SymbolTable();
MAST *asTree = new MAST();
// TableVisitor *visitor = new TableVisitor;
PrintVisitor *visitor = new PrintVisitor;
// OolongVisitor *visitor = new OolongVisitor;

%}

%code requires{
#include "../lib/Composit/Nodos.hpp"
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
%type <nodo> file_input filein epsilon test or_test or_andtest and_test and_nottest not_test comparison comp_op_expr_kleene comp_op expr pipexor_expr xor_expr andxor_expr and_expr andpandshift_expr shift_expr leftright_shift_expr arithmetic_expr sign_term term factor_operation factor power trailer_kleene trailer arglist argument_comma argument_multiple comma_argument argument subscriptlist comma_subscript subscript sliceop exprlist expr_kleene atom boolean testlist1 string_plus listmaker testlist_comp compound_stmt if_stmt elif_test_td_suite_kleene while_stmt for_stmt suite stmt_plus stmt simple_stmt small_stmt_kleene small_stmt expr_stmt expr_stmt_at augassign print_stmt print_args comma_test_kleene testlist flow_stmt break_stmt continue_stmt return_stmt funcdef parameters varargslist args_kleene comma_one

%%
file_input: /* (NEWLINE | stmt)* ENDMARKER */
	filein	{
				// cout << endl << "file_input" << endl;
				if ($1 != NULL)
				{
					Node* node = $1;
					cout << endl;
					node->accept(*visitor);
					cout << endl;
				}
				// cout<<"\nCOMPILATION COMPLETE :)\n";
			};

/*  FIXTHIS: stmt es (simple_stmt | compound_stmt)	donde simple_stmt es un SStmtListNode. ¿Debería suponer que stmt es una lista? */
filein: /* (filein (NEWLINE | stmt))* */
	epsilon				{
							// cout << "filein epsilon..." << endl;
							Node* stmtln = asTree->bFileNode();
							// Node* stmtln = asTree->bStmtListNode();
							// stmtln->accept(*visitor);
							$$ = stmtln;
						}
	| filein NEWLINE	{
							// cout << "filein newline" << endl;
							$$ = $1;
						}
	| filein stmt 		{
							// cout << "filein stmt" << endl;
							if ($1 != NULL)
							{
								Node *stmtln = $1;
								stmtln->addLChild($2);
								$$ = stmtln;
							}
						};
	
/*Aquí va la gramática*/

epsilon: 	{/*Nada xD*/};

test: /* or_test ['if' or_test 'else' test] */
	or_test							{
										// cout<<"test"<<endl;
										$$ = $1;
										// Node* node = $1; node->accept(*visitor); cout << endl;
									}
	| or_test IF or_test ELSE test	{};

or_test: /* and_test ('OR' and_test)* */
	and_test or_andtest 	{
								if ($2 != NULL)
								{
									Node *orn = $2;
									orn->setFChild($1);
									$$ = orn;
								} else {
									$$ = $1;
								}
							};
		
or_andtest: /* ('OR' and_test)* */
	epsilon 					{ $$ = NULL; }
	| or_andtest OR and_test	{
									Node *orn = asTree->bOrNode();
									orn->setSChild($3);
									$$ = orn;
									// cout<<"OR";
								};
		
and_test: /* not_test (AND not_test)* */
	not_test and_nottest	{
								if ($2 != NULL)
								{
									Node *andn = $2;
									andn->setFChild($1);
									$$ = andn;
								} else {
									$$ = $1;
								}
							};
		
and_nottest: /* ('AND' not_test)* */
	epsilon 					{ $$ = NULL; }
	| and_nottest AND not_test	{
									Node *andn = asTree->bAndNode();
									andn->setSChild($3);
									$$ = andn;
									// cout<<"AND";
								};
		
not_test: /* 'not' not_test | comparison*/
	NOT not_test	{
						Node *notn = asTree->bNotNode();
						notn->setFChild($2);
						$$ = notn;
						// cout<<"NOT";
					}
	| comparison	{$$ = $1;};

		
comparison: /* expr (comp_op expr)* */
	expr comp_op_expr_kleene 	{
									// cout << "expr comp_op_expr_kleene" << endl;
									if ($2 != NULL)
									{
										// cout << "($2 != NULL)" << endl;
										Node *compn = $2;
										compn->setFChild($1);
										// compn->accept(*visitor); cout << endl;
										$$ = compn;
									} else {
										// cout << "($2 == NULL)" << endl;
										Node* node = $1;
										// node->accept(*visitor); cout << endl;
										$$ = $1;
									}
								};

comp_op_expr_kleene: /* (comp_op expr)* */
	comp_op_expr_kleene comp_op expr 	{
											Node *compn = $2;
											compn->setSChild($3);
											// compn->accept(*visitor); cout << endl;
											$$ = compn;
										}
	| epsilon 							{$$ = NULL;};
	
comp_op: /* ('<' | '>' | '==' | '>=' | '<=' | '<>' | '!=' | 'in' | 'not' 'in' | 'is' | 'is' 'not') */
	LESSTHAN			{
							Node *compn = asTree->bLTNode();
							$$ = compn;
							// cout<<"<";
						}
	| MORETHAN			{
							Node *compn = asTree->bGTNode();
							$$ = compn;
							// cout<<">";
						}
	| EQUALS			{
							Node *compn = asTree->bEqNode();
							$$ = compn;
							// cout<<"==";
						}
	| MOREEQUAL			{
							Node *compn = asTree->bGTEqNode();
							$$ = compn;
							// cout<<">=";
						}
	| LESSEQUAL			{
							Node *compn = asTree->bLTEqNode();
							$$ = compn;
							// cout<<"<=";
						}
	| DIFFERENT			{
							Node *compn = asTree->bNEqNode();
							$$ = compn;
							// cout<<"!=";
						}
	| PICOPARENTESIS		{
								// cout<<"<>";
							}
	| IN					{
								// cout<<"IN";
							}
	| NOT IN				{
								// cout<<"NOT IN";
							}
	| IS					{
								// cout<<"IS";
							}
	| IS NOT				{
								// cout<<"IS NOT";
							};


expr: /* xor_expr ('|' xor_expr)* */
	xor_expr pipexor_expr 		{
									if ($2 != NULL)
									{
										Node *orn = $2;
										orn->setFChild($1);
										$$ = orn;
									} else {
										$$ = $1;
									}
								};
	
pipexor_expr: /* ('|' xor_expr)* */
	epsilon 						{ $$ = NULL; }	
	| pipexor_expr PIPE xor_expr 	{
										Node *orn = asTree->bOrNode();
										orn->setFChild($1);
										orn->setSChild($3);
										$$ = orn;
									};
		
xor_expr: /* and_expr ('^' and_expr)* */
	and_expr andxor_expr 	{
								if ($2 != NULL)
								{
									Node *andn = $2;
									andn->setFChild($1);
									$$ = andn;
								} else {
									$$ = $1;
								}
							};

andxor_expr: /* ('^' and_expr)* */
	epsilon 					{ $$ = NULL; }
	| andxor_expr EXP and_expr 	{
									Node *andn = asTree->bAndNode();
									andn->setFChild($1);
									andn->setSChild($3);
									$$ = andn;
								};
		
and_expr: /* shift_expr ('&' shift_expr)* */
	shift_expr andpandshift_expr 	{
										if ($2 != NULL)
										{
											Node *andn = $2;
											andn->setFChild($1);
											$$ = andn;
										} else {
											$$ = $1;
										}
									};

andpandshift_expr: /* ('&' shift_expr)* */
	epsilon 								{ $$ = NULL; }
	| andpandshift_expr ANDPAND shift_expr 	{
												Node *andn = asTree->bAndNode();
												andn->setFChild($1);
												andn->setSChild($3);
												// andn->accept(*visitor); cout << endl;
												$$ = andn;
											};

shift_expr: /* arith_expr (('<<'|'>>') arith_expr)* */
	arithmetic_expr leftright_shift_expr 	{
												if ($2 != NULL)
												{
													/* Asignar hijo izq de operador (<< | >>) */
												} else {
													$$ = $1;
												}
											};

leftright_shift_expr: /* (('>>' | '<<') arithmetic_expr)* */
	epsilon 										{ $$ = NULL; }
	| leftright_shift_expr BINRIGHT arithmetic_expr {
														// cout<<">>";
														$$ = $3;
													}
	| leftright_shift_expr BINLEFT arithmetic_expr	{
														// cout<<"<<";
														$$ = $3;
													};

arithmetic_expr: /* term ('+' term)* | term ('-' term)* */
	term sign_term	{
						// cout << "term sign_term" << endl;
						Node *termn = $1;
						// termn->accept(*visitor); cout << endl;
						if ($2 != NULL)
						{
							BinNode* node = dynamic_cast<BinNode*> ($2);
							while(node->getLeftChild() != NULL) {
								node = dynamic_cast<BinNode*> (node->getLeftChild());
							}
							node->setFChild($1);

							Node* termn = $2;
							// termn->accept(*visitor); cout << endl;
							$$ = $2;
						} else {
							$$ = $1;
						}
						// cout << "END < arithmetic_expr" << endl;
					};

sign_term: /* (('+' | '-') term)* */
	epsilon 					{ $$ = NULL; }
	| sign_term MAS term		{
									// cout<<"Suma"<<endl;
									Node *plusn = asTree->bPlusNode();
									Node* right = $3;
									// cout << "right operand" << endl;
									// right->accept(*visitor); cout << endl;
									plusn->setSChild($3);
									if ($1 != NULL)
									{
										Node* left = $1;
										// cout << "left operand" << endl;
										// left->accept(*visitor); cout << endl;
										plusn->setFChild($1);
									}
									// plusn->accept(*visitor);
									// cout << "IM RIGHT HERE" << endl;
									$$ = plusn;
								}

	| sign_term MENOS term		{
									// cout<<"Resta"<<endl;
									Node *minusn = asTree->bMinusNode();
									minusn->setSChild($3);
									if ($1 != NULL)
									{
										minusn->setFChild($1);
									}
									// minusn->accept(*visitor);
									$$ = minusn;
								};

term: /* (factor ('*'factor)* | factor ('/'factor)* | factor ('%' factor)* | factor ("//" factor)*) */
	factor factor_operation		{
									// cout << "factor factor_operation" << endl;
									Node* node = $1;
									// node->accept(*visitor); cout << endl;
									if ($2 != NULL)
									{
										BinNode* node = dynamic_cast<BinNode*> ($2);
										while(node->getLeftChild() != NULL) {
											node = dynamic_cast<BinNode*> (node->getLeftChild());
										}
										node->setFChild($1);

										Node* factorn = $2;
										// factorn->accept(*visitor); cout << endl;
										$$ = factorn;
									} else {
										$$ = $1;
									}
								};
	
factor_operation: /* (('*' | '/' | '%') factor)* */
	epsilon 								{ $$=NULL; }
	| factor_operation POR factor 			{
												// cout<<"Multiplicacion"<<endl;
												Node *multn = asTree->bMultNode();
												multn->setSChild($3);
												if ($1 != NULL)
												{
													multn->setFChild($1);
												}
												// multn->accept(*visitor);
												$$ = multn;
											}
	| factor_operation ENTRE factor 		{
												// cout<<"Division"<<endl;
												Node *divn = asTree->bDiviNode();
												divn->setSChild($3);
												if ($1 != NULL)
												{
													divn->setFChild($1);
												}
												// divn->accept(*visitor);
												$$ = divn;
											}
	| factor_operation MOD factor 			{
												// cout<<"Modulo"<<endl;
											}
	| factor_operation DIV factor 			{
												// cout<<"Division Entera"<<endl;
												Node *divn = asTree->bDiviNode();
												divn->setSChild($3);
												if ($1 != NULL)
												{
													divn->setFChild($1);
												}
												// divn->accept(*visitor);
												$$ = divn;
											};

factor: /* (('+' | '-' | '~') factor | power) */
	MAS factor			{
							// cout<<"SUMA"<<endl;
							Node *plusn = asTree->bPlusNode();
							plusn->setSChild($2);
							// plusn->accept(*visitor); cout << endl;
							$$ = plusn;
						}
	| MENOS factor		{
							// cout<<"RESTA"<<endl;
							Node *minusn = asTree->bMinusNode();
							minusn->setSChild($2);
							// minusn->accept(*visitor); cout << endl;
							$$ = minusn;
						}
	| TILDE factor 		{$$ = $2;}
	| power 			{
							$$ = $1;
							// cout<<"power"<<endl; 
							// Node* node = $1; node->accept(*visitor); cout << endl;
						};

power: /* atom trailer* ['**' factor] */
	atom trailer_kleene					{
											// cout << "atom trailer_kleene" << endl; 
											// Node* node = $1; node->accept(*visitor); cout << endl;
											if ($2 != NULL)
											{
												ArgsNode* argsn = dynamic_cast<ArgsNode*> ($2);
												if (argsn != 0)
												{
													CallNode* calln = asTree->bCallNode();
													calln->addFChild($1);
													calln->addLChild($2);
													// calln->accept(*visitor); cout << endl;
													$$ = calln;
												}
											} else {
												$$ = $1;
											}
										}
	| atom trailer_kleene POT factor	{
											$$ = $1;
											// cout << "atom trailer_kleene POT factor" << endl;
											// Node* node = $1; node->accept(*visitor); cout << endl;
										};

trailer_kleene: /* trailer* */
	epsilon					{
								// cout << "epsilon trailer_kleene" << endl;
								$$ = NULL;
							}
	|trailer_kleene trailer {
								// cout << "trailer_kleene trailer" << endl;
								Node* node = $2;
								// node->accept(*visitor); cout << endl;
								if ($1 != NULL)
								{
									Node* trailer_kleene = $1;
									// trailer_kleene->accept(*visitor); cout << endl;
								}
								$$ = $2;
							};

/* FIXTHIS: Falta ver el soporte de esto */	
trailer: /* '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME */
	OPENPAR CLOSEPAR					{
											// cout<<"()"<<endl;
											Node* argsn =  asTree->bArgsNode();
											$$ = argsn;
										}
	| OPENPAR arglist CLOSEPAR			{
											// cout<<"(ARGLIST)"<<endl;
											$$ = $2; 
										}
	| OPENCOR subscriptlist CLOSECOR	{
											// cout<<"(SUBSCRIPTLIST)"<<endl;
											$$ = $2;
										}
	| DOT NAME							{
											// cout<<".NAME"<<endl;
											string* id = new string($2);
											Node *identn = asTree->bIdentNode(id);
											// identn->accept(*visitor); cout << endl;
											$$=identn; 
										};
		
arglist: /* (argument ',')* (argument [','] |'*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument_comma argument_multiple 	{
											// cout << "argument_comma argument_multiple" << endl;
											if ($1 != NULL)
											{
												Node *argsn = $1;
												argsn->addLChild($2);
												// argsn->accept(*visitor); cout << endl;
												$$ = argsn;
											}
										};
	
argument_comma: /* (argument ',')* */
	epsilon								{
											// cout << "epsilon argument_comma" << endl;
											Node *argsn = asTree->bArgsNode();
											// argsn->accept(*visitor); cout << endl;
											$$ = argsn;
										}
	| argument_comma argument COMMA 	{
											// cout << "argument_comma argument COMMA" << endl;
											if ($1 != NULL)
											{
												Node *argsn = $1;
												argsn->addLChild($2);
												// argsn->accept(*visitor); cout << endl;
												$$ = argsn;
											}
										};
	
/* FIXTHIS: Argumentos opcionales y por referencia no tiene soporte (i.e. foo(*bar, **foobar)) */
argument_multiple: /* (argument [','] | '*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument 									{$$ = $1;}
	| argument COMMA							{$$ = $1;}
	| POR test comma_argument					{$$ = $2;}
	| POR test comma_argument COMMA POT test	{$$ = $2;}
	| POT test									{$$ = $2;};
	
comma_argument: /* (',' argument)* */
	epsilon
	| comma_argument COMMA argument 	{$$ = $3;};
	
/* FIXTHIS: Argumentos con asignacion i.e. foo(x=3) no tiene soporte */
argument: /* test [comp_for] | test '=' test */
	test 				{$$ = $1;}
	| test ASSIGN test 	{
							cout << "********************************************************" << endl;
							cout << "Argumentos con asignacion i.e. foo(x=3) no tiene soporte" << endl;
							cout << "********************************************************" << endl;
							Node *assignn = asTree->bAssignNode();
							assignn->setFChild($1);
							assignn->setFChild($3);
							$$ = assignn;
						};
			
/* FIXTHIS: No entiendo aún el uso de subscript */
subscriptlist: /* subscript (',' subscript)* [','] */
	subscript comma_subscript 			{$$ = $1;};
	| subscript comma_subscript COMMA 	{$$ = $1;};

comma_subscript: /* (',' subscript)* */
	comma_subscript COMMA subscript 	{$$ = $3;}
	| epsilon;
	
subscript: /* '.' '.' '.' | test | [test] ':' [test] [sliceop] */
	DOT DOT DOT 					{$$ = NULL;}
	| test 							{$$ = $1;}
	| test TWODOTS test sliceop		{$$ = $1;}
	| test TWODOTS test				{$$ = $1;}
	| test TWODOTS					{$$ = $1;}
	| test TWODOTS sliceop			{$$ = $1;}
	| TWODOTS test sliceop			{$$ = $2;}
	| TWODOTS test					{$$ = $2;}
	| TWODOTS sliceop				{$$ = $2;}
	| TWODOTS						{cout<<":"<<endl;};

sliceop: /* ':' [test] */
	TWODOTS test 	{cout<<":"<<endl;}
	| TWODOTS		{cout<<":"<<endl;};
	
exprlist: /* expr (',' expr)* [','] */
	expr expr_kleene COMMA  {
								if ($2 != NULL)
								{
									Node* exprln = $2;
									exprln->addFChild($1);
									// exprln->accept(*visitor); cout << endl;
									$$ = exprln;
								}
							}
	| expr expr_kleene 		{
								if ($2 != NULL)
								{
									Node* exprln = $2;
									exprln->addFChild($1);
									// exprln->accept(*visitor); cout << endl;
									$$ = exprln;
								}
							};

expr_kleene: /* (',' expr)* */
	expr_kleene COMMA expr 	{
								if ($1 != NULL)
								{
									Node* exprln = $1;
									exprln->addLChild($3);
									// exprln->accept(*visitor); cout << endl;
									$$ = exprln;
								}
							}
	| epsilon 				{
								Node* exprln = asTree->bExprListNode();
								// exprln->accept(*visitor); cout << endl;
								$$ = exprln;
							};

/* FIXTHIS: No entiendo que es ('`' testlist1 '`') */
atom: /* ( '(' [testlist_comp] ')' | '[' [listmaker] ']' |  '`' testlist1 '`' | NAME | NUMBER | STRING+ ) */
	OPENPAR CLOSEPAR					{$$ = NULL;}
	| OPENPAR testlist_comp CLOSEPAR	{$$ = $2;}
	| OPENCOR CLOSECOR					{$$ = NULL;}
	| OPENCOR listmaker CLOSECOR		{$$ = $2;}
	| APOSTROFE testlist1 APOSTROFE		{$$ = $2;}
	| string_plus						{$$ = $1; 
											// Node* node = $1; node->accept(*visitor); cout << endl;
										}
	| boolean							{$$ = $1; 
											// Node* node = $1; node->accept(*visitor); cout << endl;
										}
	| NONE								{$$ = NULL;}
	| NAME			{
						string* id = new string($1);
						Node *identn = asTree->bIdentNode(id);
						// identn->accept(*visitor); cout << endl;
						$$=identn;
					}
	| FLOATNUMBER	{
						Node *floatn = asTree->bFloatNode($1);
						// floatn->accept(*visitor); cout << endl;
						$$=floatn;
					}
	| INTEGER		{
						Node *intn = asTree->bIntNode($1);
						$$=intn;
						// intn->accept(*visitor); cout << endl;
					};
	
boolean: /* (TRUE | FALSE) */
	TRUE 	{
				Node *booln = asTree->bBoolNode(true);
				// booln->accept(*visitor); cout << endl;
				$$ = booln;
			} 
	| FALSE {
				Node *booln = asTree->bBoolNode(false);
				// booln->accept(*visitor); cout << endl;
				$$ = booln;
			};

testlist1: /* test (',' test)* */
	test comma_test_kleene 	{$$ = $1;};
	
string_plus: /* (STRING)+ */
	STRING						{
									// cout << ":::" << $1 << ":::" << endl;
									string* str = new string($1);
									Node *strn = asTree->bStrNode(str);
									// strn->accept(*visitor); cout << endl;
									$$ = strn;
								}
	| STRING string_plus		{
									$$ = $2; 
									// cout << "not here please......" << endl;
								};

/* FIXTHIS: No hay soporte para listas aún */
listmaker: 	/* test (',' test)* */
	test comma_test_kleene 	{$$ = $1;};
		
testlist_comp: /* test ( comp_for | (',' test)* [','] ) */
	test comma_test_kleene comma_one 	{$$ = $1;};

compound_stmt: /* (if_stmt | while_stmt | for_stmt | funcdef) --deprecated: classdef */
	if_stmt			{
						// cout<<"compound_stmt"<<endl;
						$$ = $1;
						Node* node = $1;
						// node->accept(*visitor); 
						cout << endl;
					}
	| while_stmt	{
						// cout<<"compound_stmt"<<endl;
						$$ = $1;
						Node* node = $1;
						// node->accept(*visitor); 
						cout << endl;
					}
	| for_stmt		{
						// cout<<"compound_stmt"<<endl;
						$$ = $1;
						Node* node = $1;
						// node->accept(*visitor); 
						cout << endl;
					}
	| funcdef		{
						// cout<<"compound_stmt"<<endl;
						$$ = $1;
						Node* node = $1;
						// node->accept(*visitor); 
						cout << endl;
					};

if_stmt: /* 'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite] */
	IF test TWODOTS suite elif_test_td_suite_kleene ELSE TWODOTS suite 	{
																			// cout << "if _ : _ else : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			Node* exprn = asTree->bExprNode();
																			exprn->addFChild($2);

																			ifn->addFChild(exprn);
																			ifn->addLChild($4);
																			if ($5 != NULL)
																			{
																				ifn->addLChild($5);
																			}
																			ifn->addLChild($8);
																			// ifn->accept(*visitor); cout << endl;
																			$$ = ifn;
																		}
	| IF test TWODOTS suite elif_test_td_suite_kleene 					{
																			// cout << "if _ : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			Node* exprn = asTree->bExprNode();
																			exprn->addFChild($2);

																			ifn->addFChild(exprn);
																			ifn->addLChild($4);
																			if ($5 != NULL)
																			{
																				ifn->addLChild($5);
																			}
																			// ifn->accept(*visitor); cout << endl;
																			$$ = ifn;
																		};
	
elif_test_td_suite_kleene: /* ('elif' test ':' suite)* */
	epsilon 											{ $$ = NULL; }
	| elif_test_td_suite_kleene ELIF test TWODOTS suite {
															// cout << "elif _ : _" << endl;
															Node *ifn = asTree->bIfNode();
															Node* exprn = asTree->bExprNode();
															exprn->addFChild($3);

															ifn->addFChild(exprn);
															ifn->addLChild($5);
															ifn->addLChild($1);
															// ifn->accept(*visitor); cout << endl;
															$$ = ifn;
														};

while_stmt: /* 'while' test ':' suite ['else' ':' suite] */
	WHILE test TWODOTS suite ELSE TWODOTS suite 	{
														// cout << "while _ : _ else : _" << endl;
														Node *whilen = asTree->bWhileNode();
														Node* exprn = asTree->bExprNode();
														exprn->addFChild($2);

														whilen->addFChild(exprn);
														whilen->addLChild($4);
														whilen->addLChild($7);
														// whilen->accept(*visitor); cout << endl;
														$$ = whilen;
													}
	| WHILE test TWODOTS suite						{
														// cout << "while _ : _" << endl;
														Node *whilen = asTree->bWhileNode();
														Node* exprn = asTree->bExprNode();
														exprn->addFChild($2);

														whilen->addFChild(exprn);
														whilen->addLChild($4);
														// whilen->accept(*visitor); cout << endl;
														$$ = whilen;
													};

for_stmt: /* 'for' exprlist 'in' testlist ':' suite ['else' ':' suite] */
	FOR exprlist IN testlist TWODOTS suite ELSE TWODOTS suite 	{
																	// cout << "for _ in _ : _ else : _" << endl;
																	Node *forn = asTree->bForNode();
																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	forn->addLChild($6);
																	forn->addLChild($9);
																	// forn->accept(*visitor); cout << endl;
																	$$ = forn;
																}
	| FOR exprlist IN testlist TWODOTS suite					{
																	// cout << "for _ in _ : _" << endl;
																	Node *forn = asTree->bForNode();

																	// cout << "exprlist:" << endl;
																	Node* exprlist = $2;
																	// exprlist->accept(*visitor); cout << endl;
																	// cout << "testlist:" << endl;
																	Node* testlist = $4;
																	// testlist->accept(*visitor); cout << endl;
																	// cout << "suite:" << endl;
																	Node* suite = $6;
																	// suite->accept(*visitor); cout << endl;

																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	// forn->accept(*visitor); cout << endl;
																	$$ = forn;
																};

suite: /* simple_stmt | NEWLINE INDENT stmt+ DEDENT */
	simple_stmt 						{
											// Node *stmtln = asTree->bStmtListNode();
											// stmtln->addFChild($1);
											// Node* node = $1; node->accept(*visitor); cout << endl;
											$$ = $1;
										}
	| NEWLINE INDENT stmt_plus DEDENT	{$$ = $3;};
		
stmt_plus: /* (stmt)+ */
	stmt_plus stmt 	{
						if ($1 != NULL)
						{
							Node *stmtln = $1;
							stmtln->addLChild($2);
							// stmtln->accept(*visitor); cout << endl;
							$$ = stmtln;
						}
						/*
						StmtListNode* stmtlnc = dynamic_cast<StmtListNode*> ($1);
						if (stmtlnc != 0)
						{
							Node *stmtln = $1;
							stmtln->addLChild($2);
							$$ = stmtln;
						} else {
							Node *stmtln = asTree->bStmtListNode();
							stmtln->addLChild($2);
							$$ = stmtln;
						}
						*/
					}
	| stmt 			{
						Node* stmtln = asTree->bStmtListNode();
						stmtln->addFChild($1);
						// stmtln->accept(*visitor); cout << endl;
						$$ = stmtln;
					};

stmt: /* (simple_stmt | compound_stmt) */
	simple_stmt 		{
							// cout << "stmt:" <<endl; 
							$$ = $1;
							// Node* node = $1; node->accept(*visitor); cout << endl; 
						}
	| compound_stmt 	{
							// cout << "stmt:" <<endl; 
							$$ = $1;
							// Node* node = $1; node->accept(*visitor); cout << endl; 
						};
	
simple_stmt: /* small_stmt (';' small_stmt)* [';'] NEWLINE */
	small_stmt small_stmt_kleene DOTCOMMA NEWLINE	{
														if ($2 != NULL)
														{
															Node* sstmtln = $2;
															sstmtln->addFChild($1);
															// sstmtln->accept(*visitor); cout << endl;
															$$ = sstmtln;
														}
													}

	| small_stmt small_stmt_kleene NEWLINE			{
														if ($2 != NULL)
														{
															Node* sstmtln = $2;
															sstmtln->addFChild($1);
															// sstmtln->accept(*visitor); cout << endl;
															$$ = sstmtln;
														}
													};

small_stmt_kleene: /* (';' small_tmt)* */
		small_stmt_kleene DOTCOMMA small_stmt 	{
													if ($1 != NULL)
													{
														Node* sstmtln = $1;
														sstmtln->addLChild($3);
														// sstmtln->accept(*visitor); cout << endl;
														$$ = sstmtln;
													}
												}
		| epsilon 								{
													Node* sstmtln = asTree->bSStmtListNode();
													$$ = sstmtln;
												};
				
small_stmt: /* (expr_stmt | print_stmt | flow_stmt) */
	expr_stmt  		{
						// Node *sstmtn = asTree->bSStmtNode();
						// sstmtn->addFChild($1);
						// Node* node = $1; node->accept(*visitor); cout << endl;
						$$ = $1;
					}
	| print_stmt 	{
						// Node *sstmtn = asTree->bSStmtNode();
						// sstmtn->addFChild($1);
						// Node* node = $1; node->accept(*visitor); cout << endl;
						$$ = $1;
					}
	| flow_stmt 	{
						// Node *sstmtn = asTree->bSStmtNode();
						// sstmtn->addFChild($1);
						// Node* node = $1; node->accept(*visitor); cout << endl;
						$$ = $1;
					};

/* FIXTHIS: Ver comentario de assing_testlist_kleene */
expr_stmt: /*testlist (augassign testlist | ('=' testlist)*) */
	/*testlist expr_stmt_at 	{*/
	test expr_stmt_at 	{
								AssignNode* assignn = dynamic_cast<AssignNode*> ($2);
								if (assignn != 0)
								{
									Node* assignn = $2;
									assignn->setFChild($1);
									// assignn->accept(*visitor); cout << endl;
									$$ = assignn;
								} else {
									Node* augassign = $2;
									augassign->setFChild($1);

									Node* exprn = asTree->bExprNode();
									exprn->addFChild(augassign);

									Node* assignn = asTree->bAssignNode();
									assignn->setFChild($1);
									assignn->setSChild(exprn);
									// assignn->accept(*visitor); cout << endl;
									$$ = assignn;
								}
							};

/* FIXTHIS: Ver comentario de assing_testlist_kleene */
expr_stmt_at: /* (augassign testlist | ('=' testlist)*) */
		/*augassign testlist 			{*/
		augassign test 			{
									// Node* exprn = asTree->bExprNode();
									// exprn->addFChild($2);

									Node* assignn = $1;
									assignn->setSChild($2);
									// assignn->setSChild(exprn);
									$$ = assignn;
								}
		/*| assign_testlist_kleene 	{$$ = $1;};*/
		/*| ASSIGN testlist 			{*/
		| ASSIGN test 			{
									Node* exprn = asTree->bExprNode();
									exprn->addFChild($2);
									// cout<<"="<<endl;
									Node* assignn = asTree->bAssignNode();
									assignn->setSChild(exprn);

									// ArgsNode* exprn = dynamic_cast<ArgsNode*> ($2);
									// if (exprn != 0)
									// {
										// assignn->setSChild($2);
									// } else {
									// 	assignn->setSChild($2);
									// }
									$$ = assignn;
								};

/* FIXTHIS: No sé realmente cómo voy a manejar algo como x, y, z = 1, 2, 3 */
/* ('=' testlist)* */
/*
assign_testlist_kleene: 
		assign_testlist_kleene ASSIGN testlist	{
													cout<<"="<<endl;
													Node* assignn = asTree->bAssignNode();
													assignn->addFChild($1);
													// assignn->addLChild($2);
													assignn->addLChild($3);
													$$ = assignn;
												}
		| epsilon								{};
*/
augassign: /* ('+=' | '-=' | '*=' | '/=') */
	MASIGUAL		{
						// cout<<"+="<<endl;
						Node* assignn = asTree->bPlusNode();
						$$ = assignn;
					}
	| MENOSIGUAL	{
						// cout<<"-="<<endl;
						Node* assignn = asTree->bMinusNode();
						$$ = assignn;
					}
	| PORIGUAL		{
						// cout<<"*="<<endl;
						Node* assignn = asTree->bMultNode();
						$$ = assignn;
					}
	| ENTREIGUAL	{
						// cout<<"/="<<endl;
						Node* assignn = asTree->bDiviNode();
						$$ = assignn;
					};
	
print_stmt: /* 'print' [test (',' test)*] */
	PRINT print_args 	{
							Node *printn = asTree->bPrintNode();
							if ($2 != NULL)
							{
								printn->addFChild($2);
								$$ = printn;
							}
							// printn->accept(*visitor); cout << endl;
						};
	
print_args: /* [test (',' test)*] */
	epsilon						{
									Node *argsn = asTree->bArgsNode();
									// argsn->accept(*visitor); cout << endl;
									$$ = argsn;
								}
	| test comma_test_kleene 	{
									Node *exprn = asTree->bExprNode();
									exprn->addFChild($1);
									// exprn->accept(*visitor); cout << endl;
									if ($2 != NULL)
									{
										Node *argsn = $2;
										argsn->addFChild(exprn);
										// argsn->accept(*visitor); cout << endl;
										$$ = argsn;
									}
								};

comma_test_kleene: /* (',' test)* */
	epsilon							{
										Node *argsn = asTree->bArgsNode();
										// argsn->accept(*visitor); cout << endl;
										$$ = argsn;
									}
	| comma_test_kleene COMMA test	{
										Node* exprn = asTree->bExprNode();
										exprn->addFChild($3);
										// exprn->accept(*visitor); cout << endl;
										if ($1 != NULL)
										{
											Node *argsn = $1;
											argsn->addLChild(exprn);
											// argsn->accept(*visitor); cout << endl;
											$$ = argsn;
										}
									};

comma_one: /* [','] */
	epsilon
	| COMMA 	{$$ = NULL;};

testlist: /*test (',' test)* [','];*/
	test comma_test_kleene comma_one	{
											Node* exprn = asTree->bExprNode();
											exprn->addFChild($1);
											// exprn->accept(*visitor); cout << endl;

											// ArgsNode* argsn = dynamic_cast<ArgsNode*> ($2);
											// bool hasNoChildren = argsn->getChildren().empty();
											// if (!hasNoChildren)
											if ($2 != NULL)
											{
												Node* argsn = $2;
												argsn->addFChild(exprn);
												// argsn->accept(*visitor); cout << endl;
												$$ = argsn;
												// cout << "comma_test_kleene was not null" << endl;
											} else {
												// $$ = exprn;
												// cout << "comma_test_kleene was null!!!" << endl;
											}
										};

/* FIXED: 
	- ¿Estos deberían de estar encapsuladas en un nodo stmt?
	- NO, se encapsulan más arriba a un SStmtNode
*/
flow_stmt: /* break_stmt | continue_stmt | return_stmt */
	break_stmt 			{$$ = $1; 
							// Node* node = $1; node->accept(*visitor); cout << endl;
						}
	| continue_stmt 	{$$ = $1; 
							// Node* node = $1; node->accept(*visitor); cout << endl;
						}
	| return_stmt 		{$$ = $1; 
							// Node* node = $1; node->accept(*visitor); cout << endl;
						};

break_stmt: /* 'break' */
	BREAK 	{
				Node* breakn = asTree->bBreakNode();
				// breakn->accept(*visitor); cout << endl;
				$$ = breakn;
			};

continue_stmt: /* 'continue' */
	CONTINUE 	{
					Node* contn = asTree->bContinueNode();
					// contn->accept(*visitor); cout << endl;
					$$ = contn;
				};

return_stmt: /* 'return' [testlist] */
	RETURN testlist	{
						Node* returnn = asTree->bReturnNode();
						returnn->addFChild($2);
						// returnn->accept(*visitor); cout << endl;
						$$ = returnn;
					}
	| RETURN		{
						Node* returnn = asTree->bReturnNode(); 
						// returnn->accept(*visitor); cout << endl;
						$$ = returnn;
					};

/* Funciones */
funcdef: /*'def' NAME parameters ':' suite*/
	DEF NAME parameters TWODOTS suite	{ 	
											// cout << "DEF NAME parameters TWODOTS suite" << endl;
											Node *funcn = asTree->bFuncNode();
											/* FIXED: Bison recibe el NAME extrañamente */
											string name ($2);
											name = name.substr(0, name.find_first_of('('));
											Node *identn = asTree->bIdentNode(&name);
											// identn->accept(*visitor); cout << endl;
											funcn->addFChild(identn);
											funcn->addLChild($3);
											funcn->addLChild($5);
											// funcn->accept(*visitor); cout << endl;
											$$ = funcn;
										};

parameters: /*'(' [varargslist] ')'*/
	OPENPAR CLOSEPAR 				{
										// cout << "OPENPAR CLOSEPAR" << endl;
										Node *argsn = asTree->bArgsNode();
										// argsn->accept(*visitor); cout << endl;
										$$ = argsn;
									}
	| OPENPAR varargslist CLOSEPAR 	{
										// cout << "OPENPAR varargslist CLOSEPAR" << endl;
										if ($2 != NULL)
										{
											Node* node = $2;
											// node->accept(*visitor); cout << endl;
											$$ = $2;
										}
									};

varargslist: /* (NAME (',' NAME)*) */
	NAME args_kleene	{
							// cout << "NAME args_kleene" << endl;
							/* FIXED: Bison recibe el NAME extrañamente */
							string name ($1);
							name = name.substr(0, name.find_first_of(' '));
							Node *identn = asTree->bIdentNode(&name);
							// identn->accept(*visitor); cout << endl;
							if ($2 != NULL)
							{
								Node *argsn = $2;
								argsn->addFChild(identn);
								// argsn->accept(*visitor); cout << endl;
								$$ = argsn;
							}
						};

args_kleene: /* (',' NAME)* */
	args_kleene COMMA NAME 	{
								// cout << "args_kleene COMMA NAME" << endl;
								Node *identn = asTree->bIdentNode(new string($3));
								// identn->accept(*visitor); cout << endl;
								Node *argsn = $1;
								argsn->addLChild(identn);
								// argsn->accept(*visitor); cout << endl;
								$$ = argsn;
							}
	| epsilon				{
								// cout << "args_kleene epsilon" << endl;
								Node *argsn = asTree->bArgsNode();
								// argsn->accept(*visitor); cout << endl;
								$$ = argsn;
							};
%%
