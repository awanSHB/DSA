#include <bits/stdc++.h>
using namespace std;

class DNode{
	public:
	int data;
	DNode *next;
	DNode *prior;
	DNode(){
		data = 0;
		next = prior = NULL;
	}
	DNode(int v){
		data = v;
		next = prior = NULL;
	}
};

class LinkedList{
	public:
		DNode *head;
		DNode *prior;
	public:
		LinkedList(){
			head = NULL;
			prior = NULL;
		}
	void display(){
		DNode *n = head;
		cout<< "NULL<-- ";
		while(n!=NULL){
			cout << "[" << n->data <<"]" << " <==> ";
			n = n->next;
		}
		cout << "\b\b\b\b\b-->NULL";  
	}
	
	void start(int v){
		DNode *n = new DNode(v);
		if(head==NULL){
			head = n;
			return;
		}
		n->next = head;
		head->prior = n;
		head = n;
	}
	
	void end(int v){
		DNode *n = new DNode(v);
		if(head==NULL){
			head = n;
			return;
		}
		DNode *l = head;
		while(l->next!=NULL)
			l = l->next;
		l->next = n;
		n->prior = l;
	}
	
	void after(int k, int v){
		DNode *n = new DNode(v);
		if(head==NULL)
			return;
		DNode *l = head;
		while(l!=NULL && l->data!=k){
			l = l->next;
		}
		n->prior = l;
		n->next = l->next;
		n->next->prior = n;
		l->next = n;
	}
	
	void before(int k, int v){
		DNode *n = new DNode(v);
		if(head==NULL)
			return;
		DNode *l = head;
		while(l->data!=k){
			l=l->next;
		}
		l->prior->next = n;
		n->prior = l;
		n->next = l;
		l->prior = n;
	}
};


int main(){
	LinkedList ll;
	
	cout << "Inserting value at start:"<<"\n\n";
	ll.start(1);
	ll.start(2);
	ll.start(3);
	ll.display();
	cout << "\n\n\n\n";
	
	cout << "Inserting value at end:"<<"\n\n";
	ll.end(7);
	ll.end(8);
	ll.end(9);
	ll.display();
	cout << "\n\n\n\n";
	
	cout << "Inserting after value:"<<"\n\n";
	ll.after(3, 5);
	ll.after(7, 10);
	ll.display();
	cout << "\n\n\n\n";
	
	cout << "Inserting before value:"<<"\n\n";
	ll.before(7, 6);
	ll.before(5, 4);
	ll.display();
}