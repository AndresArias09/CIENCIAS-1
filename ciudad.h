#include <string>
#include "Lista.h"
struct city{
	int id;
	string nombre;
	string departamento;		
	long long censo;
};

//esta clase gestiona la lectura, escritura y la busqueda en el archivo ciudad.txt
class ciudad{
	private:
		static Lista<city> ciudades;
	public:
		static Lista<city> getCiudades(){
			return ciudades;
		}
		static void leerCiudades(){ //aqui se leen los registros del archivo ciudades.txt
			
		}
};
