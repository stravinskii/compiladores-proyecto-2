%{
#include <iostream>
#include "lib/stack.h"

int new_line = 1;
stack stack;

/*

STRING		\".*\"

COMMENT		"#".*"\n"
{COMMENT}	// we do nothing as expected

LINE-COMMENT	"#".*"\n"
{LINE-COMMENT}	// we do nothing 

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
NEWLINE		"\n"+

COMMENT		"#"

STRING		"\""

INDENT		"\t"|"		"


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

{NEWLINE}	{
				std::cout << " NEWLINE" << std::endl;
				new_line++;

				int in =yyinput(); 
				if (in !='\t' && in != ' ' && in != '#')
				{
					int dedents = stack.peek();
					while(stack.peek() != 0)
					{
						stack.pop();
					}

					for (int i = 0; i < dedents; i++)
					{
						std::cout << "DEDENT ";	
					}
				}
				yyunput(in, yytext_ptr);
			}

{ID}		std::cout << "ID";

{COMMENT}	{
				int in = yyinput();
				while(in != '\n')
				{
					in = yyinput();
				}
				yyunput(in, yytext_ptr);
				std::cout << "NEWLINE" << std::endl;
				new_line++;
			}


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

{INDENT}	{
				int indent = 1;
				int in = yyinput();

				/* case: whitespace indent */
				if (in == ' ')
				{
					yyunput(in, yytext_ptr);
					int whitespace = 0;
					while (in == ' ')
					{
						whitespace++;
						in = yyinput();
					}

					/* push back last unmatched char */
					yyunput(in, yytext_ptr);

					/* convention: 8 whitespaces equals 1 tab */
					if (whitespace % 8 != 0)
					{
						indent = whitespace / 8;
					}
				}

				/* case: tab indent */
				else if (in == '\t')
				{
					yyunput(in, yytext_ptr);
					while (in == '\t')
					{
						indent++;
						in = yyinput();
					}
					/* push back last unmatched char */
					yyunput(in, yytext_ptr);
				}

				/* case: only indent */
				else
				{
					/* push back last unmatched char */
					yyunput(in, yytext_ptr);
				}

				/* if indent level matches stack peek there's nothing to do */

				if (stack.peek() < indent)
				{
					stack.push(indent);

					for (int i = 0; i < indent; i++)
					{
						std::cout << "INDENT ";
					}	
				}

				else if (stack.peek() > indent)
				{
					int dedents = stack.peek();
					/* pop stack's indent levels until match */
					while (stack.peek() != indent)
					{
						if (stack.isEmpty())
						{
							std::cout << std::endl;
							std::cout << "File \"" << yyin << "\", line " << new_line << std::endl;
							std::cout << "Indent error: unindent does not match any outer indentation level" << std::endl;
							yyterminate();
						}

						stack.pop();
					}

					/* matched unindent level */
					for (int i = 0; i < dedents - 1; i++)
					{
						std::cout << "DEDENT ";
					}
				}
			}

%%

int main(int argc, char *argv[])
{
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

	yylex();
}