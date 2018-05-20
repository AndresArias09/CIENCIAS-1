/**
	@file facade.h
	@brief interfaz del patron fachada
	
	este archivo   posee la clase abstracta del patron fachada
	@author Andres Arias & Isabel Perez
	@date 8/05/2018,28/05/2018
*/


#ifndef FACADE_H
#define FACADE_H
//interfaz (patron de diseño FACADE)
class facade{
	protected:
		int cantidad;
		bool leido;
	virtual void leerRegistros() = 0; //funcion abstracta
	virtual void escribirRegistros() = 0; //funcion abstracta
};
#endif

