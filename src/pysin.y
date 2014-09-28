%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int yylex(); 
int yyerror(const char *s) { printf ("Error: %s\n", s); }
int seguir=1;

char* checkStrings(string delimiter, vector<string> deseado ){
	for(int i=0; i<vector.length; i++;){
		if (delimiter.compare(deseado)==0)
		return deseado;
	
	}
	yyerror("de sintaxis, babuino");
}

char* checkString(string delimiter, string deseado){
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
%token DEDENT INDENT NEWLINE 

/*Aquí van los tipos*/
%type <double> arithmeric_expr arith_expr exprlist list_for


%%
/*Aquí va la gramática*/

/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};
testlist: 	/*test (',' test)* [','];*/
		test comma_test COMMA			{};
		|test comma_test			{};
comma_test:	epsilon					{};
		|COMMA test comma_test			{};
test: 		or_test 				{};
		|or_test IF or_test ELSE test		{};
or_test: 	/*and_test (OR and_test)*			{};*/
		and_test or_andtest			{};
or_andtest:	epsilon					{};
		|OR and_test or_andtest			{};
and_test: 	/*not_test (AND not_test)*		{};*/
		not_test and_nottest			{};
and_nottest:	epsilon					{};
		|AND not_test and_nottest		{};
not_test: 	NOT not_test				{};
		| comparison				{};
comparison: /*expr (comp_op expr)*			{};*/
		comp_op_expr				{};
comp_op_expr:	epsilon					{};
		|comp_op expr comp_op_expr		{};
comp_op: 	OPERATOR				{vector <string> list={"<",">","==",">=","<=","<>","!="};checkStrings($1,list);};
		| IN					{};
		| NOT IN				{};
		| IS					{};
		| IS NOT				{};
expr: /*xor_expr ('|' xor_expr)*				{};*/
	xor_expr pipexor_expr				{};
pipexor_expr: 	epsilon					{};
		|OPERATOR xor_expr			{checkString($1,"|");};
xor_expr: /*and_expr ('^' and_expr)*			{};*/
	and_expr andxor_expr				{};

andxor_expr: 	epsilon					{};
		|OPERATOR and_expr			{checkString($1,"^");};
and_expr: /*shift_expr ('&' shift_expr)*			{};*/
	shift_expr andpandshift_expr			{};
andpandshift_expr: epsilon				{};
		|OPERATOR shift_expr			{checkString($1,"&");};

shift_expr: /*arith_expr (('<<'|'>>') arith_expr)*	{};*/
	arith_expr leftright_shift_expr			{};

leftright_shift_expr: epsilon				{}
	|OPERATOR arith_expr leftright_shift_expr	{vector <string> list={">>","<<"};checkStrings($1,list);};

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
		term sing_term				{};
		
sign_tem: epsilon					{};
	|term MAS sign_term				{};
	|term MENOS sign_term				{};

term: /*factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;*/
	factor_operation				{};
	
factor_operation: epsilon				{};
	|POR factor factor_operation			{};
	|ENTRE factor factor_operation			{};
	|MOD factor factor_operation			{};
	|DIV factor factor_operation			{};

factor: /*'+' factor;
	| '-' factor;
	| '~' factor;
	| power;*/
	MAS factor					{};
	|MENOS factor					{};
	|MAS factor					{};
	|OPERATOR factor				{checkString($1,"~");};

power: /*atom trailer* ['**' factor];*/
	atom trailer_kleene				{};
	|atom trailer_kleene POT factor			{};

trailer_kleene: epsilon					{};
	|trailer trailer_kleene				{};
	
trailer: '(' ')'  					{};
	|'(' arglist ')'				{};
	| '[' subscriptlist ']' 			{};
	| DOT NAME					{};

atom: NAME;
	| NUMBER;
	| string_plus

string_plus: STRING					{};
	|STRING string_plus				{};

listmaker: 	test list_for				{};
		/*| (',' test)* [','];*/
		|comma_test COMMA			{};
		|comma_test				{};
		
single_input: NEWLINE					{};
	| simple_stmt					{};
	| compound_stmt NEWLINE				{};

file_input: /*NEWLINE* ENDMAKER;
			|stmt* ENDMARKER;*/
	newline_kleene ENDMARKER			{};
	|stmt_kleene ENDMARKER				{};
	
stmt_kleene:epsilon					{};
	|stmt stmt_kleene				{};
			
newline_kleene: epsilon					{};
	|NEWLINE newline_kleene				{};
	

