%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdio>
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
%token	STRING MAS MENOS POR ENTRE MOD DIV POT FALSE CLASS FINALLY IS RETURN NONE CONTINUE FOR LAMBDA TRY TRUE DEF FROM WHILE AND DEL NOT WITH AS ELIF IF OR ELSE IMPORT PASS BREAK EXCEPT IN PRINT COMMA DOT ASSIGN TWODOTS DOTCOMMA BINLEFT  BINRIGHT ANDPAND PIPE EXP TILDE LESSTHAN MORETHAN LESSEQUAL MOREEQUAL EQUALS DIFFERENT PICOPARENTESIS OPENPAR CLOSEPAR OPENCOR CLOSECOR OPENKEY CLOSEKEY AT RIGHT MASIGUAL MENOSIGUAL PORIGUAL ENTREIGUAL DIVIGUAL MODIGUAL ANDIGUAL ORIGUAL EXPIGUAL BINRIGHTIGUAL BINLEFTIGUAL POTIGUAL GLOBAL
%token	<identificador>	NAME
%token DEDENT INDENT NEWLINE 

/*Aquí van los tipos*/


%%
file_input: /*(NEWLINE | stmt)* ENDMARKER*/
	arithmetic_expr				{};
	
/*YA ESTAN EN EL GRANDE*/
/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

test:/*or_test ['if' or_test 'else' test] */
	or_test 				{}
	|or_test IF or_test ELSE test		{};	
	
old_test: or_test;
		
or_test: 	/*and_test (OR and_test)*		{};*/
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
		
comp_op: 	LESSTHAN
		|MORETHAN
		|EQUALS
		|MOREEQUAL
		|LESSEQUAL
		|PICOPARENTESIS
		|DIFFERENT
		| IN					{}
		| NOT IN				{}
		| IS					{}
		| IS NOT				{};
		
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
	|BINLEFT arithmetic_expr leftright_shift_expr;;

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term					{cout<<"Expresion artmetica\n";};
		
sign_term: epsilon					{}
	|MAS term sign_term				{cout<<"MAS term sig_term\n";}
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
	MAS factor					{cout<< "MAS factor";}
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
	NAME
	|NUMBER					{cout<<"NUMERO\n";}
	|string_plus;
	
string_plus: 
	STRING					{}
	|STRING string_plus;



%%


int main(int argc, char* argv[]) {
	if (argc > 1)
	{
		FILE *file =fopen(argv[1],"r");
		yyin=file;
	} 
	else
	{
		yyin = stdin;
	}
	do{
		yyparse();
	}while(!feof(yyin));
}

