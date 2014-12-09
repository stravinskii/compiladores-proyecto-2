/**
 * Definición de la clase LexList, esta clase nos va a permitir tener una lsita
 * de nodos, cada nodo contiene una tabla hash para almacenar las variables
 * visibles en este nodo, cada uno de los nodos representa un nivel léxico
 * en la tabla de símbolos.
 *
 * @author: Alejandro Hernández Mora
 * @author: Alan Mauricio García García
 */

#include <unordered_map>
#include <vector>
#include "Simbolo.hpp"

using namespace std;

typedef unordered_map <string, Simbolo> hasht;

/**
 * LexNode: Esta estructura nos permite modelar un nivel léxico
 * Atributos:
 * 			int lexLevel: Nivel léxico del nodo
 * 			hast *tabla: apuntador a la tabla hash de este nivel léxico
 * 			LexNode *Next: apuntador al nodo con el nivel léxico de su padre
 * 					(Es decir un nodo con un nivel léxico un nivel menor al suyo)
 */
struct LexNode{
		int lexLevel;
		hasht *tabla;
		LexNode *next;
	};

/**
 * Definición de la clase
 */
class LexList{
	/**
	 * La cabeza de la lista de niveles léxicos, es un LexNode
	 */
	LexNode *head;
	
	public:
		LexList(){
			LexNode *n= new LexNode;
			n->lexLevel=0;
			n->tabla=new hasht;
			n->next=NULL;
			head=n;
		} 
	
	/**
	 * Permite agregar un nivel léxico (representado por un LexNode) a la tabla de símbolos
	 */
	void addLevel(){
		LexNode *n=new LexNode;
		n->lexLevel=head->lexLevel+1;
		n->tabla= new hasht;
		n->next=head;
		head=n;				
	}
	
	/**
	 * deleteLevel(): Elimina el último nivel léxico que se encuentra en la cabeza
	 */
	void deleteLevel(){
		if(head->next!=NULL)
			head=head->next;
		else
			head=NULL;
	}
	
	/**
	 * lookUp(String name): Regresa un apuntador a la entrada que contiene a
	 * 			la variable asociada a la cadena name, en la tabla de símbolos que buscamos.
	 * 			Si la variable no se encuentra en la tabla regresa NULL;
	 */
	Simbolo* lookUp(string name){
		LexNode *temp=head;
		
		while(temp != NULL){
			hasht::const_iterator got = temp->tabla->find (name);
			if(got!=temp->tabla->end()){
				Simbolo *s= (Simbolo*)malloc(sizeof(Simbolo *));
				*s=got->second;
				
				return s;
			}
			temp=temp->next;
		}
		return NULL;
	}
	
	/**
	 * declaredLocally(): Método que nos sirve para saver si una variable fue declarada localmente
	 * 			en el nivel léxico que nos encontramos.
	 * 			regresa 1 si es local y 0 en otro caso.
	 */
	int declaredLocally(string name){
		hasht::const_iterator got = head->tabla->find(name);
		
		if(got!=head->tabla->end()){
			return 1;
		}
		return 0;
	}
	
	/**
	 * insertName(name, s): Nos permite insertar en el nivel léxico actual de la tabla de
	 * 			símbolos una variable con el nombre name con un símbolo s asociado.
	 */
	void insertName(Simbolo *s){
		string *name=s->getName();
		
		if(lookUp(*name)==NULL){
			pair<string,Simbolo> nuevo (*name,*s);
			head->tabla->insert(nuevo);
		}else{
			if(!declaredLocally(*name)){
				pair<string,Simbolo> nuevo (*name,*s);
				head->tabla->insert(nuevo);
			}else
				cout<<"Error: variable ya declarada"<<endl;
		}
	}
	
	void deleteName(Simbolo *s){
		string *name=s->getName();
		if(lookUp(*name)==NULL){
			cout<<"Error: la variable no se encuentra en la tabla"<<endl;
		}else{
			head->tabla->erase(*name);
		}
	}
	
	void printTable(){
		LexNode *temp= head;
		while(temp!=NULL){
			cout<<"******************************************\nNivel: "<<temp->lexLevel<<endl;
			printLexLevel(temp);
			cout<<"******************************************\n";
			temp=temp->next;
		}
	}
	
	void printLexLevel(LexNode *actual){
		for (auto& x: *actual->tabla){
			Simbolo sim= x.second;
			sim.imprime();
		}		
	}
	
	int tamanio(){
		LexNode *temp= head;
		int tamanio=0;
		while(temp!=NULL){
			tamanio=tamanio+temp->tabla->size();
			temp=temp->next;
			cout<<tamanio<<endl;
		}
		return tamanio;
	}
	
	vector<Simbolo> getOrderedTable(){
		vector<Simbolo> arr;
		int tam= tamanio();
		arr.reserve(tam);
		LexNode* temp=head;
		tam=0;
		while(temp!=NULL){
			for (auto& x: *temp->tabla){
				arr[tam]=x.second;
				x.second.imprime();
				tam++;
			}
			temp=temp->next;
		}
		return arr;
	}
	
	

};
