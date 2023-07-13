#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Class for Fixed Front
class Queue{
	private:
		int array_size;
		int *A;							//Array that holds Queue elements
		int rear;
	public:
		Queue(){
			array_size = 10;			//Default size
			A = new int[array_size];	//Run time size allocation
			rear = 0;
		}
		Queue(int s){
			array_size = s;				//User given size
			A = new int[array_size];	//Run time size allocation
			rear = 0;
		}
		
		bool isEmpty(){
			return (rear==0);
		}
		bool isFull(){
			return (rear==array_size);	//If started from -1 then (rear==array_size-1)
		}
		
	void enqueue(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	int getFront(){
		return (!isEmpty())? A[0]: -1;
	}
	
	void dequeue(){
		for(int i=0; i<rear; i++)
			A[i] = A[i+1];
		rear--;
	}
	
	void display(){
		cout<<"\n\t\t\t\t";
		for(int i=0; i<rear; i++)
			cout<<"[ "<<A[i]<<" ]";	
	}
};



//Class for variable Front
class QueueVf{
	private:
		int array_size;
		int front;
		int rear;
		int *A;
	public:
		QueueVf(){
			array_size = 10;
			A = new int[array_size];
			front = rear = 0;
		}
		QueueVf(int s){
			array_size = s;
			A = new int[array_size];
			front = rear = 0;
		}
		
		bool isEmpty(){
			return (front==0 && rear==0);
		}
		
		bool isFull(){
			return (front==0 && rear==array_size);
		}
	
	void enque(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	int getFront(){
		return A[front];
	}
	
	void dequeue(){
		front++;
	}
	
	
	//Method for shifting left
//	void shift_left(int front, int rear){
//		int x = rear;
//		int y = front;
//		while(y!=x)
//			A[x] = A[x+1];
//	}
	
	//Deque shofting left method
//	int deQueSl(){
//		int temp;
//		if(!isEmpty()){
//			temp = A[rear];
//			if(front==rear)
//				front=rear=0;
//			else
//				shift_left(front, rear);
//			rear--;
//		}else{
//			cout<<"Sorry!!! The Queue is Empty"<<endl;
//			return 0;
//		}
//		return temp;	
//	}
	void display(){
		cout<<"\t\t\t\t";
		for(int i=front; i<rear; i++)
			cout<<"[ "<<A[i]<<" ]";
	}
};





int main(){
	cout<<"<<<-------------------------------------Fixed Front---------------------->>>"<<"\n\n";
	Queue q1;							//Default contructor: object of queue with default size
	Queue q2(5);						//Overloaded Constructor: object with defined size
	Queue q3(10);
	int val;
	
	q1.enqueue(11);
	q1.enqueue(12);
	q1.enqueue(13);
	q1.enqueue(14);
	q1.enqueue(15);
	cout<<"Elements of the First Queue with default size :"<<endl;
	q1.display();
	
	q2.enqueue(21);
	q2.enqueue(22);
	q2.enqueue(23);
	q2.enqueue(24);
	q2.enqueue(25);
	cout<<"\n\nElements of the Second queue with defined size:"<<endl;
	q2.display();
	
	cout<<"\n\n\n\nThe Top/Front/Head element of first queue is :  "<<q1.getFront()<<endl;
	cout<<"\nThe Top/Front/Head element of second queue is:  "<<q2.getFront()<<endl;
	
	cout<<"\n\nAfter removing the First/Top/Head element of First Q: "<<endl;
	q1.dequeue();
	q1.display();
	
	cout<<"\n\nAfter removing the First/Top/Head element of Second Q: "<<endl;
	q2.dequeue();
	q2.display();
	
	
	//Queue For the variable Front
	cout<<"\n\n\n\n\n\n";
	cout<<"<<<----------------------------------Variable Front---------------------->>>"<<"\n\n";
	
	QueueVf qv1;
	QueueVf qv2(5);
	QueueVf qv3(8);
	
	qv1.enque(15);
	qv1.enque(16);
	qv1.enque(17);
	qv1.enque(18);
	qv1.enque(19);
	cout<<"\n\nFirst Queue : ";
	qv1.display();
	
	qv2.enque(25);
	qv2.enque(26);
	qv2.enque(27);
	qv2.enque(28);
	qv2.enque(29);
	cout<<"\nSecond Queue: ";
	qv2.display();
	
	cout<<"\n\n\nRemoving Top/Head/First Element of First Q : "<<"\n\t";
	qv1.dequeue();
	qv1.display();
	
	cout<<"\n\n\nRemoving Top/Head/First Element of Second Q: "<<"\n\t";
	qv2.dequeue();
	qv2.display();
	
	
}