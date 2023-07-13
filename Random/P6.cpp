#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

void begin(Node *&head, int v){
	Node *n = new Node(v);
//	n->data = v;
	n->next = head;
	head = n;
}

void mid(int prev, int val){
	if (prev==NULL){
		cout<<"Cannot assign";
		return
	}
	Node *n = new Node(int p, int v);
	n->data = v;
	node *l = *head;
	while(l!=p){
		l = l->next;
	}
	n->next = l->next;
	l->next = n;
}

void last(int v){
	Node *n = new Node(int v);
	Node *l = *head;
	while(l!=NULL){
		l = l->next;
	}
	
	n->data = v;
	n->next = NULL;
	l->next = n;
}

void printlist(){
	Node *s = *head;
	while (s!=NULL){
		cout << s->data<<" ";
		s = s->next;
	}
}

int main(){
	last(5);
	last(10);
	last(20);
	begin(1);
	mid(10, 15);
}
