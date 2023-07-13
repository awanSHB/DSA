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
	public:
		Dnode *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void display(){
			Dnode *h = head;
			cout << "NULL<-- ";
			while(h != NULL){
				cout << "[" << h->data << "]" << " <==> ";
				h = h->next;
			}
			cout << "\b\b\b\b\b-->NULL";
		}
		
		void start(int v){
			Dnode *n = new Dnode(v);
			Dnode *l = head;
			if(head == NULL){
				head = n;
				return;
			}
			n->next = head;
			head->prior = n;
			head = n;
		}
		
		void end(int v){
			Dnode *n = new Dnode(v);
			if(head==NULL){
				head = n;
				return;
			}
			Dnode *l = head;
			while(l->next!=NULL){
				l = l->next;
			}
			l->next = n;
			n->prior = l;
		}
		
		void after(int key, int val){
			Dnode *n = new Dnode(val);
			if (head==NULL)
				return;
			
			Dnode *l = head;
			while(l!=NULL && l->data != key){
				l = l->next;
			}
			n->prior = l;
			n->next = l->next;
			n->next->prior = n;
			l->next = n;
		}
		
		void before(int key, int val){
			Dnode *n = new Dnode(val);
			if(head==NULL)
				return;
			Dnode *l = head;
			Dnode *c;
			while(l!=NULL && l->data!=key){
				c = l;
				l = l->next;
			}
			n->prior = c;
			n->next = c->next;
			c->next = n;
			l->prior = n;
//			l->prior->next = n;
//			n->prior = l;
//			n->next = l;
//			l->prior = n;	
			
		}
		
		void remove(int v){
			if(head==NULL)
				return;
			Dnode *l = head;
			while(l->data!=v){
				l = l->next;
			}
			l->prior->next = l->next;
			l->next->prior = l->prior;
			delete l;
		}
		
		void removeAfter(int k){
			if(head==NULL)
				return;
			Dnode *l = head;
			Dnode *m = head;
			while(l!=NULL && l->data!=k)
				l = l->next;
			while(m!=NULL && m->data!=l->next->data)
				m = m->next;
				
			l->next = m->next;
			m->next->prior = m->prior;
//			l->next= l->next->next;
//			l->next->next->prior = l->next->prior;
			
			delete m;
		}
		
		void removeBefore(int k){
			if (head==NULL)
				return;
			Dnode *l  = head;
			Dnode *last = head;
			while(last->data!=k){
				l = last;
				last = last->next;
			}
			last->prior = l->prior;
			l->prior->next = l->next;
			delete l;
		}
};

int main(){
	LinkedList ll;
	
	cout<<"Inserting at start:"<<"\n\n";
	ll.start(1);
	ll.start(2);
	ll.start(3);
	ll.display();
	cout << "\n\n\n\n";
	
	cout << "Inserting at end:"<<"\n\n";
	ll.end(5);
	ll.end(7);
	ll.end(9);
	ll.display();
	cout<<"\n\n\n\n";
	
	cout <<"Inserting after the value:"<<"\n\n";
	ll.after(3, 4);
	ll.after(5, 6);
	ll.after(7, 8);
	ll.display();
	cout<<"\n\n\n\n";
	
	cout << "Inserting before:"<<"\n\n";
	ll.before(9, 10);
	ll.before(6, 16);
	ll.display();
	cout << "\n\n\n\n";
	
	cout<<"Removing:"<<"\n\n";
	ll.remove(6);
	ll.display();
	cout << "\n\n\n\n";
	
	cout<<"Removing After:" << "\n\n";
	ll.removeAfter(5);
	ll.display();
	cout << "\n\n\n\n";
	
	cout<<"Remove Before" << "\n\n";
	ll.removeBefore(5);
	ll.display();
}