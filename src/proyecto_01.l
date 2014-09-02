%{
#include <iostream>
#include <stack.cpp>
using namespace std
%}

%option noyywrap
%option outfile="scanner.cpp"

FALSE		[False]
CLASS		[class]
FINALLY		[finally]
IS			[is]
RETURN		[return]
NONE		[None]
CONTINUE	[continue]
FOR			[for]
LAMBDA		[lambda]
TRY			[try]
TRUE		[True]
DEF			[def]
FROM		[from]
NONLOCAL	[nonlocal]
WHILE		[while]
AND			[and]
DEL			[del]
GLOBAL		[global]
NOT			[not]
WITH		[with]
AS			[as]
ELIF		[elif]
IF			[if]
OR			[or]
YIELD		[yield]
ASSERT		[assert]
ELSE		[else]
IMPORT		[import]
PASS		[pass]
BREAK		[break]
EXCEPT		[except]
IN			[in]
RAISE		[raise]

%%

{USERNAME} cout << "Nombre de usuario: " << yytext << endl;

%%

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		yyin = argv[1];
	}
}