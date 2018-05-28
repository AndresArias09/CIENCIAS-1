/**
	@file Lista.h
	@brief Clase que realiza todas las operaciones de una lista dinamica	

	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef LISTA_H
#define LISTA_H
#include <stddef.h>
template <class T>

struct nodo {
	T x;
	nodo <T> *sig;
};

template <class T>
class Lista {
	//estructura de datos donde x es el dato a guardar y sig es la posicion a la que apunta despues
	nodo<T> *cab;
	nodo<T> *fin;
	int tam;
	
	public:
		/**
			@brief Constructor
		*/
		Lista(){
			cab=NULL;
			fin=NULL;
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
			@brief Añade un elemento al final lista
			@param dato, T que corresponde al dato que sera ingresado
		*/
		void anadir_final(T dato){
			nodo <T> *b;//creando un nodo 
			b= new nodo <T>;//separando memoria
			b->x=dato;//llenando la info con el dato dado
			b->sig= NULL;//no apunta a nada
			//mueve el apuntador de la cab y del fin
			if(lista_vacia()){
				cab=fin=b;
			}
			else{
				fin->sig=b;
				fin=b;
			}
			tam++;
		}
		/**
			@brief Añade un elemento al inicio de la lista
			@param dato, T que corresponde al dato que sera ingresado
		*/
		void anadir_inicio(T dato){
			nodo <T> *b;//creando un nodo 
			b= new nodo <T>;//separando memoria
			b->x=dato;//llenando la info con el dato dado
			b->sig= NULL;//no apunta a nada
			//mueve el apuntador de la cab y del fin
			if(lista_vacia()){
				cab=fin=b;
			}
			else{
				b->sig=cab;
				cab=b;
			}
			tam++;
		}
		/**
			@brief Añade un elemento en la posicion dada de la lista
			@param dato, T que corresponde al dato que sera ingresado
			@param posicion, int que corresponde a la posicion en la que se insertara el elemento en la lista
		*/
		void anadir_posicion (T dato, int posicion){
			if(posicion==0){
				anadir_inicio(dato);
			}
			else if(posicion>=(tam-1)){
				anadir_final(dato);
			}
			else{
				nodo<T> *anterior, *actual;
				int contador = 1;
				actual = cab->sig;
				anterior = cab;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						anterior = actual;
						actual = actual->sig;
					}
				}
				nodo<T> *b;
				b = new nodo<T>;
				b->x = dato;
				b->sig = actual;
				anterior-> sig = b;
				tam++;
			}
		}
		/**
			@brief Elimina el elemento que este al inicio de la lista
		*/
		void eliminarInicio(){
			nodo<T> *b;
			b = cab;
			cab = cab -> sig;
			delete b;
			tam--;
		}
		/**
			@brief Modifica el elemento que se encuentre en la posicion de la lista dada
			@param valorNuevo, T que corresponde a la nueva informacion del elemento
			@param posicion, int que corresponde a la posicion en donde se insertara el elemento
		*/
		void modificar(T valorNuevo, int posicion){
			if(posicion==0){
				cab->x = valorNuevo;
			}
			else if(posicion>=(tam-1)){
				fin->x = valorNuevo;
			}
			else{
				nodo<T> *b;
				int contador;
				b = new nodo<T>;
				b = cab->sig;
				contador = 1;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						b = b -> sig;
					}
				}
				b->x = valorNuevo;
			}
		}
		/**
			@brief Elimina el elemento que este al final de la lista
		*/
		void eliminar_final(){
			nodo <T> *b;//creando un nodo 
			//b= new nodo <T>;//separando memoria
			if(!lista_vacia()){
				b=cab;
				int i;
				for (i=1;i<tam-1; i++){
					b=b->sig;
			}
			delete fin;
			fin=b;
			tam--;	
			}
		}
		/**
			@brief Elimina el elemento que este en la posicion dada de la lista
			@param posicion, int
		*/
		void eliminar_posicion(int posicion){
			if (posicion>=tam-1){
				eliminar_final();
			}
			else if( posicion==0){
				eliminarInicio();
			}
			else{
				nodo <T> *b;//creando un nodo 
				nodo <T> *c;//creando un nodo 
				//b= new nodo <T>;//separando memoria
								
				if(!lista_vacia()){
					b=cab;
					c=cab;
					int i;
					for (i=0;i<posicion; i++){
						b=b->sig;
					}
					for (i=1;i<posicion; i++){
						c=c->sig;
					}
					//b->sig=c->sig;
					c->sig = b->sig;
					delete b;
					//delete c;
					tam--;
				}
			}	
		}
		/**
			@brief Devuelve el dato que se encuentre en la posicion dada
			@param posicion, int que corresponde a la posicion de la que se quiere consultar el dato
			@returns Retornar el elemento
		*/
		T devolverDato(int posicion){
				//if(lista_vacia()) return 0;
				if(posicion==0){
					return cab->x;
				}
				else if(posicion>=(tam-1)){
					return fin->x;
				}
				else{
					nodo<T> *b;
					int contador;
					b = new nodo<T>;
					b = cab->sig;
					contador = 1;
					while(true){
						if(contador==posicion){
							break;
						}
						else{
							contador++;
							b = b -> sig;
						}
					}
					return b->x;
					//delete b;
				}
			}
		/**
			@brief Retorna la cantidad de elementos que tenga la lista
			@return Retorna un entero con la cantidad de elementos
		*/
		int getTam(){
			return tam;
		}
		/**
			@brief Se verifica si existe un determinado elemento dentro de la lista
			@param dato, T que corresponde a la informacion que se quiere verificar
			@returns Retonar un booleano indicando si el dato existe o no
		*/
		bool estaDato(T dato) {
			int i;
			bool esta=false;
			for (i=0;(i<tam&&esta==false);i++){
				if(devolverDato(i)==dato){
					esta=true;
				}
				else{
					esta=false;
				}
			}
			return esta;
		}	
};
#endif
