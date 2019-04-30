#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct nodo{
	int x,y;
	nodo *sig;
};

int main(int argc, char** argv) {
	nodo *cab=NULL,*aux;
	int k,n,totalmem,c=1;
	while(c==1){
		totalmem=0;
		totalmem = sizeof(cab)+sizeof(aux)+sizeof(k)+sizeof(n);
		cout<<"Ingrese n: ";
		cin>>n;
		//int *a;
		for(k=0;k<n;k++){
			aux = new nodo;
			//cout<<"Direccion de aux: "<<aux<<"\n";
			totalmem+=sizeof(*aux);
			//cout<<"Size of struct: "<<sizeof(*aux)<<"\n";
			aux-> x = k;		
			aux-> y = n-k;
			aux -> sig = cab;
			cab = aux;
			//cout<<"Dirección en cab: "<<cab<<"\n";
			//cout<<"Dirección en aux: "<<aux<<"\n";
			//a=&(aux->x);
			//cout<<"Direccion de x: "<<a<<"\n";
			
			//cout<<"Size of x: "<<sizeof(aux->x)<<"\n";
			//cout<<"Size of y: "<<sizeof(aux->y)<<"\n";
			//cout<<"Size of sig: "<<sizeof(aux->sig)<<"\n";
		}
		while(aux!=NULL){
			cout<<aux->x<<aux->y<<"\n";
			aux=aux->sig;
		}
		for(aux=cab->sig;aux!=NULL;aux=aux->sig){
			delete cab;
			cab=aux;
		}
		cout<<"\n\n Memoria total: "<<totalmem<<"\n";
		cin>>c;	
	}
	system("pause");
	return 0;
}
