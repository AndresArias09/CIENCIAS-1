#ifndef PARTIDO_H
#define PARTIDO_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Librerias/arbolAVL.h"
#include "facade.h"
#include "estructuras.h"

struct a{
	int hola;
};

//esta clase gestiona la lectura, escritura y la busqueda en el archivo partidos.txt
class partido: public facade{
	private:
		//arbol AVL
		arbolAVL<partid> *arbolPartidos;
		//instancia unica
		static partido *instance;
		//constructor privado
		partido(){
			this->cantidad = 0;
			this->leido = false;
			arbolPartidos = new arbolAVL<partid>();
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		static partido *getInstance(){
			if(instance==0){
				instance = new partido();
			}
			return instance;
		}
		//se leen los registros del archivo departamentos.txt y se guardan en un arbol avl
		void leerRegistros(){
			if(leido==false){
				int clave;
				string nombre;
				string representante;
				partid par;
				//archivo de entrada
				ifstream archEntrada("Archivos/partidos.txt", ios::in);
				if (!archEntrada.good()){
				 	cerr<< "No se pudo abrir el archivo partidos" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()) {
					archEntrada >> clave;
					archEntrada >> nombre;
					archEntrada >> representante;
					par.clave = clave;
					par.nombre = nombre;
					par.representante = representante;
					arbolPartidos->agregar(par);
					this->cantidad++;
				}
				archEntrada.close();
				this->leido = true;
			}
		}
		
		Lista<partid> *consultarPartidos(){
			Lista<partid> *lista = arbolPartidos->recorridoInOrden();
			return lista;
		}
		
		//retorna un apuntador a la estructura que tiene esa clave
		partid *getPartido(int clave){
			partid *partido = arbolPartidos->retornarEstructura(clave);
			return partido;
		}
		
		void agregarCandidato(candidate candidato,int partido){
			partid *par = arbolPartidos->retornarEstructura(partido);
			par->candidatos.anadir_final(candidato);
		}
		
		string getNombrePartido(int clave){
			partid *par = arbolPartidos->retornarEstructura(clave);
			return par->nombre;
		}
};
partido* partido::instance = 0;
#endif
