#include<iostream>
using namespace std;

class Cirqueue{
	private:
		int front;
		int rear;
		int size;
		int *A;
	public:
		Cirqueue(int s){
			front = rear = -1;
			size = s;
			A = new int[size];
		}
		
	bool isEmpty(){
		return (front==-1)? true : false;
	}
	bool isFull(){
		if((front==0 && rear == size-1) || (rear == (front-1) % (size -1)))
			return true;
		return false;
	}
	
	void enqueue(int v){
		if(!isFull()){
			if(front==-1)
				front = 0;
			rear = (rear+1)%size;
			A[rear] = v;
		}
	}
	
	void dequeue(){
		if(!isEmpty()){
			int k = A[front];
			if(front==rear)
				front = rear = -1;
			else
				front = (front+1)%size;
			cout<<"\n\nThe remove Item is "<<k<<"\n\n";
		}
	}
	
	void display(){
		if(!isEmpty()){
			cout<<"\n\n\t\t\t";
			for(int i = front; i!=rear; i = (i+1)%size)
				cout<<A[i]<<" | ";
			cout<<A[rear];
		}
	}
	
};

int main(){
	Cirqueue cq(6);
	
	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);
	cq.enqueue(40);
	cq.enqueue(50);
	cq.enqueue(60);
	
	cq.display();
	
	cq.dequeue();
	
	cq.enqueue(70);
	
	cq.display();
}











