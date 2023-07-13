#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void display(Node *n){
	cout<<"\n\nhead\n |\n |\n";
	while(n!=NULL){
		cout<<"["<<n->data<<"] ---> ";
		n = n->next;
	}
	cout<<"NULL\n";
}

void start(Node **head, int data){
	Node *n = new Node;
	n->data = data;
	n->next = *head;
	*head = n;
}

void after(Node *prev , int d){
	if(prev==NULL){
		cout<<"\nThe prev node cannot be NULL\n";
		return;
	}
	
	Node *n = new Node;
	n->data = d;
	n->next = prev->next;
	prev->next = n;
}

void before(Node**head, Node *nxt, int d){
	Node *l = *head;
	Node *p = NULL;
	
	Node *n = new Node;
	n->data = d;
	
	if(nxt==*head){
		n->next = nxt;
		*head = n;
		return;
	}
	while(l->data!=nxt->data){
		p = l;
		l = l->next;
	}
	p->next = n;
	n->next = l;
}

void End(Node **head, int data){
	Node *l = *head;
	Node *n = new Node;
	n->data = data;
	n->next = NULL;
	
	if(*head==NULL){
		*head = n;
		return;
	}
	
	while(l->next!=NULL)
		l = l->next;
		
	l->next = n;
	return;
	
}

void remove(Node **head, int data){
	Node *l = *head;
	Node *p = NULL;
	
	if(l->data==data){
		Node *t = *head;
		*head = (*head)->next;
		delete t;
		return;
	}
	
	if(l->data==data){
		Node *t = *head;
		*head = (*head)->next;
		delete t;
		return;
	}
	
	while(l->data!=data){
		p = l;
		l = l->next;
	}
	Node *t = l;
	p->next = l->next;
	delete t;
}


int main(){
	Node *head = NULL;
	
	End(&head, 40);
	End(&head, 50);
	End(&head, 60);
	End(&head, 70);
	
	cout<<"\nInserting At End:";
	display(head);
	
	start(&head,30);
	start(&head,20);
	start(&head,10);
	
	cout<<"\n\nInserting At Start:";
	display(head);
	
	
	after(head, 100);
	after(head->next->next->next, 300);
	cout<<"\n\nInserting At After:";
	display(head);
	
	before(&head, head->next->next, 200);
	before(&head, head, 90);
	
	cout<<"\n\nInserting At Before:";
	display(head);
	
	remove(&head, 300);
	
	remove(&head, 90);
	
	cout<<"\n\nRemoving:";
	display(head);
}
