/**
	@file Pila.h
	@brief Estructura de datos Pila
	
	Esta clase realiza todas operaciones de una Pila  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef PILA_H
#define PILA_H
template <class T>
class Pila{
	private:
		T *pila;
		int p;
	public:
		/**
			@brief constructor
		*/
		Pila(int max=100){
			pila = new T[max];
			p = 0;		
		}
		/**
			@brief destructor
		*/
		~Pila(){
			delete pila;
		}
		/**
			@brief Mete un elemento a la pila
			@param Recibe el elemento de tipo T para meter a la pila
		*/
		inline void meter(T v){
			pila[p++] = v;
		}
		/**
			@brief saca un elemento de la pila
			@returns retornar un elemento de la pila
		*/
		inline T sacar(){
			return pila[--p];
		}
		/**
			@brief Indica si la pila esta vacia
		*/
		inline int vacia(){
			return !p;
		}
};
#endif

