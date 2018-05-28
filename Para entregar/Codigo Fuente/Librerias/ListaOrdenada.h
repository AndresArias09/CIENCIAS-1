/**
	@file ListaOrdenada.h
	@brief Clase que realiza todas las operaciones de una lista dinamica ordenada descendentemente

	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef LISTAO_H
#define LISTAO_H
#include <stddef.h>

template<class T>
struct node {
	float clave;
	T info;
	node *sig;
};

template<class T>
class ListaO{
	//estructura de datos donde x es el dato a guardar y sig es la posicion a la que apunta despues
	node<T> *cab;
	node<T> *fin;
	node<T> *auxinicio;
	node<T> *auxfin;
	int tam;
	
	public:
		/**
			@brief Contructor
		*/
		ListaO(){
			auxinicio = new node<T>;
			auxfin = new node<T>;
			cab=auxinicio;
			auxinicio->sig=auxfin;
			fin=auxfin;
			tam=0;
		}
		/**
			@brief Inidica si la lista se encuentra vacia
			@param Retorna un booleano que indica si esta vacia o no
		*/
		bool lista_vacia(){
			if(tam==0){
				return true;
			}
			else {
				return false;
			}
		}
		/**
			@brief Añade un elemento a la lista, ordenandolo
			@param clave, float que corresponde a la clave con la cual sera ordenado el elemento
			@param info, T que corresponde a la informacion asociada a esa clave
		*/
		void anadir(float clave,T info){
			node<T> *b,*actual,*anterior;//creando un node 
			b= new node<T>;//separando memoria
			b->clave=clave;//llenando la info con el dato dado
			b->info= info;//la info
			b->sig=NULL;
			if (lista_vacia()){
				auxinicio->sig=b;
				b->sig=auxfin;
			}
			else{
				actual = auxinicio->sig;
				anterior = auxinicio;
				int i;
				for (i=0;i<=tam; i++){
					if(clave>actual->clave||actual==auxfin){
						b->sig=actual;
						anterior->sig=b;
						break;
					}
					else{
						anterior = actual;
						actual = actual->sig;
					}			
				}	
			}
			tam++;
		}
		/**
			@brief Devuelve la informacion que se encuentra en la posicion dada
			@param posicion, int que corresponde a la posicion que se desea mostrar
			@returns Retorna la informacion asociada a la clave
		*/
		T devolverDato(int posicion){	
				//if(lista_vacia()) return 0;
					node<T> *b;
					int contador;
					b = new node<T>;
					b = auxinicio->sig;
					contador = 0;
					while(true){
						if(contador==posicion){
							break;
						}
						else{
							contador++;
							b = b -> sig;
						}
					}
					return b->info;
					//delete b;
		}
		/**
			@brief Devuelve la clave del elemento que se encuentre en la posicion
			@param posicion, int que corresponde a la posicion que se desea mostrar
			@return Retorna la clave asociada al elemento en la posicion
		*/
		float devolverClave(int posicion){	
				//if(lista_vacia()) return 0;
					node<T> *b;
					int contador;
					b = new node<T>;
					b = auxinicio->sig;
					contador = 0;
					while(true){
						if(contador==posicion){
							break;
						}
						else{
							contador++;
							b = b -> sig;
						}
					}
					return b->clave;
					//delete b;
		}
		/**
			@brief Devuelve la cantidad de registros que tiene la lista
			@returns Retorna un entero con la cantidad de elementos de la lista
		*/
		int getTam(){
			return tam;
		}	
};
#endif
