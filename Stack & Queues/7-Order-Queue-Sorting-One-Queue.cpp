#include<iostream>
using namespace std;

struct Queue{
	public:
		int rear;
		int s;
		int *A;
		
		Queue(int size){
			rear = 0;
			s = size;
			A = new int[s];
		}
		
	bool isEmpty(){
		return (rear==0);
	}
	bool isFull(){
		return (rear==s);
	}
	
	void enque(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	void deque(){
		if(!isEmpty()){
			for(int i=0; i<rear; i++)
				A[i] = A[i+1];
			rear--;
		}
	}
	
	int getFront(){
		if(!isEmpty())
			return A[0];
	}
	
	void display(){
		cout<<"\n\n\t\t\t[ ";
		for(int i=0; i<rear; i++)
			cout<<A[i]<<" | ";
		cout<<"\b\b]";
	}
};

void Transfer(int A[], int n){
	Queue q1(n);
	Queue q2(n);
	
	for(int i=0; i<n; i++)
		q1.enque(A[i]);
	
	int a = 0;
	
	while(!q1.isEmpty()){
		a = q1.getFront();
		q1.deque();
		
		int r = q2.rear;
		
		if(q2.isEmpty())
			q2.enque(a);
		else if(q2.A[r-1]<a)
			q2.enque(a);
		else{
			while(q2.A[r-1]>a && r!=0){
				q2.A[r] = q2.A[r-1];
				r--;
			}
			q2.A[r] = a;
			q2.rear++;
		}
	}
	while(!q2.isEmpty()){
		q1.enque(q2.getFront());
		q2.deque();
	}
	
	q1.display();
	
}

int main(){
	int A[12] = {3, 2, 5, 1, 6, 4, 9, 7, 8, 12, 10, 11};
	Transfer(A, 12);
}

