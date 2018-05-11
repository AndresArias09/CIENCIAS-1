#ifndef CANDIDATO
#define CANDIDATO
#include <string>
#include "Librerias/arbolAVL.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
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
		
		void insertarCandidato(candidate candidato){
			candidato.clave = ++this->cantidad;
			arbolCandidatos->agregar(candidato);
			//se agrega el candidato a la ciudad correspondiente
			ciudad::getInstance()->agregarCandidato(candidato,candidato.territorio);
			//se agrega el candidato al partido correspondiente
			partido::getInstance()->agregarCandidato(candidato,candidato.partido);
		}
		
		int getCantidad(){
			return this->cantidad;
		}
};

candidato* candidato::instance = 0;
#endif
