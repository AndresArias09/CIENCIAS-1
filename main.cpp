/**
	@file main.cpp
	@brief Ejecutable de la aplicacion
	
	este archivo posee todos los metodos necesarios para la visualizacion del programa, incluyendo los men�s  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/


#include <iostream>
#include <windows.h>
#include "partido.h"
#include "departamento.h"
#include "ciudad.h"
#include "candidato.h"
#include <iomanip>
#include <string>
#include "Librerias/ListaOrdenada.h"
#include <sstream>






using namespace std;

int insertarVice(int partido);
void censoTotal();
void censoCiudad();
void consultasTarjetones(int opcion);
void consultasCenso(int opcion);
void consultasCandidatos(int opcion);
void consultarCiudades();
void consultarCandidatosDepartamentoPartido();
void consultarCandidatosPorPartido();
void consultarCandidatosPorCiudad();
void consultarCandidatosPporPartido();
void consultarCandidatosP();
void insertarCandidato();
void iniciarSimulacion();
void eliminarCandidato();
void estadisticasAlcaldias(int opcion);
void estadisticasPresidenciales();
void estadisticasDepartamento();
void estadisticasCiudad();
void modificarCandidato();
void mostrarPartidosPoliticos();
void menuConsultas(int opcion);
void menuRegistros(int opcion);
void menuPartidos(int opcion);
void menuCandidatos(int opcion);
void menuCiudades(int opcion);
void menu(int opcion);
void tarjetonPresidencial();
void tarjetonPorCiudad();
void simulacion(int opcion);
void alcaldesPorPartido();
void cargar();


/** 
	@brief funcion para ejecutar el programa
*/
int main(){
	cargar();
	int opcion;
	menu(opcion);
}

/**
	@brief funcion para mostrar el menu principal
	@param opcion que ser� digitada posteriormente por el usuario
	@returns devuelve el menu segun la opcion ingresada.

*/
void menu(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"MENU PRINCIPAL"<<endl<<endl;
	cout<<"1. Registros"<<endl<<"2. Consultas"<<endl<<"3. Iniciar simulacion"<<endl<<"4. Salir"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //gestion de registros
			menuRegistros(opcion);
		break;
		case 2: //consultas
			menuConsultas(opcion);
		break;
		case 3: //simulacion electoral
			simulacion(opcion);
		break;
		case 4: //salir
			exit(1);
			//aqui se reescriben los archivos
		break;
		default: 
			cout<<"Dato erroneo"<<endl;
			system("pause");
			system("CLS");
			menu(opcion);
	}
}
 /**
 	@brief este menu es especifico para realizar consultas (busquedas)
 	@param opcion para elegir un tipo de consulta
 	@returns retorna menu de consulta segun la opcion ingresada
 
 	
 */
void menuConsultas(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CONSULTAS"<<endl<<endl;
	cout<<"1. Candidatos"<<endl<<"2. Censo electoral"<<endl<<"3. Tarjetones"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //consultas candidatos
			consultasCandidatos(opcion);
		break;
		case 2: //censo electoral
			consultasCenso(opcion);
		break;
		case 3: //tarjetones
			consultasTarjetones(opcion);
		break;
		case 4: //volver
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuConsultas(opcion);
	}
	system("pause");
	menu(opcion);
}
/** 
	@brief muestra menu para realizar la consulta de un tarjeton
	@param opcion que ser� ingresada por el cliente para posteriormente mostrar un tarjeton especifico
	@returns llamado a funcion que genera tarjeton segun la opcion
*/
void consultasTarjetones(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"TARJETONES ELECTORALES"<<endl<<endl;
	cout<<"1. Tarjeton electoral de una ciudad"<<endl<<"2. Tarjeton presidencial"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //tarjeton por ciudad
			tarjetonPorCiudad();
		break;
		case 2: //tarjeton presidencial
			tarjetonPresidencial();
		break;
		case 3: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasTarjetones(opcion);
	}
	system("pause");
	menu(opcion);
}

/** 
	@brief muestra menu para consultar el censo
	@param opcion que sera ingresada por el cliente para mostrar un censo especifico
	@returns llamado a funcion que muestra censo segun la opcion
*/


void consultasCenso(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CENSO ELECTORAL"<<endl<<endl;
	cout<<"1. Censo electoral de una ciudad"<<endl<<"2. Censo electoral total"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //censo electoral de una ciudad
			censoCiudad();
		break;
		case 2: //censo total
			censoTotal();
		break;
		case 3: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasCenso(opcion);
	}
	system("pause");
	menu(opcion);
}
/**
	@brief muestra menu para consulta de candidatos
	@param opcion que ingresara el usuario para elegir una consulta de candidato especifica
	@returns llamado a funcion que muestra los candidatos especificos segun opcion ingresada
*/

void consultasCandidatos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CONSULTA DE CANDIDATOS"<<endl<<endl;
	cout<<"1. Candidatos a la presidencia"<<endl<<"2. Candidatos a alcaldias por ciudad"<<endl<<"3. Candidatos a alcaldias por partido"
	<<endl<<"4. Candidatos a alcaldias por departamento y partido"<<endl<<"5. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //consultar candidatos a la presidencia
			system("cls");
			cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
			cout<<"CANDIDATOS PRESIDENCIALES"<<endl<<endl;
			cout<<"1. Consultar todos"<<endl<<"2. Consultar por partido"<<endl<<"Opcion: ";
			cin>>opcion;
			switch(opcion){
				case 1: //consultar todos los candidatos presidenciales
					consultarCandidatosP();
				break;
				case 2: //consultar candidatos presidenciales por partido
					consultarCandidatosPporPartido();
				break;
				default:
					cout<<"Dato err�neo"<<endl;
					system("pause");
					system("CLS");
					consultasCandidatos(opcion);
			}
		break;
		case 2: //consultar candidatos a alcandias por ciudad
			consultarCandidatosPorCiudad();
		break;
		case 3: //consultar candidatos a alcandias por partido
			consultarCandidatosPorPartido();
		break;
		case 4: //consultar cantidatos a alcadias por departamento y partido
			consultarCandidatosDepartamentoPartido();
		break;
		case 5: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}
 /**
	@brief muestra menu de registros 
	@param opcion sera ingresada por el usuario
	@returns llamado a menu para realizar un registro especifico
  */
