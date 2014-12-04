%{
#include <string>
#include <vector>
#include <iostream>
#include "../lib/Stack.h"
#include "pysin.hpp"
stack stack;
int new_line = 1;
int newline_dedent = 0;

extern int yyparse();



%}

%option noyywrap
%option outfile="pylex.cpp"

/* Numbers */
NAME 				[a-zA-z][_a-zA-Z0-9]*
/*NUMBER				{INTEGER}|{FLOATNUMBER}*/
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
EOF					"<<EOF>>"
TABNEWLINE			(("\t"|" ")+"\n")+

/* Operators */
MAS			"+"
MENOS		"-"
POR			"*"
ENTRE		"/"
MOD			"%"
EXP			"^"
DIV			"//"
POT			"**"
MASIGUAL	"+="
MENOSIGUAL	"-="
PORIGUAL	"*="
ENTREIGUAL	"/="
DIVIGUAL	"//="
MODIGUAL	"%="
ANDIGUAL	"&="
ORIGUAL		"|="
EXPIGUAL	"^="
POTIGUAL	"**="
APOSTROFE	"'"
PICOPARENTESIS	"<>"
BINRIGHTIGUAL	">>="
BINLEFTIGUAL	"<<="

/* Keywords */
GLOBAL		"global"
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

/* Delimiters */
COMMA		","
DOT			"."
ASSIGN		"="
TWODOTS		":"
DOTCOMMA	";"
BINLEFT		"<<"
BINRIGHT	">>"
ANDPAND		"&"
PIPE		"|"
TILDE		"~"
LESSTHAN	"<"
MORETHAN	">"
LESSEQUAL	"<="
MOREEQUAL	">="
EQUALS		"=="
DIFFERENT	"!="
OPENPAR		"("
CLOSEPAR	")"
OPENCOR		"["
CLOSECOR	"]"
OPENKEY		"{"
CLOSEKEY	"}"
AT			"@"
RIGHT		"->"

%s START
%s NEWLINE_CONTEXT
%s DEDENT_CONTEXT
%x EOF_CONTEXT
%%

{APOSTROFE}		{ BEGIN(INITIAL); return APOSTROFE; }
{EXP}			{ BEGIN(INITIAL); return EXP; }
{OPENCOR}		{ BEGIN(INITIAL); return OPENCOR; }
{CLOSECOR}		{ BEGIN(INITIAL); return CLOSECOR; }
{MAS}			{ BEGIN(INITIAL); return MAS; }
{MENOS}			{ BEGIN(INITIAL); return MENOS; }
{POR}			{ BEGIN(INITIAL); return POR; }
{ENTRE}			{ BEGIN(INITIAL); return ENTRE; }
{MOD}			{ BEGIN(INITIAL); return MOD; }
{DIV}			{ BEGIN(INITIAL); return DIV; }
{POT}			{ BEGIN(INITIAL); return POT; }
{GLOBAL}		{ BEGIN(INITIAL); return GLOBAL; }
{FALSE}			{ BEGIN(INITIAL); return FALSE; }
{CLASS}			{ BEGIN(INITIAL); return CLASS; }
{FINALLY}		{ BEGIN(INITIAL); return FINALLY; }
{IS}			{ BEGIN(INITIAL); return IS; }
{NONE}			{ BEGIN(INITIAL); return NONE; }
{RETURN}		{ BEGIN(INITIAL); return RETURN; }
{CONTINUE}		{ BEGIN(INITIAL); return CONTINUE; }
{FOR}			{ BEGIN(INITIAL); return FOR; }
{LAMBDA}		{ BEGIN(INITIAL); return LAMBDA; }
{TRY}			{ BEGIN(INITIAL); return TRY; }
{TRUE}			{ BEGIN(INITIAL); return TRUE; }
{DEF}			{ BEGIN(INITIAL); return DEF; }
{FROM}			{ BEGIN(INITIAL); return FROM; }
{WHILE}			{ BEGIN(INITIAL); return WHILE; }
{AND}			{ BEGIN(INITIAL); return AND; }
{DEL}			{ BEGIN(INITIAL); return DEL; }
{NOT}			{ BEGIN(INITIAL); return NOT; }
{WITH}			{ BEGIN(INITIAL); return WITH; }
{AS}			{ BEGIN(INITIAL); return AS; }
{ELIF}			{ BEGIN(INITIAL); return ELIF; }
{IF}			{ BEGIN(INITIAL); return IF; }
{OR}			{ BEGIN(INITIAL); return OR; }
{ELSE}			{ BEGIN(INITIAL); return ELSE; }
{IMPORT}		{ BEGIN(INITIAL); return IMPORT; }
{PASS}			{ BEGIN(INITIAL); return PASS; }
{BREAK}			{ BEGIN(INITIAL); return BREAK; }
{EXCEPT}		{ BEGIN(INITIAL); return EXCEPT; }
{IN}			{ BEGIN(INITIAL); return IN; }
{PRINT}			{ BEGIN(INITIAL); return PRINT; }

