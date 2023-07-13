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

void traverse(Node **head2){
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
}

void reversePositions(int p1, int p2){
	if(head==NULL)
		return;
	Node *C = head;
	int check = 1;
	while(C!=NULL){
		check++;
		C = C->next;
	}
	if(check<p2)
		return;
		
	int a = 1;
	Node *A = head;
	
	while(a<p1-1){
		a++;
		A = A->next;
	}
	
	int b = a;
	Node *B = A;
	
	while(b<=p2){
		b++;
		B = B->next;
	}
	
	struct Node *head2 = A->next;
	Node *R1 = head2;
	while(R1->next!=B)
		R1 = R1->next;
	R1->next = NULL;
	A->next = B;
	
	traverse(&head2);
	
	Node *R2 = head2;
	A->next = R2;
	while(R2->next!=NULL)
		R2 = R2->next;
	R2->next = B;
	display();
}

int main(){
	end(10);
	end(20);
	end(30);
	end(40);
	end(50);
	end(60);
	end(70);
	display();
	
	reversePositions(3,5);
}