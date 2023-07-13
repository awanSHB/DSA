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
		Node(int v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	private:
		Node *head;
	public:
		LinkedList(){
			head = NULL;
		}
		void display(){
			Node *last = head;
			cout << "head"<<endl;
			cout << " |"<<endl;
			while(last!=NULL){
				cout << "["<< last->data << "]" << " -> ";
				last = last->next;
			}
			cout << "NULL";
		}
		
		//Method for inseting at start
		void start(int val){
			Node *new_node = new Node(val);
			new_node -> next = head;
			head = new_node;
		}
		
		//Method for inserting after value
		void insertAfter(int key, int val){
			if(head == NULL)
				return;
			Node *check = head;
			Node *mid = new Node(val);
			while(check!=NULL){
				if(check->data==key){
					mid->next = check->next;
					check->next = mid;
					return;
				}
				check = check->next;
			}
			cout<<"Value does not exist we cannot assign after it!!!";
		}
		
		//Method for inserting at end
		void end(int val){
			Node *new_node = new Node(val);
			Node *last =  head;
			if(head==NULL){
				head = new_node;
				return;
			}
			while(last->next!=NULL){
				last = last->next;
			}
			last->next = new_node;	
		}
		
		//Method for reversing an array
		void reverseArray(int arr[], int n){
			Node *last = head;
			while(last->next!=NULL){
				last = last->next;
			}
			for(int k=4; k>=0; k--){
				Node *new_node = new Node(arr[k]);
				last->next = new_node;
				last = new_node;
			}	
		}
		
		void combineLinkedList(LinkedList ll, LinkedList mm){
			Node *first = ll.head;
			Node *second = mm.head;
			while(first!=NULL){
				Node *new_node = new Node(first->data);
				Node *last = head;
				if(head==NULL){
					head = new_node;
				}else{
					while(last->next!=NULL){
						last = last->next;
					}
					last->next = new_node;
				}
				first = first->next;
			}
			
			while(second!=NULL){
				Node *new_node = new Node(second->data);
				Node *last = head;
				if(head==NULL){
					head = new_node;
				}else{
					while(last->next!=NULL){
						last = last->next;
					}
					last->next = new_node;	
				}
				second = second->next;
				
			}
		}
		
		//Method for ascending
		void sortAscending(){
			Node *a = head;
			Node *b = NULL;
			int check;
			if(head==NULL){
				return;
			}
			while(a!=NULL){
				b = a->next;
				while(b!=NULL){
					if (a->data > b->data){
						check = b->data;
						b->data = a->data;
						a->data = check;
					}
					b = b->next;
				}
				a = a->next;
			}
		}
		//removing
		void remove(int v){
			Node *n = new Node(v);
			Node *l = head;
			Node *prev = NULL;
			Node *nxt = NULL;
			if(head == NULL)
				return;
			while(l!=NULL){
				if(l->data == v){
					prev->next = l->next;
					delete nxt;
				}
				prev = l;
				l = l->next;
				nxt = l;	
			}
		}
		
		//separateEvenOdd
		void separateEvenOdd(){
			Node *n = head;
			Node *c = head;
			Node *m = head;
			while(n!=NULL){
				c = n;
				if(n->data%2==0){
					c->next = m->next;
					delete n;
				}
				n = n->next;
				m = m->next;
			}
		}
		
		//Similar removing
		void removeSimilar(){
			Node *a = head;
			Node *b = NULL;
			while(a!=NULL){
				b = a->next;	
				while(b!=NULL){	
					if(a->data == b->data){
						remove(b->data);
					}
					b = b->next;
				}
				a = a->next;
			}
		}
		
		void Descending(){
			Node *z = NULL;
			Node *y = head;
			int t;
			if(head==NULL)
				return;
			while(y!=NULL){
				z = y->next;
				while(z!=NULL){
					if(y->data < z->data){
						t = z->data;
						z->data = y->data;
						y->data = t;
					}
					z = z->next;
				}
				y = y->next;
			}
		}
		
};

int main(){
	LinkedList ll;
	LinkedList mm;
	LinkedList cl;
	int k = 0;
	int x;
	
	//Method for inserting at start
	while(k < 3){
		cout << "Enter the head value-> ";
		cin >> x;
		ll.start(x);
		++k;
	}
	ll.display();
	cout << "\n\n\n\n";
	//Method for inserting after
	cout<<"Inserting after value:"<<"\n\n";
	ll.insertAfter(2, 5);
	ll.display();
	cout << "\n\n\n\n";   
	
	//Method for inserting at end
	cout<<"Inserting the value at end:"<<"\n\n";
	int e = 0;
	while(e < 3){
		cout << "Enter the last value -> ";
		cin >> x;
		ll.end(x);
		++e;
	}
	cout<<endl;
	ll.display();
	cout << "\n\n\n\n";
	
	//Method for adding the array in reverse order
	cout<<"Inserting array in reverse order:"<<"\n\n";
	int arr[5] = {10, 20, 40, 40, 50};
	ll.reverseArray(arr, 5);
	ll.display();
	cout << "\n\n\n\n";
	
	//Method for second ob3ect   
	cout<<"The second object value is: "<< endl;
	mm.end(40);
	mm.end(41);
	mm.end(42);
	mm.end(43);
	mm.display();
	cout<<"\n\n\n\n";
	
	cout<<"Method for combining two linked lists"<<endl;
	cl.combineLinkedList(ll, mm);
	cl.display(); 
	cout<<"\n\n\n\n";
	
	cout<< "Method for removing a particular value" << "\n\n";
	cl.remove(5);
	cl.display();
	cout << "\n\n\n\n";
	
	cout<<"Method for sorting list in ascending order" << "\n\n";
	cl.sortAscending();
	cl.display();
	cout<<"\n\n\n\n"; 
	
	cout << "Method for separating odd and even" << "\n\n";
	cl.separateEvenOdd();
	cl.display();
	cout << "\n\n\n\n";
	
	cout<<"Method for removing similar values" << "\n\n";
	cl.removeSimilar();
	cl.display();
	cout << "\n\n\n\n";
	
	cout<<"Method for sorting in descending order"<<"\n\n";
	cl.Descending();
	cl.display();
	cout<<"\n\n\n\n";
	
	
	 
}