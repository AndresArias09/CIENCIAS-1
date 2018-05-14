#ifndef estruct
#define estruct
#include "Librerias/ListaOrdenada.h"
#include "Librerias/arbolAVL.h"

//estructura para candidatos
struct candidate{
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
};
//estructura para partidos
struct partid{
	int clave;
	string nombre;
	string representante;
	Lista<candidate*> candidatos;
};
//estructura para ciudades
struct city{
	int clave;
	string nombre;
	int departamento;		
	long long censo;
	Lista<candidate*> candidatos;
};
//estructura para la simuacion de las elecciones, guarda datos acerca de cada candidato
struct candidatoSimulacion{
	candidate can;
	long long votos;
	float porcentaje;
};
//estructura para la simulacion de las elecciones, guarda datos acerca de cada ciudad
struct territorioSimulacion{
	int clave;
	city ciu;
	ListaO <candidatoSimulacion> candidatos;
	long long votosBlanco;
	long long votosNulos;
	long long abstencion;
	long long censoVotante;
	candidatoSimulacion ganador;
};
//estructura para departamentos
struct departament{
	int clave;
	string nombre;
	Lista<territorioSimulacion> ciudades;
};
#endif
