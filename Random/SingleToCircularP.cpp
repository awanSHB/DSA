#include <bits/stdc++.h>
using namespace std;

class Cnode{
	public:
		int data;
		Cnode *next;
		Cnode(){
			data = 0;
			next = NULL;
		}
		Cnode(int v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	public:
		Cnode *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		//Method for displaying
		void display(){
			Cnode *n = head;
			int a = n->data;
			cout<<"head"<<endl;
			cout<<" |"<<endl;
			do{
				cout<<"["<<n->data<<"]"<<" --> ";
				n = n->next;
			}while(n!=head);
			cout<<"\b\b\b------>["<<a<<"]";
		}
		
		//method for inserting at start
		void start(int v){
			Cnode *n = new Cnode(v);
			if(head==NULL){
				head = n;
				n->next = head;
				return;
			}	
			Cnode *l = head;
			n->next = head;
			head = n;
			while(l->next!=n->next)
				l = l->next;
			l->next = n;
		}
		
		void end(int v){
			Cnode *n = new Cnode(v);
			if(head==NULL){
				head = n;
				n->next = head;
			}
			Cnode *l = head;
			while(l->next!=head)
				l = l->next;
			l->next = n;
			n->next = head;
		}
		
		void after(int k, int v){
			if(head==NULL)
				return;
			Cnode *n = new Cnode(v);
			Cnode *l = head;
			while(l->data!=k)
				l = l->next;
			n->next = l->next;
			l->next = n;
		}
		
		void before(int k, int v){
			if(head == NULL)
				return;
			
			Cnode *n = new Cnode(v);
			Cnode *a = head;
			Cnode *b = head;
			
			if(a->data==k){
//				start(v);
//				return;	
				Cnode *l = head;
				n->next = head;
				head = n;
				while(l->next!=n->next)
					l = l->next;
				l->next = n;
				return;
			}
				
			while(b->data!=k){
				a = b;
				b = b->next;
			}
			
			n->next = a->next;
			a->next = n;
		}
		
		void remove(int v){
			Cnode *l = head;
			Cnode *a = head;
			
			if(head==NULL)
				return;
				
			while(l->data!=v){
				a = l;
				l = l->next;
			}
			
			if(l==head){
				
				while(a->next!=head)
					a = a->next;
					
				a ->next = l->next;
				head = l->next;
				
			}else{
				a -> next = l->next;
			}
			
			delete l;
		}
		
		void removeAfter(int k){
			if(head==NULL)
				return;
			Cnode *a = head;
			Cnode *b = head;
			Cnode *c = head;
			while(a->data!=k)
				a = a->next;
			
			while(b!=a->next)
				b = b->next;
			a->next = b->next;
			if(b==head){
				head = b->next;
			}
			delete b;
		}
		
		void removeBefore(int k){
			if(head==NULL)
				return;
			Cnode *a = head;
			Cnode *b = head;
			Cnode *c = head;
			Cnode *d = head;
			if(a->data==k){
				
				while(b->next!=head){
					a = b;
					b = b->next;
				}
				a->next = b->next;
				
			}else if(a->next->data==k){
				
				while(a->next!=head)
					a = a->next;
				
				a->next = b->next;
				head = b->next;
				
			}else{
				while(b->next->data!=k)
					b = b->next;
				
				while(c->next->data!=b->data)
					c = c->next;
				
				c->next = b->next;
			}
			delete b;	
		}
};

int main(){
	LinkedList ll;
	
	//Start
	for(int k = 1; k<5; k++)
		ll.start(k);
	ll.display();
	cout<<"\n\n\n";
	
	//End
	for(int k=4; k<7; k++)
		ll.end(k);
	ll.display();
	cout<<"\n\n\n";
	
	//After
	ll.after(3, 30);
	ll.after(6, 60);
	ll.display();
	cout<<"\n\n\n";
	
	ll.before(4, 10);
	ll.display();
	cout<<"\n\n\n";
	
	ll.remove(10);
	ll.display();
	cout<<"\n\n\n";
	
	ll.removeAfter(5);
	ll.removeAfter(60);
	ll.display();
	cout<<"\n\n\n";
	
	ll.removeBefore(30);
	ll.display();
}