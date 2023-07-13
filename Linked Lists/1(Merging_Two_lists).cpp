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
		
		void combine(LinkedList l1, LinkedList l2){
			Node *a = l1.head;
			Node *b = l2.head;

			while(a->next!=NULL)
				a = a->next;
			while(b!=NULL){
				a->next = b;
				b = b->next;
				a = a->next;
			}
			
		}
		
		void merge(LinkedList l1){
			Node *a = l1.head;
			Node *x = NULL;
			Node *T = NULL;
			int t;
			
			while(a!=NULL){
				x = a->next;
				while(x!=NULL){
					if(a->data > x->data){
						
						t = a->data;
						a->data = x->data;
						x->data = t;
					}
					
					x = x->next;
				}
				a = a->next;
			}
		}
		
};

int main(){
	LinkedList ll1;
	LinkedList ll2;
	LinkedList ll3;
	int ar1[4] = {1, 3, 5, 6};
	int ar2[3] = {2, 4, 7};
	
	for(int i=0; i<4; i++)
		ll1.add(ar1[i]);
	
	for(int j=0; j<3; j++)
		ll2.add(ar2[j]);
	
	ll1.display();
	ll2.display();
	
	cout<<"\n\nAfter Combining Two LinkedLists: \n";
	ll1.combine(ll1, ll2);
	ll1.display();
	
	cout<<"\n\nAfter Merging Two LinkedLists: \n";
	ll1.merge(ll1);
	ll1.display();
}












