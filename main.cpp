#include <iostream>
#include <windows.h>
#include "partido.h"
#include "departamento.h"
#include "ciudad.h"
#include "candidato.h"
#include <iomanip>
#include <string>
#include "simulacionCiudades.h"

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
void estadisticasNivelNacional();
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

int main(){
	cargar();
	int opcion;
	menu(opcion);
}

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
			iniciarSimulacion();
			simulacion(opcion);
		break;
		case 4: //salir
			candidato::getInstance()->liberar();
			ciudad::getInstance()->liberar();
			partido::getInstance()->liberar();
			departamento::getInstance()->liberar();
			simulacionCiudades::getInstance()->liberar();
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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			menuConsultas(opcion);
	}
	system("pause");
	menu(opcion);
}
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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			consultasTarjetones(opcion);
	}
	system("pause");
	menu(opcion);
}

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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			consultasCenso(opcion);
	}
	system("pause");
	menu(opcion);
}

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
					cout<<"Dato erróneo"<<endl;
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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			consultasCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}

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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			menuRegistros(opcion);
	}
	system("pause");
	menu(opcion);
}

void menuPartidos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE PARTIDOS POLITICOS"<<endl<<endl;
	mostrarPartidosPoliticos();
	system("pause");
	system("CLS");
	menu(opcion);
}

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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			menuCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}

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
			cout<<"Dato erróneo"<<endl;
			system("pause");
			system("CLS");
			menuCiudades(opcion);
	}
	system("pause");
	menu(opcion);
}

