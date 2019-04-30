#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>

void llenarArreglo(int *a,int i,int n);
void mostrarArreglo(int *a,int i,int n);
void ordenamientoInsercion(int *a,int i,int j, int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



int main(int argc, char** argv) {
	int c=1;
	while(c=1){
		//Variables para calcular tiempos
		LARGE_INTEGER t_ini, t_fin;
  		double secs;
  		//
		int i,j,n,*a;
		cout<<"Digite la dimesion del arreglo: ";
		cin>>n;
		srand(time(NULL));
		a = new int[n];  //se inicializa el arreglo
		llenarArreglo(a,i,n); //se llena el arreglo
		cout<<"Mostrando el arreglo: \n";
		mostrarArreglo(a,i,n); //se muestra el arreglo
		system("pause");
		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		ordenamientoInsercion(a,i,j,n); //se ordena el arreglo
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos
		cout<<"Mostrando arreglo ordenado: \n";
		mostrarArreglo(a,i,n); //se muestra el arreglo
		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<"\nTiempo total: "<<secs<<"\n";
		delete a;
		cin>>c;
	}
	
	system("pause");
	return 0;
}

void llenarArreglo(int *a,int i,int n){
	int x=50*n;
	for(i=0;i<n;i++){
		a[i] = 1+rand()%(50+1-1)+x;
		x-=50;
	}
}

void mostrarArreglo(int *a,int i,int n){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n";
}

void ordenamientoInsercion(int *a,int i,int j, int n){
	int b;
	for(i=1;i<n;i++){
		b=a[i];
		j=i-1;
		while(j>-1 && b<a[j]){ //
			a[j+1]=a[j]; //
			j-=1;
		}
		a[j+1]=b; //
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
