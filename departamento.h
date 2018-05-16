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
					arbolDep->agregar(dep);
					this->cantidad++;
				}
				archEntrada.close();
				this->leido = true;
			}
		}
		//retorna el nombre del departamento dado el codigo
		string getNombreDepartamento(int clave){
			return arbolDep->retornarEstructura(clave)->nombre;
		}
		//agrega una ciudad a su departamento correspondiente
		void agregarCiudad(int clave,territorioSimulacion ciudad){
			departament *dep = arbolDep->retornarEstructura(clave);
			dep->ciudades.anadir_final(ciudad); 
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
		//limpia las listas de ciudades de cada departamento
		limpiar(){
			Lista<departament> *departamentos = arbolDep->recorridoInOrden();
			for(int i=0;i<departamentos->getTam();i++){
				departament dep = departamentos->devolverDato(i);
				Lista<territorioSimulacion> ciudades = dep.ciudades;
				for(int j=0;j<ciudades.getTam();j++){
					ciudades.eliminarInicio();
				}
			}
			
		}
};
departamento* departamento::instance = 0;
#endif