void simulacion(int opcion){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"SIMULACION"<<endl<<endl;	
	cout<<"1. Estadisticas presidenciales"<<endl<<"2. Estadisticas de elecciones a alcaldias locales"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas presidenciales
			estadisticasPresidenciales();
		break;
		case 2: //estadisticas de alcaldias	
			estadisticasAlcaldias(opcion);
		break;
		case 3: //volver al inicio
			simulacionCiudades::getInstance()->limpiar();
			candidato::getInstance()->escribirRegistros();
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

void estadisticasAlcaldias(int opcion){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS DE ALCALDIAS"<<endl<<endl;
	cout<<"1. Estadisticas por ciudad"<<endl<<"2. Estadisticas por departamento"<<endl<<"3. Estadisticas a nivel nacional"<<endl<<"4. Volver atras"
	<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas por ciudad
			estadisticasCiudad();
		break;
		case 2: //estadisticas por departamento
			estadisticasDepartamento();
		break;
		case 3: //estadisticas a nivel nacional
			estadisticasNivelNacional();
		break;
		case 4: //volver a la simulacion
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
	simulacion(opcion);
}

void estadisticasNivelNacional(){
	Lista<partid> *partidos = partido::getInstance()->consultarPartidos();
	simulacionNacionales nacionales = simulacionCiudades::getInstance()->consultarEstadisticasNacionales();
	int cantidadCiudades = ciudad::getInstance()->getCantidad()-1;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS A NIVEL NACIONAL"<<endl<<endl;
	cout<<"Alcaldes por partido: "<<endl<<endl;
	cout<<"NOMBRE CANTIDAD PORCENTAJE"<<endl<<endl;
	for(int i=0;i<partidos->getTam();i++){
		partid par = partidos->devolverDato(i);
		cout<<i+1<<" "<<par.nombre<<" "<<nacionales.totalesByPartido[i]<<" "<<((float)nacionales.totalesByPartido[i]/(float)cantidadCiudades)*100<<"%"<<endl;
	}
	cout<<endl<<"Total hombres: "<<nacionales.totalHombres<<" "<<((float)nacionales.totalHombres/(float)cantidadCiudades)*100<<"%"<<endl;
	cout<<endl<<"Total mujeres: "<<nacionales.totalMujeres<<" "<<((float)nacionales.totalMujeres/(float)cantidadCiudades)*100<<"%"<<endl;
	cout<<"Cantidad de ciudades donde gano el voto en blanco: "<<nacionales.ciudadesVotoBlanco.getTam()<<endl<<endl;
	if(nacionales.ciudadesVotoBlanco.getTam()>0){
		cout<<endl<<"Ciudades en donde gano el voto en blanco: "<<endl<<endl<<"NOMBRE  DEPARTAMENTO  CENSO VOTANTE  VOTOS EN BLANCO  PORCENTAJE"<<endl<<endl;
		for(int i=0;i<nacionales.ciudadesVotoBlanco.getTam();i++){
			territorioSimulacion territorio = nacionales.ciudadesVotoBlanco.devolverDato(i);
			cout<<"-> "<<territorio.ciu.nombre<<"  "<<departamento::getInstance()->getNombreDepartamento(territorio.ciu.departamento)<<"  "<<territorio.censoVotante<<"  "<<territorio.votosBlanco<<"  "<<((float)territorio.votosBlanco/(float)territorio.censoVotante)*100<<"%"<<endl;
		}
	}
}
void estadisticasDepartamento(){
	int clave;
	Lista<territorioSimulacion> ciudades;
	Lista<partid> *partidos = partido::getInstance()->consultarPartidos();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS POR DEPARTAMENTO"<<endl<<endl;
	cout<<"Digite el codigo del departamento que desea buscar: ";
	cin>>clave;
	if(!(clave>=1 && clave<=departamento::getInstance()->getCantidad())){
		cout<<"Codigo erroneo, intentelo de nuevo"<<endl;
		system("pause");
		estadisticasDepartamento();
	}
	else{
		departamentoSimulacion depSimulacion = simulacionCiudades::getInstance()->consultarEstadisticasDepartamento(clave);
		ciudades = depSimulacion.dep.ciudades;
		cout<<endl<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(clave)<<endl;
		cout<<"CENSO ELECTORAL: "<<depSimulacion.censo<<endl<<endl;
		cout<<"CIUDADES: "<<endl<<endl;
		for(int i=0;i<ciudades.getTam();i++){
			territorioSimulacion ciu = ciudades.devolverDato(i);
			cout<<"-> "<<ciu.ciu.nombre<<endl;
		}
		cout<<"Cantidad de ciudades: "<<depSimulacion.cantidadCiudades<<endl<<endl;
		cout<<"Cantidad de ciudades donde gano el voto en blanco: "<<depSimulacion.ciudadesVotoBlanco.getTam()<<endl<<endl;
		if(depSimulacion.ciudadesVotoBlanco.getTam()>0){
			cout<<"Ciudades en donde gano el voto en blanco: "<<endl<<endl<<"NOMBRE  CENSO VOTANTE  VOTOS EN BLANCO  PORCENTAJE"<<endl<<endl;
			for(int i=0;i<depSimulacion.ciudadesVotoBlanco.getTam();i++){
				territorioSimulacion territorio = depSimulacion.ciudadesVotoBlanco.devolverDato(i);
				cout<<"-> "<<territorio.ciu.nombre<<"  "<<territorio.censoVotante<<"  "<<territorio.votosBlanco<<"  "<<((float)territorio.votosBlanco/(float)territorio.censoVotante)*100<<"%"<<endl;
			}
		}
		cout<<endl<<"REPORTE GENERAL DEL DEPARTAMENTO: "<<endl<<endl;
		cout<<"Total votos (Censo votante): "<<depSimulacion.totalVotos<<" "<<((float)depSimulacion.totalVotos/(float)depSimulacion.censo)*100<<"%"<<endl;
		cout<<"Total votos en blanco: "<<depSimulacion.votosBlanco<<" "<<((float)depSimulacion.votosBlanco/(float)depSimulacion.totalVotos)*100<<"%"<<endl;
		cout<<"Total votos nulos: "<<depSimulacion.votosNulos<<" "<<((float)depSimulacion.votosNulos/(float)depSimulacion.censo)*100<<"%"<<endl;
		cout<<"Total abstencion: "<<depSimulacion.abstencion<<" "<<((float)depSimulacion.abstencion/(float)depSimulacion.censo)*100<<"%"<<endl<<endl;
		cout<<"REPORTE DETALLADO DEL DEPARTAMENTO: "<<endl<<endl;
		cout<<"Alcaldes por partido: "<<endl<<endl;
		cout<<"NOMBRE  CANTIDAD  PORCENTAJE"<<endl;
		for(int i=0;i<partidos->getTam();i++){
			partid par = partidos->devolverDato(i);
			cout<<i+1<<" "<<par.nombre<<" "<<depSimulacion.totalByPartido[i]<<" "<<((float)depSimulacion.totalByPartido[i]/(float)depSimulacion.cantidadCiudades)*100<<"%"<<endl;
		}
		cout<<endl<<"Total hombres: "<<depSimulacion.totalHombres<<" "<<((float)depSimulacion.totalHombres/(float)depSimulacion.cantidadCiudades)*100<<"%"<<endl;
		cout<<"Total mujeres: "<<depSimulacion.totalMujeres<<" "<<((float)depSimulacion.totalMujeres/(float)depSimulacion.cantidadCiudades)*100<<"%"<<endl<<endl;
	}
}

void estadisticasCiudad(){
	int clave;
	territorioSimulacion territorio;
	candidatoSimulacion can;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS POR CIUDAD"<<endl<<endl;
	cout<<"Digite el codigo de la ciudad que desea ver: ";
	cin>>clave;
	if(!(clave>=1 && clave<=ciudad::getInstance()->getCantidad()-1)){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		estadisticasCiudad();
	}
	else{
		territorio = simulacionCiudades::getInstance()->consultarEstadisticasTerritorio(clave);
		cout<<endl<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(territorio.ciu.departamento);
		cout<<endl<<"CIUDAD: "<<territorio.ciu.nombre;
		cout<<endl<<"CENSO ELECTORAL: "<<territorio.ciu.censo<<endl<<endl;
		cout<<"RESULTADOS: "<<endl<<endl;
		cout<<"POSICION  CANDIDATO  VOTOS  PORCENTAJE"<<endl;
		for(int i=0;i<territorio.candidatos.getTam();i++){
			can = territorio.candidatos.devolverDato(i);
			cout<<i+1<<".  "<<can.can.nombre<<" "<<can.can.apellido<<"  "<<can.votos<<"  "<<can.porcentaje<<"%"<<endl;
		}
		cout<<endl<<"Total votos en blanco: "<<territorio.votosBlanco<<"  "<<((float)territorio.votosBlanco/(float)territorio.censoVotante)*100<<"%"<<endl;
		cout<<endl<<"Total votos nulos: "<<territorio.votosNulos<<"  "<<((float)territorio.votosNulos/(float)territorio.ciu.censo)*100<<"%"<<endl;
		cout<<endl<<"Total abstencion: "<<territorio.abstencion<<"  "<<((float)territorio.abstencion/(float)territorio.ciu.censo)*100<<"%"<<endl;
		cout<<endl<<"Total censo votante: "<<territorio.censoVotante<<" "<<((float)territorio.censoVotante/(float)territorio.ciu.censo)*100<<"%"<<endl;
		candidatoSimulacion ganador = territorio.candidatos.devolverDato(0);
		if(ganador.votos>territorio.votosBlanco){
			cout<<endl<<"GANADOR: "<<ganador.can.nombre<<" "<<ganador.can.apellido<<" POR EL PARTIDO POLITICO: "<<partido::getInstance()->getNombrePartido(ganador.can.partido)<<endl;
		}
		else{
			cout<<endl<<"EL VOTO EN BLANCO TUVO LA MAYORIA DE VOTOS. POR TANTO, NO HAY GANADOR"<<endl;
		}
	}
}


void consultarCiudades(){
	ciudad *ciudad = ciudad->getInstance();
	departamento *departamento = departamento->getInstance();
	//lista de estructuras 'city'
	Lista<city> *lista = ciudad->consultarCiudades();
	city ciu;
	cout<<endl;
	cout<<"NOMBRE   DEPARTAMENTO   CENSO ELECTORAL"<<endl;
	for(int i=1;i<lista->getTam();i++){
		ciu = lista->devolverDato(i);
		cout<<ciu.nombre<<"   ";
		cout<<departamento->getNombreDepartamento(ciu.departamento)<<"   ";
		cout<<ciu.censo<<"   ";
		cout<<endl;
	}
	cout<<endl;
	delete ciudad;
	delete departamento;
	delete lista;
}

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
	cout<<"CANDIDATO INGRESADO CON EXITO. SU CODIGO DE CANDIDATO ES: "<<candidato::getInstance()->getCantidad()<<endl;
}

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

