#include<iostream>
using namespace std;

struct Dnode{
	int data;
	Dnode *next;
	Dnode *prev;
};

Dnode *head = NULL;
Dnode *tail = NULL;

void display(){
	Dnode *l = head;
	cout<<"head\n |\n";
	while(l!=NULL){
		cout<<"["<<l->data<<"] <===> ";
		l = l->next;
	}
	cout<<"\b\b\b\b\b\b---> Tail\n\n\n";
}

void end(int v){
	Dnode *n = new Dnode;
	n->data = v;
	n->next = NULL;
	n->prev = NULL;
	if(head==NULL && tail==NULL){
		head = n;
		tail = n;
		return;
	}
	
	Dnode *l = head;
	while(l->next!=NULL)
		l = l->next;
	l->next = n;
	n->prev = tail;
	tail = n;
}

void remove(int v){
	Dnode *l = head;
	if(head->data==v){
		head = head->next;
		delete l;
	}else if(tail->data==v){
		Dnode *t = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete t;
	}else{
		while(l->next->data!=v){
			l = l->next;
		}
		l->next->next->prev = l->next->prev;
		l->next = l->next->next;
	}
}

void removeAll(){
	while(head!=NULL){
		Dnode *l = head;
		head = head->next;
		delete l;
	}
}

int main(){
	end(10);
	end(20);
	end(30);
	end(40);
	end(50);
	display();
	
	remove(10);
	display();
	
	remove(50);
	display();
}