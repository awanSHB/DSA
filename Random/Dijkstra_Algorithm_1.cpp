#include <iostream>
#define INF 9999
#define M 7
using namespace std;


void Dijkstra_Algorithm(int Graph[7][7], int start){
	int costMatrix[7][7];
	int distance[7];
	int visited[7];
	int nextnode;
	int count;
	int minidistance;
	int i, j;
	
	//Converting the Graph into costMatrix and replacing 0 with INF 
	for(i=0; i<M; i++){
		for(j=0; j<M; j++){
			if(Graph[i][j]==0)
				costMatrix[i][j] = INF;
			else
				costMatrix[i][j] = Graph[i][j];
		}
	}
	
	// Storing the first row of cost matrix into the distanace array
	for(i=0; i<M; i++){
		distance[i] = costMatrix[start][i];
		visited[i] = 0;
	}
	
	//Making the first element/node/vertex as visited
	visited[start] = 1;
	distance[start] = 0;
	count = 1;
	
	while(count<M-1){
		
		minidistance = INF;
		
		//Finding the minimum distance in the distance array(first row of costMatrix) 
		for(i=0; i<M; i++){
			if(distance[i] < minidistance && !visited[i]){
				minidistance = distance[i];
				nextnode = i;
			}
		}
		
		visited[nextnode] = 1;
		
		for(i=0; i<M; i++){
			if(!visited[i]){
				if(minidistance + costMatrix[nextnode][i] < distance[i]){
					distance[i] = minidistance + costMatrix[nextnode][i];
				}
			}
		}
		
		count+=1;
	}
	
	for(i=0; i<M; i++){
		if(i != start)
			printf("\n\nDistance from source to %d  :is:  %d", i, distance[i]);
	}
	
}

int main(){
	int Graph[M][M];


  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;
  
  Dijkstra_Algorithm(Graph, 0);
  return 0;
}