#include<iostream>
using namespace std;

#define V 4

//Initializing the matrix to 0
void initialize_zero(int A[][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			A[i][j] = 0;
		}
	}
}

// Adding the edges
void addEdges(int A[][V], int i, int j){
	A[i][j] = 1;
	A[j][i] = 1;
}

void show(int A[][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout<<"[ "<<A[i][j]<<" ]";
		}
		cout<<"\n";
	}
}

int main(){
	int A[V][V];
	
	//First Initialize the matrix to 0
	initialize_zero(A);
	
	addEdges(A, 0, 1);
	addEdges(A, 0, 2);
	addEdges(A, 1, 2);
	addEdges(A, 2, 0);
	addEdges(A, 2, 3);
	show(A);
}