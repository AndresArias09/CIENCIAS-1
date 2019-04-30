#include <iostream>
#include <ctime> 
#include <time.h>
#include <stdio.h>
#include <windows.h>
//#define N 8
//#define ncuad N*N
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
void mover(int **tablero, int i, int pos_x, int pos_y, int *q, int N);

//posibles movimientos de un caballo contando su posición en x y en y 
const int ejex[8] = { -1,-2,-2,-1, 1, 2, 2, 1 },
          ejey[8] = { -2,-1, 1, 2, 2, 1,-1,-2 };

using namespace std;
int main(int argc, char **argv)
{
	LARGE_INTEGER t_ini, t_fin;
    double secs;
	
  
  	//redefinw el arreglo tablero como apuntador 
  	int **tablero;						 /* tablero del caballo. */
  	int i,j,q,N=5;
  	//cout<<"ingrese N: ";
  	//cin>>N;
  	while(N<=500){
	  	tablero = new int*[N];   //Reservando memoria para las filas de tablero
	  	for(i=0; i<N; i++){
		  	tablero[i] = new int [N];  //Reservando memoria para las columnas de tablero
	  	}
	   	/* inicializa el tablero a cero */
	  	for (i = 0; i < N; i++)
	   		for (j = 0; j < N; j++)
	    		tablero[i][j] = 0;
	
	   	/* pone el primer movimiento */
	  	tablero[0][0] = 1;
	  	QueryPerformanceCounter(&t_ini);
	  	mover(tablero,2,0,0,&q, N);
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		cout<<N<<" Tiempo total: "<<secs * 1000.0 <<endl;
		
	  	/*if (q) { // hay solucion: la muestra. 
	    	for (i = 0; i < N; i++) {
	      		for (j = 0; j < N; j++)
	        	printf("%3d ", tablero[i][j]);
	      		putchar('\n');
	    	}
	  	}
	  	else
	    	printf("\nNo existe solucion\n");
		*/
		
		
		for(i=0; i<N; i++){//eliminando memoria 
			delete[] tablero[i];
		}	
		delete[] tablero;	
		N++;	
	}
  return 0;
}

void mover(int **tablero,int i, int pos_x, int pos_y, int *q, int N)
{
	  int k, u, v;
	  int ncuad = N*N;
	  k = 0;
	  *q = 0;
	  do {
	    u = pos_x + ejex[k]; v = pos_y + ejey[k]; /* selecciona posible posición*/
	    if (u >= 0 && u < N && v >= 0 && v < N) { /* mira si se encuentra entre los límites del tablero */
	      if (tablero[u][v] == 0) {  /* mira si no se ha ocupado anteriormente*/
	        tablero[u][v] = i;  /*le asigna el candidato*/
	        if (i < ncuad) {  /*sigue haciendo los movimientos*/
	          mover(tablero,i+1,u,v,q,N);
	          if (!*q) tablero[u][v] = 0; /*si en algun momento no hay más solución se devuelve*/
	        }
	        else *q = 1; /* hay solucion */
	      }
	    }
	    k++;
	  } while (!*q && k < 8);//se acabaron las alternativas y no se pudo mover el caballo o ya se llenó todo el tablero
}
