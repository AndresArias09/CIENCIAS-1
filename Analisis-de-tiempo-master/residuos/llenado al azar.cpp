#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void llenarAleatorio(char a[], int n, int i);
void mostrarArreglo(char a[], int n, int i);
int unsigned  bits (int x, int k, int j);
void cambioresiduos(char a[], int izq, int der, int b);
void intercambio (char a [],int i,int j);
void restar(char a[], int n, int i);
void agregar(char a[], int n, int i);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

using namespace std;
int main(int argc, char** argv) {
	srand (time(NULL));
	int n, i;
	int temp;
	char *a;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	//cin>> n;	
	n=10;
	while (n<=300){
		a= new char [n];
		llenarAleatorio(a,n,i);
		//mostrarArreglo(a,n,i);
		//system ("pause");
		restar(a,n,i);

		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		cambioresiduos (a,0,n-1,5);
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos
		agregar(a,n,i);
		//mostrarArreglo(a,n,i);
		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<n<<" Tiempo total: "<<secs<<"\n";
		delete a;
		n+=10;
}
	return 0;
	
}

void llenarAleatorio (char a[], int n, int i){
	for (i=0; i<n;i++){
		a[i]= (65+rand()%(80-65));
	}
}
void mostrarArreglo(char a[],int n,int i){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n";
}
int unsigned  bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}

void cambioresiduos(char a[], int izq, int der, int b){ 
	int i,j;
   	if (der>izq && b>=0){
		i= izq; j=der;
       	while(j!=i){
			while(!bits(a[i],b,1) && i<j)i++;
            while(bits(a[j],b,1) && j>i)j--;
            intercambio(a, i, j);
        }
        if (!bits(a[der],b,1)) j++;
        cambioresiduos(a, izq, j-1, b-1);
        cambioresiduos(a, j, der, b-1);
    }
}
void restar(char a[], int n, int i){
	for (i=0; i<n;i++){
		a[i]-=64;
	}
}
void agregar(char a[], int n, int i){
	for (i=0; i<n;i++){
		a[i]+=64;
	}
}
void intercambio (char a [],int i,int j){
	int temp = a [i];
	a[i] = a[j];
	a[j] = temp;
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
