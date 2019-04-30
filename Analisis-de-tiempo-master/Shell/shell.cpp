#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
void ordenshell (int *a, int n);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char *argv[]) {
	//Variables para calcular tiempos
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	//
	int *a,n,i,x;
	n=50;
	while(n<=500){
		a = new int[n];
		x= n*50;
		for(i=0;i<n;i++){
			a[i] = x;
			x-=50;
		}
		
		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		ordenshell(a,n);
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos


		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<"n = "<<n<<" - Tiempo total: "<<secs<<endl;
		delete a;
			n+=10;
	}
	
	return 0;
}

void ordenshell (int *a, int n){
	int i,j,h;  
	int v;
 	for(h=1; h<=n/9; h= 3*h+1);
 	for(; h>0; h/=3)
 	for(i=h+1;i<=n; i+=1){
		v=a[i-1]; j=i;
        while(j >h && a[j-h-1] > v){
			a[j-1] = a[j-h-1];
			j-=h;
		}
        a[j-1]=v;
    }
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


