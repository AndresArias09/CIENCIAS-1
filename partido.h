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
		//constructor privado
		partido(){
			this->cantidad = 0;
			this->leido = false;
			arbolPartidos = new arbolAVL<partid>();
			leerRegistros();
		}
		//se leen los registros del archivo departamentos.txt y se guardan en un arbol avl
		void leerRegistros(){
			if(leido==false){
				int clave,estado;
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
					archEntrada >>estado;
					par.clave = clave;
					par.estado = estado;
					par.nombre = nombre;
					par.representante = representante;
					agregarPartido(par);
				}
				archEntrada.close();
				this->leido = true;
			}
		}
	public:
		//se obtiene la instancia unica
		static partido *getInstance(){
			if(instance==0){
				instance = new partido();
			}
			return instance;
		}
		//se agrega una ciudad al arbol avl
		void agregarPartido(partid partido){
			partido.clave = ++this->cantidad;
			arbolPartidos->agregar(partido);
		}
		//retorna la lista de partidos habilitados
		Lista<partid> *consultarPartidos(){
			Lista<partid> *lista = arbolPartidos->recorridoInOrden();
			return lista;
		}
		//retorna un apuntador a la estructura que tiene esa clave
		partid *getPartido(int clave){
			partid *partido = arbolPartidos->retornarEstructura(clave);
			return partido;
		}
		//agrega un candidato a su correspondiente partido
		void agregarCandidato(candidate *candidato,int partido){
			partid *par = arbolPartidos->retornarEstructura(partido);
			par->candidatos.anadir_final(candidato);
		}
		//retorna el nombre del partido dado su codigo
		string getNombrePartido(int clave){
			partid *par = arbolPartidos->retornarEstructura(clave);
			return par->nombre;
		}
		//retorna una lista de apuntadores a los candidatos que pertenecen a un determinado partido
		Lista<candidate*> consultarCandidatosByPartido(int clave){
			partid *partid = arbolPartidos->retornarEstructura(clave);
			return partid->candidatos;
		}
		//retorna la cantidad de partidos que existen
		int getCantidad(){
			return this->cantidad;
		}
		//se libera memoria
		void liberar(){
			delete arbolPartidos;
			delete instance;
		}
		//se rescribe el archivo partidos
		void escribirRegistros(){
			ofstream archsalida("Archivos/partidos.txt",ios::out|ios::trunc);
			if (!archsalida.good()){
				cerr << "No se pudo abrir el archivo partidos" << endl;
				exit(1);
			}
			Lista<partid> partidos = *arbolPartidos->recorridoInOrden();
			for(int i=0;i<partidos.getTam();i++){
				partid par = partidos.devolverDato(i);
				if(i!=partidos.getTam()-1){
					archsalida<<par.clave<<" "<<par.nombre<<" "<<par.representante<<" "<<par.estado<<"\n";
				}
				else{
					archsalida<<par.clave<<" "<<par.nombre<<" "<<par.representante<<" "<<par.estado;
				}
			}
			archsalida.close();
		}
		//verifica si un partido eta deshabilitado
		bool estaDeshabilitado(int clave){
			partid par = *arbolPartidos->retornarEstructura(clave);
			if(par.estado==0){
				return true;
			}
			return false;
		}
};
partido* partido::instance = 0;
#endif
