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

void removeEven(){
	if(head==NULL)
		return;
		
	Node* l = head;
	while(l->next==head)
		l = l->next;
	Node *t = head;
	while(t->next!=head){
		if(head->data%2==0){
			head = head->next;
			l->next = head;
			t = head;
		}else if(t->next->data%2==0)
			t->next = t->next->next;
		else
			t = t->next;
	}
}

void removeOdd(){
	if(head==NULL)
		return;
		
	Node* l = head;
	while(l->next!=head)
		l = l->next;
	Node *t = head;
	while(t->next!=head){
		if(head->data%2!=0){
			head = head->next;
			l->next = head;
			t = head;
		}else if(t->next->data%2!=0)
			t->next = t->next->next;
		else
			t = t->next;
	}
}

void josephus(int k){
	int m;
	Node *l = head;
	
	while(head->next!=head){
		m = 1;
		while(m<k-1){
			l = l->next;
			m++;
		}
		if(l->next==head){
			head = head->next;
			l->next = head;
		}else
			l->next = l->next->next;
	}
	cout<<"\nThe last survivor is : "<<head->data<<endl;
}

void removeEvenPositioned(){
	int k = 1;
	Node *l = head;
	Node *p = NULL;
	
	while(l->next!=head){
		if(k%2==0){
			p->next = l->next;
		}
		p = l;
		l = l->next;
		k++;
	}
	if(k%2==0){
		p->next = l->next;
	}
}

int main(){
	end(10);
	end(11);
	end(12);
	end(13);
	end(14);
	end(15);
	end(16);
	end(17);
	end(18);
	end(19);
	end(20);
	display();
	
	removeEven();
	display();
	
	end(22);
	end(24);
	end(26);
	end(28);
	end(29);
	end(30);
	
	display();
	
	removeOdd();
	display();
	
	josephus(3);
	
	end(10);
	end(11);
	end(12);
	end(13);
	end(14);
	end(15);
	end(16);
	end(17);
	end(18);
	end(19);
	end(20);
	display();
	removeEvenPositioned();
	display();
	
}