#ifndef estruct
#define estruct
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

struct partid{
	int clave;
	string nombre;
	string representante;
	Lista<candidate*> candidatos;
};

struct city{
	int clave;
	string nombre;
	int departamento;		
	long long censo;
	Lista<candidate*> candidatos;
};

struct departament{
	int clave;
	string nombre;
};
#endif
