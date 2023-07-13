//
#include <bits/stdc++.h>
using namespace std;
//
//#define V 5
//int parent[V];
//
//int find(int i)
//{
////	cout<<"parent["<<i<<"]"<<endl;
//	while (parent[i] != i){
////		cout<<"parent["<<i<<"]"<<endl;
//		i = parent[i];
////		cout<<"parent["<<i<<"]"<<endl;
//	}
//	return i;
//}
//
//void union1(int i, int j)
//{
//	int a = find(i);
//	int b = find(j);
//	parent[a] = b;
//}
//
//void kruskalMST(int cost[][V])
//{
//	int mincost = 0;
//
//	for (int i = 0; i < V; i++)
//		parent[i] = i;
//
//	int edge_count = 0;
//	while (edge_count < V - 1) {
//		int min = INT_MAX, a = -1, b = -1;
//		for (int i = 0; i < V; i++) {
//			for (int j = 0; j < V; j++) {
//				if (find(i) != find(j) && cost[i][j] < min) {
//					min = cost[i][j];
//					a = i;
//					b = j;
//					cout<<"i---"<<i<<endl;
//					cout<<"j---"<<j<<endl;
//					cout<<"find(i)--"<<find(i)<<endl;
//					cout<<"find(j)--"<<find(j)<<endl;
//					cout<<min<<endl;
//				}
//			}
//		}
//
//		union1(a, b);
//		printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
//		mincost += min;
//	}
//	printf("\nMinimum cost= %d \n", mincost);
//}
//
//int main()
//{
//	int cost[][V] = {
//		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
//		{ 2, INT_MAX, 3, 8, 5 },
//		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
//		{ 6, 8, INT_MAX, INT_MAX, 9 },
//		{ INT_MAX, 5, 7, 9, INT_MAX },
//	};
//
//	kruskalMST(cost);
//
//	return 0;
//}
int parent[5] = {1, 1, 2, 3, 4};
int find(int i){
	while(parent[i]!=i){
		cout<<i<<endl;
		cout<<"  "<<parent[i]<<endl;
		i = parent[i];
	}
	return i;
}

int main(){
	cout<<find(0);
}
