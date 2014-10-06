%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
file_input: /* (NEWLINE | stmt)* ENDMARKER*/
	filein		{cout<<"COMPILATION COMPLETE :)\n";};
	
filein:epsilon
	|filein NEWLINE				{cout<<"\n";}
	|filein stmt;
	
/*Aquí va la gramática*/
/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

test:/*or_test ['if' or_test 'else' test] */
	or_test					{}
	|or_test IF or_test ELSE test		{cout<<"IF __ ELSE __ ";};	
	
old_test: or_test;

or_test: 	/*and_test (OR and_test)*		{};*/
		and_test or_andtest			{};
		
or_andtest:	epsilon					{}
		|or_andtest OR and_test			{cout<<"OR";};
		
and_test: 	/*not_test (AND not_test)*		{};*/
		not_test and_nottest			{};
		
and_nottest:	epsilon					{}
		|and_nottest AND not_test		{cout<<"AND";};
		
not_test: 	/*'not' not_test | comparison*/
	NOT not_test					{cout<<"NOT";}
	|comparison				{};

		
comparison: /*expr (comp_op expr)*			{};*/
	expr comp_op_expr_kleene;

comp_op_expr_kleene: 
	comp_op_expr_kleene comp_op expr
	|epsilon;
	
comp_op: /*'<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'*/
	LESSTHAN			{cout<<"<";}
	|MORETHAN			{cout<<">";}
	|EQUALS				{cout<<"==";}
	|MOREEQUAL			{cout<<">=";}
	|LESSEQUAL			{cout<<"<=";}
	|PICOPARENTESIS			{cout<<"<>";}
	|DIFFERENT			{cout<<"!=";}
	|IN				{cout<<"IN";}
	|NOT IN				{cout<<"NOT IN";}
	|IS				{cout<<"IS";}
	|IS NOT				{cout<<"IS NOT";};

expr: /*xor_expr ('|' xor_expr)*				{};*/
	xor_expr pipexor_expr				{};
	
pipexor_expr: 	epsilon					{}
	|pipexor_expr PIPE xor_expr ;
		
xor_expr: /*and_expr ('^' and_expr)*			{};*/
	and_expr andxor_expr				{};

andxor_expr: 	epsilon					{}
	|andxor_expr EXP and_expr ;
		
and_expr: /*shift_expr ('&' shift_expr)*			{};*/
	shift_expr andpandshift_expr			{};
	

andpandshift_expr: epsilon				{}
	|andpandshift_expr ANDPAND shift_expr;

shift_expr: /*arith_expr (('<<'|'>>') arith_expr)*	{};*/
	arithmetic_expr leftright_shift_expr			{};

leftright_shift_expr: epsilon				{}
	|leftright_shift_expr BINRIGHT arithmetic_expr	{cout<<">>";}
	|leftright_shift_expr BINLEFT arithmetic_expr	{cout<<"<<";};

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term					{};

sign_term:epsilon					{}
	|sign_term MAS term			{cout<<"Suma\n";}
	|sign_term MENOS term			{cout<<"Resta\n";};

term: /*factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;*/
	factor factor_operation				{};
	
factor_operation: epsilon				{}
	|factor_operation POR factor 			{cout<<"Multiplicacion\n";}
	|factor_operation ENTRE factor 			{cout<<"Division\n";}
	|factor_operation MOD factor 			{cout<<"Modulo\n";}
	|factor_operation DIV factor 			{cout<<"Division Entera\n";};

factor: /*'+' factor;
	| '-' factor;
	| '~' factor;
	| power;*/
	MAS factor					{cout<<"SUMA\n";}
	|MENOS factor					{cout<<"RESTA\n";}
	|TILDE factor					
	|power;		

power: /*atom trailer* ['**' factor];*/
	atom trailer_kleene				{}
	|atom trailer_kleene POT factor			{};

trailer_kleene: epsilon					{}
	|trailer_kleene trailer 				{};
	
trailer: /*'(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME*/
	OPENPAR CLOSEPAR				{cout<<"()";}
	|OPENPAR arglist CLOSEPAR			{cout<<"(ARGLIST)";}
	|OPENCOR subscriptlist CLOSECOR			{cout<<"(SUBSCRIPTLIST)";}
	|DOT NAME					{cout<<".NAME";};
		
arglist: /*(argument ',')* (argument [','] |'*' test (',' argument)* [',' '**' test] 	|'**' test) */
	argument_comma argument_multiple;
	
argument_comma: epsilon
	|argument_comma argument COMMA 			{cout<<",";};
	
argument_multiple: argument
	|argument COMMA					{cout<<",";}	
	|POR test comma_argument			{cout<<"*";}
	|POR test comma_argument COMMA POT test		{cout<<"*";}
	|POT test					{cout<<"**";};		
	
comma_argument: epsilon
	|comma_argument COMMA argument;
	
argument: /*test [comp_for] | test '=' test*/
	test comp_for
	|test
	|test ASSIGN test 		{cout<<"=";};
	