{COMMA}			{ BEGIN(INITIAL); return COMMA; } 
{DOT}			{ BEGIN(INITIAL); return DOT; }
{ASSIGN}		{ BEGIN(INITIAL); return ASSIGN; }
{TWODOTS}		{ BEGIN(INITIAL); return TWODOTS; }
{DOTCOMMA}		{ BEGIN(INITIAL); return DOTCOMMA; }

{BINLEFT}		{ BEGIN(INITIAL); return BINLEFT; }
{BINRIGHT}		{ BEGIN(INITIAL); return BINRIGHT; }
{ANDPAND}		{ BEGIN(INITIAL); return ANDPAND; }
{PIPE}			{ BEGIN(INITIAL); return PIPE; }

{TILDE}			{ BEGIN(INITIAL); return TILDE; }
{LESSTHAN}		{ BEGIN(INITIAL); return LESSTHAN; }
{MORETHAN}		{ BEGIN(INITIAL); return MORETHAN; }
{LESSEQUAL}		{ BEGIN(INITIAL); return LESSEQUAL; }
{MOREEQUAL}		{ BEGIN(INITIAL); return MOREEQUAL; }
{EQUALS}		{ BEGIN(INITIAL); return EQUALS; }

{OPENPAR}		{ BEGIN(INITIAL); return OPENPAR; }
{CLOSEPAR}		{ BEGIN(INITIAL); return CLOSEPAR; }
{OPENKEY}		{ BEGIN(INITIAL); return OPENKEY; }
{CLOSEKEY}		{ BEGIN(INITIAL); return CLOSEKEY; }
{AT}			{ BEGIN(INITIAL); return AT; }
{RIGHT}			{ BEGIN(INITIAL); return RIGHT; }
{MASIGUAL}		{ BEGIN(INITIAL); return MASIGUAL; }
{MENOSIGUAL}	{ BEGIN(INITIAL); return MENOSIGUAL; }
{PORIGUAL}		{ BEGIN(INITIAL); return PORIGUAL; }
{ENTREIGUAL}	{ BEGIN(INITIAL); return ENTREIGUAL; }
{DIVIGUAL}		{ BEGIN(INITIAL); return DIVIGUAL; }
{MODIGUAL}		{ BEGIN(INITIAL); return MODIGUAL; }
{ANDIGUAL}		{ BEGIN(INITIAL); return ANDIGUAL; }
{ORIGUAL}		{ BEGIN(INITIAL); return ORIGUAL; }
{EXPIGUAL}		{ BEGIN(INITIAL); return EXPIGUAL; }
{BINRIGHTIGUAL}	{ BEGIN(INITIAL); return BINRIGHTIGUAL; }
{BINLEFTIGUAL}	{ BEGIN(INITIAL); return BINLEFTIGUAL; }
{POTIGUAL}		{ BEGIN(INITIAL); return POTIGUAL; }

{FLOATNUMBER}	{ 
					yylval.flotante = atof(yytext);
					BEGIN(INITIAL);
					return FLOATNUMBER;
				}
{INTEGER}		{ 
					yylval.entero = atoi(yytext);
					BEGIN(INITIAL);
					return INTEGER;
				}

{NAME}		{
				std::cout << "NAME:" << yytext << std::endl;
				yylval.cadena = yytext;
				BEGIN(INITIAL);
				return NAME;
			}

