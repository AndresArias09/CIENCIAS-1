#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


template <class T>
struct nodo{
	T *interior;
};

using namespace std;
int main(int argc, char** argv) {
	
	nodo < nodo < nodo < nodo <char> > > >  biblioteca;
	//Contenido de la pagina
	char *palabras = "Introducci�n a la primera p�gina";
	char *palabras2 = "Introducci�n a la segunda p�gina";
	//Creaci�n de la p�gina 1
	nodo<char> pagina;
	pagina.interior = palabras;
	//Creaci�n p�gina 2
	nodo<char> pagina2;
	pagina.interior = palabras2;
	//Creaci�n del cap�tulo
	nodo<char> pages[] = {pagina,pagina2}; //Arreglo de p�ginas
	nodo<nodo<char> > capitulo;
	capitulo.interior = pages;
	//Creaci�n del libro
	nodo<nodo<char> > chapters[] = {capitulo,capitulo};
	nodo<nodo<nodo<char> > > libro;
	libro.interior = chapters;
	//Creaci�n de biblioteca
	nodo<nodo<nodo<char> > > books[] = {libro,libro};
	biblioteca.interior = books;
	return 0;
}

