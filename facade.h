//interfaz (patron de dise�o FACADE)
class facade{
	protected:
		int cantidad;
		bool leido;
	virtual void leerRegistros() = 0;
};
