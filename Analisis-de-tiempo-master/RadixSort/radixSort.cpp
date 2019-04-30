#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void llenarArreglo(int *a,int n,int i);
int getMax(int arr[], int n);
void countSort(int *arr, int n, int exp);
void radixsort(int *arr, int n);
void print(int arr[], int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

using namespace std;
 
 
 int main(){
 	LARGE_INTEGER t_ini, t_fin;
	double secs;
	int i,n;
	n=50;
	while(n<=500){
		srand (time(NULL));
		int *arr = new int[n];
    	llenarArreglo(arr,n,i);
    	//print(arr, n);
    	//system("pause");
    	QueryPerformanceCounter(&t_ini); //Midiendo tiempos
    	radixsort(arr, n);
    	QueryPerformanceCounter(&t_fin); //Midiendo tiempos
    	//print(arr, n);
    	secs = performancecounter_diff(&t_fin,&t_ini)*1000;
    	cout<<n<<" Tiempo total: "<<secs<<"\n";
    	delete arr;
    	n+=10;
	}
    return 0;
}

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int *arr, int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};
 	// Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 	// Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 	// Build the output array
    for (i = n - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 	// Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(int *arr, int n){
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 	int exp;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
}
 
void llenarArreglo(int *a,int n,int i){
	for(i=0;i<n;i++){
		a[i]= 1+rand()%(501-1);
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
