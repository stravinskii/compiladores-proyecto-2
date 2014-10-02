%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define YYDEBUG 1
using namespace std;

int yylex(); 
int yyerror(const char *s) { printf ("Error: %s\n", s); }

extern "C" FILE *yyin;

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
%token	STRING MAS MENOS POR ENTRE MOD DIV POT FALSE CLASS FINALLY IS RETURN NONE CONTINUE FOR LAMBDA TRY TRUE DEF FROM WHILE AND DEL NOT WITH AS ELIF IF OR ELSE IMPORT PASS BREAK EXCEPT IN PRINT COMMA DOT ASSIGN TWODOTS DOTCOMMA BINLEFT  BINRIGHT ANDPAND PIPE EXP TILDE LESSTHAN MORETHAN LESSEQUAL MOREEQUAL EQUALS DIFFERENT PICOPARENTESIS OPENPAR CLOSEPAR OPENCOR CLOSECOR OPENKEY CLOSEKEY AT RIGHT MASIGUAL MENOSIGUAL PORIGUAL ENTREIGUAL DIVIGUAL MODIGUAL ANDIGUAL ORIGUAL EXPIGUAL BINRIGHTIGUAL BINLEFTIGUAL POTIGUAL GLOBAL APOSTROFE
%token	<identificador>	NAME
%token DEDENT INDENT NEWLINE

/*Aquí van los tipos*/
/*%type <double> */


%%
goal:	file_input
	|eval_input
	|single_input;

file_input: /*NEWLINE* ENDMAKER;
			|stmt* ENDMARKER;*/
	newline_kleene /*ENDMARKER*/			{}
	|stmt_kleene /*ENDMARKER*/			{};
	
eval_input: /*testlist NEWLINE* ENDMARKER;*/
	testlist newline_kleene /*ENDMARKER*/		{};

single_input: NEWLINE					{}
	| simple_stmt					{}
	| compound_stmt NEWLINE				{};
	
	
/*Aquí va la gramática*/

/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

test:/*or_test ['if' or_test 'else' test] */
	or_test					{}
	|or_test IF or_test ELSE test		{};	
	
old_test: or_test;

or_test: 	/*and_test (OR and_test)*			{};*/
		and_test or_andtest			{};
		
or_andtest:	epsilon					{}
		|OR and_test or_andtest			{};
		
and_test: 	/*not_test (AND not_test)*		{};*/
		not_test and_nottest			{};
		
and_nottest:	epsilon					{}
		|AND not_test and_nottest		{};
		
not_test: 	NOT not_test				{}
		|comparison				{};

		
comparison: /*expr (comp_op expr)*			{};*/
	expr comp_op_expr				{};
		
comp_op_expr:	epsilon					{}
	|comp_op expr comp_op_expr		{};
		
comp_op: LESSTHAN
	|MORETHAN
	|EQUALS
	|MOREEQUAL
	|LESSEQUAL
	|PICOPARENTESIS
	|DIFFERENT
	|IN				{}
	|NOT IN				{}
	|IS				{}
	|IS NOT				{};

expr: /*xor_expr ('|' xor_expr)*				{};*/
	xor_expr pipexor_expr				{};
	
pipexor_expr: 	epsilon					{}
	|PIPE xor_expr;
		
xor_expr: /*and_expr ('^' and_expr)*			{};*/
	and_expr andxor_expr				{};

andxor_expr: 	epsilon					{}
	|EXP and_expr;
		
and_expr: /*shift_expr ('&' shift_expr)*			{};*/
	shift_expr andpandshift_expr			{};
	

andpandshift_expr: epsilon				{}
	|ANDPAND shift_expr;

shift_expr: /*arith_expr (('<<'|'>>') arith_expr)*	{};*/
	arithmetic_expr leftright_shift_expr			{};

leftright_shift_expr: epsilon				{}
	|BINRIGHT arithmetic_expr leftright_shift_expr
	|BINLEFT arithmetic_expr leftright_shift_expr;

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term					{cout<<"Expr arit\n";};

sign_term: epsilon					{}
	|MAS term sign_term				{}
	|MENOS term sign_term				{};

term: /*factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;*/
	factor factor_operation				{};
	
factor_operation: epsilon				{}
	|POR factor factor_operation			{}
	|ENTRE factor factor_operation			{}
	|MOD factor factor_operation			{}
	|DIV factor factor_operation			{};

