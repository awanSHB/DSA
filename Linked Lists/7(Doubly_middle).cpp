#include<iostream>
using namespace std;

class Dnode{
	public:
		int data;
		Dnode *next;
		Dnode *prev;
		
		Dnode()	{
			data = 0;
			next = prev = NULL;
		}
		
		Dnode(int v){
			data = v;
			next = prev = NULL;
		}
};

class LinkedList{
	private:
		Dnode *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void display(){
			Dnode *n = head;
			cout<<"\n\nhead\n |\n |\n";
			while(n!=NULL){
				cout<<"["<<n->data<<"] <===> ";
				n = n->next;
			}
			cout<<"NULL\n\n";
		}
		
		void start(int v){
			Dnode *n = new Dnode(v);
			if(head==NULL){
				head = n;
				return;
			}
			n->next = head;
			head->prev = n;
			head = n;
		}
		
		void End(int v){
			Dnode *n = new Dnode(v);
			if(head==NULL){
				head = n;
				return;
			}
			
			Dnode *l = head;
			while(l->next!=NULL)
				l = l->next;
			l->next = n;
			n->prev = l;
		}
		
		void insertMiddle(int v){
			Dnode *n = new Dnode(v);
			Dnode *l = head;
			
			Dnode *p = NULL;
			Dnode *tr = head;
			
			int count = 0;
			int t = 0;
			
			while(l!=NULL){
				l = l->next;
				count++;
			}
			
			while(t!=count/2){
				p = tr;
				tr = tr->next;
				t++;
			}
			
			tr->prev = n;
			n->prev = p;
			p->next = n;
			n->next = tr;
		}
	
};

int main(){
	LinkedList la;
	
	la.End(10);
	la.End(20);
	la.End(30);
	la.End(40);
	la.start(9);
	la.start(8);
	la.start(7);
	
	la.display();
	
	la.insertMiddle(100);
	la.display();
	
	la.insertMiddle(1000);
	la.display();
}









