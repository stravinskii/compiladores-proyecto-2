%{
#include <stdio.h>
#include <stdlib.h>
int yylex(); 
int yyerror(const char *s) { printf ("Error: %s\n", s); }
int seguir=1;
%}
/*Aquí van las uniones*/
%union Data {
	int entero;
	float flotante;
	double doble;
	char caracter;
	char* identificador;
	char* cadena;
}

/*Aquí van los tokens*/
%token	<doble> NUMBER
%token	<cadena> STRING KEYWORD OPERATOR DELIMITER
%token	<identificador>	ID
%token DEDENT INDENT NEWLINE

/*Aquí van los tipos*/
%type 	<doble> term fact exp goal


%%
/*Aquí va la gramática*/

/* Expresiones aritméticas */
testlist: test (',' test)* [','];
test: or_test ['if' or_test 'else' test];
or_test: and_test ('or' and_test)*;
and_test: not_test ('and' not_test)*;
not_test: 'not' not_test 
		| comparison;
comparison: expr (comp_op expr)*;
comp_op: '<';
		| '>';
		| '==';
		| '>=';
		| '<=';
		| '<>';
		| '!=';
		| 'in';
		| 'not' 'in';
		| 'is';
		| 'is' 'not';
expr: xor_expr ('|' xor_expr)*;
xor_expr: and_expr ('^' and_expr)*;
and_expr: shift_expr ('&' shift_expr)*;
shift_expr: arith_expr (('<<'|'>>') arith_expr)*;

arithmetic_expr: term ('+' term)*;
				| term ('-' term)*;

term: factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;

factor: '+' factor;
		| '-' factor;
		| '~' factor;
		| power;

power: atom trailer* ['**' factor];

trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME;

atom: NAME;
	| NUMBER;
	| STRING+;

listmaker: 	test list_for;
		| (',' test)* [','];
		
single_input: NEWLINE;
			| simple_stmt;
			| compound_stmt NEWLINE;

file_input: NEWLINE* ENDMAKER;
			|stmt* ENDMARKER;

eval_input: testlist NEWLINE* ENDMARKER;

/* Condicionales */

compound_stmt: if_stmt;
			 | while_stmt;
			 | for_stmt;
			 | with_stmt;
			 | funcdef;

if_stmt: 'if' test ':' suite if_stmt_elif if_stmt_else;
if_stmt_elif: if_stmt_elif;
			| 'elif' test ':' suite;
			| epsilon;
if_stmt_else: 'else' ':' suite;
			| epsilon;

while_stmt: 'while' test ':' suite while_stmt_else; 
while_stmt_else: 'else' ':' suite;
				| epsilon;

for_stmt: 'for' exprlist 'in' testlist ':' suite for_stmt_else; 
for_stmt_else: 'else' ':' suite;
				| epsilon;

/* Quizás estaría bien eliminar with de la gramática */
with_stmt: 'with' with_item (',' with_item)*  ':' suite
with_item: test ['as' expr]

suite: simple_stmt; 
		| NEWLINE INDENT suite_stmt DEDENT;
suite_stmt:	stmt;
		| more_stmt;
more_stmt: stmt more_stmt;
		| epsilon;

simple_stmt: small_stmt more_simple_stmt end_simple_stmt NEWLINE;

more_simple_stmt: ';' small_stmt;
				| epsilon; 
end_simple_stmt: ';';
				| epsilon;

small_stmt: expr_stmt; 
			| print_stmt;
			| del_stmt;
			| pass_stmt;
			| flow_stmt;
			| global_stmt;
			| exec_stmt;

expr_stmt: testlist expr_stmt_at;
expr_stmt_at: augassign testlist;
			| more_testlist;
more_testlist: '=' testlist more_testlist;
				| '=' testlist;
				| epsilon; 

augassign: '+=';
		| '-=';
		| '*=';
		| '/=';
		| '%=';
		| '&=';
		| '|=';
		| '^=';
		| '<<=';
		| '>>=';
		| '**=';
		| '//=';

print_stmt: 'print' print_stmt_next 
print_stmt_next: print_stmt_test
				| '>>' test [ (',' test)+ print_stmt_test_last ];

print_stmt_second: more_test print_stmt_test_last;
more_test: ',' test;
		| ',' test more_test;

print_stmt_test: test print_stmt_more_test print_stmt_test_last;
				| epsilon;
print_stmt_more_test: ',' test print_stmt_more_test;
					| epsilon;
print_stmt_test_last: ';';
					| epsilon;

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: 'del' exprlist;

pass_stmt: 'pass';

flow_stmt: break_stmt;
		| continue_stmt; 
		| return_stmt; 
		| raise_stmt;

break_stmt: 'break';
continue_stmt: 'continue';
return_stmt: 'return' return_stmt_tl;
return_stmt_tl: testlist;
				| epsilon;

/* raise me parece innecesario */
/* raise_stmt: 'raise' [test [',' test [',' test]]]; */

/* exec me parece innecesario */
/* exec_stmt: 'exec' expr ['in' test [',' test]]; *?

/* global me parece innecesario pero en tema de registros plantea algo importante */
global_stmt: 'global' NAME global_stmt_name;
global_stmt_name: ',' NAME global_stmt_name;
				| epsilon;

/* Funciones */

funcdef: 'def' NAME parameters ':' suite;
parameters: '(' varargslist ')';
varargslist: args_first args_first_next;
			| fpdef args_def args_def_more ',';
			| fpdef args_def args_def_more;
			| epsilon;

args_first: fpdef ['=' test] ',' args_first;
			| epsilon;

args_first_next: '*' NAME args_name;
				| '**' NAME;

args_name: ',' '**' NAME;
		| epsilon;

args_def: '=' test;
		| epsilon;

args_def_more: ',' fpdef args_def args_def_more;
			| epsilon;

fpdef: NAME;
	| '(' fplist ')';

fplist: fpdef fpdef_more ',';
		| fpdef fpdef_more;
fpdef_more: ',' fpdef fpdef_more;
			| epsilon;

%%

int main()
{
	while(seguir)
	{
		printf(">> ");
		yyparse();
	}
	return 0;
}
