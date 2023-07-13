#include <iostream>
using namespace std;

/*
In this program we have to remove the nodes in the linked list whose position is mentioned
int their elements.

For this we will create a dummy linkedList inside the remove Function, and then by comparing 
the elements in dummy list we will remove the nodes in the original list.
*/
 
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
		
		void createDummy(Node *n){
			if(n==NULL)
				return;
			add(n->data);
			createDummy(n->next);
		}
		
		void show(Node *n){
			if(n==NULL){
				cout<<"NULL";
				return;
			}
			cout<<"["<<n->data<<"] --> ";
			show(n->next);
		}
		
		void remove(){
			Node *l1 = head;
			
			//We are creating a dummy LinkedList.
			LinkedList l2;
			l2.createDummy(head);
			Node *d = l2.head;
			
			Node *prev = NULL;
			int t = 1;
			
			while(l1!=NULL){
				
				if(t==d->data){
					
					if(prev==NULL)
						head = l1->next;
					else
						prev->next = l1->next;
					
					
					Node *r = l1;
					d = d->next;
					l1 = l1->next;
					delete r;
					
				}else{
					
					prev = l1;
					l1 = l1->next;
				
				}
				t+=1;
			}
			show(head);
		
		}
};

int main(){
	LinkedList l1;
	l1.add(1);
	l1.add(3);
	l1.add(5);
	l1.add(6);
	l1.add(8);
	l1.add(9);
	l1.add(10);
	l1.add(11);
	
	l1.display();
	
	l1.remove();
	
}
