%{
#include <iostream>
#include "../lib/Stack.h"
#include <fstream>

using namespace std;
int newLine=1;
Stack stack;
ofstream arch_salida;



%}

%option noyywrap
%option outfile="pylex.cpp"


FALSE		"False"
CLASS		"class"
FINALLY		"finally"
IS		"is"
RETURN		"return"
NONE		"None"
CONTINUE	"continue"
FOR		"for"
LAMBDA		"lambda"
TRY		"try"
TRUE		"True"
DEF		"def"
FROM		"from"
WHILE		"while"
AND		"and"
DEL		"del"
NOT		"not"
WITH		"with"
AS		"as"
ELIF		"elif"
IF		"if"
OR		"or"
ELSE		"else"
IMPORT		"import"
PASS		"pass"
BREAK		"break"
EXCEPT		"except"
IN		"in"
PRINT		"print"
EQUALS		"=="
ASSIGN		"="
PLUS		"+"
MINUS		"-"
MULT		"*"
DIV		"/"
MOD		"%"
LESSTHAN	"<"
GREATERTHAN	">"

/*Administrativos, tipos y caracteres especiales*/
DOTS		":"
INDENT		"        "|"\t"
DEDENT		"dedent"


ID 			[a-zA-z][_a-zA-Z0-9]*
NUMBER			{INTEGER}|{FLOATNUMBER}
INTEGER        		{DECIMALINTEGER}
DECIMALINTEGER		{NONZERODIGIT}{DIGIT}*|"0"+
NONZERODIGIT  		[1-9]
DIGIT			[0-9]
FLOATNUMBER  		{POINTFLOAT}|{EXPONENTFLOAT}
POINTFLOAT   		{INTPART}+{FRACTION}|{INTPART}"."
EXPONENTFLOAT		({INTPART}|{POINTFLOAT}){EXPONENT}
INTPART      		{DIGIT}+
FRACTION     		"."{DIGIT}+
EXPONENT     		("e"|"E")("+"|"-"){1}{DIGIT}+

NEWLINE		"\n"+
COMMENT		"#"
STRING		"\""
COMMA		","
ERROR		"mistake"
EOF		"\0"


%%

{FALSE}		arch_salida<<"FALSE";
{CLASS}		arch_salida<<"CLASS";
{FINALLY}	arch_salida<<"FINALLY";
{IS}		arch_salida<<"IS";
{RETURN}	arch_salida<<"RETURN";
{NONE}		arch_salida<<"NONE";
{CONTINUE}	arch_salida<<"CONTINUE";
{FOR}		arch_salida<<"FOR";
{LAMBDA}	arch_salida<<"LAMBDA";
{TRY}		arch_salida<<"TRY";
{TRUE}		arch_salida<<"TRUE";
{DEF}		arch_salida<<"DEF";
{FROM}		arch_salida<<"FROM";
{WHILE}		arch_salida<<"WHILE";
{AND}		arch_salida<<"AND";
{DEL}		arch_salida<<"DEL";
{NOT}		arch_salida<<"NOT";
{WITH}		arch_salida<<"WITH";
{AS}		arch_salida<<"AS";
{ELIF}		arch_salida<<"ELIF";
{IF}		arch_salida<<"IF";
{OR}		arch_salida<<"OR";
{ELSE}		arch_salida<<"ELSE";
{IMPORT}	arch_salida<<"IMPORT";
{PASS}		arch_salida<<"PASS";
{BREAK}		arch_salida<<"BREAK";
{EXCEPT}	arch_salida<<"EXCEPT";
{IN}		arch_salida<<"IN";
{PRINT}		arch_salida<<"PRINT";
{EQUALS}	arch_salida<<"EQUALS";
{ASSIGN}	arch_salida<<"ASSIGN";
{NUMBER}	arch_salida<<"NUMBER";
{COMMA}		arch_salida<<",";
{PLUS}		arch_salida<<"+";
{MINUS}		arch_salida<<"-";
{MULT}		arch_salida<<"*";
{DIV}		arch_salida<<"/";
{MOD}		arch_salida<<"%";
{DOTS}		arch_salida<<":";
{LESSTHAN}	arch_salida<<"<";
{GREATERTHAN}	arch_salida<<">";

{ERROR}		{cout<<"Error de sintáxis en la línea " <<newLine; yyterminate();}
{COMMENT}	{int in=yyinput();
		while(in != '\n'){
			in=yyinput();
		}
		arch_salida<<"COMMENT NEWLINE\n";newLine++;}
{NEWLINE}	{arch_salida<<" NEWLINE\n"; newLine++;
		int in =yyinput(); 
		if(in!='\t' && in!=' ' && in !='#'){
			while(stack.get_Size()){
				stack.pop();
				arch_salida<<"DEDENT ";
			}
		}
		unput(in);
		}		
{ID}		arch_salida<<"ID ";
{STRING}	{int in = yyinput();
		while(in != '"' && in != '\n' ){
			in=yyinput();
		}
		unput(' ');
		if (in == '\n' || in==EOF){
			cout<<"Error de sintaxis en la línea "<<newLine <<": String no terminada correctamente\n";
			yyterminate();
		}else{
		arch_salida<<"STRING";
		}}
{INDENT}	{int in=yyinput(); int spaces=0;int indentLevel= stack.pick(); int nivel=1;
		while(in==' '||in=='\t'){
			if(in==' ')
				spaces++;
			in=yyinput();
			if(spaces==8){
				++spaces;
				spaces=0;
				++nivel;
				arch_salida<<"INDENT ";
			}
			++nivel;
		}
		unput(in);
		
		if(nivel>indentLevel&& in != '#'){
			stack.push(nivel);
			indentLevel++;
			arch_salida<<"INDENT ";
		}else if(nivel<indentLevel && in != '#'){
			stack.pop();
			indentLevel--;
			arch_salida<<"DEDENT ";
		}else if(nivel!=indentLevel && in != '#'){
			cout<<"Error de indentación en la línea: "<<newLine;
			yyterminate();
		}
		nivel=0;}
{EOF}		arch_salida<<"EOF";


%%



int main(int argc, char *argv[])
{
	Stack stack;
	// push zero to stack as proposed in Python documentation
	stack.push(0);
	if (argc > 1)
	{
		yyin = fopen(argv[1], "r");
		
	} 
	else
	{
		yyin = stdin;
	}
	arch_salida.open("ejemplo.pyl");
	yylex();
	cout<<"\n";
	arch_salida.close();
	

	
}
