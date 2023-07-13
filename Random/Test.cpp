#include <bits/stdc++.h>
using namespace std;

class Dnode{
	public:
		int data;
		Dnode *next;
		Dnode *prior;
		Dnode(){
			data = 0;
			next = prior = NULL;
		}
		Dnode(int v){
			data = v;
			next = prior = NULL;
		}
	
};

class LinkedList{
	private:
		Dnode *head;
		Dnode *tail;
	public:
		LinkedList(){
			head = tail = NULL;
		}
		
		void display(){
			Dnode *h = head;
			if(head!=NULL){
				cout<<"head"<<endl;
				cout<<" |"<<endl;
				cout<<"["<<head->data<<"]";
				h = h->next;
				do{
					cout<<" <===> "<<"["<<h->data<<"]";
					h = h->next;
				}while(h!=head);
				cout<<" ----> "<<head->data;
			}else{
				cout<<"Sorry!!! The linkedList is Empty"<<"\n\n";
			}
			
		}
		
		void insertStart(int v){
			Dnode *n = new Dnode(v);
			if(head==NULL){
				head = tail = n;
				tail->next = head;
			}
			else if(head==tail){
				tail->prior = n;
				head = n;
				n->next = tail;
				tail->next = head;
			}
			else{
				head->prior = n;
				n->next = head;
				head = n;
				tail->next = head;
				
			}
		}
		
		void insertEnd(int v){
			Dnode *n = new Dnode(v);
			Dnode *c = head;
			if(head==NULL){
				head = tail = n;
				head = n;
				tail->next = head;
			}else if(head==tail){
				head->next = n;
				n->prior = head;
				tail = n;
				tail->next = head;
			}else{
				tail->next = n;
				n->prior = tail;
				tail = n;
				tail->next = head;
			}
		}
		
		void insert(int v){
			Dnode *n = new Dnode(v);
			Dnode *s = head;
			Dnode *a = head;
			Dnode *b = head;
			Dnode *c = head;
			if(head==NULL){
				insertEnd(v);
			}else if(head==tail){
				if(a->data > v)
					insertStart(v);
				else
					insertEnd(v);
			}else if(tail->next==head&& head->next==tail){
				if(tail->data < v)
					insertEnd(v);
				else if(head->data > v)
					insertStart(v);
			}else{
				if(head->data > v){
					insertStart(v);
					return;
				}else if(tail->data < v){
					insertEnd(v);
					return;
				}
				
				while(b->data < v){
					c = b;
					b = b->next;
				}
				n->prior = c->next->prior;
				c->next->prior = n;
				n->next = c->next;
				c->next = n;
			}
		}
		
		void remove(int v){
			if(head==NULL)
				return;
			Dnode *r = head;
			Dnode *a = head;
			Dnode *t = tail;
			if(a->data==v){
				head = head->next;
				tail->next = head;
				delete a;
				return;
			}else if(tail->data==v){
				tail->prior->next = head;
				tail->prior = NULL;
				delete t;
				return;
			}
			if(r->data==v){
				head->data = 0;
				head = tail = NULL;
			}
			while(r->data!=v){
				a = r;
				r = r->next;
			}
			r->next->prior = r->prior;
			a->next = r->next;
		}
		
};

int main(){
	LinkedList ll;
	ll.insert(50);
	ll.insert(9);
	ll.insert(55);
	ll.insert(5);
	ll.insert(40);
	ll.insert(35);
	ll.insert(48);
	ll.display();
	cout<<"\n\n\n";
	
	cout<<"After Removing the head value:-"<<"\n\n";
	ll.remove(5);
	ll.display();
	
	cout<<"\n\n\n\nAfter Removing the tail value:- "<<"\n\n";
	ll.remove(55);
	ll.display();
	
	cout<<"\n\n\nAfter Removing Specific Value:- "<<"\n\n";
	ll.remove(40);
	ll.display();
}