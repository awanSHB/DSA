#include <iostream>
using namespace std;

//#arshall Algorithm is for Directed Graph
//#when Column is 0 means No other Node can access The Node's Column
//#When Row is 0 means Current Node Cannot go to other nodes
Warshall_Algorithm(int M[4][4]){
	for(int k=0; k<4; k++){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				M[i][j] = M[i][j] || (M[i][k] && M[k][j]);
			}
		}
	}
}

display(int A[4][4]){
	for(int i=0; i<4; i++){
		cout<<"| ";
		for(int j=0; j<4; j++){
			cout<<A[i][j]<<"  ";
		}
		cout<<"|\n";
	}	
}

multiply(int N1[4][4], int N2[4][4], int M[4][4], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				M[i][j] += N1[i][k] * N2[k][j];
			}
			
		}
	}
	for(int i=0; i<4; i++){
		cout<<"| ";
		for(int j=0; j<4; j++){
			cout<<M[i][j]<<"  ";
		}
		cout<<"|\n";
	}
}

addMatrix(int A[4][4], int A1[4][4], int A2[4][4], int B[4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			B[i][j] += A[i][j] + A1[i][j] + A2[i][j];
		}
	}
	
	for(int i=0; i<4; i++){
		cout<<"| ";
		for(int j=0; j<4; j++){
			cout<<B[i][j]<<"  ";
		}
		cout<<"|\n";
	}
}



int main(){
	int A[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
	display(A);
	int A1[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int A2[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int B[4][4]  = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	
	cout<<"\n\nSquare Matrix:"<<endl;
	multiply(A, A, A1, 4);
	
	cout<<"\n\nCube Matrix:"<<endl;
	multiply(A, A1, A2, 4);
	
	cout<<"\n\nAdding Three Matrixes:\n"<<endl;
	addMatrix(A, A1, A2, B);
	
	int F[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	for(int i=0; i<4; i++){
		for(int j = 0; j<4; j++){
			if(A[i][j] == 0)
				F[i][j] = 0;
			else
				F[i][j] = 1;
		}
	}
	cout<<"\n\nNew Matrix:\n";
	display(F);
	Warshall_Algorithm(F);
	cout<<"\n\nAfter Warshall:\n\n";
	display(F);
	
//	int M1[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}};
	int M1[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}};
	Warshall_Algorithm(M1);
	cout<<"\n\nWarshall:\n";
	display(M1);

}