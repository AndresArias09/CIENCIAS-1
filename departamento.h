#ifndef DEPARTAMENTO
#define DEPARTAMENTO
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Librerias/arbolAVL.h"
#include "facade.h"
#include <stddef.h>
#include "estructuras.h"

//esta clase gestiona la lectura, escritura y la busqueda en el archivo departamentos.txt
class departamento: public facade{
	private:
		//arbol AVL
		arbolAVL<departament> *arbolDep;
		//instancia unica
		static departamento *instance;
		//constructor privado
		departamento(){
			arbolDep = new arbolAVL<departament>();
			this->cantidad = 0;
			this->leido = false;
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		static departamento *getInstance(){
			if(instance==0){
				instance = new departamento();
			}
			return instance;
		}
		//se leen los registros del archivo departamentos.txt y se guardan en un arbol avl
		void leerRegistros(){
			if(leido==false){
				int clave;
				string nombre;
				departament dep;
				//archivo de entrada
				ifstream archEntrada("Archivos/departamentos.txt", ios::in);
				if (!archEntrada.good()){
				 	cerr << "No se pudo abrir el archivo departamentos" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()) {
					archEntrada >> clave;
					archEntrada >> nombre;
					dep.clave = clave;
					dep.nombre = nombre;
					agregarDepartamento(dep);
				}
				archEntrada.close();
				this->leido = true;
			}
		}
		//se agrega una departamento
		void agregarDepartamento(departament dep){
			dep.clave = ++this->cantidad;
			arbolDep->agregar(dep);
		}
		//retorna el nombre del departamento dado el codigo
		string getNombreDepartamento(int clave){
			return arbolDep->retornarEstructura(clave)->nombre;
		}
		//returna una lista con los departamentos en los que se hacen las votaciones
		Lista<departament> *consultarDepartamentos(){
			return arbolDep->recorridoInOrden();
		}
		//destructor
		void liberar(){
			delete arbolDep;
			delete instance;
		}
		//retorna la cantidad de departamentos
		int getCantidad(){
			return this->cantidad;
		}
		//se reescribe el archivo departamentos.txt
		void escribirRegistros(){
			ofstream archsalida("Archivos/departamentos.txt",ios::out|ios::trunc);
			if (!archsalida.good()){
				cerr << "No se pudo abrir el archivo departamentos" << endl;
				exit(1);
			}
			Lista<departament> departamentos = *arbolDep->recorridoInOrden();
			for(int i=0;i<departamentos.getTam();i++){
				departament dep = departamentos.devolverDato(i);
				if(i!=departamentos.getTam()-1){
					archsalida<<dep.clave<<" "<<dep.nombre<<"\n";
				}
				else{
					archsalida<<dep.clave<<" "<<dep.nombre;
				}
			}
			archsalida.close();
		}
};
departamento* departamento::instance = 0;
#endif

