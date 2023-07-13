#include <iostream>
using namespace std;


class Queue{
	private:
		int A[9];
		int rear;
	public:
		Queue(){
			rear = 0;
		}
		bool isEmpty(){
			return (rear==0);
		}
		bool isFull(){
			return (rear == 9);
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
	}
	
};

void que1(){
	Queue q1;
	int A[5] = {2, 5, 3, 4, 1};
	for(int i=0; i<5; i++){
		q1.enque(A[i]);
	}
	
	Queue q2;
	int x = 0;
	bool check = true;
	q2.enque(q1.getFront());
	q1.deque();
	
	for(int i=0; i<9; i++){
		if(q2.isEmpty()){
			q2.enque(q1.getFront());
			q1.deque();
		}	
		if(q1.getFront() > q2.getFront()){
			q2.enque(q1.getFront());
			q1.deque();
			q1.enque(q2.getFront());
			q2.deque();
		}else{
			int x = q2.getFront();
			q2.deque();
			while(!q1.isEmpty()){
				q2.enque(q1.getFront());
				q1.deque();
			}
			while(!q2.isEmpty() && q2.getFront() <= x){
				q1.enque(q2.getFront());
				q2.deque();
			}
			q1.enque(x);
			while(!q2.isEmpty()){
				q1.enque(q2.getFront());
				q2.deque();
			}
		}
	}
	q1.display();
	cout<<"\n"<<endl;

}

void que2(){
	Queue q1;
	int A[9] = {2, 5, 3, 4, 1, 13, 7, 9, 11};
	for(int i=0; i<9; i++){
		q1.enque(A[i]);
	}
	
	Queue q2;
	Queue q3;
	q2.enque(q1.getFront());
	q1.deque();
	while(!q1.isEmpty()){
	
		while(!q2.isEmpty()){
			q3.enque(q2.getFront());
			q2.deque();
		}
		while(!q3.isEmpty() && q3.getFront() < q1.getFront()){
			q2.enque(q3.getFront());
			q3.deque();
		}
		q2.enque(q1.getFront());
		q1.deque();
		while(!q3.isEmpty()){
			q2.enque(q3.getFront());
			q3.deque();
		}
	}
	while(!q2.isEmpty()){
		q1.enque(q2.getFront());
		q2.deque();
	}
	q1.display();
}

int main(){
	que1();
	que2();
}
