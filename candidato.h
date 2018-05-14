#ifndef CANDIDATO
#define CANDIDATO
#include <string.h>
#include "Librerias/arbolAVL.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "estructuras.h"
#include "facade.h"
#include "ciudad.h"
#include "partido.h"

//esta clase gestiona la lectura, escritura y la busqueda en el archivo candidatos.txt
class candidato: public facade{
	private:
		//arbol avl
		arbolAVL<candidate> *arbolCandidatos;
		//instancia unica
		static candidato *instance;
		//constructor privado
		candidato(){
			this->cantidad = 0;
			this->leido = false;
			arbolCandidatos = new arbolAVL<candidate>();
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		static candidato* getInstance(){
			if(instance==0){
				instance = new candidato();
			}
			return instance;
		}
		void leerRegistros(){ //aqui se leen los registros del archivo candidatos.txt
			int clave;
			string nombre;
			string apellido;
			long long cc;
			string sexo;
			string estadoCivil;
			string fechaNacimiento;
			int ciudadNatal;
			int ciudadResidencia;
			int partido;
			int territorio;
			int formulaVi;
			int estado;
			candidate can;
			this->cantidad = 0;
			//archivo de entrada
			ifstream archEntrada("Archivos/candidatos.txt", ios::in);
			if(!archEntrada.good()){
			 	cerr << "No se pudo abrir el archivo candidatos.txt" << endl;
    			exit(1);
			}
			//se leen los registros
			while(!archEntrada.eof()){
				archEntrada >> clave;
				archEntrada >> nombre;
				archEntrada >> apellido;
				archEntrada >> cc;
				archEntrada >> sexo;
				archEntrada >> estadoCivil;
				archEntrada >> fechaNacimiento;
				archEntrada >> ciudadNatal;
				archEntrada >> ciudadResidencia;
				archEntrada >> partido;
				archEntrada >> territorio;
				archEntrada >> formulaVi;
				archEntrada >> estado;
				can.clave = clave;
				can.nombre = nombre;
				can.apellido = apellido;
				can.cc = cc;
				can.sexo = sexo;
				can.estadoCivil = estadoCivil;
				can.fechaNacimiento = fechaNacimiento;
				can.ciudadNatal = ciudadNatal;
				can.ciudadResidencia = ciudadResidencia;
				can.partido = partido;
				can.territorio = territorio;
				can.formulaVi = formulaVi;
				can.estado = estado;
				this->insertarCandidato(can);
			}
			archEntrada.close();
		}
		//se inserta un candidato al arbol avl
		void insertarCandidato(candidate candidato){
			candidato.clave = ++this->cantidad;
			arbolCandidatos->agregar(candidato);
			candidate *can = arbolCandidatos->retornarEstructura(candidato.clave); 
			//se agrega el candidato a la ciudad correspondiente
			ciudad::getInstance()->agregarCandidato(can,candidato.territorio);
			//se agrega el candidato al partido correspondiente
			partido::getInstance()->agregarCandidato(can,candidato.partido);
		}
		//retonar la cantidad de registros
		int getCantidad(){
			return this->cantidad;
		}
		//modifica un candidado
		void modificarCandidato(int clave, candidate nuevo){
			candidate *can = arbolCandidatos->retornarEstructura(clave);
			can->nombre = nuevo.nombre;
			can->apellido = nuevo.apellido;
			can->cc = nuevo.cc;
			can->estadoCivil =  nuevo.estadoCivil;
			can->fechaNacimiento = nuevo.fechaNacimiento;
			can->ciudadNatal = nuevo.ciudadNatal;
			can->estado = nuevo.estado;
		}
		//retorna un apuntador a un candidato dado su codigo
		candidate *getCandidato(int clave){
			return arbolCandidatos->retornarEstructura(clave);
		}
		//calcula una edad dada una fecha de nacimiento
		int calcularedad(string fecha,int yearactual,int mesactual, int diaactual){
			char *nuevafecha=strdup(fecha.c_str());
			int dia,mes,year;
			char *ptr;
			ptr=strtok(nuevafecha,"/");
			dia=atoi(ptr);
			ptr=strtok(NULL,"/");
			mes=atoi(ptr);
			ptr=strtok(NULL,"/");
			year=atoi(ptr);
			//cout<<dia<<endl;
			//cout<<mes<<endl;
			//cout<<year<<endl;
			//cout<<hoy->tm_year<<" "<<hoy->tm_mon<< " "<<hoy->tm_mday<<endl;	
			//calcular edad
			int dias,meses,years;
			years=yearactual-year;
			meses=mesactual-mes;
			dias=diaactual-dia;
	
			if (dias<0){
				meses--;
			}
	
			if(meses<0){
				years--;
			}
			return years;
		}
		//elimina (cambia de estado) a un candidato
		void eliminarCandidato(int clave){
			candidate *can = arbolCandidatos->retornarEstructura(clave);
			can->estado = 0; 
		}
		//destructor
		void liberar(){
			escribirRegistros();
			delete arbolCandidatos;
			delete instance;
		}
		//escribir registros en archivo plano
		void escribirRegistros(){
			ofstream archsalida("Archivos/candidatos.txt",ios::out|ios::trunc);
			if (!archsalida.good()){
				cerr << "No se pudo abrir el archivo candidatos" << endl;
				exit(1);
			}
			Lista<candidate> candidatos = *arbolCandidatos->recorridoInOrden();
			for(int i=0;i<candidatos.getTam();i++){
				candidate can = candidatos.devolverDato(i);
				archsalida<<can.clave<<" "<<can.nombre<<" "<<can.apellido<<" "<<can.cc<<" "<<can.sexo<<" "<<can.estadoCivil
				<<" "<<can.fechaNacimiento<<" "<<can.ciudadNatal<<" "<<can.ciudadResidencia<<" "<<can.partido<<" "<<can.territorio<<" "
				<<can.formulaVi<<" "<<can.estado<<"\n";
			}
			archsalida.close();
		}
};


candidato* candidato::instance = 0;
#endif
