#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void cambioresiduos(int *a, int izq, int der, int b);
unsigned bits (int x, int k, int j);
void intercambio(int *a,int i, int j);
//void mostrarArreglo(int *a,int n,int i);
void codigoAscii(int *a,char b[],int n,int i);
void caracteres(int *a,char b[],int n,int i);


using namespace std;

int main(int argc, char *argv[]) {
	int i;
	char x[] = "EJEMPLOAORDENAR";
	char *b;
	b = x;
	int *arregloA = new int[strlen(x)];
	codigoAscii(arregloA,x,strlen(x),i); //se pasan las letras a su código ascii
	cout<<b<<endl;
	//for(i=0;i<15;i++) cout<<arregloA[i]<<endl;
	system("pause");
	cambioresiduos(arregloA,0,strlen(x)-1,4);
	//for(i=0;i<15;i++) cout<<arregloA[i]<<endl;
	caracteres(arregloA,b,strlen(x),i);
	cout<<b;
	return 0;
}

void codigoAscii(int *a,char b[],int n,int i){
	for(i=0;i<n;i++){
		a[i] = b[i]-64;
	}
}

void caracteres(int *a,char *b,int n,int i){
	for(i=0;i<n;i++){
		b[i] = a[i]+64;
	}
}

void cambioresiduos(int *a, int izq, int der, int b){ 
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

void intercambio(int *a,int i, int j){
	int temp;
	temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

unsigned bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}
