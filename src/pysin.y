%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../lib/MAST.hpp"
#include <string>


using namespace std;
#define YYDEBUG 1
int yylex(); 
int yyerror(const char *s) { printf ("\nError: %s\n", s); }

extern "C" FILE *yyin;


//SymbolTable *st = new SymbolTable();
MAST *asTree = new MAST();
VisitorNode *visitor = new VisitorNode;

%}

%code requires{
#include "../lib/Nodos.hpp"

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
				// Node *sstmtln = asTree->bSStmtListNode();
				// sstmtln->addFChild($1);
				// $$ = sstmtln;
				Node* node = $1;
				// node->accept(*visitor);
				cout<<"\nCOMPILATION COMPLETE :)\n";
			};

/*  FIXTHIS: stmt es (simple_stmt | compound_stmt)	donde simple_stmt es un SStmtListNode. ¿Debería suponer que stmt es una lista? */
filein: /* (filein (NEWLINE | stmt))* */
	epsilon				{cout << "filein epsilon..." << endl;}
	| filein NEWLINE	{
							cout << "filein newline" << endl;
							$$ = $1;
						}
	| filein stmt 		{
							cout << "filein stmt" << endl;
							if ($2 != NULL)
							{
								Node *stmtln = $2;
								stmtln->addFChild($1);
								$$ = stmtln;
							}
						};
	
/*Aquí va la gramática*/

epsilon: 	{/*Nada xD*/};