comp_for: /*'for' exprlist 'in' or_test [comp_iter]*/
	FOR exprlist IN or_test comp_iter	{cout<<"FOR";}
	| FOR exprlist IN or_test		{cout<<"FOR";};
	
comp_iter: /*comp_for | comp_if */
	comp_for 
	| comp_if;
	
comp_if: /*'if' old_test [comp_iter] */
	IF old_test				{cout<<"IF";}
	|IF old_test comp_iter			{cout<<"IF";};
		
subscriptlist: /*subscript (',' subscript)* [',']*/
	subscript comma_subscript
	|subscript comma_subscript COMMA;

comma_subscript: comma_subscript COMMA subscript
	|epsilon;
	
subscript: /*'.' '.' '.' | test | [test] ':' [test] [sliceop] */
	DOT DOT DOT
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
	|expr expr_kleene;

expr_kleene: expr_kleene COMMA expr
	| epsilon;

atom:/* ('(' [testlist_comp] ')' 
	| '[' [listmaker] ']' 
	| '{' [dictorsetmaker] '}' 
	|  '`' testlist1 '`' 
	| NAME | NUMBER | STRING+)*/ 
	/*atom_help*/
	OPENPAR CLOSEPAR
	|OPENPAR testlist_comp CLOSEPAR		
	|OPENCOR listmaker CLOSECOR
	|OPENKEY CLOSEKEY
	|OPENKEY dictorsetmaker CLOSEKEY	
	|APOSTROFE testlist1 APOSTROFE
	|NAME					{cout<<"IDENTIFICADOR";}
	|NUMBER					{cout<<"NUMBER";}
	|string_plus;
	
	
dictorsetmaker: /*( (test ':' test (comp_for | (',' test ':' test)* [','])) |
                  (test (comp_for | (',' test)* [','])) )*/
                  test TWODOTS test direct_set_help
                  |test comp_for
                  |test comma_test_kleene COMMA
                  |test comma_test_kleene;
                  
direct_set_help: /*(comp_for | (',' test ':' test)* [','])*/
	comp_for
	|direct_set_help2 COMMA
	|direct_set_help2;
	
direct_set_help2: epsilon
	| direct_set_help2 COMMA test TWODOTS test;

testlist1: /*test (',' test)**/
	test comma_test_kleene;
	
string_plus: 
	STRING					{cout<<"STRING";}
	|STRING string_plus;

/*LO QUE ESTA ARRIBA ES DE ARITHMETIC EXP*/
listmaker: 	/*test ( list_for | (',' test)* [','] )*/
	test list_for				{}		
	|test comma_test_kleene comma_one			{};
		
testlist_comp: /* test ( comp_for | (',' test)* [','] )*/
	test comp_for
	|test comma_test_kleene comma_one;
		
list_for: /* 'for' exprlist 'in' testlist_safe [list_iter]*/
	FOR exprlist IN testlist_safe 		{cout<<"FOR";}
	|FOR exprlist IN testlist_safe list_iter	{cout<<"FOR";};

list_iter: /*list_for | list_if*/
	list_for 
	| list_if;

testlist_safe: /*old_test [(',' old_test)+ [',']];*/
	old_test
	|old_test comma_old_test_plus
	|old_test comma_old_test_plus COMMA;
	
comma_old_test_plus: COMMA old_test
	|comma_old_test_plus COMMA old_test;

list_if: /*'if' old_test [list_iter]*/
	IF old_test					{cout<<"IF___";}
	|IF old_test list_iter				{cout<<"IF___";};
	
compound_stmt: /*if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated*/
	if_stmt
	| while_stmt
	| for_stmt
	| funcdef;

if_stmt: /*'if' test ':' suite ('elif' test ':' suite)* ['else' ':' suite]*/
	IF test TWODOTS suite elif_test_td_suite_kleene ELSE TWODOTS suite {cout<<"IF___:___ELSE:";}
	|IF test TWODOTS suite elif_test_td_suite_kleene 		{cout<<"IF___:___";};
	
elif_test_td_suite_kleene: epsilon
	|elif_test_td_suite_kleene ELIF test TWODOTS suite		{cout<<"ELIF___:";};	

while_stmt: /*'while' test ':' suite ['else' ':' suite] */
	WHILE test TWODOTS suite ELSE TWODOTS suite 	{cout<<"WHILE___:___ ELSE :";}
	|WHILE test TWODOTS suite			{cout<<"WHILE___:";};

for_stmt: /*'for' exprlist 'in' testlist ':' suite ['else' ':' suite]*/
	FOR exprlist IN testlist TWODOTS suite ELSE TWODOTS suite {cout<<"FOR";}
	|FOR exprlist IN testlist TWODOTS suite			{cout<<"FOR";};

suite: /*simple_stmt | NEWLINE INDENT stmt+ DEDENT*/
	simple_stmt
	| NEWLINE INDENT stmt_plus DEDENT		{cout<<"\nINDENT___DEDENT";};
		
