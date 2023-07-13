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
	public:
		LinkedList(){
			head = NULL;
		}
		
		bool isEmpty(){
			return head == NULL;
		}
		
		void display(){
			Node *last = head;
			if(head!=NULL){
				while(last!=NULL){
					if(last->data>99){
						cout <<"\t\t\t\t|   |"<<endl;
						cout <<"\t\t\t\t|"<< last->data<< "|"<<endl;
					}
					else if(last->data>9){
						cout <<"\t\t\t\t|   |"<<endl;
						cout <<"\t\t\t\t|_"<< last->data<< "|"<<endl;
					}else{
						cout <<"\t\t\t\t|   |"<<endl;
						cout <<"\t\t\t\t|_"<< last->data<< "_|"<<endl;
					}
					last = last->next;
				}
			}else{
				cout<<"The Stack is EMPTY!!!";
			}
			
		}
		
		//Method for inseting at start
		void start(int val){
			Node *new_node = new Node(val);
			new_node -> next = head;
			head = new_node;
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
		
		//Method for getting the first element
		int getFirst(){
			Node *n = head;
			return n->data;
		}
		
		//Method for sorting
		void sortAscending(){
			Node *a = head;
			Node *b = head;
			int t;
			
			while(a!=NULL){
				b = a->next;
				while(b!=NULL){
					if(a->data > b->data){
						t = a->data;
						a->data = b->data;
						b->data = t;
					}
					b = b->next;
				}
				a = a->next;
			}
		}
		
		//Method for sorting descending
		void sortDescending(){
			Node *a = head;
			Node *b = head;
			int t;
			
			while(a!=NULL){
				b = a->next;
				while(b!=NULL){
					if(a->data < b->data){
						t = a->data;
						a->data = b->data;
						b->data = t;
					}
					b = b->next;
				}
				a = a->next;
			}
		}
		
};

class Stack{
	private:
		LinkedList ll;
	public:
		bool isEmpty(){
			return ll.isEmpty();
		}
		
		void push(int v){
			ll.start(v);
		}
		
		void pop(){
			ll.removefirst();
		}
		
		void peek(){
			if(!isEmpty())	
				cout<<"\n-----------Top value is: "<< ll.getFirst();
			else
				return ;
		}
		
		void display(){
			ll.display();
		}
		
		void ascending(){
			ll.sortAscending();
		}
		
		void descending(){
			ll.sortDescending();
		}
};

int main(){
	Stack s;
	
	int noofvals;
	int val;
	
	cout<<"Enter the number of values you want to enter in stack: ";
	cin>>noofvals;
	cout<<"\n";
	
	for(int i = 0; i<noofvals; i++){
		cout<<"Enter the value no "<<(i+1)<<" : ";
		cin>>val;
		s.push(val);
	}
	cout<<"\n\nAfter Sorting In Ascending : "<<endl;
	s.ascending();
	s.display();
	
	cout<<"\n\nAfter sorting In Descending : "<<endl;
	s.descending();
	s.display();
	
	s.peek();
	s.pop();
	
	cout<<"\n\nAfter Removing The First/Top Element"<<"\n\n";
	s.display();
	return 0;
}