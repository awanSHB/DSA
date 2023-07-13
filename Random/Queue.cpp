#include <bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int A[6];
		int rear;
	public:
		Queue(){
			rear = 0;
		}
		bool isEmpty(){
			return (rear==0);
		}
		bool isFull(){
			return (rear == 6);
		}
		
	
	//Method for inertion
	void enque(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	//Method for getting a top value
	int getFront(){
		if(!isEmpty())
			return A[0];
		else
			return -1;
	}
	
	//Methdo for Removing
	void deque(){
		for(int i=0; i<rear; i++)
			A[i] = A[i+1];
		rear--;
	}
	
	void display(){
		cout<<"\t\t\t\t\t| ";
		for(int i = 0; i< rear; i++){
			cout<<A[i] << " | ";
		}
		
//		deque();
//		}
	}
	
};

int main(){
	Queue q;
	
	q.enque(10);
	q.enque(2);
	q.enque(3);
	q.enque(4);
	q.enque(5);
	q.enque(6);
	
	q.display();
	cout<<"\n\n";
	
	q.deque();
	q.display();
	cout<<"\n\n";
	
//	q.deque();
//	q.display();
//	cout<<"\n\n";
	
}