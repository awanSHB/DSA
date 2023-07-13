#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int val){
			data = val;
			next  = NULL;
		}
};

class LinkedList{
	private:
		Node *head;
	public:
		LinkedList(){
			head = new Node(0);
		}
		
		~LinkedList(){
			Node *c = head;
			while(c!=NULL){
				Node *t = c;
				c = c->next;
				delete t;
			}	
		}
		
		void display(){
			cout<<"\n\nhead\n  |\n  |\n";
			Node *n = head;
			while(n!=NULL){
				cout<<"["<<n->data<<"] --> ";
				n = n->next;
			}
			cout<<"NULL\n";
		}
		
		void insert(int v){
			Node *n = new Node(v);
			n->next = head->next;
			head->next = n;
		}
};

int main(){
	LinkedList ll;
	
	ll.insert(10);
	ll.insert(20);
	ll.insert(30);
	
	ll.display();
	
}