factor: /*'+' factor;
	| '-' factor;
	| '~' factor;
	| power;*/
	MAS factor					{}
	|MENOS factor					{}
	|TILDE factor				
	|power;		

power: /*atom trailer* ['**' factor];*/
	atom trailer_kleene				{}
	|atom trailer_kleene POT factor			{};

trailer_kleene: epsilon					{}
	|trailer trailer_kleene				{};
	
trailer: OPENPAR CLOSEPAR
	|OPENPAR arglist CLOSEPAR	
	|OPENCOR subscriptlist CLOSECOR
	|DOT NAME					{};
		
arglist: /*(argument ',')* (argument [','] |'*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument_comma argument_multiple;
	
argument_comma: epsilon
	|argument COMMA argument_comma;
	
argument_multiple: argument COMMA
	|argument
	|POR test comma_argument
	|POR test comma_argument COMMA POT test
	|POT test;
	
comma_argument: epsilon
	|COMMA argument comma_argument;
	
argument: /*test [comp_for] | test '=' test*/
	test comp_for
	|test
	|test ASSIGN test;
	
comp_for: FOR exprlist IN or_test comp_iter
	| FOR exprlist IN or_test;
	
comp_iter: comp_for 
	| comp_if;
	
comp_if: IF old_test
	|IF old_test comp_iter;	
		
subscriptlist: /*subscript (',' subscript)* [',']*/
	subscript comma_subscript
	|subscript comma_subscript COMMA;

comma_subscript: COMMA subscript comma_subscript
	|epsilon;
	
/* subscript: '.' '.' '.' | test | [test] ':' [test] [sliceop] */
subscript: DOT DOT DOT
	| test 
	| test TWODOTS test sliceop
	| test TWODOTS test
	| test TWODOTS
	| test TWODOTS sliceop
	| TWODOTS test sliceop
	| TWODOTS test
	| TWODOTS sliceop
	| TWODOTS;

sliceop: /*':' [test];*/
	TWODOTS test
	|TWODOTS;
	
exprlist: /*expr (',' expr)* [',']*/
	expr expr_kleene COMMA
	| expr expr_kleene;

expr_kleene: COMMA expr expr_kleene
	| epsilon;

atom:/* ('(' [yield_expr|testlist_comp] ')' | '[' [listmaker] ']' | '{' [dictorsetmaker] '}' |  '`' testlist1 '`' | NAME | NUMBER | STRING+)*/ 
	/*atom_help*/
	OPENPAR testlist_comp CLOSEPAR
	|OPENCOR listmaker CLOSECOR
	|APOSTROFE testlist1 APOSTROFE
	|NAME
	|NUMBER
	|string_plus;

testlist1: test comma_test;
	
string_plus: 
	STRING					{}
	|STRING string_plus;

/*LO QUE ESTA ARRIBA ES DE ARITHMETIC EXP*/
listmaker: 	/*test ( list_for | (',' test)* [','] )*/
		test list_for				{}		
		|test comma_test comma_one			{};
		
		
testlist_comp: test 
	|comp_for
	|comma_test comma_one;
		
list_for: FOR exprlist IN testlist_safe 
	|FOR exprlist IN testlist_safe list_iter;

comma_test:epsilon				{}
	|COMMA test comma_test			{};

list_iter: list_for 
	| list_if;

testlist_safe: /*old_test [(',' old_test)+ [',']];*/
	old_test
	|old_test COMMA old_test
	|old_test COMMA old_test COMMA;

list_if: IF old_test
	|IF old_test list_iter;
	
stmt_kleene:epsilon					{}
	|stmt stmt_kleene				{};
			
newline_kleene: epsilon					{}
	|NEWLINE newline_kleene				{};
	

compound_stmt: if_stmt
	| while_stmt
	| for_stmt
	| funcdef;

if_stmt: /*'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite]*/
	IF test TWODOTS suite elif_test_td_suite_kleene else_td_suite_one;
	
elif_test_td_suite_kleene: epsilon
	|ELIF test TWODOTS suite elif_test_td_suite_kleene;
	
else_td_suite_one: epsilon
	|ELSE TWODOTS suite;

while_stmt: WHILE test TWODOTS suite while_stmt_else ;

