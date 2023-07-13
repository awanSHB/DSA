#include<bits/stdc++.h>
using namespace std;

class DCnode{
	public:
		int data;
		DCnode *next;
		DCnode *prior;
		
		DCnode(){
			data = 0;
			next = prior = NULL;
		}
		
		DCnode(int v){
			data = v;
			next = prior = NULL;
		}
};

class LinkedList{
	public:
		DCnode *head;
		DCnode *tail;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		//Displaying
		void display(){
			DCnode *last = head;
			int a = last->data;
			
			cout <<"head"<<endl;
			cout<<" |"<<endl;
			
			do{
				cout<<"["<<last->data<<"]"<<" <===> ";
				last = last->next;
				
			}while(last!=head);
			
			cout<<"\b\b=======> ["<<a<<"]"<<endl;
		}
		
		//Start
		void start(int v){
			DCnode *n = new DCnode(v);
			if(head==NULL){
				head = tail = n;
				head->prior = tail;
				tail->next = head;
			}
			else if(head==tail){
				head->prior = n;
				head = n;
				head->next = tail;
				head->prior = tail;
				tail->next = head;
			}
			else{
				head->prior = n;
				n->next = head;
				head = n;
				head->prior = tail;
				tail->next = head;
			}
		}
		
		//End
		void end(int v){
			DCnode *n = new DCnode(v);
			if(head==NULL){
				head = tail = n;
				head->prior = tail;
				tail->next = head;
			}
			else if(head==tail){
				head->next = n;
				tail = n;
				tail->prior = head;
				head->prior = tail;
				tail->next = head;
			}
			else{
				tail->next = n;
				n->prior = tail;
				tail = n;
				head->prior = tail;
				tail->next = head;
			}
		}
		
		//After
		void after(int k, int v){
			DCnode *n = new DCnode(v);
			DCnode *l = head;
			
			if(head==NULL)
				return;
				
			while(l->data!=k)
				l = l->next;
				
			n->prior = l->next->prior;
			l->next->prior = n;
			n->next = l->next;
			l->next = n;
		}
		
		//Adding array
		void addarray(int arr[], int n){
			for(int k=0; k<n; k++){
				end(arr[k]);
			}
		}
		
		//merge
		void merge(LinkedList l1, LinkedList l2){
			DCnode *f = l1.head;
			DCnode *s = l2.head;
			do{
				end(f->data);
				f = f->next;
			}while(f!=l1.head);
			
			do{
				end(s->data);
				s = s->next;
			}while(s!=l2.head);
			
		}
		
		void reverse(){
			DCnode *curr = head->next;
			DCnode *prev = head;
			DCnode *t = head;
			
			prev->next = prev;
			prev->prior = prev;
			
			while(curr!=head){
				
				t = curr->next;
				curr->next = prev;
				prev->prior = curr;
				head->next = curr;
				curr->prior = head;
				
				prev = curr;
				curr = t;
			}
			head = prev;
		}
		
		void removeDuplicate(){
			DCnode *a = head;
			DCnode *b = NULL;
			DCnode *t = NULL;
			do{
				b = a->next;
				t = a;
				while(b!=head){
					
					if(a->data==b->data){
						b->next->prior = b->prior;
						t->next = b->next;
						delete b;
						t = a;
					}else
						t = b;
					b = b->next;
					
				}
				a = a->next;
			}while(a!=head);
		}
};

int main(){
	LinkedList ll;
	LinkedList l1;
	LinkedList l2;
	LinkedList l3;
	
	cout<<"Inserting values at start: "<<endl;
	ll.start(1);
	ll.start(2);
	ll.display();
	cout<<"\n\n";
	
	cout<<"Inserting values at End: "<<endl;
	ll.end(4);
	ll.end(5);
	ll.display();
	cout<<"\n\n";
	
	cout<<"Inserting value after a value: "<<endl;
	ll.after(4, 40);
	ll.display();
	cout<<"\n\n";
	
	cout<<"Inserting an array at the tail of LinkedList: "<<endl;
	int arr[5] = {10, 11, 12};
	ll.addarray(arr, 3);
	ll.display();
	cout<<"\n\n";
	
	cout<<"Merging two newly created LinkedLists with different objects: "<<endl;
	l1.end(20);
	l1.end(21);
	l1.end(23);
	l2.end(23);
	l2.end(24);
	l2.end(24);
	l2.end(25);
	l3.merge(l1, l2);
	l3.display();
	cout<<"\n\n\n";
	
	cout<<"Reversing The LinkedList: "<<endl;
	ll.reverse();
	ll.display();
	cout<<"\n\n\n";
	
	cout<<"Removing duplicate values in the LinkedList: "<<endl;
	l3.removeDuplicate();
	l3.display();
}