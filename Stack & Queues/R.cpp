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
			cout<<"\nFull!!!\n";
	}
	void push_back(int v){
		if(!isFull()){
			A[++rear] = v;
			count++;
		}else
			cout<<"\nFull!!!\n";
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
	d.display();
	
	d.pop_back();
	d.display();
	
	d.pop_front();
	d.display();
}