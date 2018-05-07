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
		//constructor
		Lista(){
			cab=NULL;
			fin=NULL;
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
		//añade un dato al final de la lista
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
	
		void eliminarInicio(){
			nodo<T> *b;
			b = cab;
			cab = cab -> sig;
			delete b;
			tam--;
		}

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
		
	int getTam(){
		return tam;
	}	
};
