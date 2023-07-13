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
	private:
		DCnode *head;
		DCnode *tail;
		int A[10];
		int index;
		int tr;
		int T[10];
		int c;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
			A[10];
			T[10];
			index = 0;
			tr = 0;
			c = 0;
		}
		
		//Method for displaying LinkedList
		void display(){
			DCnode *last = head;
			DCnode *track = head;
			int t = 0;
			do{
				cout<<"["<<last->data<<"]"<<" <===> ";
				last = last->next;
				
			}while(last!=head);
			
			cout<<"Head"<<endl;
			
			do{
				cout<<" "<<  T[t] <<"         ";
				track = track->next;
				t+=1;
			}while(track!=head);
		}
		void insert(int v){
			T[c] = v;
			c++;
		}
		
		
		//Method for Inserting at end and keep track of position
		void end(int v){
			DCnode *n = new DCnode(v);
			if(head==NULL){
				head = tail = n;
				head->prior = tail;
				tail -> next = head;
			}else if(head==tail){
				tail->next = n;
				tail = n;
				tail->prior = head;
				head->prior = tail;
				tail->next = head;
			}else{
				tail -> next = n;
				n->prior = tail;
				tail = n;
				head -> prior = tail;
				tail->next = head;
			}
			tr = tr + 1;
			insert(tr);
			
		}
		
		void removeElement(int v){
			for(int i=v; i<5; i++)
				T[i] = T[i+1];
			c--;
		}
		
		//Method for removing specific
		void remove(int v){
			DCnode *n = new DCnode(v);
			int c = 0;
			DCnode *a = head;
			DCnode *l = head;
			DCnode *t = tail;
			if(head==NULL)
				return;
			if(head==tail){
				if(l->data == v){
					head = NULL;
					l->data = 0;
					A[index] = v;
					R[index] = v;
					return;
				}
			}else{
				if(l->data==v){
					head = head->next;
					l->data = 0;
					head->prior =tail;
					tail->next = head;
					A[index] = v;
					removeElement(index);
					R[index] = v;
					return;
				}
				while(l->data!=v){
					a = l;
					index++;
					l = l->next;
				}
				l->next->prior = l->prior;
				a->next = l->next;
				A[index] = v;
				removeElement(index);
			}
		}
		
		void restore(){
			DCnode *n = head;
			int k = 1;
			DCnode *a = new DCnode(A[index]);
			int b;
			do{
				b++;
				if(b==index)
					break;
				n = n->next;
			}while(n!=head);
			a->prior = n->next->prior;
			n->next->prior = a;
			a->next = n->next;
			n->next = a;
			for(int i=b; i<5; i++){
				T[i] = i+1;
			}
		}
		
};

int main(){
	LinkedList ll;
	int noofvals;
	int v;
	int r;
	bool choice = true;
	char choic;
	
	cout<<"Enter the number of values that you want to Enter(<10): ";
	cin>>noofvals;
	for(int i=1; i<=noofvals; i++){
		cout<<"Enter the value no "<<i<<" : ";
		cin>>v;
		ll.end(v);
	}
	cout<<"\n\n";
	ll.display();
	cout<<"\n\n\n";
	while(choice){
		cout<<"Enter the value that you want to remove: ";
		cin>>r;
		cout<<"\n\n";
		ll.remove(r);
		ll.display();
		cout<<"\n\n\n";
		
		cout<<"After restring the removed value: "<<"\n\n";
		ll.restore();
		ll.display();
		cout<<"\n\nDo you want to remove another value(y/n)? ";
		cin>>choic;
		if(choic!='y')
			choice = false;
		
	}
	
}