{STRING}	{
				char in = yyinput();
				std::string str;
				while (in != '"')
				{
					/* Concatenate char to string for bison token */
					str += in;
					/* Python doesnt allow multi-line strings */
					in = yyinput();
					if (in == '\n' || in == EOF)
					{
						std::cout << "File \"" << yyin << "\", line " << new_line << std::endl;
						std::cout << "Syntax error: EOL while scanning a string" << std::endl;
						yyterminate();
					}
				}

				/*
				*/
				char* cstr = new char[str.size() + 1];
				std::copy(str.begin(), str.end(), cstr);
				cstr[str.size()] = '\0';
				std::cout << "STRING: " << cstr << std::endl;
				yylval.cadena = cstr;
				/*
				delete[] cstr;
				std::vector<char> cstr(str.begin(), str.end());
				cstr.push_back('\0');
				std::cout << "STRING: " << &*cstr.begin() << std::endl;
				yylval.cadena = &*cstr.begin();
				*/

				/*yylval.cadena = yytext;*/
				

				BEGIN(INITIAL);
				return STRING;
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

<DEDENT_CONTEXT>{NEWLINE}	{
								char in = yyinput();
								/* if it's an indent */
								if (in == '\t' || in == ' ')
								{
									/* push back unmatching char */
									unput(in);
									BEGIN(NEWLINE_CONTEXT);
									/*std::cout<<"newline";*/
									return NEWLINE;
								}
								/* if it's a comment */
								else if (in == '#')
								{
									/* push back unmatching char */
									unput(in);
									BEGIN(NEWLINE_CONTEXT);
									/*std::cout<<"newline";*/
									return NEWLINE;
								}
								/* if it's not an INDENT or COMMENT check DEDENT */
								else
								{
									int eof_reached = (in == EOF) ? 1 : 0;

									/* push back unmatching char */
									unput(in);

									/* if last DEDENT was returned */
									if (stack.peek() == 0)
									{
										newline_dedent = 0;

										if (eof_reached)
										{
											BEGIN(NEWLINE_CONTEXT);
										}
										else
										{
											BEGIN(INITIAL);
										}

										if (!newline_dedent)
										{
											return NEWLINE;
										}
									}
									/* there are still DEDENTS level to pop */
									else
									{
										if (!newline_dedent)
										{
											newline_dedent = 1;
											/* push back newline for next DEDENT */
											unput('\n');
											/*std::cout<<"newline";*/
											return NEWLINE;
										}
										else
										{
											stack.pop();
											/* push back newline for next DEDENT */
											unput('\n');
											/*std::cout<<"dedent";*/
											return DEDENT;
										}
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
				BEGIN(DEDENT_CONTEXT);
				// yyless(yyleng);
				unput('\n');
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

<NEWLINE_CONTEXT>{COMMENT}	{
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

<NEWLINE_CONTEXT>{TABNEWLINE}	{
									for (int i = 0; i < yyleng; i++)
									{
										char c = yytext[i];
										if (c == '\n')
										{
											new_line++;
										}
									}

									BEGIN(NEWLINE_CONTEXT);
								}

<NEWLINE_CONTEXT>{INDENT}	{
								int indent = 0;
								if (yytext == "\t")
								{
									indent = 8;
								}
								else
								{
									indent = 1;
								}

								int in = yyinput();
								while (in == ' ' || in == '\t')
								{
									/* case: whitespace indent */
									if (in == ' ')
									{
										indent++;
									}

									/* case: tab indent */
									else if (in == '\t')
									{
										indent+=8;
									}

									in = yyinput();
								}

								/* push back last unmatched char */
								unput(in);
								/*if(in =='\n'){
									std::cout<<"Aqui hay algo chueco\n";
									
									
								}*/
								/* if indent level matches stack peek there's nothing to do */

								if (stack.peek() < indent)
								{
									stack.push(indent);
									/*std::cout<<"indent";*/
									return INDENT;

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
									/*std::cout<<"dedent";*/
									return DEDENT;
								}
							}

<NEWLINE_CONTEXT><<EOF>>	{ 
								// std::cout << std::endl << "<NEWLINE_CONTEXT><<EOF>>" << std::endl;
								yyterminate();
							}

<EOF_CONTEXT><<EOF>>	{
							// std::cout << std::endl << "<EOF_CONTEXT><<EOF>>" << std::endl;
							if (stack.peek() != 0)
							{
								stack.pop();
								return DEDENT;
							}
							else
							{
								yyterminate();
							}
						}

<<EOF>>	{
			// std::cout << std::endl << "<<EOF>>" << std::endl;
			// yyterminate();
			BEGIN(EOF_CONTEXT);
			return NEWLINE;
		}

%%

int main(int argc, char* argv[]) 
{
	stack.push(0);
	BEGIN(START);
	if (argc > 1)
	{
		FILE *file =fopen(argv[1],"r");
		yyin=file;
	} 
	else
	{
		yyin = stdin;
	}

	do {
		extern int yydebug;
		/*yydebug = 1;*/
		yyparse();
	} while (!feof(yyin));
	
	
	
}
