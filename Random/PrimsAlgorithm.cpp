#include <iostream>
#define S 5
#define M 99999
using namespace std;

void Algorithm(int Graph[S][S], int index){
//	char edges[5] = {'A', 'B', 'C', 'D', 'E'};
	int no_of_edges = 0;
	int selected[S];
	for(int i=0; i<S; i++)
		selected[i] = 0;
	
	selected[index] = 1;
	
	int row;
	int col;
	int total_sum = 0;
	
	while(no_of_edges < S-1){
		int min = M;
		for(int i=0; i<S; i++){
			if(selected[i]){
				for(int j=0; j<S; j++){
					if(!selected[j] && Graph[i][j]!=0){
						if(Graph[i][j] < min){
							min = Graph[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
		}
		
//		cout<<edges[row]<<" - "<<edges[col]<<" = "<<Graph[row][col]<<"\n";
		no_of_edges++;
		selected[col] = 1;
		total_sum+=min;
	}
	cout<<"\n\nTotal MinDistance is:- "<<total_sum;
}

int main(){
	int Graph[5][5] = {
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
	{0, 19, 51, 0, 31},
	{0, 42, 66, 31, 0}
	};
	
	Algorithm(Graph, 2);
	
}