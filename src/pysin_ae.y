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
%token	<cadena> STRING MAS MENOS POR ENTRE MOD DIV POT OPERATOR DELIMITER FALSE CLASS FINALLY IS RETURN NONE CONTINUE FOR LAMBDA TRY TRUE DEF FROM WHILE AND DEL NOT WITH AS ELIF IF OR ELSE IMPORT PASS BREAK EXCEPT IN PRINT COMMA DOT ASSIGN TWODOTS GLOBAL DOTCOMMA EOF
%token	<identificador>	NAME
%token DEDENT INDENT NEWLINE 

/*Aquí van los tipos*/
/*%type <double> */


%%
/*Aquí va la gramática*/

/* Expresiones aritméticas */
epsilon:	{/*Nada xD*/};

arithmetic_expr: /*term ('+' term)*			{};
		|term ('-' term)*			{};*/
	term sign_term				{ std::cout << " "; };
		
sign_term: epsilon					{ std::cout << " "; }
	|term MAS sign_term				{ std::cout << " "; }
	|term MENOS sign_term				{ std::cout << " "; };

term: /*factor ('*'factor)*;
	| factor ('/'factor)*;
	| factor ('%' factor)*;
	| factor ("//" factor)*;*/
	factor_operation				{ std::cout << " "; };
	
factor_operation: epsilon				{ std::cout << " "; }
	|POR factor factor_operation			{ std::cout << " "; }
	|ENTRE factor factor_operation			{ std::cout << " "; }
	|MOD factor factor_operation			{ std::cout << " "; }
	|DIV factor factor_operation			{ std::cout << " "; };

factor: /*'+' factor;
	| '-' factor;
	| '~' factor;
	| power;*/
	MAS factor 			{ std::cout << " "; }
	|MENOS factor 		{ std::cout << " "; }
	|MAS factor			{ std::cout << " "; }
	|OPERATOR factor 	{checkString($1,"~");};

power: atom		{ std::cout << " "; }
	/*atom trailer* ['**' factor];*/
	/* atom trailer_kleene				{} */
	/* |atom trailer_kleene POT factor			{}; */

atom: NAME 		{ std::cout << " "; }
	| NUMBER	{ std::cout << " "; };

%%


int main() {

	while(seguir){
		printf(">> ");
		yyparse();
	}
	return 0;
}