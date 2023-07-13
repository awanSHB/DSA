#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct Node *head = NULL;

void display(){
	if(head==NULL){
		cout<<"\n!!!!!!Linked List is Empty!!!!!!\n";
		return;
	}
	cout<<"\nhead\n |\n";
	Node *l = head;
	do{
		cout<<"["<<l->data<<" ] --> ";
		l = l->next;
	}while(l!=head);
	cout<<"\b\b-------> ["<<head->data<<"]\n\n\n";
}

void end(int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(head==NULL){
		head = n;
		n->next = head;
	}else{
		Node *t = head;
		do{
			t = t->next;
		}while(t->next!=head);
		
		t->next = n;
		n->next = head;
	}
}

void index(int v){
	int count = 1;
	Node *k = head;
	while(k->next!=head){
		if(k->data==v){
			cout<<"\n\nThe Index  Of "<< v <<" is : "<<count<<"\n";
			return;
		}
		k = k->next;
		count++;
	}
	cout<<"\nThe Value "<< v << " Doesn't Exists\n";
}


void remove(int v){
	if(head==NULL)
		return;
	Node *t = head;
	if(head->data==v){
		do{
			t = t->next;
		}while(t->next!=head);
		Node *k = head->next;
		t->next = head->next;
		head = k;
	}else{
		while(t->next->data!=v && t->next!=head)
			t = t->next;
		if(t->next==head){
			cout<<"\nThe Given Values Doesn't Exists\n";
			return;
		}
		t->next = t->next->next;
	}
}

void removeAll(){
	if(head==NULL)
		return;
	Node *k = head;
	do{
		Node *t = k;
		k = k->next;
		delete t;
	}while(k!=head);
	head = NULL;
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
	end(90);
	display();
	
	index(40);
	index(10);
	index(800);
	
	remove(50);
	display();
	remove(10);
	display();
	remove(90);
	display();
	
	removeAll();
	display();
}