void menuRegistros(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS"<<endl<<endl;
	cout<<"1. Ciudades"<<endl<<"2. Candidatos"<<endl<<"3. Partidos politicos"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //registros de ciudades
			menuCiudades(opcion);
		break;
		case 2: //candidatos
			menuCandidatos(opcion);
		break;
		case 3: //partidos politicos
			menuPartidos(opcion);
		break;
		case 4: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuRegistros(opcion);
	}
	system("pause");
	menu(opcion);
}
/**
	@brief funcion que muestra el menu para mostrar un partido
	@param opcion que ingresara el usuario finalizada la visualizacion de los partidos
	@returns muestra los partidos politicos 
	
*/
void menuPartidos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE PARTIDOS POLITICOS"<<endl<<endl;
	mostrarPartidosPoliticos();
	system("pause");
	system("CLS");
	menu(opcion);
}
/**
	@brief funcion que muestra el menu para registrar un candidato
	@param opcion que ingresara el usuario finalizado el registro de un candidato
	@returns llamada llamada a funciones de registro de un candidato, segun opcion
	
*/
void menuCandidatos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE CANDIDATOS"<<endl<<endl;
	cout<<"1. Insertar"<<endl<<"2. Eliminar"<<endl<<"3. Modificar"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //insertar un candidato
			insertarCandidato();
		break;
		case 2: //eliminar un candidato
			eliminarCandidato();
		break;
		case 3: //modificar un candidato
			modificarCandidato();
		break;
		case 4: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}
/**
	@brief funcion que muestra el menu de la consulta de ciudades
	@param opcion que ingresara el usuario finalizada la visualizacion de las ciudades
	@returns llamado a funciones de las ciudades 
	
*/
void menuCiudades(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE CIUDADES"<<endl<<endl;
	cout<<"1. Consultar todas las ciudades"<<endl<<"2. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //consultar ciudades
			consultarCiudades();
		break;
		case 2: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuCiudades(opcion);
	}
	system("pause");
	menu(opcion);
}

/**
	@brief funcion que muestra el menu para la simulacion de 
	@param opcion que ingresara el usuario finalizada la visualizacion de los partidos
	@returns muestra los partidos politicos 
	
*/
void simulacion(int opcion){
	iniciarSimulacion();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"SIMULACION"<<endl<<endl;	
	cout<<"1. Iniciar simulacion de elecciones presidenciales"<<endl<<"2. Iniciar simulacion de elecciones a alcaldias locales"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas presidenciales
			estadisticasPresidenciales();
		break;
		case 2: //estadisticas de alcaldias
			estadisticasAlcaldias(opcion);
		break;
		case 3: //volver al inicio
			system("cls");
			menu(opcion);
		break;
		default:
			cout<<"Dato erroneo";
			system("pause");
			system("cls");
			menu(opcion);
	}
	system("pause");
	menu(opcion);
}
/**
	@brief muestra menu para visualizar estadisticas por ciudad
	@param opcion sera ingresada posteriormente para elegir un resultado de estadisticas especifico
	@returns llamado a funcion de estadisticas especificas
*/
void estadisticasAlcaldias(int opcion){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS DE ALCALDIAS"<<endl<<endl;
	cout<<"1. Estadisticas por ciudad"<<endl<<"2. Estadisticas por departamento"<<endl<<"3. Total alcaldes por partido"<<endl<<"4. Volver atras"
	<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas por ciudad
			estadisticasCiudad();
		break;
		case 2: //estadisticas por departamento
			estadisticasDepartamento();
		break;
		case 3: //total alcaldes por partidos
			alcaldesPorPartido();
		break;
		case 4: //volver al menu de simulacion
			system("cls");
			simulacion(opcion);
		break;
		default:
			cout<<"Dato erroneo";
			system("pause");
			system("cls");
			estadisticasAlcaldias(opcion);
	}	
	system("pause");
	menu(opcion);
}
/** 
@brief funcion para mostrar los alcaldes por partido
@returns alcaldes por partido

*/
void alcaldesPorPartido(){
	
}
/** 
@brief funcion para mostrar estadisticas por departamento
@returns estadisticas por departamento

*/
void estadisticasDepartamento(){
	
}
/** 
@brief funcion para mostrar estadisticas por ciudad
@returns estadisticas por ciudad

*/ 
void estadisticasCiudad(){

}
/** 
@brief funcion para mostrar  nombre, departamento y censo electoral de todas las ciudades
@returns impresion de nombre, departamento y censo electoral dada la lista de las ciudades
*/

