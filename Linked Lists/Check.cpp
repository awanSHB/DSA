#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct Node *head = NULL;

void display(){
	Node *n = head;
	cout<<"\n\nhead\n |\n |\n";
	while(n!=NULL){
		cout<<"["<<n->data<<"] ---> ";
		n = n->next;
	}
	cout<<"NULL\n";
}

void End(int data){
	Node *l = head;
	Node *n = new Node;
	n->data = data;
	n->next = NULL;
	
	if(head==NULL){
		head = n;
		return;
	}
	
	while(l->next!=NULL)
		l = l->next;
		
	l->next = n;
	return;
	
}

int main(){
	struct Node *a = head;
	End(1);
	End(2);
	End(3);
	End(4);
	
	display();
	
}