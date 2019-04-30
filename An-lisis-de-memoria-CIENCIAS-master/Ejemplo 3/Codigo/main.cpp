#include <iostream>
#include <stdlib.h>
#include <time.h>

void llenarMatriz(int **x,int n,int i,int j);
void mostrarMatriz(int **x,int n,int i,int j);
void sumarMatrices(int **x,int**y,int **z,int n,int i,int j,int *memoria);
void eliminarMemoria(int **x,int**y,int **z,int n,int i,int j);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int **a,**b,**c,n,i,j,totalMem;
	totalMem = sizeof(a)+sizeof(b)+sizeof(c)+sizeof(n)+sizeof(i)+sizeof(j);
	srand(time(NULL));
	cout<<"Ingrese el tamaño de la matriz cuadrada: ";
	cin>>n;
	a = new int*[n];
	b = new int*[n];
	c = new int*[n];
	llenarMatriz(a,n,i,j); //se llena la matriz
	llenarMatriz(b,n,i,j); //se llena la matriz
	cout<<"Matriz 1: \n";
	mostrarMatriz(a,n,i,j);
	cout<<"Matriz 2: \n";
	mostrarMatriz(b,n,i,j);
	//Se suman las matrices y se muestra la matriz resultante
	sumarMatrices(a,b,c,n,i,j,&totalMem);
	cout<<"Matriz 3: \n";
	mostrarMatriz(c,n,i,j);
	eliminarMemoria(a,b,c,n,i,j);
	cout<<"\n Total memoria: "<<totalMem<<"\n";
	system("pause");
	
	return 0;
}

void llenarMatriz(int **x,int n, int i, int j){
		for(i=0;i<n;i++){
		x[i] = new int[n];
		for(j=0;j<n;j++){
			x[i][j]=1+rand()%(101-1); //Generación de números aleatorios entre a y b = a+rand()%(b+1-a) 	
		}
	}
}

void mostrarMatriz(int **x,int n,int i,int j){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<x[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void sumarMatrices(int **x,int**y,int **z,int n,int i,int j,int *memoria){
	for(i=0;i<n;i++){
		z[i] = new int[n];
		*memoria += sizeof(x[i])+sizeof(y[i])+sizeof(z[i]);
		for(j=0;j<n;j++){
			z[i][j] = x[i][j]+y[i][j];
			*memoria += sizeof(x[i][j])+sizeof(y[i][j])+sizeof(z[i][j]);
		}
	}
}

void eliminarMemoria(int **x,int**y,int **z,int n,int i,int j){
	for(i=0;i<n;i++){
		delete x[i];
		delete y[i];
		delete z[i];
	}
	delete x;
	delete y;
	delete z;
}