void eliminarCandidato(){
	int clave;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ELIMINAR UN CANDIDATO"<<endl<<endl;
	cout<<"Digite el codigo del candidato que desea eliminar: ";
	cin>>clave;
	if(!(clave>=1 && clave<=candidato::getInstance()->getCantidad())){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		eliminarCandidato();
	}
	else{
		candidato::getInstance()->eliminarCandidato(clave);
	    cout<<"CANDIDATO ELIMINADO"<<endl;
	}
	
}

void modificarCandidato(){
	int clave;
	candidate nuevo;
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"MODIFICAR UN CANDIDATO"<<endl<<endl;
	cout<<"Digite el codigo del candidato que desea modificar: ";
	cin>>clave;
	if(!(clave>=1 && clave<=candidato::getInstance()->getCantidad())){
		cout<<"Codigo erronea. Intentelo de nuevo"<<endl;
		system("pause");
		modificarCandidato();
	}
	else{
		candidate *can = candidato::getInstance()->getCandidato(clave);
		if(can->estado==0){
			cout<<"No puede modificar este candidato porque ya está eliminado"<<endl;
			system("pause");
		}
		else{
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
			cout<<endl<<"DIGITE LA NUEVA INFORMACION PARA EL CANDIDATO:"<<endl<<endl;
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
	}
}

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

 void consultarCandidatosDepartamentoPartido(){
	partido *par=partido::getInstance();
	ciudad *ciu=ciudad::getInstance();
	int opcionpartido;
	int opciondepartamento;
	int i;
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
	if(!(opcionpartido>=1 && opcionpartido<=partido::getInstance()->getCantidad())){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		consultarCandidatosDepartamentoPartido();
	}
	else{
		cout<<"Digite el codigo del departamento que desea consultar: ";
		cin>>opciondepartamento;
		if(!(opciondepartamento>=1 && opciondepartamento<=departamento::getInstance()->getCantidad())){
			cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
			system("pause");
			consultarCandidatosDepartamentoPartido();
		}
		else{
			Lista <candidate*> lista= par->consultarCandidatosByPartido(opcionpartido);
			Lista <candidate*> opciones;
			candidate *can;
			for (i=0; i<lista.getTam();i++){
				can=lista.devolverDato(i);
				if(opciondepartamento==ciu->getDepartamento(can->territorio)&&can->estado==1){
					opciones.anadir_final(can);
				}
			}
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
	}
 }

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
	if(!(clave>=1 && clave<=partido::getInstance()->getCantidad())){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		consultarCandidatosPorPartido();
	}
	else{
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
}

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
	if(!(clave>=1 && clave<=ciudad::getInstance()->getCantidad()-1)){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		consultarCandidatosPorCiudad();
	}
	else{
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
}

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
	if(presi==NULL || presi->formulaVi==0 || presi->estado==0){
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

void censoTotal(){
	ciudad *ciu=ciudad::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"Censo electoral Colombia: "<<ciu->getCensoTotal()<<endl;
	
}

void censoCiudad(){
	int clave;
	ciudad *ciu=ciudad::getInstance();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"Digite el codigo de la ciudad que desea ver: ";
	cin>>clave;
	if(!(clave>=1 && clave<=ciudad::getInstance()->getCantidad()-1)){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		censoCiudad();
	}
	else{
		if(clave==0){
			cout<<"Dato erroneo";
			system("pause");
			censoCiudad();
		}
		else{
			cout<<ciu->getNombreCiudad(clave)<<": "<<ciu->getCenso(clave)<<endl;
		}
	}
}

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
	for (i=0;i<lista.getTam();i++){
		can=lista.devolverDato(i);
		if (can->estado==1&&can->formulaVi!=0){
			opciones.anadir_final(can);
		}	
	}
	srand(time(NULL));
	Lista <int> tarjeton;
	for(i=0;i<opciones.getTam();i++){
			do{
				num=rand()%(opciones.getTam());
			}while(tarjeton.estaDato(num));
			tarjeton.anadir_final(num);
		}
	cout<<"NUMERO  NOMBRE  PARTIDO POLITICO  FORMULA VICEPRESIDENCIAL"<<endl;
	cout<<"0. Voto en blanco"<<endl;
	for (i=0;i<tarjeton.getTam();i++){
		j=tarjeton.devolverDato(i);
		can=opciones.devolverDato(j);
		vice=prin->getCandidato(can->formulaVi);
		cout<<i+1<<". "<<can->nombre<<"  "<<can->apellido<<"  "<<par->getNombrePartido(can->partido)<<"  "<<vice->nombre<<"  "<<vice->apellido<<endl;
	}
}

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
	if(!(clave>=1 && clave<=ciudad::getInstance()->getCantidad()-1)){
		cout<<"Codigo erroneo. Intentelo de nuevo"<<endl;
		system("pause");
		tarjetonPorCiudad();
	}
	else{
		cout<<"DEPARTAMENTO: "<<departamento::getInstance()->getNombreDepartamento(ciu->getCiudad(clave)->departamento)<<endl;
		cout<<"CIUDAD: "<<ciudad::getInstance()->getNombreCiudad(clave)<<endl<<endl;
		Lista<candidate*> lista = ciudad::getInstance()->getCandidatoByCiudad(clave);
		Lista <candidate*> opciones;
		int num;
		int i;
		int j;
		for (i=0;i<lista.getTam();i++){
			can=lista.devolverDato(i);
			if (can->estado==1){
				opciones.anadir_final(can);
			}	
		}
		srand(time(NULL));
		Lista <int> tarjeton;
		for(i=0;i<opciones.getTam();i++){
				do{
					num=rand()%(opciones.getTam());
				}while(tarjeton.estaDato(num));
				tarjeton.anadir_final(num);
			}
		cout<<"NUMERO  NOMBRE  PARTIDO POLITICO"<<endl;
		cout<<"0. Voto en blanco"<<endl;
		for (i=0;i<tarjeton.getTam();i++){
			j=tarjeton.devolverDato(i);
			can=opciones.devolverDato(j);
			cout<<i+1<<".  "<<can->nombre<<"  "<<can->apellido<<"  "<<partido::getInstance()->getNombrePartido(can->partido)<<endl;
		}
	}
}
void estadisticasPresidenciales(){
	
}

void iniciarSimulacion(){
	simulacionCiudades::getInstance()->iniciar();
}
void cargar(){
	departamento::getInstance();
	ciudad::getInstance();
	partido::getInstance();
	candidato::getInstance();
}


