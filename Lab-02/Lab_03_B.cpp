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

void start(int v){
	Dnode *n = new Dnode;
	n->data = v;
	if(head==NULL && tail==NULL){
		n->next = NULL;
		n->prev = NULL;
		head = n;
		tail = n;
		return;
	}
	n->next = head;
	head->prev = n;
	head = n;
}

void swap(int v1, int v2){
	if(head==NULL || tail==NULL)
		return;
	Dnode *a = head;
	Dnode *b = head;
	
	while(a->next->data!=v1)
		a = a -> next;
	while(b->next->data!=v2)
		b = b -> next;
	
	Dnode *n1 = a->next;			//Storing the required node in another node
	Dnode *n2 = b->next;			//Storing the required node in another node
	
	//Here we are breaking the first node link (removing node)
	a->next->next->prev = a->next->prev;
	a->next = a->next->next;
	
	//Here we are breaking the second node link (removing node)
	b->next->next->prev = b->next->prev;
	b->next = b->next->next;
	
	
	n2->prev = a->next->prev;
	a->next->prev = n2;
	n2->next = a->next;
	a->next = n2;

	n1->prev = b->next->prev;
	b->next->prev = n1;
	n1->next = b->next;
	b->next = n1;
}

void traverse(){
	
	Dnode *p = NULL;
	Dnode *f = head;
	Dnode *t = head;
	
	while(t->next!=NULL){
		f = f->next;
		if(p==NULL){
			t->next = p;
		}else{
			t->next = p;
			t->prev = NULL;
		}
		p = t;
		t = f;
	}
	t->next = p;
	p->prev = t;
	head = t;
}

struct Node{
	int dat;
	Node *next;
};
Node *headsl = NULL;

void insert(int v){
	Node *n = new Node;
	n->dat  = v;
	n->next = NULL;
	if(headsl==NULL){
		headsl = n;
		return;
	}
	Node *l = headsl;
	while(l->next!=NULL)
		l = l->next;
	l->next = n;
}

void show(){
	cout<<"\n\n";
	Node *n = headsl;
	while(n!=NULL){
		cout<<"["<<n->dat<<"] --> ";
		n = n->next;
	}
	cout<<"NULL\n\n";
}

void convertTodouble(){
	Node *l = headsl;
	while(l!=NULL){
		end(l->dat);
		l = l->next;
	}
	display();
}

int main(){
	//Converting a single linkedlist into a double linkedlist
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	show();
	convertTodouble();
	
	//Inserting at end of double linkedlist
	end(10);
	end(20);
	end(30);
	end(40);
	end(50);
	end(60);
	end(70);
	end(80);
	display();
	
	traverse();
	display();
	
	swap(30, 70);
	display();
	
	traverse();
	display();

}