void consultarCiudades(){
	ciudad *ciudad = ciudad->getInstance();
	departamento *departamento = departamento->getInstance();
	//lista de estructuras 'city'
	Lista<city> *lista = ciudad->consultarCiudades();
	city ciu;
	cout<<endl;
	cout<<"Nombre"<<setw(10)<<"Departamento"<<setw(10)<<"Censo electoral"<<endl;
	for(int i=1;i<lista->getTam();i++){
		ciu = lista->devolverDato(i);
		cout<<ciu.nombre<<setw(10);
		cout<<departamento->getNombreDepartamento(ciu.departamento)<<setw(10);
		cout<<ciu.censo<<setw(10);
		cout<<endl;
	}
	cout<<endl;
	delete ciudad;
	delete departamento;
	delete lista;
}
/** 
	@brief funcion para insertar candidato
	@returns formulario para ingresar un candidato
	
	
*/
void insertarCandidato(){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"INSERTAR UN NUEVO CANDIDATO"<<endl<<endl;
	candidato *candidato = candidato->getInstance();
	candidate can;
	string nombre,apellido,sexo,estadoCivil,fechaNacimiento;
	long long cc;
	int ciudadNatal,ciudadResidencia,partido,territorio,formulaVi,estado,tipoCandidato;
	cout<<"Nombre: ";
	cin>>nombre;
	cout<<"Apellido: ";
	cin>>apellido;
	cout<<"C.C.: ";
	cin>>cc;
	cout<<"Sexo: ";
	cin>>sexo;
	cout<<"Estado Civil: ";
	cin>>estadoCivil;
	cout<<"Fecha de nacimiento: ";
	cin>>fechaNacimiento;
	cout<<"Codigo ciudad natal: ";
	cin>>ciudadNatal;
	cout<<"Codigo ciudad residencia: ";
	cin>>ciudadResidencia;
	cout<<"Codigo partido politico: ";
	cin>>partido;
	cout<<"Tipo de candidato: 1. Presidencial 2. Alcaldia local: ";
	cin>>tipoCandidato;
	switch(tipoCandidato){
		case 1: //candidato presidencial
			territorio = 0;
			formulaVi = insertarVice(partido);
			estado = 1;
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
			//se agrega el candidato
			candidato->insertarCandidato(can);
		break;
		case 2: //candidato alcaldia local
			territorio = ciudadResidencia;
			formulaVi = 0;
			estado = 1;
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
			//se agrega el candidato
			candidato->insertarCandidato(can);
		break;
		default:
			cout<<"Dato erroneo";
			system("pause");
			system("cls");
			insertarCandidato();
	}
	cout<<"CANDIDATO INGRESADO CON EXITO"<<endl;
}

/** 
 @brief funcion para insertar un candidato vicepresidencial (necesaria al insertar uno presidencial)
 @return formulario de insercion candidato vicepresidencial
*/
int insertarVice(int partido){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"INSERTAR CANDIDATO VICEPRESIDENCIAL"<<endl<<endl;
	candidato *candidato = candidato->getInstance();
	candidate can;
	string nombre,apellido,sexo,estadoCivil,fechaNacimiento;
	long long cc;
	int ciudadNatal,ciudadResidencia,territorio,formulaVi,estado,tipoCandidato;
	cout<<"Nombre: ";
	cin>>nombre;
	cout<<"Apellido: ";
	cin>>apellido;
	cout<<"C.C.: ";
	cin>>cc;
	cout<<"Sexo: ";
	cin>>sexo;
	cout<<"Estado Civil: ";
	cin>>estadoCivil;
	cout<<"Fecha de nacimiento: ";
	cin>>fechaNacimiento;
	cout<<"Codigo ciudad natal: ";
	cin>>ciudadNatal;
	cout<<"Codigo ciudad residencia: ";
	cin>>ciudadResidencia;
	territorio = 0;
	formulaVi = 0;
	estado = 1;
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
	//se agrega el candidato
	candidato->insertarCandidato(can);
	return candidato->getCantidad();
}

/**
@brief fucion para eliminar un candidato dada la calve
@returns elimina un candidato

*/

void eliminarCandidato(){
	int clave;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ELIMINAR UN CANDIDATO"<<endl<<endl;
	cout<<"Digite el codigo del candidato que desea eliminar: ";
	cin>>clave;
	candidato::getInstance()->eliminarCandidato(clave);
	cout<<"CANDIDATO ELIMINADO"<<endl;
}
/** 
 @brief funcion para modificar un candidato
 @return formulario de modificacion  candidato
*/
void modificarCandidato(){
	int clave;
	candidate nuevo;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"MODIFICAR UN CANDIDATO"<<endl<<endl;
	cout<<"Digite el codigo del candidato que desea modificar: ";
	cin>>clave;
	candidate *can = candidato::getInstance()->getCandidato(clave);
	cout<<endl<<"CANDIDATO:"<<endl;
	cout<<"Nombre: "<<can->nombre<<endl;
	cout<<"Apellido: "<<can->apellido<<endl;
	cout<<"C.C.: "<<can->cc<<endl;
	cout<<"Sexo: "<<can->sexo<<endl;
	cout<<"Fecha de nacimiento: "<<can->fechaNacimiento<<endl;
	cout<<"Estado Civil: "<<can->estadoCivil<<endl;
	cout<<"Sexo: "<<can->sexo<<endl;
	cout<<"Ciudad natal: "<<ciudad::getInstance()->getNombreCiudad(can->ciudadNatal)<<endl;
	cout<<"Ciudad de residencia: "<<ciudad::getInstance()->getNombreCiudad(can->ciudadResidencia)<<endl;
	cout<<"Partido politico: "<<partido::getInstance()->getNombrePartido(can->partido)<<endl;
	if(can->territorio==0){
		if(can->formulaVi!=0)
			cout<<"Tipo de candidato: PRESIDENCIAL"<<endl;
		else
			cout<<"Tipo de candidato: VICEPRESIDENCIAL"<<endl;
	}
	else{
		cout<<"Tipo de candidato: Alcaldia local"<<endl;
		cout<<"Territorio al que aspira: "<<ciudad::getInstance()->getNombreCiudad(can->territorio)<<endl;
	}
	cout<<endl<<"DIGITE LA NUEVA INFORMACI�N PARA EL CANDIDATO:"<<endl<<endl;
	cout<<"Nombre: ";
	cin>>nuevo.nombre;
	cout<<"Apellido: ";
	cin>>nuevo.apellido;
	cout<<"C.C.: ";
	cin>>nuevo.cc;
	cout<<"Estado civil: ";
	cin>>nuevo.estadoCivil;
	cout<<"Fecha de nacimiento: ";
	cin>>nuevo.fechaNacimiento;
	cout<<"Codigo de la ciudad de nacimiento: ";
	cin>>nuevo.ciudadNatal;
	nuevo.estado = 1;
	candidato::getInstance()->modificarCandidato(clave,nuevo);
	cout<<endl<<"CANDIDATO MODIFICADO CON EXITO";	
}
/**
@brief funcion para mostrar todos los partidos politicos
@returns nombre del partido junto su representante legal

*/

