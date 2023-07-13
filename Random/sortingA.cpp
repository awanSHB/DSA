#include<iostream>
using namespace std;

void mergee(int A[], int lower, int mid, int upper);

void display(int A[], int size){
	cout<<"[ ";
	for(int i=0; i<size; i++)
		cout<<A[i]<<", ";
	cout<<"\b\b ]"<<endl;
}

void mergeSort(int Ar[], int low, int upp){
	if(low>=upp)
		return;
	int midd = (low+upp)/2;
	
	mergeSort(Ar, low, midd);
	mergeSort(Ar, midd+1, upp);
	
	cout<<"lower---"<<low<<"\nmid----"<<midd<<"\nupper---"<<upp<<endl;
	display(Ar, upp+1);
	
	mergee(Ar, low, midd, upp);
	
}

void mergee(int A[], int lower, int mid, int upper){
	
	int i, j, k;
	int n1 = mid-lower+1;
	int n2 = upper-mid;
	
	int X[n1];
	int Y[n2];
	
	for(i=0; i<n1; i++){
		X[i] = A[lower+i];
	}
	for(j = 0; j<n2; j++){
		Y[j] = A[mid+j+1];
	}
	
	i = j = 0;
	k = lower;
	
	while(i<n1 && j<n2){
		if(X[i] < Y[j])
			A[k++] = X[i++];
		else
			A[k++] = Y[j++];
	}
	
	while(i<n1)
		A[k++] = X[i++];
	while(j<n2)
		A[k++] = Y[j++];
	
//	display(A, 6);
}


int main(){
	int A[6] = {4, 5, 1, 2, 8, 7};
	mergeSort(A, 0, 5);
	display(A, 6);
}















