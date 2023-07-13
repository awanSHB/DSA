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
			struct Node *s = head;
			cout << "{";
			while(s!=NULL){
				cout << s->data << ", ";
				s = s->next;
			}
			cout << "\b\b}";
		}
		
		//Method for displaying the square
		void displaySquare(){
			struct Node *s = head;
			cout << "{";
			while(s!=NULL){
				cout << (s->data)*(s->data) << ", ";
				s = s->next;
			}
			cout << "\b\b}";
		}
		
		// Inserting value at start
		void start(int v){
			Node *n = new Node(v);
			n->next = head;
			head = n;
		}
		void end(int v){
			Node *n = new Node(v);
			Node *l = head;
			if (head==NULL){
				head = n;
				return;
			}
			while(l->next!=NULL){
				l = l->next;
			}
			l->next = n;
		}
		
		// Method for inserting value after a value
		void after(int x, int v){
			Node *n = new Node(v);
			Node *p = head;
			if(head == NULL){
				cout << "Cannot assign value!!!";
				return;
			}
			while(p!=NULL && p->data !=x){
				p = p->next;
			}
			n->next = p->next;
			p->next = n;
		}
		
		// Method for inserting before value
		void before(int x, int v){
			Node *n = new Node(v);
			Node *p = head;
			Node *a = head;
			if (head == NULL){
				cout << "Cannot assign!!!";
				return;
			}
			while(p!=NULL && p->data!=x ){
				a = p;
				p = p->next;
			}
			n->next = a->next;
			a->next = n;
		}
		
		// Method for reversing a list
		void reverse(){
			Node *curr = head;
			Node *prev = NULL;
			while(curr!=NULL){
				head = curr -> next;
				curr->next = prev;
				prev = curr;
				curr = head;
			}
			head = prev;
		}
		
		//Method to reverse using recursion
		Node *reverserecursion(Node *head){
			if (head == NULL || head->next == NULL){
				return head;
			}
			
			Node *rest = reverserecursion(head->next);
			head->next->next = head;
			
			head->next = NULL;
			
			return rest;
		}
		
		
		//Method for swapping
		void swap(int node1, int node2){
			
			Node *pos1 = head;
			Node *pos2 = head;
			Node *prev1 = NULL;
			Node *prev2 = NULL;
			Node *temp = NULL;
			
			if(node1 == node2)
				return;
			
			if(head==NULL)
				return;
			
			while(pos1!=NULL && pos1->data!=node1){
				prev1 = pos1;
				pos1 = pos1->next;
			}
			
			while(pos2!=NULL && pos2->data!=node2){
				prev2 = pos2;
				pos2 = pos2->next;
			}
			
			if (pos1!=NULL && pos2!=NULL){
				if(prev1!=NULL){
					prev1->next = pos2;
				}else{
					head = pos2;
				}
				
				if(prev2!=NULL){
					prev2->next = pos1;
				}else{
					head = pos1;
				}
			}
			temp = pos1->next;
			pos1->next = pos2->next;
			pos2->next = temp;
		}
		
		//Method to sorting in ascending order
		void ascending(){
			Node *n = head;
			Node *i = NULL;
			int temp;
			
			if(head == NULL){
				return;
			}
			else{
				while(n!=NULL){
					i = n->next;
					while(i!=NULL){
						if (n->data > i->data){
							temp = n->data;
							n->data = i->data;
							i->data = temp;
						}
						i = i->next;
					}
					n = n->next;
				}
			}
			
		}
		
		//Method for adding whole array
		void remove(int v){	
			Node *p, *r;
			p = r = head;
// 		    Node *p = head;
//			Node *r = head;
			
			while(r!=NULL && r->data != v){
				p = r;
				r = r->next;
			}
			
			if(r==head){
				head = head->next;
			}else{
				p->next = r->next;
				delete r;
			}
		}
		
		//Method to remove the first element
		void removefirst(){
			Node *r = head;
			if(r==NULL){
				cout<<"The list is emptry!!!";
				return;
			}
			head = head -> next;
			delete r;
		}
		
		//Method to remove the last element
		void removelast(){
			Node *b = head;
			Node *h = head;
			if(h==NULL){
				cout<<"EMPTY!!!";
				return;			
			}
			while(h->next!=NULL){
				b = h;
				h = h->next;
			}
			b->next = NULL;
			delete h;	
		}
		
		//Method for adding array
		void addarray(int foo[], int n){
			Node *l = head;
			while(l->next!=NULL){
				l = l->next;
			}
			for (int i = 0; i<n; i++){
				Node *n = new Node(foo[i]);
				l->next = n;
				l = n;
			}
		}
		
		
		//Method for removing after value
		void removeAfter(int v){
			Node *h = head;
			Node *b = head;
			
			while(h!=NULL && h->data!=v){
				h = h->next;
			}
			
			while(b!=NULL && b->data!=h->next->data){
				b = b->next;
			}
			
			h->next = b->next;
			delete b;
		}
		
		//Method for removing before
		void removeBefore(int v){
			Node *n = new Node(v);
			Node *h = head;
			Node *b = head;
			Node *c = head;
			Node *d = head;
			
			while(h!=NULL && h->data!=v){
				b = h;
				h = h->next;
			}
			
			while(c!=NULL && c->data!=b->data){
				d = c;
				c = c->next;
			}
				
			d->next = b->next;
			delete c;
		}
		
		//Method for getting the first element
		void getFirst(){
			Node *n = head;
			cout << n->data;
		}
		
		//Method for getting last element
		void getLast(){
			Node *n = head;
			while(n->next!=NULL){
				n = n->next;
			}
			cout << n->data;
		}
		
		//Method for removing all
		void removeall(){
			Node *p = head;
			while(head!=NULL){
				p = head;
				head = head->next;
				delete p;
			}
		}
};