test: /* or_test ['if' or_test 'else' test] */
	or_test							{$$ = $1;}
	| or_test IF or_test ELSE test	{cout<<"IF __ ELSE __ ";};

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
	epsilon
	| or_andtest OR and_test	{
									Node *orn = asTree->bOrNode();
									orn->setSChild($3);
									$$ = orn;
									cout<<"OR";
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
	epsilon
	| and_nottest AND not_test	{
									Node *andn = asTree->bAndNode();
									andn->setSChild($3);
									$$ = andn;
									cout<<"AND";
								};
		
not_test: /* 'not' not_test | comparison*/
	NOT not_test	{
						Node *notn = asTree->bNotNode();
						notn->setFChild($2);
						$$ = notn;
						cout<<"NOT";
					}
	| comparison	{$$ = $1;};

		
comparison: /* expr (comp_op expr)* */
	expr comp_op_expr_kleene 	{
									if ($2 != NULL)
									{
										Node *compn = $2;
										compn->setFChild($1);
										$$ = compn;
									} else {
										$$ = $1;
									}
								};

comp_op_expr_kleene: /* (comp_op expr)* */
	comp_op_expr_kleene comp_op expr 	{
											Node *compn = $2;
											compn->setSChild($3);
											$$ = compn;
										}
	| epsilon;
	
comp_op: /* ('<' | '>' | '==' | '>=' | '<=' | '<>' | '!=' | 'in' | 'not' 'in' | 'is' | 'is' 'not') */
	LESSTHAN			{
							Node *compn = asTree->bLTNode();
							$$ = compn;
							cout<<"<";
						}
	| MORETHAN			{
							Node *compn = asTree->bGTNode();
							$$ = compn;
							cout<<">";
						}
	| EQUALS			{
							Node *compn = asTree->bEqNode();
							$$ = compn;
							cout<<"==";
						}
	| MOREEQUAL			{
							Node *compn = asTree->bGTEqNode();
							$$ = compn;
							cout<<">=";
						}
	| LESSEQUAL			{
							Node *compn = asTree->bLTEqNode();
							$$ = compn;
							cout<<"<=";
						}
	| DIFFERENT			{
							Node *compn = asTree->bNEqNode();
							$$ = compn;
							cout<<"!=";
						}
	| PICOPARENTESIS		{cout<<"<>";}
	| IN					{cout<<"IN";}
	| NOT IN				{cout<<"NOT IN";}
	| IS					{cout<<"IS";}
	| IS NOT				{cout<<"IS NOT";};


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
	epsilon
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
	epsilon
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
	epsilon
	| andpandshift_expr ANDPAND shift_expr 	{
												Node *andn = asTree->bAndNode();
												andn->setFChild($1);
												andn->setSChild($3);
												$$ = andn;
											};

shift_expr: /* arith_expr (('<<'|'>>') arith_expr)* */
	arithmetic_expr leftright_shift_expr 	{$$ = $1;};

leftright_shift_expr: /* (('>>' | '<<') arithmetic_expr)* */
	epsilon
	| leftright_shift_expr BINRIGHT arithmetic_expr {$$ = $3; cout<<">>";}
	| leftright_shift_expr BINLEFT arithmetic_expr	{$$ = $3; cout<<"<<";};

arithmetic_expr: /* term ('+' term)* | term ('-' term)* */
	term sign_term	{
						cout << "term sign_term" << endl;
						if ($2 != NULL)
						{
							Node *termn = $2;
							cout << "I'M RIGHT HERE 2!" << endl;
							termn->setFChild($1);
							$$ = termn;
						} else {
							$$ = $1;
						}
					};

sign_term: /* (('+' | '-') term)* */
	epsilon
	| sign_term MAS term		{
									Node *plusn = asTree->bPlusNode();
									plusn->setFChild($1);
									plusn->setSChild($3);
									$$ = plusn;
									cout<<"Suma";
								}

	| sign_term MENOS term		{
									Node *minusn = asTree->bMinusNode();
									minusn->setFChild($1);
									minusn->setSChild($3);
									$$ = minusn;
									cout<<"Resta";
								};

term: /* (factor ('*'factor)* | factor ('/'factor)* | factor ('%' factor)* | factor ("//" factor)*) */
	factor factor_operation		{
									cout << "factor factor_operation" << endl;
									if ($2 != NULL)
									{
										Node* factorn = $2;
										factorn->setFChild($1);
										$$ = factorn;
									} else {
										$$ = $1;
									}
								};
	
factor_operation: /* (('*' | '/' | '%') factor)* */
	epsilon 								{$$=NULL;}
	| factor_operation POR factor 			{
												Node *multn = asTree->bMultNode();
												multn->setFChild($1);
												multn->setSChild($3);
												$$ = multn;
												cout<<"Multiplicacion"<<endl;
											}
	| factor_operation ENTRE factor 		{
												Node *divn = asTree->bDiviNode();
												divn->setFChild($1);
												divn->setSChild($3);
												$$ = divn;
												cout<<"Division"<<endl;
											}
	| factor_operation MOD factor 			{
												cout<<"Modulo"<<endl;
											}
	| factor_operation DIV factor 			{
												Node *divn = asTree->bDiviNode();
												divn->setFChild($1);
												divn->setSChild($3);
												$$ = divn;
												cout<<"Division Entera"<<endl;
											};

factor: /* (('+' | '-' | '~') factor | power) */
	MAS factor			{
							Node *plusn = asTree->bPlusNode();
							plusn->setSChild($2);
							$$ = plusn;
							cout<<"SUMA"<<endl;
						}
	| MENOS factor		{
							Node *minusn = asTree->bMinusNode();
							minusn->setSChild($2);
							$$ = minusn;
							cout<<"RESTA"<<endl;
						}
	| TILDE factor 		{$$ = $2;}
	| power 			{$$ = $1;cout<<"power"<<endl;};

power: /* atom trailer* ['**' factor] */
	atom trailer_kleene					{$$ = $1;cout << "atom trailer_kleene" << endl; 
											/*
											if ($1 != NULL)
											{
												cout << "$1 IS NOT NULL" << endl;
												StrNode* strn = dynamic_cast<StrNode*> ($1);
												if (strn!=0)
												{
													cout << "cast done "<< endl;
													//strn->accept(*visitor);
												} else {
													cout << "couldnt cast "<< endl;
												}
											} else {
												cout << "$1 IS NULL!!!!!" << endl;
											}
											*/
										}
	| atom trailer_kleene POT factor		{$$ = $1;cout << "atom trailer_kleene POT factor" << endl;};

trailer_kleene: /* trailer* */
	epsilon					{cout << "epsilon trailer_kleene" << endl;}
	|trailer_kleene trailer {cout << "trailer_kleene trailer" << endl;};

/* FIXTHIS: Falta ver el soporte de esto */	
trailer: /* '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME */
	OPENPAR CLOSEPAR					{cout<<"()"<<endl;}
	| OPENPAR arglist CLOSEPAR			{$$ = $2; cout<<"(ARGLIST)"<<endl;}
	| OPENCOR subscriptlist CLOSECOR	{$$ = $2; cout<<"(SUBSCRIPTLIST)"<<endl;}
	| DOT NAME							{
											cout<<".NAME"<<endl;
											string* id = new string($2);
											Node *identn = asTree->bIdentNode(id);
											$$=identn; 
										};
		
arglist: /* (argument ',')* (argument [','] |'*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument_comma argument_multiple 	{
											if ($1 != NULL)
											{
												Node *argsn = $1;
												argsn->addLChild($2);
												$$ = argsn;
											}
										};
	
argument_comma: /* (argument ',')* */
	epsilon								{
											Node *argsn = asTree->bArgsNode();
											$$ = argsn;
										}
	| argument_comma argument COMMA 	{
											if ($1 != NULL)
											{
												Node *argsn = $1;
												argsn->addLChild($2);
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
									$$ = exprln;
								}
							}
	| expr expr_kleene 		{
								if ($2 != NULL)
								{
									Node* exprln = $2;
									exprln->addFChild($1);
									$$ = exprln;
								}
							};

expr_kleene: /* (',' expr)* */
	expr_kleene COMMA expr 	{
								if ($1 != NULL)
								{
									Node* exprln = $1;
									exprln->addLChild($3);
									$$ = exprln;
								}
							}
	| epsilon 				{
								Node* exprln = asTree->bArgsNode();
								$$ = exprln;
							};

/* FIXTHIS: No entiendo que es ('`' testlist1 '`') */
atom: /* ( '(' [testlist_comp] ')' | '[' [listmaker] ']' |  '`' testlist1 '`' | NAME | NUMBER | STRING+ ) */
	OPENPAR CLOSEPAR					{$$ = NULL;}
	| OPENPAR testlist_comp CLOSEPAR	{$$ = $2;}
	| OPENCOR CLOSECOR					{$$ = NULL;}
	| OPENCOR listmaker CLOSECOR		{$$ = $2;}
	| APOSTROFE testlist1 APOSTROFE		{$$ = $2;}
	| string_plus						{$$ = $1;}
	| boolean							{$$ = $1;}
	| NONE								{$$ = NULL;}
	| NAME			{
						cout << ";;;" << $1 << ";;;" << endl;
						string* id = new string($1);
						Node *identn = asTree->bIdentNode(id);
						identn->accept(*visitor);
						$$=identn;
					}
	| FLOATNUMBER	{
						Node *floatn = asTree->bFloatNode($1);
						$$=floatn;
					}
	| INTEGER		{
						Node *intn = asTree->bIntNode($1);
						$$=intn;
						intn->accept(*visitor);
					};
	
boolean: /* (TRUE | FALSE) */
	TRUE 	{
				Node *booln = asTree->bBoolNode(true);
				$$ = booln;
			} 
	| FALSE {
				Node *booln = asTree->bBoolNode(false);
				$$ = booln;
			};

testlist1: /* test (',' test)* */
	test comma_test_kleene 	{$$ = $1;};
	
string_plus: /* (STRING)+ */
	STRING						{
									cout << ":::" << $1 << ":::" << endl;
									string* str = new string($1);
									Node *strn = asTree->bStrNode(str);
									strn->accept(*visitor);
								}
	| STRING string_plus		{$$ = $2; cout << "not here please......" << endl;};

/* FIXTHIS: No hay soporte para listas aún */
listmaker: 	/* test (',' test)* */
	test comma_test_kleene 	{$$ = $1;};
		
testlist_comp: /* test ( comp_for | (',' test)* [','] ) */
	test comma_test_kleene comma_one 	{$$ = $1;};

compound_stmt: /* (if_stmt | while_stmt | for_stmt | funcdef) --deprecated: classdef */
	if_stmt			{$$ = $1;}
	| while_stmt	{$$ = $1;}
	| for_stmt		{$$ = $1;}
	| funcdef		{$$ = $1;};

if_stmt: /* 'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite] */
	IF test TWODOTS suite elif_test_td_suite_kleene ELSE TWODOTS suite 	{
																			cout << "if _ : _ else : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild($2);
																			ifn->addLChild($4);
																			ifn->addLChild($5);
																			ifn->addLChild($8);
																			$$ = ifn;
																		}
	| IF test TWODOTS suite elif_test_td_suite_kleene 					{
																			cout << "if _ : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild($2);
																			ifn->addLChild($4);
																			ifn->addLChild($5);
																			$$ = ifn;
																		};
	
elif_test_td_suite_kleene: /* ('elif' test ':' suite)* */
	epsilon
	| elif_test_td_suite_kleene ELIF test TWODOTS suite {
															cout << "elif _ : _" << endl;
															Node *ifn = asTree->bIfNode();
															ifn->addFChild($3);
															ifn->addLChild($5);
															ifn->addLChild($1);
															$$ = ifn;
														};

while_stmt: /* 'while' test ':' suite ['else' ':' suite] */
	WHILE test TWODOTS suite ELSE TWODOTS suite 	{
														cout << "while _ : _ else : _" << endl;
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild($2);
														whilen->addLChild($4);
														whilen->addLChild($7);
														$$ = whilen;
													}
	| WHILE test TWODOTS suite						{
														cout << "while _ : _" << endl;
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild($2);
														whilen->addLChild($4);
														$$ = whilen;
													};

for_stmt: /* 'for' exprlist 'in' testlist ':' suite ['else' ':' suite] */
	FOR exprlist IN testlist TWODOTS suite ELSE TWODOTS suite 	{
																	cout << "for _ in _ : _ else : _" << endl;
																	Node *forn = asTree->bForNode();
																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	forn->addLChild($6);
																	forn->addLChild($9);
																	$$ = forn;
																}
	| FOR exprlist IN testlist TWODOTS suite					{
																	cout << "for _ in _ : _" << endl;
																	Node *forn = asTree->bForNode();
																	forn->addFChild($2);
																	forn->addLChild($4);
																	forn->addLChild($6);
																	$$ = forn;
																};

suite: /* simple_stmt | NEWLINE INDENT stmt+ DEDENT */
	simple_stmt 						{
											Node *stmtln = asTree->bStmtListNode();
											stmtln->addFChild($1);
											$$ = stmtln;
										}
	| NEWLINE INDENT stmt_plus DEDENT	{$$ = $3;};
		
stmt_plus: /* (stmt)+ */
	stmt_plus stmt 	{
						if ($1 != NULL)
						{
							Node *stmtln = $1;
							stmtln->addLChild($2);
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
						$$ = stmtln;
					};

stmt: /* (simple_stmt | compound_stmt) */
	simple_stmt 		{$$ = $1;}
	| compound_stmt 	{$$ = $1;};
	
simple_stmt: /* small_stmt (';' small_stmt)* [';'] NEWLINE */
	small_stmt small_stmt_kleene DOTCOMMA NEWLINE	{
														if ($2 != NULL)
														{
															Node* sstmtln = $2;
															sstmtln->addFChild($1);
															$$ = sstmtln;
														}
													}

	| small_stmt small_stmt_kleene NEWLINE			{
														if ($2 == NULL)
														{
															Node* sstmtln = $2;
															sstmtln->addFChild($1);
															$$ = sstmtln;
														}
													};

small_stmt_kleene: /* (';' small_tmt)* */
		small_stmt_kleene DOTCOMMA small_stmt 	{
													if ($1 != NULL)
													{
														Node* sstmtln = $1;
														sstmtln->addLChild($3);
														$$ = sstmtln;
													}
												}
		| epsilon 								{
													Node* sstmtln = asTree->bSStmtListNode();
													// $$ = sstmtln;
												};
				
small_stmt: /* (expr_stmt | print_stmt | flow_stmt) */
	expr_stmt  		{
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild($1);
						$$ = sstmtn;
					}
	| print_stmt 	{
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild($1);
						$$ = sstmtn;
					}
	| flow_stmt 	{
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild($1);
						$$ = sstmtn;
					};

/* FIXTHIS: Ver comentario de assing_testlist_kleene */
expr_stmt: /*testlist (augassign testlist | ('=' testlist)*) */
	testlist expr_stmt_at 	{
								AssignNode* assignn = dynamic_cast<AssignNode*> ($2);
								if (assignn != 0)
								{
									Node* assignn = $2;
									assignn->setFChild($1);
									$$ = assignn;
								} else {
									Node* augassign = $2;
									augassign->setFChild($1);

									Node* assignn = asTree->bAssignNode();
									assignn->setFChild($1);
									assignn->setSChild(augassign);
									$$ = assignn;
								}
							};

/* FIXTHIS: Ver comentario de assing_testlist_kleene */
expr_stmt_at: /* (augassign testlist | ('=' testlist)*) */
		augassign testlist 			{
										if ($1 != NULL)
										{
											Node* assignn = $1;
											assignn->setSChild($2);
											$$ = assignn;
										}
									}
		/*| assign_testlist_kleene 	{$$ = $1;};*/
		| ASSIGN testlist 			{
										cout<<"="<<endl;
										Node* assignn = asTree->bAssignNode();
										// Node* intn = asTree->bIntNode(22);
										// assignn->setSChild(intn);
										ArgsNode* exprn = dynamic_cast<ArgsNode*> ($2);
										if (exprn != 0)
										{
											// Node* intn = asTree->bIntNode(22);
											// assignn->setSChild(intn);
											assignn->setSChild($2);
											cout << "Its an expression node!!!!" << endl;
										} else {
											cout << "Its not an expression node" << endl;
										}
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
						cout<<"+=";
						Node* assignn = asTree->bPlusNode();
						$$ = assignn;
					}
	| MENOSIGUAL	{
						cout<<"-=";
						Node* assignn = asTree->bMinusNode();
						$$ = assignn;
					}
	| PORIGUAL		{
						cout<<"*=";
						Node* assignn = asTree->bMultNode();
						$$ = assignn;
					}
	| ENTREIGUAL	{
						cout<<"/=";
						Node* assignn = asTree->bDiviNode();
						$$ = assignn;
					};
	
print_stmt: /* 'print' [test (',' test)*] */
	PRINT print_args 	{
							cout << "print" << endl;
							Node *printn = asTree->bPrintNode();
							if ($2 != NULL)
							{
								printn->addFChild($2);
								$$ = printn;
							}
						};
	
print_args: /* [test (',' test)*] */
	epsilon						{
									Node *argsn = asTree->bArgsNode();
									$$ = argsn;
								}
	| test comma_test_kleene 	{
									Node *exprn = asTree->bExprNode();
									exprn->addFChild($1);
									if ($2 != NULL)
									{
										Node *argsn = $2;
										argsn->addFChild(exprn);
										$$ = argsn;
									}
								};

comma_test_kleene: /* (',' test)* */
	epsilon							{
										Node *argsn = asTree->bArgsNode();
										$$ = argsn;
									}
	| comma_test_kleene COMMA test	{
										Node* exprn = asTree->bExprNode();
										exprn->addFChild($3);
										if ($1 != NULL)
										{
											Node *argsn = $1;
											argsn->addLChild(exprn);
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
											if ($2 != NULL)
											{
												Node* argsn = $2;
												argsn->addFChild(exprn);
												$$ = argsn;
												cout << "comma_test_kleene was not null" << endl;
											} else {
												cout << "comma_test_kleene was null!!!" << endl;
											}
										};

/* FIXED: 
	- ¿Estos deberían de estar encapsuladas en un nodo stmt?
	- NO, se encapsulan más arriba a un SStmtNode
*/
flow_stmt: /* break_stmt | continue_stmt | return_stmt */
	break_stmt 			{$$ = $1;}
	| continue_stmt 	{$$ = $1;}
	| return_stmt 		{$$ = $1;}; 

break_stmt: /* 'break' */
	BREAK 	{Node* breakn = asTree->bBreakNode(); $$ = breakn;};

continue_stmt: /* 'continue' */
	CONTINUE 	{Node* contn = asTree->bContinueNode(); $$ = contn;};

return_stmt: /* 'return' [testlist] */
	RETURN testlist	{
						cout << "return __" << endl;
						Node* returnn = asTree->bReturnNode();
						returnn->addFChild($2);
						$$ = returnn;
					}
	| RETURN		{
						cout << "return" << endl;
						Node* returnn = asTree->bReturnNode(); 
						$$ = returnn;
					};

/* Funciones */
funcdef: /*'def' NAME parameters ':' suite*/
	DEF NAME parameters TWODOTS suite	{
											cout << "def name(_):\n" << endl;
											Node *funcn = asTree->bFuncNode();
											string* id = new string($2);
											Node *identn = asTree->bIdentNode(id);
											funcn->addFChild(identn);
											funcn->addLChild($3);
											funcn->addLChild($5);
											$$ = funcn;
										};

parameters: /*'(' [varargslist] ')'*/
	OPENPAR CLOSEPAR 				{
										Node *argsn = asTree->bArgsNode();
										$$ = argsn;
									}
	| OPENPAR varargslist CLOSEPAR 	{
										if ($2 != NULL)
										{
											$$ = $2;
										}
									};

varargslist: /* (NAME (',' NAME)*) */
	NAME args_kleene	{
							string* id = new string($1);
							Node *identn = asTree->bIdentNode(id);
							if ($2 != NULL)
							{
								Node *argsn = $2;
								argsn->addFChild(identn);
								$$ = argsn;
							}
						};
args_kleene: /* (',' NAME)* */
	args_kleene COMMA NAME 	{
								string* id = new string($3);
								Node *identn = asTree->bIdentNode(id);
								Node *argsn = $1;
								argsn->addLChild(identn);
								$$ = argsn;
							}
	| epsilon				{
								Node *argsn = asTree->bArgsNode();
								$$ = argsn;
							};
%%
