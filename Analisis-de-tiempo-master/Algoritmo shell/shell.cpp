#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>


void ordenshell (int *a, int N);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
void llenarArreglo(int *a,int i,int n, int x);
void mostrarArreglo(int *a,int i,int n);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char *argv[]) {
	int *a,n,i,x;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	n=50;
	while (n<=500){
	
	a = new int[n];
	llenarArreglo(a,i,n,x);
	//mostrarArreglo(a,i,n);
	QueryPerformanceCounter(&t_ini); //Midiendo tiempos
	ordenshell(a,n);
	QueryPerformanceCounter(&t_fin); //Midiendo tiempos
	secs = performancecounter_diff(&t_fin,&t_ini)*1000;
	//mostrarArreglo(a,i,n);
	cout<<"Cuando n vale: "<< n <<" El tiempo es de: "<< secs<<endl;
	delete a;
	n+=10;
	}
	return 0;
}

void ordenshell (int *a, int N){
	int i,j,h,v;
 	for(h=1 ;h<(N-1)/9; h= 3*h);
 		for(; h>0; h/=3)
 		for(i=h;i<N; i++){
			v=a[i]; j=i;
            while(j>=h && a[j-h] > v)
                {a[j] = a[j-h]; j-=h;
				}
            a[j]=v;
        }
}
void llenarArreglo(int *a,int i,int n, int x){

	for(i=0;i<n;i++){
		a[i] = x;
		x+=50;
	}
}

void mostrarArreglo(int *a,int i,int n){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n";
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

