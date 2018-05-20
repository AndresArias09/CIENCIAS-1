/**
	@file partido.h
	@brief clase que gestiona el archivo partido
	
	este archivo posee todos los metodos necesarios para el manejo de la informacion de los partidos  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/


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

//esta clase gestiona la lectura, escritura y la busqueda en el archivo partidos.txt
class partido: public facade{
	private:
		//arbol AVL
		arbolAVL<partid> *arbolPartidos;
		//instancia unica
		static partido *instance;
			/** 
			@brief metodo constructor 
			@returns lectura de registros 
		*/
		partido(){
			this->cantidad = 0;
			this->leido = false;
			arbolPartidos = new arbolAVL<partid>();
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		/** 
		@brief metodo de instanciacion de la clase (Patron singleton)
		@returns devuelve la instancia de la clase
		
		*/
		static partido *getInstance(){
			if(instance==0){
				instance = new partido();
			}
			return instance;
		}
		/**
		@brief funcion para leer los registros del archivo 
		*/
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
		
		
		/** 
		@brief funcion para obtener todos los partidos
		@returns apuntador a lista tipo partid con todos los partidos  
		*/
		Lista<partid> *consultarPartidos(){
			Lista<partid> *lista = arbolPartidos->recorridoInOrden();
			return lista;
		}
		/** 
		@brief funcion para obtener un partido dada su clave
		@returns apuntador a la estructura tipo partid que tiene esa clave 
		@param clave int 
		*/
		partid *getPartido(int clave){
			partid *partido = arbolPartidos->retornarEstructura(clave);
			return partido;
		}
		/** 
		@brief funcion para agregar un candidato a su correspondiente partido
		@param candidato candidate*
		@param partido int  
		*/
		void agregarCandidato(candidate *candidato,int partido){
			partid *par = arbolPartidos->retornarEstructura(partido);
			par->candidatos.anadir_final(candidato);
		}
		/** 
		@brief funcion para obtener el nombre de un partido dada su clave
		@returns string con el nombre del partido
		@param clave int 
		*/
		string getNombrePartido(int clave){
			partid *par = arbolPartidos->retornarEstructura(clave);
			return par->nombre;
		}
		/** 
		@brief funcion para obtener los candidatos que corresponden a un determinado partido
		@returns lista de apuntadores a los candidatos que pertenecen a un determinado partido
		@param clave int
		@param partido int  
		*/
		Lista<candidate*> consultarCandidatosByPartido(int clave){
			partid *partid = arbolPartidos->retornarEstructura(clave);
			return partid->candidatos;
		}
};
partido* partido::instance = 0;
#endif
