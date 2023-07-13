#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void insert(Node **head, int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(*head==NULL){
		*head = n;
		return;
	}
	Node *l = *head;
	while(l->next!=NULL)
		l = l->next;
	l->next = n;
}

int removeHead(Node **head){
	Node *h = *head;
	*head = (*head)->next;
	int k = h->data;
	delete h;
	return k;
}

class Queue{
	private:
		struct Node *head;
	public:	
		Queue(){
			head = NULL;
		}
		
	bool isEmpty(){
		return head==NULL;
	}
	
	void enqueue(int v){
		insert(&head, v);
	}
	int dequeue(){
		cout<<"\n\n-------------> ";
		return removeHead(&head);
	}
	
	void display(){
		cout<<"\n\n\t\t\t[ ";
		for(Node *k = head; k!=NULL; k = k->next)
			cout<<k->data<<" | ";
		cout<<"\b\b]";
	}
};

void insertHead(Node **head, int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(*head==NULL){
		*head = n;
		return;
	}
	n->next = *head;
	*head = n;
}

void insertLast(Node **head, int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(*head == NULL){
		*head = n;
		return;
	}
	Node *k;
	for(k = *head; k->next!=NULL; k = k->next){}
	k->next = n;
}

int removeLast(Node **head){
	if(*head==NULL)
		return -1;
	Node *k;
	for(k = *head; k->next->next!=NULL; k = k->next){}
	Node *temp = k->next;
	k->next = NULL;
	int r = temp->data;
	delete temp;
	return r;
}


class Deque{
	private:
		struct Node *head;
	public:
		Deque(){
			head = NULL;
		}
	bool isEmpty(){
		return head==NULL;
	}
	
	void pushFront(int v){
		insertHead(&head, v);
	}
	void pushBack(int v){
		insertLast(&head, v);
	}
	
	int getFront(){
		cout<<"\n\n";
		return removeHead(&head);
	}
	int getLast(){
		cout<<"\n\n";
		return removeLast(&head);
	}
	
	void display(){
		cout<<"\n\n\t\t\t[ ";
		for(Node *k= head; k!=NULL; k = k->next)
			cout<<k->data<<" | ";
		cout<<"\b\b]";
	}
};

int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.display();
	
	cout<<q.dequeue()<<endl;
	q.display();
	
	
	cout<<"\n\n\n\n---------------------------------------------------------------------\n\n";
	Deque dq;
	dq.pushBack(40);
	dq.pushBack(50);
	dq.pushBack(60);
	dq.pushFront(30);
	dq.pushFront(20);
	dq.pushFront(10);
	dq.display();
	
	cout<<dq.getFront()<<endl;
	cout<<dq.getLast()<<endl;
	dq.display();
}











