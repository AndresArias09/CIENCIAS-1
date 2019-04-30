#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	int n,total,i,j;
	int **a;
	cout<<"Digite un numero: ";
	total = total + sizeof(n)+sizeof(i)+sizeof(j)+sizeof(a);
	cin>>n;
	a = new int*[n];
	for(i=0;i<n;i++){
		a[i] = new int[n];
		total = total+sizeof(a[i]);
		for(j=0;j<n;j++){
			a[i][j]=i*j;
			total=total+sizeof(a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" \n";
		}
		delete a[i];
	}
	cout<<"Valor total: "<<total<<"\n";
	delete a;
	system("pause");
	return 0;
}
