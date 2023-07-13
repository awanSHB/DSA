#include <iostream>
#define INFINITY 5000
using namespace std;

display(int A[4][4]){
	for(int i=0; i<4; i++){
		cout<<"|    ";
		for(int j=0; j<4; j++){
			cout<<A[i][j]<<"     ";
		}
		cout<<"|\n";
	}	
}


minimumDistance(int Q[4][4]){
	for(int k=0; k<4; k++){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				Q[i][j] = min(Q[i][j], Q[i][k] + Q[k][j]);
			}
		}
	}
	display(Q);
	
}

replaceVal(int Q[4][4], int M[4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(M[i][j]==0)
				Q[i][j] = INFINITY;
			else
				Q[i][j] = M[i][j];
		}
	}
	display(Q);
	cout<<"\n\n";
	minimumDistance(Q);
}

int main(){
	int W[4][4] = {{0, 2, 0, 4}, {2, 0, 3, 0}, {0, 3, 0, 2}, {4, 0, 2, 0}};
	int Q[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	
	replaceVal(Q, W);
//	display(Q);
//	minimumDistance(Q);
}