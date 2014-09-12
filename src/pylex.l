%{
#include <iostream>
#include "lib/stack.h"

int new_line = 1;

/*

STRING		\".*\"
{STRING}	std::cout << "STRING";

INDENT		[\t]
<INDENT>	{
				std::cout << "INDENT";
				// push or pop number of indent of stack
				while (yytext != EOF)
				{
					std::cout << yytext;
				}
			}


*/

%}

%option noyywrap
%option outfile="pylex.cpp"

FALSE		"False"
CLASS		"class"
FINALLY		"finally"
IS			"is"
RETURN		"return"
NONE		"None"
CONTINUE	"continue"
FOR			"for"
LAMBDA		"lambda"
TRY			"try"
TRUE		"True"
DEF			"def"
FROM		"from"
WHILE		"while"
AND			"and"
DEL			"del"
NOT			"not"
WITH		"with"
AS			"as"
ELIF		"elif"
IF			"if"
OR			"or"
ELSE		"else"
IMPORT		"import"
PASS		"pass"
BREAK		"break"
EXCEPT		"except"
IN			"in"
PRINT		"print"

ID 			[a-z][a-z0-9]*
NUMBER		[0-9]*
FRACTION	[0-9]*.[0-9]*
NEWLINE		[\n]
COMMENT		"#".*

STRING		["]


%%

{FALSE}		std::cout << "FALSE";
{CLASS}		std::cout << "CLASS";
{FINALLY}	std::cout << "FINALLY";
{IS}		std::cout << "IS";
{RETURN}	std::cout << "RETURN";
{NONE}		std::cout << "NONE";
{CONTINUE}	std::cout << "CONTINUE";
{FOR}		std::cout << "FOR";
{LAMBDA}	std::cout << "LAMBDA";
{TRY}		std::cout << "TRY";
{TRUE}		std::cout << "TRUE";
{DEF}		std::cout << "DEF";
{FROM}		std::cout << "FROM";
{WHILE}		std::cout << "WHILE";
{AND}		std::cout << "AND";
{DEL}		std::cout << "DEL";
{NOT}		std::cout << "NOT";
{WITH}		std::cout << "WITH";
{AS}		std::cout << "AS";
{ELIF}		std::cout << "ELIF";
{IF}		std::cout << "IF";
{OR}		std::cout << "OR";
{ELSE}		std::cout << "ELSE";
{IMPORT}	std::cout << "IMPORT";
{PASS}		std::cout << "PASS";
{BREAK}		std::cout << "BREAK";
{EXCEPT}	std::cout << "EXCEPT";
{IN}		std::cout << "IN";
{PRINT}		std::cout << "PRINT";

{NUMBER} 	std::cout << "NUMBER";

{COMMENT}	/* we do nothing as expected */
{NEWLINE}	std::cout << std::endl; new_line++;
{ID}		std::cout << "ID";

{STRING}	{
				int in = yyinput();
				while (in != '"')
				{
					/* Python doesnt allow multi-line strings */
					in = yyinput();
					if (in == '\n')
					{
						std::cout << "File \"" << yyin << "\", line " << new_line << std::endl;
						std::cout << "Syntax error: EOL while scanning a string" << std::endl;
						yyterminate();
					}
				}
				std::cout << "STRING";
			}

%%

int main(int argc, char *argv[])
{
	stack stack;
	// push zero to stack as proposed in Python documentation
	stack.push((char*) '0');

	if (argc > 1)
	{
		yyin = fopen(argv[1], "r");
	} 
	else
	{
		yyin = stdin;
	}

	yylex();
	// yyparse()
	// yyterminate()
}