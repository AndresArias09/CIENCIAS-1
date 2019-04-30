/**
	@file arbolAVL.h
	@brief Clase que realiza todas las operaciones de un arbol binario ordenado AVL	

	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "Pila.h"
#include "Lista.h"

template <class T>
struct x{
	int clave;
	T elemento;
	int izq;
	int der;
};

using namespace std;
template <class T>

class arbolAVL {
	private:
		int tama;
		int i;
		int indice;
		x <T> *arreglo;
		int auxactual;
		int auxrevisado;
		/**
			@brief Funcion recursiva que utiliza una pila para realizar el recorrido in orden del arbol binario
			@param node, int que corresponde al nodo padre del cual se van a realizar los recorridos
			@param lista, Lista<T>* que corresponde a una apuntador a una lista de todos los elementos del recorrido del arbol
		*/
		void inOrden(int node,Lista<T> *lista){
			Pila<int> pila;
			int actual = node;
			//se meten los nodos en la pila
			while(actual!=0){
				pila.meter(actual);
				actual = arreglo[actual].izq;
			}
			//se imprimen todos los nodoss segun como este dada la pila
			int current;
			while(!pila.vacia()){
				current = pila.sacar();
				lista->anadir_final(arreglo[current].elemento);
				if(arreglo[current].der!=0)
					inOrden(arreglo[current].der,lista);
			}
		}
		/**
			@brief Funcion recursiva que utiliza una pila para realizar el recorrido pre orden del arbol binario
			@param node, int que corresponde al nodo padre del cual se van a realizar los recorridos
			@param lista, Lista<T>* que corresponde a una apuntador a una lista de todos los elementos del recorrido del arbol
		*/
		void preOrden(int node,Lista<T> *lista){
			int actual = node;
			Pila<int> pila;
			while(actual!=0){
				lista->anadir_final(arreglo[actual].elemento);
				pila.meter(actual);
				actual = arreglo[actual].izq;
			}
			int current;
			while(!pila.vacia()){
				current = pila.sacar();
				if(arreglo[current].der!=0)
					preOrden(arreglo[current].der,lista);
			}
		}
		/**
			@brief Funcion recursiva que utiliza una pila para realizar el recorrido pos orden del arbol binario
			@param node, int que corresponde al nodo padre del cual se van a realizar los recorridos
			@param lista, Lista<T>* que corresponde a una apuntador a una lista de todos los elementos del recorrido del arbol
		*/
		void posOrden(int node,Lista<T> *lista){
			int actual = node;
			Pila<int> pila;
			while(actual!=0){
				pila.meter(actual);
				actual = arreglo[actual].izq;
			}
			int current;
			while(!pila.vacia()){
				current = pila.sacar();
				if(arreglo[current].der!=0)
					posOrden(arreglo[current].der,lista);
				lista->anadir_final(arreglo[current].elemento);
			}
		}
		/**
			@brief Funcion que realiza una rotacion sencilla a la izquierda sobre un nodo del arbol
			@param abuelo, int que corresponde al nodo padre del nodo sobre el cual se va a rotar
			@param padre, int que corresponde al nodo sobre el cual se va a rotar
			@param hijoDerecho, int que corresponde al hijo derecho del nodo sobre el cual se hara una rotacion
		*/
		void rotacionSencillaIzquierda(int abuelo,int padre, int hijoDerecho){
			int nieto;
			nieto = arreglo[hijoDerecho].izq;
			arreglo[hijoDerecho].izq = padre;
			arreglo[padre].der = nieto;
			if(abuelo!=0){
				if(arreglo[abuelo].izq==padre){
					arreglo[abuelo].izq = hijoDerecho;
				}
				else{
					arreglo[abuelo].der = hijoDerecho;
				}
			}
			//se verifica si está en la raiz
			if(arreglo[0].izq==padre){
				arreglo[0].izq=hijoDerecho;
			}
		}
		/**
			@brief Funcion que realiza una rotacion sencilla a la derecha sobre un nodo del arbol
			@param abuelo, int que corresponde al nodo padre del nodo sobre el cual se va a rotar
			@param padre, int que corresponde al nodo sobre el cual se va a rotar
			@param hijoIzquierdo, int que corresponde al hijo izquierdo del nodo sobre el cual se hara una rotacion
		*/
		void rotacionSencillaDerecha(int abuelo,int padre, int hijoIzquierdo){
			int nieto;
			nieto = arreglo[hijoIzquierdo].der;
			arreglo[hijoIzquierdo].der = padre;
			arreglo[padre].izq = nieto;
			if(abuelo!=0){
				if(arreglo[abuelo].izq==padre){
					arreglo[abuelo].izq = hijoIzquierdo;
				}
				else{
					arreglo[abuelo].der = hijoIzquierdo;
				}
			}
			//se verifica si está en la raiz
			if(arreglo[0].izq==padre){
				arreglo[0].izq=hijoIzquierdo;
			}
		}
		/**
			@brief Funcion que diagnostica que rotacion se debe hacer sobre un nodo desequilibrado
			@param abuelo, int que corresponde al nodo padre del nodo que esta en desequilibrio
			@param padre, int que corresponde al nodo que se encuentra desequilibrado
		*/
		void rotacion(int abuelo,int padre){
			int desequi = desequilibrio(arreglo[padre]);
			//desequilibrio positivo (rotacion a la izquierda)
			if(desequi>0){
				int hijoDerecho = arreglo[padre].der;
				int desHijoDerecho = desequilibrio(arreglo[hijoDerecho]);
				//rotacion sencilla hacia la izquierda
				if(desHijoDerecho>=0){
					rotacionSencillaIzquierda(abuelo,padre,hijoDerecho);
				}
				//rotacion doble hacia la izquierda
				else if(desHijoDerecho<0){
					//rotacion sencilla del hijo a la derecha
					rotacionSencillaDerecha(padre,hijoDerecho,arreglo[hijoDerecho].izq);
					//rotacion sencilla del padre a la izquierda
					rotacionSencillaIzquierda(abuelo,padre,arreglo[padre].der);
				}
			}
			//desequilibrio negativo (rotacion a la derecha)
			else{
				int hijoIzquierdo = arreglo[padre].izq;
				int desHijoIzquierdo = desequilibrio(arreglo[hijoIzquierdo]);
				//rotacion doble hacia la derecha
				if(desHijoIzquierdo>0){
					//rotacion sencilla del hijo a la izquierda
					rotacionSencillaIzquierda(padre,hijoIzquierdo,arreglo[hijoIzquierdo].der);
					//rotacion sencilla del padre a la derecha
					rotacionSencillaDerecha(abuelo,padre,arreglo[padre].izq);
				}
				//rotacion sencilla hacia la derecha
				else if(desHijoIzquierdo<=0){
					rotacionSencillaDerecha(abuelo,padre,hijoIzquierdo);
				}		
			}
		}
		/**
			@brief Funcion que verifica si se debe hacer un balanceo en el arbol binario
			@param valor, int que corresponde al valor que se acabe ingresar o eliminar en el arbol y que por ese hecho podria causar un desequilibrio en el arbol
		*/
		void equilibrar(int valor){
			/*se hace el recorrido hasta el valor recientemente agregado o eliminado para ir mirando si algun nodo a lo largo de ese recorrido
			se ha desequilibrado*/
			int padre,hijo;
			Pila<int> pilaHijos;
			Pila<int> pilaPadres;
			padre = 0;
			hijo = arreglo[0].izq; //raiz
			while(hijo!=0){
				pilaHijos.meter(hijo);
				pilaPadres.meter(padre);
				padre = hijo;
				//si el nodo que se examino tiene la clave que se ingreso, se termina el algoritmo
				if(arreglo[hijo].clave==valor){
					hijo = 0;
				}
				//si el valor es menor que la clave del nodo, se va a la izquierda
				else if(valor<arreglo[hijo].clave){
					hijo = arreglo[padre].izq;
				}
					//si el valor es mayor que la clave del nodo, se va a la derecha
				else{
					hijo = arreglo[padre].der;
				}
				
			}
			while(!pilaHijos.vacia()){
				hijo = pilaHijos.sacar();
				padre = pilaPadres.sacar();
				if(esta_desequilibrado(arreglo[hijo])){
					rotacion(padre,hijo);
				}
			}
		}
		/**
			@brief Funcion recurvisa que calcula la altura de un determinado nodo del arbol
			@param este, x<T> nodo al cual se le va a calcular la altura
		*/
		int altura(x <T> este){
			if(este.izq==0&&este.der==0){
				return 0;
			}
			else{
				int altder;
				int altizq;
				if(este.der==0||este.izq==0){
					if(este.der==0&&este.izq!=0){
						return altura(arreglo[este.izq])+1;
					}
					else if(este.izq==0&&este.der!=0){
						return altura(arreglo[este.der])+1;
					}		
				}
				else {
					altder=altura(arreglo[este.der]);
					altizq=altura(arreglo[este.izq]);
					if(altizq>altder){
						return altizq+1;
					}
					else{
						return altder+1;
					}			
				}			
			}
		}
		/**
			@brief Funcion que calcula el factor de desequilibrio de un arbol
			@param dato, x<T> que corresponde al nodo al cual se le calculara el factor de desequilibrio
		*/
		int desequilibrio(x <T> dato){
				if(dato.der==0&&dato.izq==0){
					return 0;
				}
				//se le aumenta 1 para contar el nodo donde está ubicado
				else{
					if(dato.der==0&&dato.izq!=0){
					
						return 0-(altura(arreglo[dato.izq])+1);
					}
					else if(dato.izq==0&&dato.der!=0){
						return (altura(arreglo[dato.der])+1);
					}
					else {
						int altder;
						int altizq;
						altder=altura(arreglo[dato.der])+1;
						altizq=altura(arreglo[dato.izq])+1;
						return altder-altizq;			
					}
			}
		}
		/**
			@brief Funcion que verifica si un nodo esta desequilibrado o no
			@param dato, x<T> que corresponde al nodo al cual se le calculara el factor de desequilibrio
			@returns Retorna un booleano que verifica si el nodo esta desequilibrado o no
		*/
		bool esta_desequilibrado(x <T> dato){
			if (desequilibrio(dato)<-1||desequilibrio(dato)>1){
				return true;
			}
			else{
				return false;
			}
		}
		void revisar(){
		//comienza desde uno hasta el indice ya que son los unicos a los que se les debe calcular el desequilibrio
			cout<<"Raiz "<<arreglo[0].izq<<endl;
			for(int i=1; i<=indice;i++){
				cout<<"NODO: "<<endl;
				cout<<arreglo[i].elemento.nombre;;
				cout<<arreglo[i].clave<<" ";
				cout<<arreglo[i].izq<<" ";
				cout<<arreglo[i].der<<endl;
				cout<<"Desequilibrio: "<<desequilibrio(arreglo[i])<<endl;
			}
		}
		
	public:
		/**
			@brief Constructor
		*/
		arbolAVL(int tam=500){
			auxactual=0;
			auxrevisado=0;
			tama=tam;
			arreglo= new x <T> [tama+1];
			indice=0;
			for(i=0;i<tama;i++){
				arreglo[i].der=i+1;
			}
			arreglo[tam].der=0;				
		}
		/**
			@brief Funcion que agregar un elemento al arbol
			@param dato, x<T> que corresponde nodo que se va  agregar al arbol
		*/
		void agregar(T estruct){
			auxactual=arreglo[0].der;
			arreglo[auxactual].clave=estruct.clave;
			arreglo[0].der=arreglo[auxactual].der;
			arreglo[auxactual].izq=0;
			arreglo[auxactual].der=0;
			arreglo[auxactual].elemento = estruct;
			if(indice==0){
				arreglo[0].izq=auxactual;
			}
			else{
				auxrevisado=arreglo[0].izq;
				while(auxrevisado!=0){
					if(arreglo[auxactual].clave>arreglo[auxrevisado].clave){
						if(arreglo[auxrevisado].der==0){
							arreglo[auxrevisado].der=auxactual;
							auxrevisado=0;
						}
						else
						{
							auxrevisado=arreglo[auxrevisado].der;
						}		
					
					}
					else{
						if(arreglo[auxrevisado].izq==0){
							arreglo[auxrevisado].izq=auxactual;
							auxrevisado=0;
						}
						else{
							auxrevisado=arreglo[auxrevisado].izq;
						}
						
					}	
				}		
			}
			indice++;
			equilibrar(estruct.clave); //se equilibra el arbol si es necesario		
		}
		/**
			@brief Funcion que elimina un elemento del arbol
			@param valor, int calve que se va a eliminar del arbol
		*/
		void eliminar(int valor){
			int padre=0;
			int hijo=arreglo[0].izq;
			
			while(arreglo[hijo].clave!=valor){
				if(valor>arreglo[hijo].clave){
					padre=hijo;
					hijo=arreglo[hijo].der;
				}
				else{
					padre=hijo;
					hijo=arreglo[hijo].izq;
				}
			}
			//elimina una hoja
			if(arreglo[hijo].der==0&&arreglo[hijo].izq==0){
				if(arreglo[padre].der==hijo){
					arreglo[padre].der=0;
				}
				else{
					arreglo[padre].izq=0;
				}			
			}
			//eliminar x con un solo hijo
			else if(arreglo[hijo].der==0||arreglo[hijo].izq==0){
				int hijoaux;
				if(arreglo[hijo].der!=0){
					hijoaux=arreglo[hijo].der;
				}
				else{
					hijoaux=arreglo[hijo].izq;
				}
				if(arreglo[padre].der==hijo){
					arreglo[padre].der=hijoaux;
				}
				else{
					arreglo[padre].izq=hijoaux;
				}
			}
		// comienza lo bueno
		
			else if(arreglo[hijo].der!=0&&arreglo[hijo].izq!=0){
				int padrerep;
				int hijorep;
				
				padrerep=hijo;
				hijorep=arreglo[padrerep].der;
				
				while(arreglo[hijorep].izq!=0){
					padrerep=hijorep;
					hijorep=arreglo[hijorep].izq;
				}
				if(arreglo[hijorep].der==0&&arreglo[hijorep].izq==0){
					if(arreglo[padrerep].der==hijorep){
						arreglo[padrerep].der=0;
					}
					else{
						arreglo[padrerep].izq=0;
					}				
				}
				else if(arreglo[hijorep].der==0||arreglo[hijorep].izq==0){
					int hijoaux;
					if(arreglo[hijorep].der!=0){
					hijoaux=arreglo[hijorep].der;
					}
					else{
						hijoaux=arreglo[hijorep].izq;
					}
					if(arreglo[padrerep].der==hijorep){
						arreglo[padrerep].der=hijoaux;
					}
					else{
						arreglo[padrerep].izq=hijoaux;
					}	
				}
				arreglo[hijorep].der=arreglo[hijo].der;
				arreglo[hijorep].izq=arreglo[hijo].izq;
				if(padre==0){
					arreglo[0].izq=hijorep;
				}
				else{
					if(arreglo[padre].der==hijo){
						arreglo[padre].der=hijorep;
					}
					else{
						arreglo[padre].izq=hijorep;
					}		
				}	
			}	
			//liberando espacio
			arreglo[hijo].der=arreglo[0].der;
			arreglo[0].der=hijo;
			arreglo[hijo].clave=0;
			arreglo[hijo].izq=0;
			indice--;
			equilibrar(valor); //se equilibra el arbol si es necesario	
		}
		/**
			@brief Funcion que verifica si el arbol esta lleno
			@retuns Retorna un booleano verificando si el arbol esta lleno o no
		*/
		bool arbolLleno(){
			if(indice==tama){
				return true;
			}
			return false;
		}
		/**
			@brief Funcion que verifica si el arbol esta vacio
			@retuns Retorna un booleano verificando si el arbol esta vacio o no
		*/
		bool arbolVacio(){
			if(indice==0){
				return true;
			}
			return false;
		}
		/**
			@brief Funcion que retorna la informacion asociada a una clave dentro del arbol
			@param clave, int que corresponde a la clave del elemento que se desea consultar
			@retuns Retorna una estructura de tipo T 
		*/
		T *retornarEstructura(int clave){
			int padre = 0;
			int hijo = arreglo[0].izq; //raiz
			T *elemento = new T();
			while(hijo!=0){
				if(arreglo[hijo].clave == clave){
					elemento = &arreglo[hijo].elemento;
					hijo = 0;
				}
				else{
					padre = hijo;
					if(clave<arreglo[padre].clave){
						hijo = arreglo[padre].izq;
					}
					else{
						hijo = arreglo[padre].der;
					}
				}
			}
			return elemento;
		}
		/**
			@brief Retorna una lista con el recorrido in orden del arbol
			@returns Un apuntador a una lista con los elementos del arbol
		*/
		Lista<T> *recorridoInOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			inOrden(node,lista);
			return lista;
		}
		/**
			@brief Retorna una lista con el recorrido pre orden del arbol
			@returns Un apuntador a una lista con los elementos del arbol
		*/
		Lista<T> *recorridoPreOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			preOrden(node,lista);
			return lista;
		}
		/**
			@brief Retorna una lista con el recorrido pos orden del arbol
			@returns Un apuntador a una lista con los elementos del arbol
		*/
		Lista<T> *recorridoPosOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			posOrden(node,lista);
			return lista;
		}
		
};
#endif
