#include<iostream>
using namespace std;

class CirQueue{
	private:
		int front;
		int rear;
		int size;
		int *A;
	public:
		CirQueue(int s){
			size = s;
			front = rear = -1;
			A = new int[size];
		}
	
	bool isEmpty(){
		return (front==-1);
	}
	bool isFull(){
		return ((rear+1)%size==front && rear!=-1);
	}
	
	void enqueuePriority(int v){
		if(isFull()){
			cout<<"\n\n\nThe Queue is Full!!! Cannot Enqueue "<<v<<".\n\n";
			return;
		}
		
		if(front==-1){
			front = 0;
			rear = (rear+1)%size;
			A[rear] = v;
		}else{
			
			int t = front;
			int Temp = rear;
			rear = (rear+1)%size;
			
			if(A[front] > v && front!=0){
				t = front-1;
				A[t] = v;
				front = front-1;
				if(front==rear)
					rear = size - 1;
						
			}
			else{
				while(A[Temp] > v){
					A[(Temp+1)%size] = A[Temp];
					Temp--;
				}
				A[(Temp+1)%size] = v;
			}
		}
	}
	
	void enqueue(int v){
		if(isFull()){
			cout<<"\n\n\nThe Queue is Full! Cannot Enqueue "<<v<<".\n";
			return;
		}
		
		front = (front==-1)? 0:front;
		rear = (rear+1)%size;
		A[rear] = v;
	}
	
	void dequeue(){
		if(isEmpty())
			return;
		
		int T = A[front];
		front = (front==rear)? front=rear=-1 : (front+1)%size;
		cout<<"\n-------> "<<T<<"\n\n";
	}
	
	void display(){
		cout<<"\n\n\t\t\t";
		if(isEmpty())
			return;
		for(int i=front; i!=rear; i = (i+1)%size)
			cout<<A[i]<<" | ";
		cout<<A[rear];
	}
};

int main(){
	CirQueue cq(6);
	CirQueue cqp(6);
	
	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);
	cq.enqueue(40);
	cq.enqueue(50);
	cq.display();
	
	cq.enqueue(60);
	cq.display();
	
	cq.enqueue(70);
	cq.display();
	
	cq.dequeue();
	cq.display();
	
	cq.enqueue(70);
	cq.display();
	
	cq.dequeue();
	cq.display();
	cq.enqueue(80);
	cq.display();
	
	cout<<"\n\n\n\nPriority Circular Queue:\n";
	
	cqp.enqueuePriority(10);
	cqp.enqueuePriority(30);
	cqp.enqueuePriority(50);
	cqp.enqueuePriority(60);
	cqp.display();
	
	cqp.enqueuePriority(20);
	cqp.display();
	
	cqp.enqueuePriority(40);
	cqp.display();
	
	cqp.dequeue();
	cqp.display();
	
	cqp.enqueuePriority(10);
	cqp.display();
	
	cqp.dequeue();
	cqp.dequeue();
	cqp.display();
	
	cqp.enqueuePriority(25);
//	cqp.enqueuePriority(35);
	cqp.display();
	
}


