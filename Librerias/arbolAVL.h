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
		int auxactual=0;
		int auxrevisado=0;
		//Recorrido in orden del arbol
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
		//Recorrido pre orden del arbol
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
		//Recorrido pos orden del arbol
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
		//Rotacion sencilla de uno nodo a la izquierda
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
		//Rotacion sencilla de un nodo a la derecha
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
		//Rotacion de un nodo
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
		//Se da equilibrio al arbol
		void equilibrar(T valor){
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
		//funcion recursiva para calcular la altura de un nodo
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
		//funcion para el desequilibrio
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
		//funcion para determinar si esta o no desequilibrado
		bool esta_desequilibrado(x <T> dato){
			if (desequilibrio(dato)<-1||desequilibrio(dato)>1){
				return true;
			}
			else{
				return false;
			}
		}	
		
	public:
		//Constructor
		arbolAVL(int tam=500){
			tama=tam;
			arreglo= new x <T> [tama+1];
			indice=0;
			for(i=0;i<tama;i++){
				arreglo[i].der=i+1;
			}
			arreglo[tam].der=0;				
		}
		//Agregar un valor al arbol
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
		//Eliminacion de un nodo del arbol
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
		//Revisa si el arbol se encuentra lleno
		bool arbolLleno(){
			if(indice==tama){
				return true;
			}
			return false;
		}
		//Revisa si el arbol se encuentra vacio
		bool arbolVacio(){
			if(indice==0){
				return true;
			}
			return false;
		}
		T retornarEstructura(int clave){
			int padre = 0;
			int hijo = arreglo[0].izq; //raiz
			T elemento;
			while(hijo!=0){
				if(arreglo[hijo].clave == clave){
					elemento = arreglo[hijo].elemento;
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
		//Retorna una lista con el recorrido in orden del arbol
		Lista<T> *recorridoInOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			inOrden(node,lista);
			return lista;
		}
		//Retorna una lista con el recorrido pre orden del arbol
		Lista<T> *recorridoPreOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			preOrden(node,lista);
			return lista;
		}
		//Retorna una lista con el recorrido pos orden del arbol
		Lista<T> *recorridoPosOrden(){
			int node = arreglo[0].izq;
			Lista<T> *lista = new Lista<T>();
			posOrden(node,lista);
			return lista;
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
		
};
#endif
