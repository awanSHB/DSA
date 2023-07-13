#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class CirQue{
	private:
		int front;
		int rear;
		int array_size;
		int count;
		T *A;
	public:
		CirQue(){
			array_size = 5;
			A = new T[array_size];
			count = 0;
			front = 0;
			rear = 0;
		}
		
		CirQue(int s){
			array_size = s;
			A = new T[array_size];
			count = 0;
			front = 0;
			rear = 0;
		}
		
		bool isEmpty(){
			return (count==0);
		}
		
		int next(int r){
			return ((r+1)%array_size);
		}
		
		bool isFull(){
//			return ((rear+1)%array_size==front);
//			return (rear==array_size-1 && front==0);
//			return (count==array_size);
//            cout<<"front--"<<front<<" rear--"<<rear;
//			if (next(rear)==front)
//				return true;
//			else
//				return false;
			return (count==array_size);
		}
	
	void enqueue(T v){
		if(!isFull()){
			A[rear++] = v;
//			rear %= array_size;
			count++;
			if(rear==array_size)
				rear = 0;
		}
	}
	
	T getFront(){
		return (!isEmpty())? A[front]:-1;
	}
	
	void dequeue(){
		front++;
		count--;
		front = (front==array_size)? 0: front;
//		front %=array_size;
	}
	
	void display(){
		cout<<"\n\n\t\t\t\t ";
		int a = front;
		for(int i=0; i<count; i++){
			cout<<A[a++]<<" | ";
//			a%=array_size;//means if(a==array_size) then return 0 else return its current value
		}				 //which will be incremented by each iteration of the loop
	}
};

int main(){
	CirQue <int> q1;		//Declaring int object and calling default constructor
	CirQue <char> q2(15);	//Delaring char object and calling userdefined constructor
	CirQue <string> q3(3);	//Declaring string object and calling userdefined constructor
	
	q1.enqueue(10);
	q1.enqueue(11);
	q1.enqueue(12);
	q1.enqueue(13);
	q1.enqueue(14);
//	q1.enqueue(15);
	
	q1.display();
	
	string st = "hello world";
	for(int i=0; i<st.length(); i++)
		q2.enqueue(st[i]);
	q2.display();
	
	q3.enqueue("I");
	q3.enqueue("Love");
	q3.enqueue("Coding");
	q3.display();
	
	
	
}