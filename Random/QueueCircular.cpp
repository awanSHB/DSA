#include <bits/stdc++.h>
using namespace std;

class CirQueue{
	private:
		int A[6];
		int front;
		int rear;
		int count;
	public:
		CirQueue(){
			count = 0;
			front = 0;
			rear = 0;
		}
		
		bool isEmpty(){
			return (front==rear);
		}
		
		bool isFull(){
			return ((rear+1)%6==front);
		}
		
	void enqueu(int v){
		if(!isFull()){
			A[rear] = v;
			rear++;
			count++;
//		rear = (rear==6) ? 0:rear;
			if(rear==6)
				rear = 0;
		}
	}
	
	int getFront(){
		return (!isEmpty())? A[front] : -1;
//		if(!isEmpty())
//			return A[front];
//		else
//			return -1;
	}
	
	void dequeue(){
		front++;
		count--;
		
		front %= 6;
		
//		if(front==6)
//			front = 0;
		
//		front = (front==6)? 0: front;
	}
	
	void display(){
		cout<<"\n\n\n\t\t\t\t| ";
		for(int i=front; i<=rear; i++)
			cout<<A[i]<<" | ";
	}
};

int main(){
	CirQueue cQ;
	int val;
	
	for(int c=0; c<6; c++){
		cout<<"Enter the value no "<<(c+1)<<" : ";
		cin>>val;
		cQ.enqueu(val);
	}
	cout<<"\n\nThe Front value is : "<<cQ.getFront()<<endl;
	cQ.display();
	
	cQ.dequeue();
	cout<<"\n\nThe Front value is : "<<cQ.getFront();
	cQ.display();
}