//interfaz (patron de diseño FACADE)
class facade{
	protected:
		int cantidad;
		bool leido;
	virtual void leerRegistros() = 0;
};
