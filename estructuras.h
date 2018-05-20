/**
	@file escructuras.h
	@brief gestiona las estructuras necesarias para todo el proyecto
	
	este archivo posee todos las estructuras necesarias para el proyecto  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/

#ifndef estruct
#define estruct
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
//estructura para departamentos
struct departament{
	int clave;
	string nombre;
	Lista<city*> ciudades;
};
#endif
