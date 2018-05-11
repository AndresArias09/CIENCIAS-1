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
		string getNombreDepartamento(int clave){
			departament *dep = arbolDep->retornarEstructura(clave);
			return dep->nombre;
		}
		/*bool getDepartamento(int clave, departament *estructura){
			return arbolDep.retornarEstructura(clave,estructura);
		}*/
};
#endif
departamento* departamento::instance = 0;
