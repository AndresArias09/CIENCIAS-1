#ifndef CIUDAD
#define CIUDAD
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Librerias/arbolAVL.h"
#include "facade.h"
#include "estructuras.h"

//esta clase gestiona la lectura, escritura y la busqueda en el archivo ciudad.txt
class ciudad: public facade{
	private:
		//arbol AVL
		arbolAVL<city> *arbolCiudades;
		//instancia unica
		static ciudad *instance;
		//constructor privado
		ciudad(){
			arbolCiudades = new arbolAVL<city>();
			this->cantidad = 0;
			this->leido = false;
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		static ciudad *getInstance(){
			if(instance == 0){
				instance = new ciudad();
			}
			return instance;
		}
		void leerRegistros(){
			if(this->leido==false){
				int clave;
				string nombre;
				int departamento;		
				long long censo;
				city ciuda;
				//archivo de entrada
				ifstream archEntrada("Archivos/ciudades.txt", ios::in);
				if (!archEntrada.good()){
					cerr << "No se pudo abrir el archivo ciudades" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()){
					archEntrada >> clave;
					archEntrada >> nombre;
					archEntrada >> departamento;
					archEntrada >> censo;
					ciuda.clave = clave;
					ciuda.nombre = nombre;
					ciuda.departamento = departamento;
					ciuda.censo = censo;
					arbolCiudades->agregar(ciuda);
					this->cantidad++;
				}
				archEntrada.close();
				this->leido = true;
			} 
		}
		Lista<city> *consultarCiudades(){
			Lista<city> *lista = arbolCiudades->recorridoInOrden();
			return lista;
		}
		//retorna un apuntador a la estructura que tiene esa clave
		Lista<candidate*> getCandidatoByCiudad(int clave){
			city *ciudad = arbolCiudades->retornarEstructura(clave);
			Lista<candidate*> lista = ciudad->candidatos;
			return lista;
		}
		
		void agregarCandidato(candidate *candidato,int territorio){
			city *ciu = arbolCiudades->retornarEstructura(territorio);
			ciu->candidatos.anadir_final(candidato);
		}
		
		string getNombreCiudad(int clave){
			city *ciu = arbolCiudades->retornarEstructura(clave);
			return ciu->nombre;
		}
};
ciudad* ciudad::instance = 0;
#endif
