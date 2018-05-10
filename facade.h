#ifndef FACADE_H
#define FACADE_H
//interfaz (patron de diseño FACADE)
class facade{
	protected:
		int cantidad;
		bool leido;
	virtual void leerRegistros() = 0;
	//se cargan todos los registros de los archivos
};
#endif
