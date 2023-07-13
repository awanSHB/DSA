#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int v){
			data = v;
			next = NULL;
		}
};

class Queue{
	private:
		int rear;
		int size;
		int *A;
	public:
		Queue(){
			rear = 0;
			size = 30;
			A = new int[size];
		}
		Queue(int s){
			rear = 0;
			size = s;
			A = new int[size];
		}
	bool isEmpty(){
		return rear==0;
	}
	bool isFull(){
		return rear==size;
	}
	
	void enque(int v){
		if(!isFull())
			A[rear++] = v;
	}
	
	int getFront(){
		if(!isEmpty())
			return A[0];
		else
			return -1;
	}
	
	void deque(){
		for(int i = 0; i<rear; i++){
			A[i] = A[i+1];
		}
		rear--;
	}
	
	void combine(Queue q1, Queue q2, Queue q3){
		rear = 0;
		while(!q1.isEmpty()){
			enque(q1.getFront());
			q1.deque();
		}
		while(!q2.isEmpty()){
			enque(q2.getFront());
			q2.deque();
		}
		while(!q3.isEmpty()){
			enque(q3.getFront());
			q3.deque();
		}
		OrderArrange();
	}
	
	void OrderArrange(){
		for(int i=0; i<rear; i++){
			for(int j=i+1; j<rear; j++){
				if(A[i] > A[j]){
					int s = A[j];
					A[j] = A[i];
					A[i] = s;
				}
			}
		}
	}
	
	
	void display(){
		cout<<"\n\t| ";
		for(int i=0; i<rear; i++){
			cout<<A[i]<< " | ";
		}
	}
	
		
};

class Bag{
	private:
		Node *head;
	public:
		Bag(){
			head = NULL;
		}
	
	void show(){
		Node *n = head;
		cout<<"\t";
		while(n!=NULL){
			cout<<n->data<<" --> ";
			n = n->next;
		}
		cout<<"NULL";
	}
	
	void put(int v){
		Node *n = new Node(v);
		Node *l = head;
		if(head==NULL)
		{
			head = n;
			return;
		}
		while(l->next!=NULL)
			l = l->next;
		l->next = n;
	}
	
	void get(int v){
		Node *a = head;
		int b = 1;
		while(a!=NULL){
			if(a->data==v){
				cout<<"\n\n\tYour Val:- "<<a->data<<" Is Present At:- "<<b<<"TH node"<<endl;
				return;
			}
			a = a->next;
			b++;
		}
		cout<<"\tThe Val :- "<<v<<" Is Not Present"<<endl;
	}
	
};

int main(){
	Queue q1(4);
	Queue q2(8);
	Queue q3(7);
	Queue q;
	
	int A1[4] = {9, 15, 21, 25};
	int A2[8] = {2, 4, 6, 8, 10, 12, 14, 16};
	int A3[7] = {1, 3, 5, 7, 11, 13, 17};
	
	for(int i=0; i<4; i++){
		q1.enque(A1[i]);
	}
	for(int i=0; i<8; i++){
		q2.enque(A2[i]);
	}
	for(int i=0; i<7; i++){
		q3.enque(A3[i]);
	}
	
	cout<<"\tDiplaying Queue 1:";
	q1.display();
	cout<<"\n\n\tDiplaying Queue 2:";
	q2.display();
	cout<<"\n\n\tDiplaying Queue 3:";
	q3.display();
	
	cout<<"\n\n\n\tDisplaying Combined Queues In Ascending Order:";
	q.combine(q1, q2, q3);
	q.display();
	cout<<"\n\n\n\n\n";
	
	Bag b;
	int I[10] = {12, 14, 22, 24, 32, 34, 42, 44, 52, 54};
	for(int i=0; i<10; i++)
		b.put(I[i]);
	b.show();
	b.get(34);
	b.get(53);
}