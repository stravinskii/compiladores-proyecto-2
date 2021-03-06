/**
 * Esta biblioteca de c++ nos sirve para modelar una variable en la tabla de símbolos
 * para nuestro compilador de Python, así mismo se define un tipo "tipo", el cual
 * va a modelar el tipo de la variable en cuestión, este tipo es una unión.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */


#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
/**
 * Definción de tipo, en este tipo almacenaremos el valor de la variable
 */
union tipo{
	int integer;
	float float_number;
	string cadena;
};

/**
 * Definición de la clase Símbolo
 */
class Simbolo{
	public:
		string *name;
		tipo *valor;
		int type;
		
		Simbolo(string *n){
			valor= (tipo*)malloc(sizeof(tipo));
			name=n;
			type=3;
		}
	
		Simbolo(string *n, int *val){
			valor= (tipo*)malloc(sizeof(tipo));
			name=n;
			valor->integer =*val;
			type=0;
		}
		
		Simbolo(string *n, float *val){
			valor= (tipo*)malloc(sizeof(tipo));
			name=n;
			valor->float_number=*val;
			type=1;
		}
		
		Simbolo(string *n, string *val){
			valor=(tipo*) new string;
			name=n;
			valor->cadena =*val;
			type=2;
		}
		
		tipo* getValor(){
			return valor;
		}
		
		string* getName(){
			return name;
		}
		
		void setValue(int val){
			this->type=0;
			valor->integer=val;
		}
		
		void setValue(float val){
			this->type=1;
			valor->float_number=val;
		}
		
		void setValue(string *val){
			this->type=2;
			valor->cadena =*val;
		}
		
		int getType(){
			return type;
		}
		
		void imprime(){
			if(type==0)
				cout<<*name<<" = "<<(*valor).integer<<" | int"<<endl;
			if(type==1)
				cout<<*name<<" = "<<(*valor).float_number<<" | float"<<endl;
			if(type==2)
				cout<<*name<<" = "<<(*valor).cadena<<" | string"<<endl;
			if(type==3)
				cout<<*name<<" =   | dynamic type"<<endl;
			
		}
};
