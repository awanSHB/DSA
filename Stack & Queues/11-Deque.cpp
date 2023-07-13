#include<iostream>
using namespace std;

struct Deque{
	int front;
	int rear;
	int *A;
	int count;
	
	Deque(){
		front = rear = count = 0;
		A = new int[10];
	}
	
	bool isEmpty(){
		return count==0;
	}
	bool isFull(){
		return count==10;
	}
	
	void push_front(int v){
		if(!isFull()){
			A[front--] = v;
			count++;
		}else
			cout<<"\n!Full! Cannot Insert "<<v<<"\n";
	}
	void push_back(int v){
		if(!isFull()){
			A[++rear] = v;
			count++;
		}else
			cout<<"\n!!!Full!!! Cannot Insert "<<v<<"\n";
	}
	
	void pop_front(){
		cout<<"\npop_front\n";
		if(!isEmpty()){
			front+=1;
			count--;
		}
	}
	void pop_back(){
		cout<<"\npop_back\n";
		if(!isEmpty()){
			rear-=1;
			count--;
		}
	}
	
	void display(){
		cout<<"\n\n";
		for(int i=front+1; i<=rear; i++){
			cout<<"["<<A[i]<<"] ";
		}
	}
};

int main(){
	Deque d;
	d.push_back(40);
	d.push_back(50);
	d.push_back(60);
	d.push_front(30);
	d.push_front(20);
	d.push_front(10);
	d.push_back(70);
	d.push_back(80);
	d.push_front(8);
	d.push_front(5);
	d.push_front(1);
	d.display();
	
	d.pop_back();
	d.display();
	
	d.pop_front();
	d.display();
}

/*
class Deque{
	public:
	int front;
	int rear;
	int *A;
	int count;
	
	Deque(){
		front = 0;
		rear = 0;
		A = new int[10];
		count = 0;
	}
	
	bool isEmpty(){
		return count==0;
	}
	
	bool isFull(){
		return count==10;
	}
	
	void push_front(int v){
		if(!isFull()){
			A[front] = v;
			front--;
			count++;
		}else
			cout<<"\n\nQueue is Full!!!!\n\n";
	}
	void push_back(int v){
		if(!isFull()){
			A[++rear] = v;
			count++;
		}else
			cout<<"\n\nQueue is Full!!!!\n\n";
	}
	
	void pop_front(){
		cout<<"\npop_front";
		if(!isEmpty()){
			front++;
			count--;
		}
	}
	void pop_back(){
		cout<<"\npop_back\n";
		if(!isEmpty()){
			rear--;
			count--;
		}
	}
	
	void display(){
		cout<<"\n\n\n";
		for(int k = front+1; k <= rear; k++)
			cout<<"["<<A[k]<<"] ";
	}
};

int main(){
	Deque dq;
	dq.push_back(40);
	dq.push_back(50);
	dq.push_front(30);
	dq.push_front(20);
	dq.push_front(10);
	dq.push_front(11);
	dq.push_back(60);
	dq.push_front(100);
	dq.push_back(70);
	dq.push_back(80);
	dq.push_back(90);
	dq.push_front(111);
	dq.display();
	
	dq.pop_front();
	dq.display();
	
	dq.push_back(120);
	dq.display();
	
	dq.pop_back();
	dq.display();
	
	dq.pop_back();
	dq.display();
}
*/