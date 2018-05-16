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
			departament *dep = arbolDep->retornarEstructura(clave);
			return dep->nombre;
		}
		//agrega una ciudad a su departamento correspondiente
		void agregarCiudad(int clave,city *ciudad){
			departament *dep = arbolDep->retornarEstructura(clave);
			dep->ciudades.anadir_final(ciudad); 
		}
		Lista<departament> *consultarDepartamento(){
			Lista<departament> *lista = arbolDep->recorridoInOrden();
			return lista;
		}
		Lista <long long> getVotosPbyDepartamento(int clave, Lista <Lista <long long> > votosciudades){
			departament *dep=arbolDep->retornarEstructura(clave);
			Lista <city*> ciudades = dep->ciudades;
			Lista <Lista <long long> > votosciudep;
			Lista <long long> totales;
			long long total;
			int i;
			int j;
			for (i=0;i<ciudades.getTam();i++){	
				votosciudep.anadir_final(votosciudades.devolverDato(ciudades.devolverDato(i)->clave));	
			}
			for (i=0;i<votosciudep.devolverDato(i).getTam();i++){
				total=0;
				for(j=0;j<votosciudep.getTam();j++){
					total+=votosciudep.devolverDato(j).devolverDato(i);
				}
				totales.anadir_final(total);
			}
			return totales;
		}
		Lista <Lista<long long> > getVotosDepartamentos (Lista <Lista<long long> > votosciudades){
			Lista <departament> *departamentos=consultarDepartamento();
			Lista <Lista <long long> > lista;
			Lista <long long> auxiliar;
			int i;
			for (i=1;i<=departamentos->getTam();i++){
				auxiliar=getVotosPbyDepartamento(i,votosciudades);
				lista.anadir_final(auxiliar);
			}
			return lista;
		}
		Lista <Lista<float> > getPorcentajesDepartamentos (Lista <Lista <long long> > votosdepartamento ){
			int i;
			int j;
			Lista <Lista <float> > porcentajes;
			double porcentaje=0.0;
			for (i=0;i<votosdepartamento.getTam();i++){
				Lista <float>  auxiliar;
				for(j=0;j<votosdepartamento.devolverDato(i).getTam();j++){
					porcentaje= ((float)votosdepartamento.devolverDato(i).devolverDato(j)/(float)getCensobyDepartamento(i+1))*100.0;
					auxiliar.anadir_final(porcentaje);
				}
				porcentajes.anadir_final(auxiliar);
			}
			return porcentajes;
		}
		long long getCensobyDepartamento(int op){
			int i;
			long long censo=0;
			departament *dep=arbolDep->retornarEstructura(op);
			Lista <city*> ciudades = dep->ciudades;
			for (i=0;i<ciudades.getTam();i++){
				censo+=ciudades.devolverDato(i)->censo;	
			}
			return censo;
		}
		Lista <Lista <long long> > votosDepartamentoSexo (Lista <Lista <long long> >votos, Lista <candidate*>candidatos){
			Lista<Lista <long long> > votosSexo;
			candidate *can;
			int i;
			int j;
			long long mujeres;
			long long hombres;
			for (i=0;i<votos.getTam();i++){
				Lista<long long> auxiliar;
				hombres=0;
				mujeres=0;
				for(j=0;j<candidatos.getTam();j++){
					can=candidatos.devolverDato(j);
					if(can->sexo.compare("Mujer")==0){
						mujeres+=votos.devolverDato(i).devolverDato(j);
					}
					else{
						hombres+=votos.devolverDato(i).devolverDato(j);
					}
				}
				
				auxiliar.anadir_final(mujeres);
				auxiliar.anadir_final(hombres);
				votosSexo.anadir_final(auxiliar);
			}
			return votosSexo;
		}
};
departamento* departamento::instance = 0;
#endif

