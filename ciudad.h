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
#include "departamento.h"

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
		//se leen los registros del archivo
		void leerRegistros(){
			if(this->leido==false){
				int clave,estado;
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
					archEntrada >> estado;
					ciuda.clave = clave;
					ciuda.nombre = nombre;
					ciuda.departamento = departamento;
					ciuda.censo = censo;
					ciuda.estado = estado;
					this->agregarCiudad(ciuda);
				}
				archEntrada.close();
				this->leido = true;
			} 
		}
	public:
		//se obtiene la instancia unica
		static ciudad *getInstance(){
			if(instance == 0){
				instance = new ciudad();
			}
			return instance;
		}
		//se agrega una ciudad al arbol avl
		void agregarCiudad(city ciudad){
			ciudad.clave = this->cantidad++;
			arbolCiudades->agregar(ciudad);
		}
		//se consultan todas las ciudades habilitadas para el censo electoral
		Lista<city> *consultarCiudades(){
			Lista<city> *lista = arbolCiudades->recorridoInOrden();
			return lista;
		}
		//retorna una lista de apuntadores de candidatos asociados a una ciudad
		Lista<candidate*> getCandidatoByCiudad(int clave){
			city *ciudad = arbolCiudades->retornarEstructura(clave);
			Lista<candidate*> lista = ciudad->candidatos;
			return lista;
		}
		//agrega un candidato a su ciudad correspondiente
		void agregarCandidato(candidate *candidato,int territorio){
			city *ciu = arbolCiudades->retornarEstructura(territorio);
			ciu->candidatos.anadir_final(candidato);
		}
		//retorna el nombre de la ciudad dado el codigo
		string getNombreCiudad(int clave){
			city *ciu = arbolCiudades->retornarEstructura(clave);
			return ciu->nombre;
		}
		//retorna el censo de una ciudad
		long long getCenso(int clave){
			city *ciu=arbolCiudades->retornarEstructura(clave);
			return ciu->censo;
		}
		//retorna el censo nacional
		long long getCensoTotal(){
			Lista <city> *cities=arbolCiudades->recorridoInOrden();
			long long censototal=0;
			for(int i=1;i<cities->getTam();i++){
				censototal+=getCenso(i);
			}
			return censototal;
		}
		//retorna de lista de candidato presidenciales
		Lista<candidate*>getCandidatoPresidencial(){
			city *ciu = arbolCiudades->retornarEstructura(0);
			return ciu->candidatos; 
		}
		//retorna el candidato presidencial segun el partido
		candidate *getCandidatoPByPartido(int partido){
			Lista<candidate*> lista = ciudad::getInstance()->getCandidatoByCiudad(0);
			candidate *presi = NULL;
			for(int i=0;i<lista.getTam();i++){
				presi = lista.devolverDato(i);
				if(presi->partido==partido && presi->estado==1){
					i=lista.getTam();
				}
			}
			return presi;
		}
		//retona un apuntador a la ciudad dado su codigo
		city *getCiudad(int clave){
			return arbolCiudades->retornarEstructura(clave);
		}
		//retona el codigo del departamento de una ciudad
		int getDepartamento(int clave){
			return arbolCiudades->retornarEstructura(clave)->departamento;
		}
		//retorna la cantidad de registros de ciudades
		int getCantidad(){
			return this->cantidad;
		}
		//destructor
		void liberar(){
			delete arbolCiudades;
			delete instance;
		}
		//se rescribe el archivo ciudades
		void escribirRegistros(){
			ofstream archsalida("Archivos/ciudades.txt",ios::out|ios::trunc);
			if (!archsalida.good()){
				cerr << "No se pudo abrir el archivo ciudades" << endl;
				exit(1);
			}
			Lista<city> ciudades = *arbolCiudades->recorridoInOrden();
			for(int i=0;i<ciudades.getTam();i++){
				city ciu = ciudades.devolverDato(i);
				if(i!=ciudades.getTam()-1){
					archsalida<<ciu.clave<<" "<<ciu.nombre<<" "<<ciu.departamento<<" "<<ciu.censo<<" "<<ciu.estado<<"\n";
				}
				else{
					archsalida<<ciu.clave<<" "<<ciu.nombre<<" "<<ciu.departamento<<" "<<ciu.censo<<" "<<ciu.estado;
				}
			}
			archsalida.close();
		}
		//se modifica una ciudad
		void modificarCiudad(city nueva){
			city *ciu = arbolCiudades->retornarEstructura(nueva.clave);
			ciu->nombre = nueva.nombre;
			ciu->departamento = nueva.departamento;
			ciu->censo = nueva.censo;
		}
};
ciudad* ciudad::instance = 0;
#endif
