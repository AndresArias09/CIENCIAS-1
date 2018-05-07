#include <string>
#include "Lista.h"
struct partid{
	int id;
	string nombre;
	string representante;
};

//esta clase gestiona la lectura, escritura y la busqueda en el archivo partidos.txt
class partido{
	private:
		static Lista<partid> partidos;
	public:
		static Lista<partid> getPartidos(){
			return partidos;
		}
		static void leerPartidos(){ //aqui se leen los registros del archivo partidos.txt
			
		}
};
