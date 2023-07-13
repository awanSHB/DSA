#include <iostream>
using namespace std;
 
class Node{
	public:
		int data;
		Node *next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(int v){
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
		
		void display(){
			Node *ll = head;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
		
		void add(int v){
			Node *n = new Node(v);
			if(head==NULL){
				head = n;
				return;
			}
			Node *d = head;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void remove(int v){
			Node *l = head;
			Node *p = NULL;
			Node *copy = l;
			bool check = false;
			
			if(head->data==v){
				head = head->next;
				delete l;
				return;
			}
			
			while(l->next!=NULL){
				p = l;
				l = l->next;
				copy = l;
				if(l->data==v){
					p->next = l->next;
					delete copy;
					return;
				}	
			}
			cout<<"\nOOPS! The Node has not been Found...";
			
		}
};

int main(){
	LinkedList l1;
	
	int ar1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	for(int i=0; i<8; i++)
		l1.add(ar1[i]);
	
	l1.display();
	
	l1.remove(5);
	l1.display();
	
	l1.remove(7);
	l1.display();
	
	l1.remove(1);
	l1.display();
	
	l1.remove(8);
	l1.display();
	
	l1.remove(10);
}














