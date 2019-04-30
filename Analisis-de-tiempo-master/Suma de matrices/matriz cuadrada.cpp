#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void llenarMatriz(int **x,int n,int i,int j);
void mostrarMatriz(int **x,int n,int i,int j);
void sumarMatrices(int **x,int**y,int **z,int n,int i,int j);
void eliminarMemoria(int **x,int**y,int **z,int n,int i,int j);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	//Variables para calcular tiempos
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
  	//
	int **a,**b,**c,n,i,j;
	n = 5;
	while(n<=150){
		srand(time(NULL));
		a = new int*[n];
		b = new int*[n];
		c = new int*[n];
		llenarMatriz(a,n,i,j); //se llena la matriz
		llenarMatriz(b,n,i,j); //se llena la matriz
		//Se suman las matrices y se muestra la matriz resultante
		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		sumarMatrices(a,b,c,n,i,j);
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos
		eliminarMemoria(a,b,c,n,i,j);
		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<"\n n = "<<n<<" - Total tiempo: "<<secs<<"\n";
		n+=5;
	}
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

void sumarMatrices(int **x,int**y,int **z,int n,int i,int j){
	for(i=0;i<n;i++){
		z[i] = new int[n];
		for(j=0;j<n;j++){
			z[i][j] = x[i][j]+y[i][j];
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

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
