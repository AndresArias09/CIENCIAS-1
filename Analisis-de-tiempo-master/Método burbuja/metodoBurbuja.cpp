#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <windows.h> //libreria que se necesita para medir el tiempo

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}




using namespace std;

int main(int argc, char*
* argv) {
	int *a;
	int n;
	int i;
	int temp1;
	int temp2;
	int j;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;

	
	cout<<"Ingrese el tamaño del arreglo: ";
	cin>>n;
	a= new int [n];
	j=n;
	cout<< "arreglo sin ordenar \n";
	for(i=0;i<n;i++){
		a[i]=(j*50);
		j--;
		cout<<a[i]<< endl;
	}
	QueryPerformanceCounter(&t_ini); //captura tiempo de incio
	for (i=n-1; i>0;i--){
		for (j=1;j<=i;j++){
			if (a[j-1] > a[j]){	
				temp1=a[j-1];
				temp2=a[j];
				a[j-1]=temp2;
				a[j]=temp1;	
			} 
			
		}
	}
	QueryPerformanceCounter(&t_fin);//captura tiempo final
	secs = performancecounter_diff(&t_fin, &t_ini);//resta final con inicial
	
	
	cout<<"arreglo ordenado \n";	
	for(i=0;i<n;i++){
		cout<<a[i]<< endl;
	}
	cout<< "tiempo: "<<secs* 1000.0;
	return 0;
}







