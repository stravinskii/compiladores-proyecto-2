%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int yylex(); 
int yyerror(const char *s) { printf ("Error: %s\n", s); }
int seguir=1;

string checkStrings(string delimiter, string deseado[]){
	for(int i=0; i< deseado->length(); i++){
		if (delimiter.compare(deseado[i])==0)
			return *deseado;
	}
	yyerror("de sintaxis, babuino");
}

string checkString(string delimiter, string deseado){
	if(delimiter.compare(deseado)==0)
		return deseado;
	else
		yyerror("de sintaxis, babuino");
}


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
%token	<cadena> STRING MAS MENOS POR ENTRE MOD DIV POT OPERATOR DELIMITER FALSE CLASS FINALLY IS RETURN NONE CONTINUE FOR LAMBDA TRY TRUE DEF FROM WHILE AND DEL NOT WITH AS ELIF IF OR ELSE IMPORT PASS BREAK EXCEPT IN PRINT COMMA DOT ASSIGN TWODOTS GLOBAL DOTCOMMA 
%token	<identificador>	NAME
%token DEDENT INDENT NEWLINE EOF

/*Aquí van los tipos*/


%%
file_input: 
	|arithmetic_expr				{};
	
/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

/*test (',' test)* [','];*/
/*
testlist:
		test comma_test COMMA			{}
		|test comma_test			{};
		
comma_test:	epsilon					{}
		|COMMA test comma_test			{};
*/
		
test: 		or_test 				{}
		|or_test IF or_test ELSE test		{};
		
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
		
comp_op: 	OPERATOR				{string[] list={"<",">","==",">=","<=","<>","!="};checkStrings($1,list);}
		| IN					{}
		| NOT IN				{}
		| IS					{}
		| IS NOT				{};
		
expr: /*xor_expr ('|' xor_expr)*				{};*/
	xor_expr pipexor_expr				{};
	
pipexor_expr: 	epsilon					{}
		|OPERATOR xor_expr pipexor_expr		{checkString($1,"|");};
		
xor_expr: /*and_expr ('^' and_expr)*			{};*/
	and_expr andxor_expr				{};

andxor_expr: 	epsilon					{}
	|OPERATOR and_expr andxor_expr			{checkString($1,"^");};
		
and_expr: /*shift_expr ('&' shift_expr)*			{};*/
	shift_expr andpandshift_expr			{};
	
andpandshift_expr: epsilon				{}
	|OPERATOR shift_expr andpandshift_expr		{checkString($1,"&");};

shift_expr: /*arith_expr (('<<'|'>>') arith_expr)*	{};*/
	arithmetic_expr leftright_shift_expr			{};

leftright_shift_expr: epsilon				{}
	|OPERATOR arithmetic_expr leftright_shift_expr	{string[] list={">>","<<"};checkStrings($1,list);};

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term				{};
		
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
	|OPERATOR factor				{checkString($1,"~");}
	|power						{};

power: /*atom trailer* ['**' factor];*/
	atom trailer_kleene				{}
	|atom trailer_kleene POT factor			{};

trailer_kleene: epsilon					{}
	|trailer trailer_kleene				{};
	
trailer: /*trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME*/
	DELIMITER DELIMITER				{checkString($1,"("),sheckString($2,")");}
	|DELIMITER arglist DELIMITER			{checkString($1,"("),sheckString($3,")");}
	|DELIMITER subscriptlist DELIMITER 		{checkString($1,"["),sheckString($3,"]");}
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
		
/*EXPRLIST*/
subscriptlist: /*subscript (',' subscript)* [',']*/
	subscript comma_subscript
	|subscript comma_subscript COMMA;

comma_subscript: epsilon
	|COMMA subscript comma_subscript;
	
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
	

	
atom: NAME
	| NUMBER
	| string_plus;

string_plus: STRING					{}
	|STRING string_plus;
	

/*old_test [(',' old_test)+ [',']];*/
/*
testlist_safe:
	old_test
	|old_test COMMA old_test
	|old_test COMMA old_test COMMA;

comma_old_test: COMMA old_test;
*/

old_test: or_test;

exprlist: expr expr_kleene COMMA
	| expr expr_kleene;

expr_kleene: COMMA expr expr_kleene
	| epsilon;


%%


int main() {

	yyparse();
}