while_stmt_else: ELSE TWODOTS suite
	| epsilon;

for_stmt: FOR exprlist IN testlist TWODOTS suite for_stmt_else; 

for_stmt_else: ELSE TWODOTS suite
	| epsilon;

suite: simple_stmt
	| NEWLINE INDENT more_stmt DEDENT;
		
more_stmt: stmt more_stmt
	| epsilon;

stmt: simple_stmt 
	| compound_stmt;
	
simple_stmt: /*small_stmt (';' small_stmt)* [';'] NEWLINE */
	small_stmt more_simple_stmt end_simple_stmt;

small_stmt: expr_stmt
	| print_stmt
	| del_stmt
	| pass_stmt
	| flow_stmt
	| global_stmt;

more_simple_stmt: DOTCOMMA small_stmt more_simple_stmt
		| epsilon; 
				
end_simple_stmt: DOTCOMMA NEWLINE
		|NEWLINE;

expr_stmt: /*testlist (augassign (yield_expr|testlist) |('=' (yield_expr|testlist))*)*/
	testlist expr_stmt_at;

expr_stmt_at: augassign testlist
	|assign_testlist_kleene;

assign_testlist_kleene: ASSIGN testlist assign_testlist_kleene
	| epsilon; 

augassign: MASIGUAL
	|MENOSIGUAL
	|PORIGUAL
	|ENTREIGUAL
	|MODIGUAL
	|ANDIGUAL
	|ORIGUAL
	|EXPIGUAL
	|BINRIGHTIGUAL
	|BINLEFTIGUAL
	|POTIGUAL
	|DIVIGUAL;

print_stmt: /*'print' ( [ test (',' test)* [','] ] | '>>' test [ (',' test)+ [','] ] )*/
	PRINT print_stmt_next;

print_stmt_next: print_stmt1
	|print_stmt2
	;
	
print_stmt1: test comma_test_kleene comma_one;

comma_test_kleene: epsilon
	|COMMA test comma_test_kleene;

print_stmt2: BINRIGHT comma_test_plus comma_one;
	
comma_one: epsilon
	|COMMA;

comma_test_plus: COMMA test
	| COMMA test comma_test_plus;

	
testlist: /*test (',' test)* [','];*/
	test comma_test COMMA			{}
	|test comma_test			{};
	

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: DEL exprlist;

pass_stmt: PASS;

flow_stmt: break_stmt
	| continue_stmt
	| return_stmt; 

break_stmt: BREAK;

continue_stmt: CONTINUE;

return_stmt: RETURN testlist
	|RETURN;

/* global me parece innecesario pero en tema de registros plantea algo importante */
global_stmt: /*'global' NAME (',' NAME)* */
	GLOBAL NAME global_stmt_name;
	
global_stmt_name: COMMA NAME global_stmt_name
	| epsilon;

/* Funciones */

funcdef: DEF NAME parameters TWODOTS suite;

parameters: /*'(' varargslist ')';*/
		OPENPAR varargslist CLOSEPAR;
		
varargslist: /*
	  ((fpdef ['=' test] ',')* ('*' NAME [',' '**' NAME] | '**' NAME) | fpdef ['=' test] (',' fpdef ['=' test])* [',']) */
	a b
	|c
	|c COMMA;
	
a: fpdef COMMA a
	|fpdef EQUALS test COMMA a
	|epsilon;
	
b: POR NAME 
|POR NAME COMMA POT NAME
| POT NAME;
	
c: fpdef EQUALS test d
| fpdef d;

d: COMMA fpdef d
| COMMA fpdef EQUALS test d
|epsilon;
	
fpdef: NAME
	/*| '(' fplist ')';*/
	|OPENPAR fplist CLOSEPAR;

fplist: fpdef fpdef_more COMMA
	| fpdef fpdef_more;
	
fpdef_more: COMMA fpdef fpdef_more
	| epsilon;

%%


int main(int argc, char* argv[]) 
{
	/* Flex */
	// BEGIN(START);
	// stack.push(0);
	/* end Flex */
	
	if (argc > 1)
	{
		FILE *file =fopen(argv[1],"r");
		yyin = file;
	} 
	else
	{
		yyin = stdin;
	}

	do
	{
		yyparse();
	} 
	while (!feof(yyin));
}






