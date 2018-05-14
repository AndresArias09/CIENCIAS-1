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
		//constructor
		ListaO(){
			auxinicio = new node<T>;
			auxfin = new node<T>;
			cab=auxinicio;
			auxinicio->sig=auxfin;
			fin=auxfin;
			tam=0;
		}
		bool lista_vacia(){
			if(tam==0){
				return true;
			}
			else {
				return false;
			}
		}
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

		int getTam(){
			return tam;
		}	
};
#endif
