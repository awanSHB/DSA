#include<iostream>
using namespace std;


template <class T>
class Node{
	public:
		T data;
		Node *next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(T v){
			data = v;
			next = NULL;
		}
};


template <class T>
class LinkedList{
	public:
		Node<T> *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void display(){
			Node<T> *ll = head;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
		
		void show(Node<T> *n){
			if(n==NULL)
				return;
			cout<<"  "<<n->data;
			show(n->next);
		}
		
		void add(T v){
			Node<T> *n = new Node<T>(v);
			if(head==NULL){
				head = n;
				return;
			}
			Node<T> *d = head;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void joinRemove(LinkedList <T> la, LinkedList <int> lb){
			
			if(la.head == NULL || lb.head == NULL){
        		return;
    		}
			Node<T> *l1 = la.head;
			Node<int> *l2 = lb.head;
			Node<T> *prev = NULL;
			int track = 1;
			
			while(l1!=NULL && l2!=NULL){
				
				if(track==l2->data){
					Node<T> *rand = l1;
					prev->next = l1->next;
					l1=l1->next;
					delete rand;
					l2=l2->next;
					track+=1;
				}else{
					prev = l1;
					l1 = l1->next;
					track++;
				}
			}
			
			if(l2!=NULL)
				cout<<"The index "<< l2->data <<" does not exists in l1";
			
		}
};

int main(){
	LinkedList <char> l1;
	LinkedList <int> l2;
	
	l1.add('A');
	l1.add('B');
	l1.add('C');
	l1.add('D');
	l1.add('E');
	
	l1.display();

	l2.add(2);
	l2.add(4);
	l2.add(8);
	
	l2.display();
	
	l1.joinRemove(l1, l2);
	
	l1.display();
}



/*
class Nodet{
	public:
		int data;
		Nodet *next;
		
		Nodet(){
			data = 0;
			next = NULL;
		}
		
		Nodet(int v){
			data = v;
			next = NULL;
		}
};

class Nodec{
	public:
		char data;
		Nodec *next;
		
		Nodec(){
			data = 0;
			next = NULL;
		}
		
		Nodec(char v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	public:
		Nodet *headt;
		Nodec *headc;
	public:
		LinkedList(){
			headt=NULL;
			headc=NULL;
		}
		
		void displayt(){
			Nodet *ll = headt;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
		
		void displayc(){
			Nodec *ll = headc;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
	
		void addt(int v){
			Nodet *n = new Nodet(v);
			if(headt==NULL){
				headt = n;
				return;
			}
			Nodet *d = headt;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void addc(int v){
			Nodec *n = new Nodec(v);
			if(headc==NULL){
				headc = n;
				return;
			}
			Nodec *d = headc;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void joinRemove(LinkedList la, LinkedList lb){
			
			if(la.headc == NULL || lb.headt == NULL){
        		return;
    		}
			Nodec *l1 = la.headc;
			Nodet *l2 = lb.headt;
			Nodec *prev;
			Nodec *rand;
			int track = 1;
			
			while(l1!=NULL && l2!=NULL){
				if(track==l2->data){
					Nodec *rand = l1;
					prev->next = l1->next;
					l1 = l1->next;
					delete rand;
					l2 = l2->next;
					track++;
				}else{
					prev = l1;
					l1 = l1->next;
					track++;
				}
			}
			
			while(l2!=NULL){
				cout<<"The index "<<l2->data<<" Does not exists in LinkedList 1\n";
				l2 = l2->next;
			}
		}
	
};

int main(){
	LinkedList l1;
	LinkedList l2;
	
	l1.addc('A');
	l1.addc('B');
	l1.addc('C');
	l1.addc('D');
	l1.addc('E');
	
	l1.displayc();
	
	l2.addt(2);
	l2.addt(4);
	l2.addt(8);
	
	l2.displayt();
	
	l1.joinRemove(l1, l2);
	l1.displayc();
}

*/