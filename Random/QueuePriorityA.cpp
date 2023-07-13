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
	private:
		Node *head;
		int j;
		int *A;
	public:
		LinkedList(){
			head = NULL;
			j = 0;
			A = new int[10];
		}
		
		void push(int dat, int pr){
			Node *n = new Node(dat);
			Node *l = head;
			if(head==NULL){
				head = n;
				A[j++] = pr;
				return;
			}
			while(l->next!=NULL){
				l = l->next;
			}
			l->next = n;
			A[j++] = pr;
		}
		
		void arrange(){
			Node *n = head;
			Node *a;
			int tr;
			int ta;
			int t;
			int tn;
			while(n!=NULL && tr<j){
					a = n->next;
					ta = tr+1;
					while(a!=NULL && ta<j){
						if(A[tr] < A[ta]){
							t = A[ta];
							A[ta] = A[tr];
							A[tr] = t;
							
							tn = a->data;
							a->data = n->data;
							n->data = tn;
						}
						a = a->next;
						ta+=1;
					}
				n = n->next;
				tr+=1;
			}
		}
		
		void display(){
			cout<<"\n\n\n";
			Node *n =head;
			while(n!=NULL){
				cout<<"["<<n->data<<"]"<<" --> ";
				n = n->next;
			}
			cout<<"NULL"<<endl;
//			cout<<" ";
			for(int i=0; i<j; i++){
				cout<<"|"<<A[i]<<"|      ";
			}
		}
		
};

int main(){
	LinkedList ll;
	ll.push(100, 10);
	ll.push(50, 5);
	ll.push(80, 8);
	ll.push(20, 7);
	ll.push(50, 9);
	ll.push(70, 6);
	ll.push(300, 4);
	ll.push(40, 3);
	ll.push(90, 20);
	ll.push(120, 15);
	ll.display();
	
	cout<<"\n\n\n\nAfter Arranging According to Priorities: ";
	ll.arrange();
	ll.display();
}