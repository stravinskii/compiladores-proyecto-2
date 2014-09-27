%{
#include <iostream>
#include "lib/stack.h"

stack stack;
int new_line = 1;
bool start = true;

/*
{NUMBER}		{std::cout << "NUMBER"; return NUMBER;}
*/

%}

%option noyywrap
%option outfile="pylex.cpp"


NAME 				[a-zA-z][_a-zA-Z0-9]*
NUMBER				{INTEGER}|{FLOATNUMBER}
INTEGER        		{DECIMALINTEGER}
DECIMALINTEGER		{NONZERODIGIT}{DIGIT}*|"0"+
NONZERODIGIT  		[1-9]
DIGIT				[0-9]
FLOATNUMBER  		{POINTFLOAT}|{EXPONENTFLOAT}
POINTFLOAT   		{INTPART}+{FRACTION}|{INTPART}"."
EXPONENTFLOAT		({INTPART}|{POINTFLOAT}){EXPONENT}
INTPART      		{DIGIT}+
FRACTION     		"."{DIGIT}+
EXPONENT     		("e"|"E")("+"|"-"){1}{DIGIT}+

NEWLINE				"\n"+
COMMENT				"#"
STRING				"\""
INDENT				"\t"|" "
EOF 				"\0"

KEYWORDS			("False"|"class"|"finally"|"is"|"return"|"None"|"continue"|"for"|"lambda"|"try"|"True"|"def"|"from"|"while"|"and"|"del"|"not"|"with"|"as"|"elif"|"if"|"or"|"else"|"import"|"pass"|"break"|"except"|"in"|"print")
OPERATORS			("+"|"-"|"*"|"**"|"/"|"//"|"%"|"<<"|">>"|"&"|"|"|"^"|"~"|"<"|">"|"<="|">="|"=="|"!=")
DELIMITERS			("("|")"|"["|"]"|"{"|"}"|","|":"|"."|";"|"@"|"="|"->"|"+="|"-="|"*="|"/="|"//="|"%="|"&="|"|="|"^="|">>="|"<<="|"**=")


%s START
%s NEWLINE
%s DEDENT
%%

{EOF}		{std::cout << "EOF";}

{KEYWORDS}		{
					// yylval.cadena = yytext;
					std::cout << yytext;
					BEGIN(INITIAL);
					// return KEYWORDS
				}
{OPERATORS}		{
					// yylval.cadena = yytext;
					std::cout << yytext;
					BEGIN(INITIAL);
					// return OPERATORS
				}
{DELIMITERS} 	{
					// yytext.cadena = yytext;
					std::cout << yytext;
					BEGIN(INITIAL);
					// return DELIMITERS
				}

{FLOATNUMBER}	{ 
					/* yylval.flotante = atof(yytext); */
					BEGIN(INITIAL);
					std::cout << "NUMBER";
				}
{INTEGER}		{ 
					/* yylval.entero = atoi(yytext); */
					BEGIN(INITIAL);
					std::cout << "NUMBER"; 
				}

{NAME}		{
				/* yylval.identificador = yytext; */
				BEGIN(INITIAL);
				std::cout << "NAME";
			}

{STRING}	{
				int in = yyinput();
				while (in != '"')
				{
					/* Python doesnt allow multi-line strings */
					in = yyinput();
					if (in == '\n' || in == EOF)
					{
						std::cout << "File \"" << yyin << "\", line " << new_line << std::endl;
						std::cout << "Syntax error: EOL while scanning a string" << std::endl;
						yyterminate();
					}
				}
				/* yylval.cadena = yytext; */
				std::cout << "STRING";
				BEGIN(INITIAL);
			}

<START>{NEWLINE}	{
						new_line++;
						int in = yyinput();
						if (in == '\n')
						{
							while (in != '\n')
							{
								new_line++;
								in = yyinput();
							}
						}

						if (in != '#')
						{
							BEGIN(INITIAL);
						}

						/* push back unmatching char */
						unput(in);
					}

<DEDENT>{NEWLINE}	{
						std::cout << "NEWLINE token in condition DEDENT" << std::endl;
						int in = yyinput();
						/* if it's an indent */
						if (in == '\t' || in == ' ')
						{
							// std::cout << "its an indent!" << std::endl;
							/* push back unmatching char */
							unput(in);
							BEGIN(INITIAL);
							std::cout << "NEWLINE" << std::endl;
						}
						/* if it's a comment */
						else if (in == '#')
						{
							// std::cout << "its a comment!" << std::endl;
							/* push back unmatching char */
							unput(in);
							BEGIN(NEWLINE);
							std::cout << "NEWLINE" << std::endl;
						}
						/* if it's not an INDENT or COMMENT check DEDENT */
						else
						{
							// std::cout << "not indent nor comment" << std::endl;
							/* push back unmatching char */
							unput(in);

							/* if last DEDENT was returned */
							if (stack.peek() == 0)
							{
								// std::cout << "last dedent" << std::endl;
								BEGIN(INITIAL);
								std::cout << "NEWLINE" << std::endl;
							}
							/* there are still DEDENTS level to pop */
							else
							{
								// std::cout << "dedent found from stack peek" << std::endl;
								stack.pop();
								/* push back newline for next DEDENT */
								yyless(yyleng);
								std::cout << "DEDENT";
							}
						}
					}

{NEWLINE}	{
				new_line++;
				int in = yyinput();
				if (in == '\n')
				{
					while (in != '\n')
					{
						new_line++;
						in = yyinput();	
					}
				}

				/* push back unmatching char */
				unput(in);
				/* push back last newline for DEDENT check */
				BEGIN(DEDENT);
				yyless(yyleng);
			}

<START>{COMMENT}	{
						int in = yyinput();
						while (in != '\n')
						{
							in = yyinput();
						}

						in = yyinput();
						if (in != '#' && in != '\n')
						{
							BEGIN(INITIAL);
						}

						/* push back unmatching char */
						unput(in);
					}

<NEWLINE>{COMMENT}	{
						int in = yyinput();
						while (in != '\n')
						{
							in = yyinput();
						}
						new_line++;

						/* check if there are more line comments */
						in = yyinput();
						if (in != '#')
						{
							BEGIN(INITIAL);
						}

						/* push back unmatching char */
						unput(in);
					}

{COMMENT}	{
				int in = yyinput();
				while(in != '\n')
				{
					in = yyinput();
				}
				unput(in);
				new_line++;
			}

<NEWLINE>{INDENT}	{
						int indent = 1;
						int in = yyinput();

						/* case: whitespace indent */
						if (in == ' ')
						{
							unput(in);
							while (in == ' ')
							{
								indent++;
								in = yyinput();
							}

							/* push back last unmatched char */
							unput(in);
						}

						/* case: tab indent */
						else if (in == '\t')
						{
							unput(in);
							while (in == '\t')
							{
								indent++;
								in = yyinput();
							}
							/* push back last unmatched char */
							unput(in);
						}

						/* case: only indent */
						else
						{
							/* push back last unmatched char */
							unput(in);
						}

						/* if indent level matches stack peek there's nothing to do */

						if (stack.peek() < indent)
						{
							stack.push(indent);
							std::cout << "INDENT";

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
							/*
							for (int i = 0; i < dedents - 1; i++)
							{
								return DEDENT;
							}
							*/
							std::cout << "DEDENT";
						}
					}

%%

int main(int argc, char *argv[])
{
	BEGIN(START);

	/* push zero to stack as proposed in Python documentation */
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