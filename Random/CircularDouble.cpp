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
		Dnode *tail;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
	
		void display(){
			Dnode *n = head;
			int a = n->data;
			cout<<"head"<<endl;
			cout<<" |"<<endl;
			if(head!=NULL){
				do{
					cout<<"["<<n->data<<"]"<<" <=> ";
					n = n->next;
				}while(n!=head);
			}else{
				cout<<"The LinkedList you are calling is EMPTY!!!"<<endl;
			}
			cout<<"";
			cout<<"\b\b\b\b\b <=======> ["<<a<<"]\n\n";
		}
		
		void start(int v){
			Dnode *n = new Dnode(v);
			if(head == NULL){
				head = tail = n;
				head -> prior = tail;
				tail -> next = head;
			}else if(head == tail){
				head->prior = n;
				head = n;
				head->next = tail;
				head->prior = tail;
				tail->next = head;
			}else{
				head -> prior = n;
				n->next = head;
				head = n;
				head->prior = tail;
				tail->next = head;
				
			}
		}
		
		
		void end(int val){
			Dnode *n = new Dnode(val);
			if (head == NULL){
				head = tail = n;
				head->prior = tail;
				tail->next = head;
			}
			else if(head==tail){
				head->next = n;
				tail = n;
				tail->prior = head;
				tail->next = head;
				head->prior = tail;
			}
			else{
				tail->next = n;
				n->prior = tail;
				tail = n;
				tail->next = head;
				head->prior = tail;
			}
		}
		
		void after(int k, int v){
			Dnode *n = new Dnode(v);
			Dnode *c = head;
			if(head==NULL)
				return;
			if(head==tail){
//				if(c->data==k){
//					head->next = n;
//					tail = n;
//					tail->prior = head;
//					head->prior = tail;
//					tail->next = head;
//				}else{
//					return;
//				}
			}else{
				while(c->data!=k){
					c = c->next;
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
			Dnode *l = head;
			Dnode *c = head;
			while(l->data!=v){
				c = l;
				l = l->next;
			}
			if(l==head){
				if(head->next==head){
					head->data = 0;
					head = NULL;
					return;
				}
				while(c->next!=head)
					c = c->next;
				c->next = head->next; // or c->next = l->next
				head = head->next;
				head->prior = c;	  // or head->prior = tail;
			}else{
				l->next->prior = l->prior;
				c->next = l->next;
			}
			delete l;
		}
		
		void removeAll(){
			Dnode *l = head;
			Dnode *c = head;
			while(l!=tail->next){
				head = l;
				l = l->next;
				delete head;
			}
		}
		
};

int main(){
	LinkedList ll;
	
	ll.start(1);
	ll.start(2);
	ll.start(3);
	ll.display();
	cout<<"\n\n\n";
	
	for(int k = 5; k<10; k++)
		ll.end(k);
	ll.display();
	cout<<"\n\n\n";
	
	ll.after(9, 10);
	ll.display();
	cout<<"\n\n\n";
	
	ll.remove(3);
	ll.display();
	cout<<"\n\n\n";
	
	ll.removeAll();
	cout<<"Removed All elements!!!";
	ll.display();
}