stmt_plus: stmt_plus stmt
	| stmt;

stmt: /*simple_stmt | compound_stmt*/
	simple_stmt 
	| compound_stmt;
	
simple_stmt: /*small_stmt (';' small_stmt)* [';'] NEWLINE */
	small_stmt more_simple_stmt end_simple_stmt;

small_stmt: /*(expr_stmt | print_stmt  | del_stmt | pass_stmt | flow_stmt |
             import_stmt | global_stmt | exec_stmt | assert_stmt)*/
	expr_stmt
	| print_stmt
	| del_stmt
	| pass_stmt
	| flow_stmt
	| global_stmt;

more_simple_stmt:more_simple_stmt DOTCOMMA small_stmt
		| epsilon; 
				
end_simple_stmt: DOTCOMMA NEWLINE	{cout<<";\n";}
		|NEWLINE		{cout<<"\n";};

expr_stmt: /*testlist (augassign (yield_expr|testlist) |('=' (yield_expr|testlist))*)*/
	testlist expr_stmt_at;

expr_stmt_at: augassign testlist
	|assign_testlist_kleene;

assign_testlist_kleene: assign_testlist_kleene ASSIGN testlist	{cout<<"=";}
	| epsilon; 

augassign: /*('+=' | '-=' | '*=' | '/=' | '%=' | '&=' | '|=' | '^=' |
            '<<=' | '>>=' | '**=' | '//=')*/
	MASIGUAL	{cout<<"+=";}
	|MENOSIGUAL	{cout<<"-=";}
	|PORIGUAL	{cout<<"*=";}
	|ENTREIGUAL	{cout<<"/=";}
	|MODIGUAL	{cout<<"%=";}
	|ANDIGUAL	{cout<<"&=";}
	|ORIGUAL	{cout<<"|=";}
	|EXPIGUAL	{cout<<"^=";}
	|BINRIGHTIGUAL	{cout<<">>=";}
	|BINLEFTIGUAL	{cout<<"<<=";}
	|POTIGUAL	{cout<<"**=";}
	|DIVIGUAL	{cout<<"//=";};
	
print_stmt: /*'print' ( [ test (',' test)* [','] ] | '>>' test [ (',' test)+ [','] ] )*/
	PRINT print_stmt1		{cout<<"PRINT";}
	|PRINT print_stmt2		{cout<<"PRINT";};
	
print_stmt1: epsilon
	|test comma_test_kleene comma_one;

comma_test_kleene: epsilon
	|comma_test_kleene COMMA test	{cout<<",";};

print_stmt2: BINRIGHT test		{cout<<">>";}
	|BINRIGHT test comma_test_plus comma_one {cout<<">>";};
	
comma_one: epsilon
	|COMMA		{cout<<",";};

comma_test_plus: COMMA test
	| comma_test_plus COMMA test;

	
testlist: /*test (',' test)* [','];*/
	test comma_test_kleene comma_one	{};
	

/* Quizás estaría bien eliminar del de la gramática */
del_stmt: DEL exprlist;

pass_stmt: PASS;

flow_stmt: /*break_stmt | continue_stmt | return_stmt | raise_stmt | yield_stmt*/
	break_stmt
	| continue_stmt
	| return_stmt; 

break_stmt: BREAK;

continue_stmt: CONTINUE;

return_stmt: RETURN testlist
	|RETURN;

/* global me parece innecesario pero en tema de registros plantea algo importante */
global_stmt: /*'global' NAME (',' NAME)* */
	GLOBAL NAME global_stmt_name;
	
global_stmt_name:global_stmt_name COMMA NAME
	| epsilon;

/* Funciones */

funcdef: /*'def' NAME parameters ':' suite*/
	DEF NAME parameters TWODOTS suite;

parameters: /*'(' [varargslist] ')';*/
	OPENPAR CLOSEPAR
	|OPENPAR varargslist CLOSEPAR;
		
varargslist: /*
	  ((fpdef ['=' test] ',')* ('*' NAME [',' '**' NAME] | '**' NAME) | fpdef ['=' test] (',' fpdef ['=' test])* [',']) */
	a b
	|fpdef EQUALS test d
	|fpdef d COMMA
	|fpdef d;
	
a: a fpdef COMMA
	|a fpdef EQUALS test COMMA
	|epsilon;
	
b: POR NAME 
|POR NAME COMMA POT NAME
| POT NAME;

d: d COMMA fpdef
| d COMMA fpdef EQUALS test
|epsilon;
	
fpdef: 	/*NAME | '(' fplist ')';*/
	NAME
	|OPENPAR fplist CLOSEPAR;

fplist: /*fpdef (',' fpdef)* [',']*/
	fpdef fpdef_kleene COMMA
	|fpdef fpdef_kleene;
	
fpdef_kleene: fpdef_kleene COMMA fpdef
	| epsilon;

%%


