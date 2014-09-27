%{
#include <iostream>
#include "lib/stack.h"

int new_line = 1;
stack stack;

/*
LINE-COMMENT	"#".*"\n"
{LINE-COMMENT}	// we do nothing 
{NUMBER}		{std::cout << "NUMBER"; return NUMBER;}
*/

%}

%option noyywrap
%option outfile="pylex.cpp"


ID 					[a-zA-z][_a-zA-Z0-9]*
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


%s NEWLINE
%%

{KEYWORDS}		{
					std::cout << yytext;
					BEGIN(INITIAL);
				}
{OPERATORS}		{
					std::cout << yytext;
					BEGIN(INITIAL);
				}
{DELIMITERS} 	{
					std::cout << yytext;
					BEGIN(INITIAL);
				}

{FLOATNUMBER}	{ 
					/* yylval.flotante = atof(yytext); */
					std::cout << "NUMBER"; 
					BEGIN(INITIAL);
				}
{INTEGER}		{ 
					/* yylval.entero = atoi(yytext); */
					std::cout << "NUMBER"; 
					BEGIN(INITIAL);
				}

{NEWLINE}	{
				std::cout << "NEWLINE" << std::endl;
				/* return NEWLINE; */
				new_line++;

				int in = yyinput(); 
				if (in !='\t' && in != ' ' && in != '#')
				{
					int dedents = stack.peek();
					while(stack.peek() != 0)
					{
						stack.pop();
					}

					for (int i = 0; i < dedents; i++)
					{
						std::cout << "DEDENT";
						/* return DEDENT; */
					}
				}
				yyunput(in, yytext_ptr);
				BEGIN(NEWLINE);
			}

{ID}		{
				/* yylval.identificador = yytext; */
				std::cout << "ID";
				BEGIN(INITIAL);
			}

<NEWLINE>{COMMENT}	{
						int in = yyinput();
						while(in != '\n')
						{
							in = yyinput();
						}
						new_line++;
						BEGIN(INITIAL);
					}

{COMMENT}	{
				int in = yyinput();
				while(in != '\n')
				{
					in = yyinput();
				}
				yyunput(in, yytext_ptr);
				new_line++;
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

<NEWLINE>{INDENT}	{
						int indent = 1;
						int in = yyinput();

						/* case: whitespace indent */
						if (in == ' ')
						{
							yyunput(in, yytext_ptr);
							while (in == ' ')
							{
								indent++;
								in = yyinput();
							}

							/* push back last unmatched char */
							yyunput(in, yytext_ptr);
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

{EOF}		{std::cout << "EOF";}

%%

int main(int argc, char *argv[])
{
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