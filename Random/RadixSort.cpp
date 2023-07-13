#include <bits/stdc++.h>
#include "math.h"
using namespace std;

class Queue{
	private:
		int A[6];
		int front;
		int rear;
		
	public:
		Queue(){
			front = rear = 0;
		}
	
		bool isEmpty(){
			if(front==rear){
				front = rear = 0;
				return true;
			}else
				return false;
		}
		
		bool isFull(){
			return (rear==6);
		}
		
	void enque(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	void deque(){
		front++;
	}
	
	int getFront(){
		if(!isEmpty())
			return A[front];
		else
			return -1;
	}
};

void radixSort(int A[], int n){
	Queue q[10];
	int digits = 0;
	int x = 1;
	int d;
	int max = 0;
	int num = 0;
	int c=0;
	int st[6] = {0};
	
	for(int a = 0; a<n; a++){
		if(A[a] > max)
			max = A[a];
	}
	num = max;
	
	while(num>0){
		digits++;
		num /= 10;
	}
	
	for(int i=0; i<digits; i++){
		
		for(int k=0; k<n; k++){
			d = (A[k]/x)%10;
			q[d].enque(A[k]);
		}
		int j = 0;
		for(int m=0; m<10; m++){
			while(!q[m].isEmpty()){
				A[j++] = q[m].getFront();
				q[m].deque();
			}
		}
		x *= 10;
	}
//	for(int e=0; e<n; e++)
//		cout<<A[e]<< endl;
}

void display(int Ar[], int n){
	cout<<"\t\t\t\t";
	for(int e=0; e<n; e++)
		cout<<"[ "<<Ar[e]<<" ]";
}

int main(){
	int ar[6] = {321, 123, 432, 111, 555, 25};
	radixSort(ar, 6);
	display(ar, 6);
}