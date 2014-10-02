%{
#include <iostream>
#include "pysin.hpp"
#include "lib/stack.h"

stack stack;
int new_line = 1;
bool started = true;

extern int yyparse();

%}

%option noyywrap
%option outfile="pylex.cpp"

/* Numbers */
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
EOF					"<<EOF>>"

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
%%

{APOSTROFE}		return APOSTROFE;
{EXP}			return EXP;
{OPENCOR}		return OPENCOR;
{CLOSECOR}		return CLOSECOR;
{MAS}			return MAS;
{MENOS}			return MENOS;
{POR}			return POR;
{ENTRE}			return ENTRE;
{MOD}			return MOD;
{DIV}			return DIV;
{POT}			return POT;
{GLOBAL}		return GLOBAL;
{FALSE}			return FALSE;
{CLASS}			return CLASS;
{FINALLY}		return FINALLY;
{IS}			return IS;
{NONE}			return NONE;
{RETURN}		return RETURN;
{CONTINUE}		return CONTINUE;
{FOR}			return FOR;
{LAMBDA}		return LAMBDA;
{TRY}			return TRY;
{TRUE}			return TRUE;
{DEF}			return DEF;
{FROM}			return FROM;
{WHILE}			return WHILE;
{AND}			return AND;
{DEL}			return DEL;
{NOT}			return NOT;
{WITH}			return WITH;
{AS}			return AS;
{ELIF}			return ELIF;
{IF}			return IF;
{OR}			return OR;
{ELSE}			return ELSE;
{IMPORT}		return IMPORT;
{PASS}			return PASS;
{BREAK}			return BREAK;
{EXCEPT}		return EXCEPT;
{IN}			return IN;
{PRINT}			return PRINT;

{COMMA}			return COMMA; 
{DOT}			return DOT;
{ASSIGN}		return ASSIGN;
{TWODOTS}		return TWODOTS;
{DOTCOMMA}		return DOTCOMMA;

{BINLEFT}		return BINLEFT;
{BINRIGHT}		return BINRIGHT;
{ANDPAND}		return ANDPAND;
{PIPE}			return PIPE;

{TILDE}			return TILDE;
{LESSTHAN}		return LESSTHAN;
{MORETHAN}		return MORETHAN;
{LESSEQUAL}		return LESSEQUAL;
{MOREEQUAL}		return MOREEQUAL;
{EQUALS}		return EQUALS;

{OPENPAR}		return OPENPAR;
{CLOSEPAR}		return CLOSEPAR;
{OPENKEY}		return OPENKEY;
{CLOSEKEY}		return CLOSEKEY;
{AT}			return AT;
{RIGHT}			return RIGHT;
{MASIGUAL}		return MASIGUAL;
{MENOSIGUAL}	return MENOSIGUAL;
{PORIGUAL}		return PORIGUAL;
{ENTREIGUAL}	return ENTREIGUAL;
{DIVIGUAL}		return DIVIGUAL;
{MODIGUAL}		return MODIGUAL;
{ANDIGUAL}		return ANDIGUAL;
{ORIGUAL}		return ORIGUAL;
{EXPIGUAL}		return EXPIGUAL;
{BINRIGHTIGUAL}	return BINRIGHTIGUAL;
{BINLEFTIGUAL}	return BINLEFTIGUAL;
{POTIGUAL}		return POTIGUAL;
{EOF}			;

{FLOATNUMBER}	{ 
					/* yylval.flotante = atof(yytext); */
					BEGIN(INITIAL);
					return NUMBER;
				}
{INTEGER}		{ 
					/* yylval.entero = atoi(yytext); */
					BEGIN(INITIAL);
					return NUMBER;
				}

{NAME}		{
				/* yylval.identificador = yytext; */
				BEGIN(INITIAL);
				return NAME;
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
								int in = yyinput();
								/* if it's an indent */
								if (in == '\t' || in == ' ')
								{
									/* push back unmatching char */
									unput(in);
									BEGIN(NEWLINE_CONTEXT);
									return NEWLINE;
								}
								/* if it's a comment */
								else if (in == '#')
								{
									/* push back unmatching char */
									unput(in);
									BEGIN(NEWLINE_CONTEXT);
									return NEWLINE;
								}
								/* if it's not an INDENT or COMMENT check DEDENT */
								else
								{
									/* push back unmatching char */
									unput(in);

									/* if last DEDENT was returned */
									if (stack.peek() == 0)
									{
										BEGIN(INITIAL);
										return NEWLINE;
									}
									/* there are still DEDENTS level to pop */
									else
									{
										stack.pop();
										/* push back newline for next DEDENT */
										// yyless(yyleng);
										unput('\n');
										return DEDENT;
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

<NEWLINE_CONTEXT>{INDENT}	{
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
									/*
									for (int i = 0; i < dedents - 1; i++)
									{
										return DEDENT;
									}
									*/
									return DEDENT;
								}
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
		yyparse();
	} while (!feof(yyin));
}