eval_input: /*testlist NEWLINE* ENDMARKER;*/
	|testlist newline_kleene ENDMARKER		{};


/* Ciclos y Condicionales */

compound_stmt: if_stmt;
	| while_stmt;
	| for_stmt;
	| funcdef;

if_stmt: IF test TWODOTS suite if_stmt_elif if_stmt_else;
if_stmt_elif: if_stmt_elif;
			| ELIF test TWODOTS suite;
			| epsilon;
if_stmt_else: ELSE TWODOTS suite;
			| epsilon;

while_stmt: WHILE test TWODOTS suite while_stmt_else; 
while_stmt_else: ELSE TWODOTS suite;
	| epsilon;

for_stmt: FOR exprlist IN testlist TWODOTS suite for_stmt_else; 
for_stmt_else: ELSE TWODOTS suite;
	| epsilon;

suite: simple_stmt; 
		| NEWLINE INDENT suite_stmt DEDENT;
suite_stmt:	stmt;
		| more_stmt;
more_stmt: stmt more_stmt;
		| epsilon;

simple_stmt: small_stmt more_simple_stmt end_simple_stmt NEWLINE;

more_simple_stmt: DOTCOMMA small_stmt;
				| epsilon; 
end_simple_stmt: DOTCOMMA;
				| epsilon;

small_stmt: expr_stmt; 
			| print_stmt;
			| del_stmt;
			| pass_stmt;
			| flow_stmt;
			| global_stmt;

expr_stmt: testlist expr_stmt_at;
expr_stmt_at: augassign testlist;
			| more_testlist;
more_testlist: ASSIGN testlist more_testlist;
				| ASSIGN testlist;
				| epsilon; 

augassign: DELIMITER	{vector <string> list={"+=","-=","*=","/=","%=","&=","|=","^=","<<=",">>=","**=","//="};checkStrings($1,list);};

print_stmt: PRINT print_stmt_next 
print_stmt_next: print_stmt_test
	/*| '>>' test [ (',' test)+ print_stmt_test_last ];*/
	| DELIMITER test					{checkString($1,">>");};
	| DELIMITER test comma_test_plus print_stmt_test_last	{checkString($1,">>");};

comma_test_plus: COMMA test;
	| COMMA test comma_test_plus;

print_stmt_second: more_test print_stmt_test_last;
more_test: COMMA test;
		| COMMA test more_test;

print_stmt_test: test print_stmt_more_test print_stmt_test_last;
				| epsilon;
print_stmt_more_test: COMMA test print_stmt_more_test;
					| epsilon;
print_stmt_test_last: COMMA;
					| epsilon;

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: DEL exprlist;

pass_stmt: PASS;

flow_stmt: break_stmt;
		| continue_stmt; 
		| return_stmt; 

break_stmt: BREAK;
continue_stmt: CONTINUE;
return_stmt: RETURN return_stmt_tl;
return_stmt_tl: testlist;
				| epsilon;

/* global me parece innecesario pero en tema de registros plantea algo importante */
global_stmt: GLOBAL NAME global_stmt_name;
global_stmt_name: COMMA NAME global_stmt_name;
				| epsilon;

/* Funciones */

funcdef: DEF NAME parameters TWODOTS suite;
parameters: /*'(' varargslist ')';*/
		DELIMITER varargslist DELIMITER			{checkString($1,"(");checkString($3,")");};
varargslist: args_first args_first_next;
			| fpdef args_def args_def_more COMMA;
			| fpdef args_def args_def_more;
			| epsilon;

args_first: fpdef ASSIGN test COMMA args_first;
	|fpdef COMMA args_first;
	| epsilon;

args_first_next: POR NAME args_name;
	| POT NAME;

args_name: COMMA POT NAME;
		| epsilon;

args_def: ASSIGN test;
		| epsilon;

args_def_more: COMMA fpdef args_def args_def_more;
			| epsilon;

fpdef: NAME;
	/*| '(' fplist ')';*/
	|DELIMITER fplist DELIMITER				{checkString($1,"(");checkString($3,")");};

fplist: fpdef fpdef_more COMMA;
	| fpdef fpdef_more;
fpdef_more: COMMA fpdef fpdef_more;
			| epsilon;

exprlist: expr expr_kleene ',';
		| expr expr_kleene;

expr_kleene: ',' expr expr_kleene;
			| epsilon;


%%


int main() {

	while(seguir){
		printf(">> ");
		yyparse();
	}
	return 0;
}






