#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <windows.h> //libreria que se necesita para medir el tiempo

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
void llenarArreglo(int *a,int i,int n);
int busquedaBinaria(int *a, int tamano, int clave);



using namespace std;

int main(int argc, char*
* argv) {
	int *a;
	int n;
	int i;
	int j;
	int respuesta;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;

	
	
	n = 5;
	while(n<=150){
		a= new int [n];
		llenarArreglo(a,i,n);	
		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		respuesta= busquedaBinaria(a,n,a[n-1]);
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos
		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<"n = "<<n<<" - Tiempo total: "<<secs<<"\n";
		delete a;
		n+=5;
	}
	
	
	return 0;
	
	
}
	//cout<< "tiempo: "<<secs* 1000.0;
	


int busquedaBinaria(int *a, int tamano, int clave)
{
	int iArriba = tamano-1;
	int iAbajo = 0;
	int iCentro;
	
	while (iAbajo <= iArriba)
	{
		iCentro = (iArriba + iAbajo)/2;
		if (a[iCentro] == clave)
 			return iCentro;
      	else
 		if (clave < a[iCentro])
   			iArriba=iCentro-1;
 		else
   			iAbajo=iCentro+1;
    }
  	return -1;
  	
}

void llenarArreglo(int *a,int i,int n){
	int x=50;
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






