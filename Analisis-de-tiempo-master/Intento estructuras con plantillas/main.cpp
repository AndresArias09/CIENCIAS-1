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
	char *palabras = "Introducción a la primera página";
	char *palabras2 = "Introducción a la segunda página";
	//Creación de la página 1
	nodo<char> pagina;
	pagina.interior = palabras;
	//Creación página 2
	nodo<char> pagina2;
	pagina.interior = palabras2;
	//Creación del capítulo
	nodo<char> pages[] = {pagina,pagina2}; //Arreglo de páginas
	nodo<nodo<char> > capitulo;
	capitulo.interior = pages;
	//Creación del libro
	nodo<nodo<char> > chapters[] = {capitulo,capitulo};
	nodo<nodo<nodo<char> > > libro;
	libro.interior = chapters;
	//Creación de biblioteca
	nodo<nodo<nodo<char> > > books[] = {libro,libro};
	biblioteca.interior = books;
	return 0;
}