void mostrarPartidosPoliticos(){
	partido *partido = partido->getInstance();
	Lista<partid> *lista = partido->consultarPartidos();
	partid par;
	cout<<"NOMBRE\t\tREPRESENTANTE LEGAL"<<endl;
	for(int i=0;i<lista->getTam();i++){
		par = lista->devolverDato(i);
		cout<<par.nombre<<"\t\t";
		cout<<par.representante<<endl;
	}
	cout<<endl;
	delete partido;
	delete lista;
}
/** 
	@brief funcion para consultar candidatos por departamento dado un partido mostrando toda su informacion
	@returns retorna toda la informacion de los candidatos dada la clave de un departamento y un partido
*/
 void consultarCandidatosDepartamentoPartido(){
	//llamado clases 
	partido *par=partido::getInstance();
	ciudad *ciu=ciudad::getInstance();
	int opcionpartido;
	int opciondepartamento;
	int i;
	//capturando la fecha actual
	time_t tiempo;
	struct tm *hoy;
	tiempo=time(NULL);
	hoy=localtime(&tiempo);
	int yearactual=hoy->tm_year+=1900;
	int mesactual=hoy->tm_mon++;
	int diaactual=hoy->tm_mday;
	system("cls");
	
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CANDIDATOS A ALCALDIAS POR PARTIDO POLITICO"<<endl<<endl;
	cout<<"Digite el codigo del partido que desea consultar: ";
	cin>>opcionpartido;
	cout<<"Digite el codigo del departamento que desea consultar: ";
	cin>>opciondepartamento;
	//lista de candidatos dada una clave del partido
	Lista <candidate*> lista= par->consultarCandidatosByPartido(opcionpartido);
	Lista <candidate*> opciones;
	candidate *can;
	//se busca los candidatos del partido que pertenecen al departamento dada la clave
	for (i=0; i<lista.getTam();i++){
		can=lista.devolverDato(i);
		if(opciondepartamento==ciu->getDepartamento(can->territorio)&&can->estado==1){
			opciones.anadir_final(can);
		}
	}
	//impresion
	cout<<endl<<"PARTIDO POLITICO: "<<partido::getInstance()->getNombrePartido(opcionpartido)<<endl;
	cout<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(opciondepartamento)<<endl<<endl;
	for(int i=0;i<opciones.getTam();i++){
		can = opciones.devolverDato(i);
			cout<<"CIUDAD: "<<ciudad::getInstance()->getNombreCiudad(can->territorio)<<endl;
			cout<<endl<<"NOMBRE APELLIDO C.C. SEXO ESTADO CIVIL FECHA NACIMIENTO EDAD CIUDAD NATAL CIUDAD RESIDENCIA"<<endl<<endl;	
			cout<<can->nombre<<" ";
			cout<<can->apellido<<" ";
			cout<<can->cc<<" ";
			cout<<can->sexo<<" ";
			cout<<can->estadoCivil<<" ";
			cout<<can->fechaNacimiento<<" ";
			cout<<candidato::getInstance()->calcularedad(can->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os ";
			cout<<ciudad::getInstance()->getNombreCiudad(can->ciudadNatal)<<" ";
			cout<<ciudad::getInstance()->getNombreCiudad(can->ciudadResidencia)<<" ";
			cout<<endl<<endl;
	}
 }
/**
	@brief funcion para consultar candidatos por partido 
	@returns muestra los candidatos de un partido 
*/
void consultarCandidatosPorPartido(){
	
	int clave;
	Lista<candidate*> lista;
	candidate *can;
	time_t tiempo;
	struct tm *hoy;
	tiempo=time(NULL);
	hoy=localtime(&tiempo);
	int yearactual=hoy->tm_year+=1900;
	int mesactual=hoy->tm_mon++;
	int diaactual=hoy->tm_mday;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CANDIDATOS A ALCALDIAS POR PARTIDO POLITICO"<<endl<<endl;
	cout<<"Digite el codigo del partido que desea consultar: ";
	cin>>clave;
	cout<<endl<<"PARTIDO POLITICO: "<<partido::getInstance()->getNombrePartido(clave)<<endl<<endl;
	lista = partido::getInstance()->consultarCandidatosByPartido(clave);
	for(int i=0;i<lista.getTam();i++){
		can = lista.devolverDato(i);
		if(can->estado==1 && can->territorio!=0){
			cout<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(ciudad::getInstance()->getCiudad(can->territorio)->departamento)<<endl;
			cout<<"CIUDAD: "<<ciudad::getInstance()->getNombreCiudad(can->territorio)<<endl<<endl;
			cout<<"NOMBRE APELLIDO C.C. SEXO ESTADO CIVIL FECHA NACIMIENTO EDAD CIUDAD NATAL CIUDAD RESIDENCIA"<<endl<<endl;
			cout<<can->nombre<<" ";
			cout<<can->apellido<<" ";
			cout<<can->cc<<" ";
			cout<<can->sexo<<" ";
			cout<<can->estadoCivil<<" ";
			cout<<can->fechaNacimiento<<" ";
			cout<<candidato::getInstance()->calcularedad(can->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os ";
			cout<<ciudad::getInstance()->getNombreCiudad(can->ciudadNatal)<<" ";
			cout<<ciudad::getInstance()->getNombreCiudad(can->ciudadResidencia)<<" ";
			cout<<endl<<endl;
		}
	}
}

/** 
@brief muestra los candidatos a alcaldias por cuidad
@returns informacion de los canndidatos a alcaldias por ciudad
*/
void consultarCandidatosPorCiudad(){
	int clave;
	candidate *can;
	ciudad *ciu = ciudad::getInstance();
	partido *par = partido::getInstance();
	time_t tiempo;
	struct tm *hoy;
	tiempo=time(NULL);
	hoy=localtime(&tiempo);
	int yearactual=hoy->tm_year+=1900;
	int mesactual=hoy->tm_mon++;
	int diaactual=hoy->tm_mday;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CANDIDATOS POR ALCALDIA LOCAL"<<endl<<endl;
	cout<<"Digite el codigo de la ciudad que desea ver: ";
	cin>>clave;
	cout<<endl<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(ciu->getCiudad(clave)->departamento)<<endl;
	cout<<"CIUDAD: "<<ciudad::getInstance()->getNombreCiudad(clave)<<endl<<endl;
	Lista<candidate*> lista = ciudad::getInstance()->getCandidatoByCiudad(clave);
	for(int i=0;i<lista.getTam();i++){
		can = lista.devolverDato(i);
		if(can->estado==1){ //se muestran solo los que tienen el estado en 1, alguno podria estar eliminado y no debe mostrarse
			cout<<"PARTIDO: "<<par->getNombrePartido(can->partido)<<endl;
			cout<<"NOMBRE APELLIDO C.C. SEXO ESTADO CIVIL FECHA NACIMIENTO EDAD CIUDAD NATAL CIUDAD RESIDENCIA"<<endl<<endl;
			cout<<can->nombre<<" ";
			cout<<can->apellido<<" ";
			cout<<can->cc<<" ";
			cout<<can->sexo<<" ";
			cout<<can->estadoCivil<<" ";
			cout<<can->fechaNacimiento<<" ";
			cout<<candidato::getInstance()->calcularedad(can->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os ";
			cout<<ciu->getNombreCiudad(can->ciudadNatal)<<" ";
			cout<<ciu->getNombreCiudad(can->ciudadResidencia)<<" ";
			cout<<endl<<endl;
		}
	}
}
/** 
	@brief muestra los candidatos presidenciales dado un partido 
	@returns muestra toda la informacion de un candidato en especifico
*/
void consultarCandidatosPporPartido(){
	candidate *presi,*vice;
	int partido;
	time_t tiempo;
	struct tm *hoy;
	tiempo=time(NULL);
	hoy=localtime(&tiempo);
	int yearactual=hoy->tm_year+=1900;
	int mesactual=hoy->tm_mon++;
	int diaactual=hoy->tm_mday;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CANDIDATOS PRESIDENCIALES"<<endl<<endl;
	cout<<"Digite el codigo del partido: ";
	cin>>partido;
	presi = ciudad::getInstance()->getCandidatoPByPartido(partido);
	if(presi==NULL || presi->formulaVi==0){
		cout<<"No hay ningun candidato presidencial habilidato por ese partido"<<endl;
	}
	else{
		vice = candidato::getInstance()->getCandidato(presi->formulaVi);
		cout<<endl<<"PARTIDO POLITICO: "<<partido::getInstance()->getNombrePartido(partido)<<endl<<endl;
		cout<<endl<<"CANDIDATO PRESIDENCIAL\t\t\tCANDIDATO VICEPRESIDENCIAL"<<endl<<endl;
		cout<<"Nombre: "<<presi->nombre<<"\t\t\tNombre: "<<vice->nombre<<endl;
		cout<<"Apellido: "<<presi->apellido<<"\t\t\tApellido: "<<vice->apellido<<endl;
		cout<<"Sexo: "<<presi->sexo<<"\t\t\tSexo: "<<vice->sexo<<endl;
		cout<<"Edad: "<<candidato::getInstance()->calcularedad(presi->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os "<<"\t\t\tEdad: "<<candidato::getInstance()->calcularedad(vice->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os ";
		cout<<endl;
	}
}
/** 
 @brief muestra toda la informacion de un candidato en especifico
 @ returns candidatos presidenciales
*/

void consultarCandidatosP(){
	candidate *presi,*vice;
	time_t tiempo;
	struct tm *hoy;
	tiempo=time(NULL);
	hoy=localtime(&tiempo);
	int yearactual=hoy->tm_year+=1900;
	int mesactual=hoy->tm_mon++;
	int diaactual=hoy->tm_mday;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CANDIDATOS PRESIDENCIALES"<<endl<<endl;
	Lista<candidate*> lista = ciudad::getInstance()->getCandidatoPresidencial();
	cout<<"CANDIDATO PRESIDENCIAL\t\t\tCANDIDATO VICEPRESIDENCIAL"<<endl<<endl;
	for(int i=0;i<lista.getTam();i++){
		presi = lista.devolverDato(i);
		if(presi->estado==1  && presi->formulaVi!=0){
			vice = candidato::getInstance()->getCandidato(presi->formulaVi);
			cout<<"Nombre: "<<presi->nombre<<"\t\t\tNombre: "<<vice->nombre<<endl;
			cout<<"Apellido: "<<presi->apellido<<"\t\t\tApellido: "<<vice->apellido<<endl;
			cout<<"Sexo: "<<presi->sexo<<"\t\t\tSexo: "<<vice->sexo<<endl;
			cout<<"Edad: "<<candidato::getInstance()->calcularedad(presi->fechaNacimiento,yearactual,mesactual,diaactual)<<"\t\t\tEdad: "<<candidato::getInstance()->calcularedad(vice->fechaNacimiento,yearactual,mesactual,diaactual)<<endl;
			cout<<"Edad: "<<candidato::getInstance()->calcularedad(presi->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os "<<"\t\t\tEdad: "<<candidato::getInstance()->calcularedad(vice->fechaNacimiento,yearactual,mesactual,diaactual)<<" a"<<char(-92)<<"os ";
			cout<<"Partido politico: "<<partido::getInstance()->getNombrePartido(presi->partido)<<endl;
			cout<<endl<<endl;
		}
	}
}
/** 
	@brief muestra todo la poblacion acta para votar en el pais
*/
void censoTotal(){
	ciudad *ciu=ciudad::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"Censo electoral Colombia: "<<ciu->getCensoTotal()<<endl;
	
}

/** 
	@brief muestra todo la poblacion acta para votar en una ciudad dada su clave
*/
void censoCiudad(){
	int clave;
	ciudad *ciu=ciudad::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"Digite el codigo de la ciudad que desea ver: ";
	cin>>clave;
	if(clave==0){
		cout<<"Dato erroneo";
		system("pause");
		censoCiudad();
	}
	else{
		cout<<ciu->getNombreCiudad(clave)<<": "<<ciu->getCenso(clave)<<endl;
	}
}
/** 
@brief generacion aleatoria del tarjeton presidencial 
@returns tarjeton electoral presidencial
*/
void tarjetonPresidencial(){
	candidate *can,*vice;
	ciudad *ciu = ciudad::getInstance();
	candidato *prin=candidato::getInstance();
	partido *par=partido::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"TARJETON PRESIDENCIAL"<<endl<<endl;
	Lista<candidate*> lista = ciu->getCandidatoPresidencial();
	Lista <candidate*> opciones;
	int num;
	int i;
	int j;
	// busca candidatos presidenciales no eliminados
	for (i=0;i<lista.getTam();i++){
		can=lista.devolverDato(i);
		if (can->estado==1&&can->formulaVi!=0){
			opciones.anadir_final(can);
		}	
	}
	//genera tarjeton de forma aleatoria
	srand(time(NULL));
	Lista <int> tarjeton;
	for(i=0;i<opciones.getTam();i++){
			do{
				num=rand()%(opciones.getTam());
			}while(tarjeton.estaDato(num));
			tarjeton.anadir_final(num);
		}
		//impresion
	cout<<"NUMERO  NOMBRE  PARTIDO POLITICO  FORMULA VICEPRESIDENCIAL"<<endl;
	cout<<"0. Voto en blanco"<<endl;
	for (i=0;i<tarjeton.getTam();i++){
		j=tarjeton.devolverDato(i);
		can=opciones.devolverDato(j);
		vice=prin->getCandidato(can->formulaVi);
		cout<<i+1<<". "<<can->nombre<<"  "<<can->apellido<<"  "<<par->getNombrePartido(can->partido)<<"  "<<vice->nombre<<"  "<<vice->apellido<<endl;
	}
}
/** 
@brief generacion aleatoria del tarjeton de alcaldia local 
@returns tarjeton electoral a la alcaldia local
*/
void tarjetonPorCiudad(){
	int clave;
	candidate *can;
	partido *par=partido::getInstance();
	ciudad *ciu = ciudad::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"TARJETON POR ALCALDIA LOCAL"<<endl<<endl;
	cout<<"Digite el codigo de la ciudad que desea ver: ";
	cin>>clave;
	cout<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(ciu->getCiudad(clave)->departamento)<<endl;
	cout<<"CIUDAD: "<<ciudad::getInstance()->getNombreCiudad(clave)<<endl<<endl;
	Lista<candidate*> lista = ciudad::getInstance()->getCandidatoByCiudad(clave);
	Lista <candidate*> opciones;
	int num;
	int i;
	int j;
	//candiadtos a alcaldia local no eliminados
	for (i=0;i<lista.getTam();i++){
		can=lista.devolverDato(i);
		if (can->estado==1){
			opciones.anadir_final(can);
		}	
	}
	srand(time(NULL));
	Lista <int> tarjeton;
	//generacion aleatoria del tarjeton
	for(i=0;i<opciones.getTam();i++){
			do{
				num=rand()%(opciones.getTam());
			}while(tarjeton.estaDato(num));
			tarjeton.anadir_final(num);
		}
	//impresion
	cout<<"NUMERO  NOMBRE  PARTIDO POLITICO"<<endl;
	cout<<"0. Voto en blanco"<<endl;
	for (i=0;i<tarjeton.getTam();i++){
		j=tarjeton.devolverDato(i);
		can=opciones.devolverDato(j);
		cout<<i+1<<".  "<<can->nombre<<"  "<<can->apellido<<"  "<<partido::getInstance()->getNombrePartido(can->partido)<<endl;
	}
}
/** 
@brief muestra todos las estadisticas de una simulacion de las elecciones presidenciales
@returns informacion de todos los resultados nacionales

*/
void estadisticasPresidenciales(){
	int i;
	int j;
	ciudad *ciu= ciudad::getInstance();
	candidate *can;
	Lista <Lista <long long> > votos= ciu->getVotosCiudades();
	ListaO <string> lista;
	Lista <candidate*> candidatosP= ciu->getCandidatoPresidencial();
	system("cls");
	//resultados nacionales
	cout<<"RESULTADOS ELECCIONES PRESIDENCIALES: "<<endl<<endl;
	cout<<"TOTAL VOTOS: "<<ciu->getCensoTotal()<<endl<<endl;
	Lista <long long> votostotales=ciu->getVotosPTotal(votos);
	Lista <float> porcentajes=ciu->getPorcentajesPTotal(votostotales);
	cout<<"NOMBRE   VOTOS   PORCENTAJE"<<endl<<endl;
	for(i=0;i<votostotales.getTam()-3;i++){
		std::ostringstream ss;
		std::ostringstream ss1;
		can=candidatosP.devolverDato(i);
		ss<<votostotales.devolverDato(i);
		ss1<<porcentajes.devolverDato(i);
		lista.anadir(porcentajes.devolverDato(i),can->nombre+"   "+can->apellido+"   "+ss.str()+"   "+ss1.str()+"%");
	}
	for(i=0;i<lista.getTam();i++){
		cout<<lista.devolverDato(i)<<endl;
	}
	lista.anadir(porcentajes.devolverDato(i),"blanco");
	
	cout<<endl<<"VOTOS EN BLANCO:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;
	i++;
	cout<<"VOTOS NULOS:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;
	i++;
	cout<<"TOTAL ABSTENCION:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;
	
	
	
	if((lista.devolverDato(0).compare("blanco"))==0){
		cout<<"HA GANADO EL VOTO EN BLANCO, SE REPITEN LAS ELECCIONES"<<endl;
	}
	else {
		cout<<endl<<"GANADOR DE LA PRIMERA VUELTA: ";
		cout<< lista.devolverDato(0)<<endl<<endl;
		if(lista.devolverClave(0)>50){
			cout<<"LAS ELECCIONES SE DEFINIERON EN PRIMERA VUELTA"<<endl;
			cout<<"EL NUEVO PRESIENTE DE LA REPUBLICA ES: ";
			cout<< lista.devolverDato(0);
		}
		else {
			cout<<"SE DEBE LLEVAR A CABO LA SEGUNDA VUELTA ENTRE LOS SIGUIENTES CANDIDATOS: "<<endl<<endl;
			cout<<"NOMBRE   VOTOS   PORCENTAJE"<<endl<<endl;
			cout<< lista.devolverDato(0)<<endl;
			if((lista.devolverDato(1).compare("blanco"))==0){
				cout<< lista.devolverDato(2)<<endl;
			}
			else{
				cout<< lista.devolverDato(1)<<endl;
			}
			
		} 
	}
	ListaO <string> listapar;
	partido *par=partido::getInstance();

	for(i=0;i<votostotales.getTam()-3;i++){
		std::ostringstream ss;
		std::ostringstream ss1;
		can=candidatosP.devolverDato(i);
		ss<<votostotales.devolverDato(i);
		ss1<<porcentajes.devolverDato(i);
		listapar.anadir(porcentajes.devolverDato(i),par->getNombrePartido(can->partido)+"   "+ss.str()+"   "+ss1.str()+"%");
	}
	system ("pause");
	system ("cls");	
	cout<<"RESULTADO ELECCIONES PRESIDENCIALES A NIVEL NACIONAL POR PARTIDO: "<<endl;
	cout<<"PARTIDO   VOTOS   PORCENTAJE"<<endl<<endl;	
	for(i=0;i<listapar.getTam();i++){
		cout<<listapar.devolverDato(i)<<endl;
	}
	listapar.anadir(porcentajes.devolverDato(i),"blanco");
	
	cout<<endl<<"VOTOS EN BLANCO:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;
	i++;
	cout<<"VOTOS NULOS:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;
	i++;
	cout<<"TOTAL ABSTENCION:"<<" ";
	cout<<votostotales.devolverDato(i)<<" ";
	cout<<porcentajes.devolverDato(i)<<"%"<<endl;	
	system("PAUSE");
	system("cls");
	
	Lista <long long> votosSexoPais = ciu->getVotosPSexo(votostotales);
	cout<<"RESULTADOS ELECCIONES PRESIDENCIALES POR SEXO A NIVEL NACIONAL: "<<endl;
	cout<<"MUJERES\t\t\tHOMBRES"<<endl<<endl;
		long long total=0;
		total = votosSexoPais.devolverDato(0)+votosSexoPais.devolverDato(1);
		for(i=0;i<votosSexoPais.getTam();i++){
			cout<<votosSexoPais.devolverDato(i)<<" "<<((float)votosSexoPais.devolverDato(i)/(float)total)*100<<" %\t\t";	
		}
		cout<<endl;
	
	system("PAUSE");
	system ("cls");
	departamento *dep= departamento::getInstance();
	Lista < Lista <long long> > votostotalesdep=dep->getVotosDepartamentos(votos);
	Lista <Lista <float> > porcentajesdep=dep->getPorcentajesDepartamentos(votostotalesdep);
	//Resultados por departamento	
	for (j=0;j<votostotalesdep.getTam();j++){
		system("cls");
		cout<<"RESULTADOS ELECCIONES PRESIDENCIALES POR DEPARTAMENTO: "<<endl<<endl;
		ListaO <string> listaCandidatos;
		cout<<"Departamento: "<<dep->getNombreDepartamento(j+1)<<" Censo: "<<dep->getCensobyDepartamento(j+1)<<endl<<endl;
		cout<<"NOMBRE   VOTOS   PORCENTAJE"<<endl<<endl;
		for(i=0;i<votostotalesdep.devolverDato(j).getTam()-3;i++){
			std::ostringstream ss;
			std::ostringstream ss1;
			can=candidatosP.devolverDato(i);
			ss<<votostotalesdep.devolverDato(j).devolverDato(i);
			ss1<<porcentajesdep.devolverDato(j).devolverDato(i);
			listaCandidatos.anadir(porcentajes.devolverDato(i),can->nombre+"   "+can->apellido+"   "+ss.str()+"   "+ss1.str()+"%");
		}
		for(i=0;i<listaCandidatos.getTam();i++){
			cout<<listaCandidatos.devolverDato(i)<<endl;	
		}
		cout<<endl<<"VOTOS EN BLANCO:"<<" ";
		cout<<votostotalesdep.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesdep.devolverDato(j).devolverDato(i)<<"%"<<endl;
		i++;
		cout<<endl<<"VOTOS NULOS:"<<" ";
		cout<<votostotalesdep.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesdep.devolverDato(j).devolverDato(i)<<"%"<<endl;
		i++;
		cout<<endl<<"TOTAL ABSTENCION:"<<" ";
		cout<<votostotalesdep.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesdep.devolverDato(j).devolverDato(i)<<"%"<<endl;
		system("PAUSE");
	}
	
	Lista <Lista <long long> > votosSexo = dep->votosDepartamentoSexo(votostotalesdep,ciu->getCandidatoPresidencial());
	

	
	for (j=0;j<votostotalesdep.getTam();j++){
		system("cls");
		cout<<"RESULTADOS ELECCIONES PRESIDENCIALES POR DEPARTAMENTO Y SEXO: "<<endl<<endl;
		cout<<"Departamento: "<<dep->getNombreDepartamento(j+1)<<" Censo: "<<dep->getCensobyDepartamento(j+1)<<endl<<endl;
		cout<<"MUJERES\t\t\tHOMBRES"<<endl<<endl;
		long long total = votosSexo.devolverDato(j).devolverDato(0)+votosSexo.devolverDato(j).devolverDato(1);
		for(i=0;i<votosSexo.devolverDato(j).getTam();i++){
			cout<<votosSexo.devolverDato(j).devolverDato(i)<<" "<<((float)votosSexo.devolverDato(j).devolverDato(i)/(float)total)*100<<" %\t\t";	
		}
		cout<<endl<<endl;
		system("PAUSE");
		system("cls");
	}
	
	for (j=0;j<votostotalesdep.getTam();j++){
		system("cls");
		cout<<"RESULTADOS ELECCIONES PRESIDENCIALES POR DEPARTAMENTO Y PARTIDO: "<<endl<<endl;
		cout<<"Departamento: "<<dep->getNombreDepartamento(j+1)<<" Censo: "<<dep->getCensobyDepartamento(j+1)<<endl<<endl;
		ListaO<string> votosPartidos;
		for(i=0;i<votostotalesdep.devolverDato(j).getTam()-3;i++){
			std::ostringstream ss;
			std::ostringstream ss1;
			can=candidatosP.devolverDato(i);
			ss<<votostotalesdep.devolverDato(j).devolverDato(i);
			ss1<<porcentajesdep.devolverDato(j).devolverDato(i);
			votosPartidos.anadir(porcentajesdep.devolverDato(j).devolverDato(i),par->getNombrePartido(can->partido)+"   "+ss.str()+"   "+ss1.str()+"%");
		}
		for(i=0;i<votosPartidos.getTam();i++){
			cout<<votosPartidos.devolverDato(i)<<endl;	
		}
		cout<<endl;
		system("PAUSE");
		system("cls");
	}
	//resultados por ciudad
	Lista <Lista <float> > porcentajesciu= ciu->getPorcentajesCiudades(votos);
	for (j=1;j<votos.getTam();j++){
		system("cls");
		cout<<"RESULTADOS ELECCIONES PRESIDENCIALES POR CIUDAD: "<<endl<<endl;
		cout<<"NOMBRE   VOTOS   PORCENTAJE"<<endl<<endl;
		cout<<"Ciudad: "<<ciu->getNombreCiudad(j)<<" Censo: "<<ciu->getCenso(j)<<endl<<endl;
		ListaO <string> candidates;
		for(i=0;i<votostotalesdep.devolverDato(j).getTam()-3;i++){
			std::ostringstream ss;
			std::ostringstream ss1;
			can=candidatosP.devolverDato(i);
			ss<<votos.devolverDato(j).devolverDato(i);
			ss1<<porcentajesciu.devolverDato(j).devolverDato(i);
			candidates.anadir(porcentajes.devolverDato(i),can->nombre+"   "+can->apellido+"   "+ss.str()+"   "+ss1.str()+"%");	
		}
		for(i=0;i<candidates.getTam();i++){
			cout<<candidates.devolverDato(i)<<endl;	
		}
		cout<<endl<<"VOTOS EN BLANCO"<<" ";
		cout<<votos.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesciu.devolverDato(j).devolverDato(i)<<"%"<<endl;
		i++;
		cout<<endl<<"VOTOS NULOS"<<" ";
		cout<<votos.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesciu.devolverDato(j).devolverDato(i)<<"%"<<endl;
		i++;
		cout<<endl<<"TOTAL ABSTENCION"<<" ";
		cout<<votos.devolverDato(j).devolverDato(i)<<" ";
		cout<<porcentajesciu.devolverDato(j).devolverDato(i)<<"%"<<endl;
		system("PAUSE");
		system("cls");
	}
	int opcion;
	simulacion(opcion);
}
/** 
 @brief funcion para iniciar la simulacion de las elecciones
*/
void iniciarSimulacion(){
}

/** 
@brief genera las instancias de todos las clases necesarias
*/
void cargar(){
	departamento::getInstance();
	ciudad::getInstance();
	partido::getInstance();
	candidato::getInstance();
}


