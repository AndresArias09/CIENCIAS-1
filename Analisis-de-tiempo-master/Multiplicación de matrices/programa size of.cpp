#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void crearMatriz(int n, int **a,int i,int j);
void mostrarMatriz(int n, int **a,int i, int j);
void eliminarMatriz(int n, int **a,int i, int j);
void multiplicar(int **a, int **b, int **c, int n,int i, int j, int k);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
using namespace std;


int main(int argc, char** argv) {
	srand(time(NULL));
	int n;
	int i;
	int j;
	int k;
	int **a;
	int **b;
	int **c;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;

	cout<<"Ingrese el tamanio de la matriz (n): ";
	cin>>n;
	a= new int *[n];
	b= new int *[n];
	c= new int *[n];
	crearMatriz(n,a,i,j);
	crearMatriz(n,b,i,j);
	mostrarMatriz(n, a,i,j);
	mostrarMatriz(n, b,i,j);
	QueryPerformanceCounter(&t_ini); //Midiendo tiempos
	multiplicar(a, b, c, n,i, j, k);
	QueryPerformanceCounter(&t_fin); //Midiendo tiempos
	mostrarMatriz(n, c,i,j);
	
	eliminarMatriz(n, a,i, j);
	eliminarMatriz(n, b,i, j);
	eliminarMatriz(n, c,i, j);
	secs = performancecounter_diff(&t_fin,&t_ini)*1000;
	cout<<secs<< endl;
	system ("pause");
	return 0;
}

void crearMatriz(int n, int **a,int i, int j){
		
		for (i=0;i<n;i++){
			a[i]=new int [n];
			for(j=0;j<n;j++){
			a[i][j]= 1+rand()%(21-1);
		}
	}
}	
void mostrarMatriz(int n, int **a,int i, int j){
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout << a [i][j]<<" || ";
		}
			cout << "\n";
			
	}
}
void eliminarMatriz(int n, int **a,int i, int j){
	for (i=0;i<n;i++){
		delete a[i];
	}
	delete a;
}

void multiplicar(int **a, int **b, int **c, int n,int i, int j, int k){
	for (i=0; i<n; i++){
		c[i]= new int[n];
		for (j=0;j<n;j++){
			c[i][j]=0;
			for (k=0;k<n;k++){
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

