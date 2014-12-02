#include "SymbolTable.hpp"

using namespace std;

int main(){
	//Creamos símbolos para probar el la tabla de símbolos
	string name="x";
	double val=2.3;
	Simbolo *s = new Simbolo(&name, &val);
	
	string name1="y";
	int val1=3;
	Simbolo *s1 = new Simbolo(&name1, &val1);
	
	string name2="z";
	string val2="cinco";
	Simbolo *s2 = new Simbolo(&name2, &val2);
		
	SymbolTable *tabla_de_simbolos = new SymbolTable;
	
	
	tabla_de_simbolos->insertName(s);
	cout<<"Se insertó algo en la tabla: ";
	s->imprime();
	tabla_de_simbolos->insertName(s1);
	cout<<"Se insertó algo en la tabla: ";
	s1->imprime();
	
	cout<<"EL estado actual de la tabla es:"<<endl;
	tabla_de_simbolos->printTable();
	
	tabla_de_simbolos->openScope();
	cout<<"Se abrió un nuevo alcance en la tabla"<<endl;
	
	tabla_de_simbolos->insertName(s2);
	cout<<"Se insertó algo en la tabla: ";
	s2->imprime();
	
	cout<<"EL estado actual de la tabla es:"<<endl;
	tabla_de_simbolos->printTable();
	
	if(tabla_de_simbolos->declaredLocally("z")==1)
		cout<<"z es una variable local\n";
	else
		cout<<"z NO es una variable local\n";
		
	if(tabla_de_simbolos->declaredLocally("x")==1)
		cout<<"x es una variable local\n";
	else
		cout<<"x NO es una variable local\n";
	
	
	
	cout<<"Vamos a buscar a w en la tabla de símbolos"<<endl;
	Simbolo *aux=tabla_de_simbolos->lookUp("w");	
	if(aux==NULL)
		cout<<"w NO existe"<<endl;
		
	cout<<"Vamos a buscar a x en la tabla de símbolos"<<endl;
	aux=tabla_de_simbolos->lookUp("x");
	if(aux!=NULL){
		cout<<"x es:"<<endl;
		aux->imprime();
	}
	
	
	cout<<"Se cerró un alcance en la tabla:\n";
	tabla_de_simbolos->closeScope();
	
	cout<<"EL estado actual de la tabla es:"<<endl;
	tabla_de_simbolos->printTable();
	
	free(s);
	free(s1);
	free(s2);
	free(aux);
	free(tabla_de_simbolos);
	
	
	
}
