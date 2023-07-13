#include<iostream>
using namespace std;

//This is a variable front dynamic(doubly LL) Priority Queue
//This is also a double ended queue

struct Node{
	int data;
	int priority;
	Node *next;
	Node *prev;
};

Node *front = NULL;
Node *rear = NULL;

void insert(int d, int p){
	Node *n = new Node;
	n->data = d;
	n->priority = p;
	n->next = NULL;
	n->prev = NULL;
	
	if(front==NULL && rear==NULL){
		front = n;
		rear = n;
	}
	else if(n->priority < front->priority){
		n->next = front;
		front->prev = n;
		front = n;
	}
	else if(n->priority > rear->priority){
		rear->next = n;
		n->prev = rear;
		rear = n;
	}else{
		Node *l = rear;
		while(l->priority > n->priority)
			l = l->prev;
		n->prev = l->next->prev;
		l->next->prev = n;
		n->next = l->next;
		l->next = n;
	}
}

void removeFront(){
	Node *r = front;
	front = front->next;
	front->prev = NULL;
	delete r;
}

void removeRear(){
	Node *r = rear;
	rear = rear->prev;
	rear->next = NULL;
	delete r;
}

int getFront(){
	return front->data;
}

int getRear(){
	return rear->data;
}

void displayD(){
	cout<<"\n\n";
	Node *s = front;
	while(s->next!=NULL){
		cout<<"["<<s->data<<"] <==> ";
		s = s->next;
	}
	cout<<"["<<s->data<<"] --> NULL";
	s = s->next;
}

void displayP(){
	cout<<"\n ";
	Node *s = front;
	while(s->next!=NULL){
		cout<<s->priority<<"         ";
		s = s->next;
	}
	cout<<" "<<s->priority;
	s = s->next;
	cout<<"\n\n";
}

struct Queue{
	
	bool isEmpty(){
		return (front==NULL && rear==NULL);
	}
	
	void enque(int d, int p){
		insert(d, p);
	}
	
	void dequeF(){
		if(!isEmpty())
			removeFront();
	}
	void dequeR(){
		if(!isEmpty())
			removeRear();
	}
	
	int showF(){
		cout<<"\n\nThe Front Element is : ";
		return getFront();
	}
	int showR(){
		cout<<"\n\nThe Rear Element is  : ";
		return getRear();
	}
	
	void show(){
		displayD();
		displayP();
	}
};

int main(){
	Queue q;
	q.enque(10, 4);
	q.enque(20, 2);
	q.enque(40, 1);
	q.enque(60, 6);
	q.enque(50, 5);
	q.enque(30, 3);
	q.enque(15, 0);
	q.enque(80, 8);
	
	q.show();
	
	q.dequeF();
	q.show();
	
	q.dequeR();
	q.show();
	
	cout<<q.showF();
	cout<<q.showR()<<endl;
	
	q.enque(70, 7);
	q.enque(100, 10);
	
	q.show();
	
	cout<<q.showF();
	cout<<q.showR();
}