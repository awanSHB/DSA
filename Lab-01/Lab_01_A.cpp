#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL;

void display(){
	Node *l = head;
	cout<<"\nhead\n |\n";
	while(l!=NULL){
		cout<<"["<<l->data<<"] --> ";
		l = l->next;
	}
	cout<<"NULL\n\n\n\n";
}

void end(int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(head==NULL){
		head = n;
		return;
	}
	
	Node *t = head;
	while(t->next!=NULL)
		t = t->next;
	t->next = n;
	
}

void start(int v){
	Node *n = new Node;
	n->data = v;
	n->next = head;
	head = n;
	
}

void after(int k, int v){
	if(head==NULL){
		cout<<"\n\nLinked List is Empty!!!";
		return;
	}
	Node *t = head;
	while(t!=NULL){
		if(t->data==k){
			Node *n = new Node;
			n->data = v;
			n->next = t->next;
			t->next = n;
			return;
		}
		t = t->next;
	}
	cout<<"\n\nKey: "<<k<<" Not Found!!!!\n";
}

void removeFirst(){
	Node *t = head;
	head = head->next;
	delete t;
}

void removeLast(){
	Node *t = head;
	Node *p;
	while(t->next!=NULL){
		p = t;
		t = t->next;
	}
	p->next = t->next;
	delete t;
}

void remove(int k){
	Node *t = head;
	Node *p;
	if(head==NULL){
		cout<<"\nLinked List is Empty!!!\n";
		return;
	}
	while(t!=NULL){
		if(t->data==k){
			p->next = t->next;
			delete t;
			return;
		}
		p = t;
		t = t->next;
	}
	cout<<"The Node: "<<k<<" Not Found!!!\n";
}

void removeList(){
	Node *t;
	while(head!=NULL){
		t = head;
		head = head->next;
		delete t;
	}
	cout<<"\n!!!!!!!!!!The List Deleted!!!!!!!!!\n";
}

int main(){
	cout<<"Inserting At End: \n";
	end(30);
	end(40);
	end(50);
	display();
	
	cout<<"Inserting At Start: \n";
	start(20);
	start(10);
	display();
	
	cout<<"Inserting After Value: \n";
	after(20, 200);
	after(50, 500);
	display();
	
	cout<<"Inserting After Value: \n";
	after(100, 700);
	display();
	
	cout<<"Removing Head: \n";
	removeFirst();
	display();
	
	cout<<"Removing Last Node: \n";
	removeLast();
	display();
	
	cout<<"Removing Specific Node: \n";
	remove(40);
	display();
	
	remove(100);
	
	removeList();
	display();
}