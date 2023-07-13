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

void show(Node **hd){
	Node *n = *hd;
	while(n!=NULL){
		cout<<"["<<n->data<<"] --> ";
		n = n->next;
	}
	cout<<"NULL\n\n";
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

void traverse(Node *n, Node **head2){
	Node *p = NULL;
	Node *c = *head2;
	Node *t = *head2;
	
	while(c!=NULL){
		t = t->next;
		c->next = p;
		p = c;
		c = t;
	}
	*head2 = p;
	n->next = *head2;
	display();
}

void reverseMiddle(){
	int count = 0;
	int mid = 0;
	int i = 1;
	
	Node *A = head;
	Node *T = head;
	
	while(A!=NULL){
		count++;
		A=A->next;
	}
	mid = count/2;
	
	while(i<mid){
		i++;
		T = T->next;
	}
	struct Node *head2 = T->next;
	show(&head2);
	T->next = NULL;
	traverse(T, &head2);
}

int main(){
	end(10);
	end(20);
	end(30);
	end(40);
	end(50);
	end(60);
	end(70);
	end(80);
	display();
	reverseMiddle();
}

