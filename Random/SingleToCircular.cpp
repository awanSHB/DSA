#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node (int v){
			data = v;
			next = NULL;
			
		}
};

class LinkedList{
	public:
		Node *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		//Method for displaying lisked list
		void display(){
			Node *s = head;
			int a = 0;
			int b = 0;
			if(head!=NULL){
				do{
					if(a==0)
						b = s->data;
					cout << "[" << s->data << "]" << "->";
					s = s->next;
					a+=1;
				}while(s!=head);
			}
			cout<<"\b------>head->["<<b<<"]";
		}       
		
		void start(int v){
			Node *n = new Node(v);
			if(head==NULL){
				head = n;
				n->next = head;
				return;
			}
			Node *l = head;
			n->next = head;
			head = n;
			while(l->next != n->next)
				l = l->next;
			l->next = n;
		}
		
		void end(int v){
			Node *n = new Node(v);
			if(head==NULL){
				head = n;
				n->next = head;
				return;
			}
			n->next = head;
			Node *l = head;
			while(l->next!=n->next)
				l = l->next;
			l->next = n;
			
		}
		
		void remove(int v){
			if(head==NULL)
				return;
			Node *l = head;
			Node *c = head;
			
			while(l->data!=v){
				c = l;
				l = l->next;
			}
			if(l->data!=v){
				std::cout<<"Does not exist!!!"<<std::endl;
				return;
			}
			if(l==head){
				if(head->next==head){
					head->data = 0;
					head = NULL;
					return;
				}
				while(c->next!=head){
					c = c->next;
				}
				c->next = l->next;
				head = l->next;	
			}else{
				c->next = l->next;
			}
			delete l;
		}
		
		void removeAfter(int k){
			Node *a = head;
			Node *b = head;
			if(head==NULL)
				return;
			while(a->data!=k)
				a=a->next;
			while(b->data!=a->next->data)
				b = b->next;
			a->next = b->next;
			delete b;
		}
		
		void removeBefore(int k){
			Node *a = head;
			Node *b = head;
			Node *c = head;
			Node *d = head;
			Node *e = head;
			if(head==NULL)
				return;
			while(b->data!=k){
				a = b;
				b = b->next;
			}
			if(a==head){
				e = a->next;
				if(e->data==k){
					while(c->data!=a->data){
					c = c->next;
					}
				}
				c->next = a->next;
			}else{
				while(d->data!=a->data){
					c = d;
					d = d->next;
				}
				c->next = a->next;
			}
			delete a;
			
		}
		
};

int main(){
	LinkedList ll;
	
	cout<< "Start:"<<"\n\n";
	ll.start(1);
	ll.start(2);
	ll.start(3);
	ll.start(4);
	ll.start(5);
	ll.display();
	cout << "\n\n\n\n";
	
	cout << "End:" << "\n\n";
	ll.end(6);
	ll.end(7);
	ll.end(8);
	ll.display();
	cout << "\n\n\n\n";
	
	cout <<"Remove:" << "\n\n";
	ll.remove(5);
	ll.display();
	cout<<"\n\n\n\n";
	
	cout<<"Remove After!!!"<<"\n\n";
	ll.removeAfter(3);
	ll.display();
	cout<<"\n\n\n\n";
	
	cout<<"Remove Before!!!"<<"\n\n";
	ll.removeBefore(3);
	ll.display();
	cout<<"\n\n\n\n";
	
}           