/**
 * Definición de la biblioteca SymbolTable para la tabla de símbolos para
 * nuestro compilador de python
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */
 
#include "LexList.hpp"
#include <vector>

class SymbolTable{
	/**
	 * Esta variable modela la Lista léxica que contiene a tabla de símbolos
	 * dividida en niveles, uno por cada nivel léxico
	 */
	LexList *symbolTable= new LexList;
	 public:
	 /**
	  * lookUp regresa la estructura que contiene los atributos de la declaración
	  * válida actual de name. Si no existe una declaración válida activa de nombre 
	  * regresa un valor que lo indique, generalmente un apuntador nulo.
	  */
	Simbolo* lookUp(string name){
		cout<<"looking up..."<<endl;
		return symbolTable->lookUp(name);
	 }
	 
	 /**
	  * insert(name, record) ingresa nombre en la tabla de símbolos bajo el alcance activo.
	  * record contiene los atributos del símbolo, obtenidos a partir de su declaración.
	  */
	void insertName(Simbolo *record){
		symbolTable->insertName(record);
	 }
	 
	void deleteName(Simbolo *record){
		symbolTable->deleteName(record);
	}
	 
	 /**
	  * openScope() abre un nuevo alcance en la tabla de símbolos. Los símbolos nuevos
	  * se ingresarán en el alcance resultante.
	  */
	 void openScope(){
		 symbolTable->addLevel();
	 }
	 
	 /**
	  * closeScope() cierra el alcance más recientemente abierto en la tabla de símbolos.
	  * Las subsecuentes referencias a símbolos se revierten hacia los alcances exteriores.
	  */
	 void closeScope(){
		 symbolTable->deleteLevel();
	 }

	/**
	 * declaredLocally(name) verifica si name está presente en el alcance actual 
	 * (más interno) y de ser así regresa true . Si name está en un alcance exterior, 
	 * o no está en la tabla de símbolos, regresa false .
	 */
	int declaredLocally(string name){
		return symbolTable->declaredLocally(name);
	}
	
	vector<Simbolo> getOrderedTable(){
		return symbolTable->getOrderedTable();
	}
	
	int tamanio(){
		return symbolTable->tamanio();
	}
	
	void printTable(){
		symbolTable->printTable();
	}
	 
};
 
 
 
