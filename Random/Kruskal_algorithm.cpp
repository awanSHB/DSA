#include<iostream>
#define S 5
#define INF 99999
using namespace std;

int parent[S];

int find(int index){
	while(parent[index]!=index){
		index = parent[index];
	}
	return index;
}

void detect_cycle(int a, int b){
	int Ap = find(a);
	int Bp = find(b);
	parent[Bp] = Ap;
}

int Kruskal(int G[S][S]){
	int minimum_cost = 0;
	int minweight = 0;
	int r;
	int c;
	int edges = 0;
	
	for(int i=0; i<S; i++)
		parent[i] = i;
	
	while(edges < S-1){
		minweight = INF;
		r = -1;
		c = -1;
		for(int i=0; i<S; i++){
			for(int j=0; j<S; j++){
				if(find(i)!=find(j) && ( G[i][j] < minweight && G[i][j]!=0 ) ){
					minweight = G[i][j];
					r = i;
					c = j;
				}
			}
		}
		
		detect_cycle(r, c);
		printf("Vertex :- %d : (%d, %d) minimum_cost :- %d\n", edges++, r, c, minweight);
		minimum_cost+=minweight;
	}
	
	return minimum_cost;
}

int main(){
//	int Graph[5][5] = {
//		{ 0, 2, 0, 6, 0},
//		{ 2, 0, 3, 8, 5 },
//		{ 0, 3, 0, 0, 7 },
//		{ 6, 8, 0, 0, 9 },
//		{ 0, 5, 7, 9, 0 },
//	};
	
	int Graph[5][5] = {
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
	{0, 19, 51, 0, 31},
	{0, 42, 66, 31, 0}
	};
	
	cout<<Kruskal(Graph);
}
