int main(){
	LinkedList ll;
	cout << "Inserting value at start:"<<endl;
	
	// -*-
	ll.start(9);
	ll.start(10);
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "Inserting value at last:" << endl;
	ll.end(1);
	ll.end(2);
	ll.end(3);
	ll.end(4);
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "Inserting Value after value:" << endl;
	ll.after(2, 5);
	ll.after(3, 7);
	ll.display();
	cout<<"\n\n\n";
	
	
	// -*-
	cout << "Inserting value before value:"<<endl;
	ll.before(3, 81);
	ll.before(7, 14);
	ll.display();
	cout<<"\n\n\n";
	
	// -*-
	cout << "Displaying the square value:"<<endl;
	ll.displaySquare();
	cout << "\n\n\n";
	
	// -*-
	cout << "Reversing a linked list:"<<endl;
	ll.reverse();
	ll.display();
	cout<<"\n\n\n";
	
	// -*-
	cout << "Reversing a linked list using recursion:"<<endl;
	ll.head = ll.reverserecursion(ll.head);
	ll.display();
	cout<<"\n\n\n";
	
	// -*-
	cout << "Swapping a LinkedList:" << endl;
	ll.swap(14, 7);
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "sorting in ascending order" << endl;
	ll.ascending();
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "Deletting a value:"<<endl;
	ll.remove(5);
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "Deletting First value:"<<endl;
	ll.removefirst();
	ll.display();
	cout << "\n\n\n";
	
	
	// -*-
	cout << "Deletting last value:"<<endl;
	ll.removelast();
	ll.display();
	cout << "\n\n\n";
	
	// -*-
	cout << "Adding an array" << endl;
	int foo[5] = {20, 21, 22, 23, 24};
	ll.addarray(foo, 5);
	ll.display();
	cout << "\n\n\n";
	
	// -*-
	cout<<"Deleting After element:"<<endl;
	ll.removeAfter(2);
	ll.display();
	cout<<"\n\n\n";
	
	
	// -*-
	cout<<"Deleting Before element:"<<endl;
	ll.removeBefore(7);
	ll.display();
	cout<<"\n\n\n";
	
	
	// -*-
	cout << "Getting the first element:"<<endl;
	ll.getFirst();
	cout << "\n\n\n";
	
	// -*-
	cout << "Getting the last element:"<<endl;
	ll.getLast();
	cout << "\n\n\n";
	
	ll.removeall();
	cout<<"List has been successfully removed:";
		
}
                
