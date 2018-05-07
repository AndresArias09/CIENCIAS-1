#include <string>
#include "Lista.h"

struct candidate{
	int id;
	string nombre;
	string apellido;
	long long cc;
	string sexo;
	string estadoCivil;
	string fechaNacimiento;
	string ciudadNatal;
	string ciudadResidencia;
	string partido;
	string territorio;
	string formulaVi;
	string estado;
};

//esta clase gestiona la lectura, escritura y la busqueda en el archivo candidatos.txt
class candidato{
	private:
		static Lista<candidate> candidatos;
	public:
		Lista<candidate> getCandidatos(){
			return candidatos;
		}
		void leerCandidatos(){ //aqui se leen los registros del archivo candidatos.txt
			
		}
};
