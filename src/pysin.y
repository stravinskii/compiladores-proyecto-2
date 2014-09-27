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

if_stmt: 'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite];

while_stmt: 'while' test ':' suite ['else' ':' suite];

for_stmt: 'for' exprlist 'in' testlist ':' suite ['else' ':' suite];

/* Quizás estaría bien eliminar with de la gramática */
with_stmt: 'with' with_item (',' with_item)*  ':' suite
with_item: test ['as' expr]

suite: simple_stmt; 
	| NEWLINE INDENT stmt+ DEDENT;

simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE;

small_stmt: expr_stmt; 
			| print_stmt;  
			| del_stmt;
			| pass_stmt; 
			| flow_stmt;
			| global_stmt; 
			| exec_stmt;

expr_stmt: testlist (augassign testlist | ('=' testlist)*);

augassign: ('+=' | '-=' | '*=' | '/=' | '%=' | '&=' | '|=' | '^=' | '<<=' | '>>=' | '**=' | '//=');

print_stmt: 'print' ( [ test (',' test)* [','] ] | '>>' test [ (',' test)+ [','] ] );

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: 'del' exprlist;

pass_stmt: 'pass';

flow_stmt: break_stmt;
		| continue_stmt; 
		| return_stmt; 
		| raise_stmt;

break_stmt: 'break';
continue_stmt: 'continue';
return_stmt: 'return' [testlist];

/* raise me parece innecesario */
raise_stmt: 'raise' [test [',' test [',' test]]]

/* global me parece innecesario pero en tema de registros plantea algo importante */
global_stmt: 'global' NAME (',' NAME)*;

/* exec me parece innecesario */
exec_stmt: 'exec' expr ['in' test [',' test]];

funcdef: 'def' NAME parameters ':' suite;
parameters: '(' [varargslist] ')';
varargslist: ((fpdef ['=' test] ',')*('*' NAME [',' '**' NAME] | '**' NAME) |
              fpdef ['=' test] (',' fpdef ['=' test])* [','])
fpdef: NAME | '(' fplist ')'
fplist: fpdef (',' fpdef)* [',']

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
