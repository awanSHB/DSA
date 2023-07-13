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
		
		//Before
		void before(int k, int v){
			DCnode *n = new DCnode(v);
			DCnode *l = head;
			if(k==l->data){
				while(l->next!=head)
					l = l->next;
				n->prior = l->next->prior;
				l->next->prior = n;
				n->next = l->next;
				l->next = n;
			}else{
				while(l->data!=k)
					l = l->next;
				n->prior = l->prior;
				n->next = l->prior->next;
				l->prior->next = n;
				l->prior = n;
			}
		}
		
		//Remove First
		void removeHead(){
			DCnode *l = head;
			DCnode *a = head;
			
			if(head==NULL)
				return;
				
			if(head->next==head){
				head->data = 0;
				head = NULL;
				cout<<"--------Deleted--------";
				return;
			}
			
			while(l->next!=head)
				l = l->next;
				
			head = a->next;
			l->next = head;
			head->prior = l;
			delete a;
		}
		
		//Remove tail
		void removeTail(){
			DCnode *l = head;
			DCnode *a = head;
			if(head==NULL)
				return;
			
			if(head->next==head){
				head->data = 0;
				head = NULL;
				cout<<"--------Deleted--------";
				return;
			}
			
			while(l->next->next!=head)
				l = l->next;
			
			a = l->next;
			l->next = head;
			head->prior = l;
			delete a;
		}
		
		//Remove After
		void removeAfter(int k){
			DCnode *l = head;
			DCnode *a = head;
			if(head==NULL)
				return;
			
			if(head->next==head){
				cout<<"There is no After!!!";
				return;
			}
				
			while(l->data!=k)
				l = l->next;
			a = l->next;
			l->next = a->next;
			a->next->prior = l;
			delete a;
		}
		
		//Remove Before
		void removeBefore(int k){
			DCnode *l = head;
			DCnode *a = head;
			DCnode *b = head;
			
			if(head==NULL)
				return;
			
			if(l->data==k){
				while(a->next->next!=head)
					a = a->next;
				b = a->next;
				a->next = head;
				head->prior = a;
			}
			else if(l->next->data==k){
				while(a->next!=head)
					a = a->next;
				b = a->next;
				head = b->next;
				a->next = head;
				head->prior = a;
			}
			else{
				while(a->data!=k){
					b = a;
					a = a->next;
				}
				a->prior = b->prior;
				b->prior->next = b->next;
			}
			delete b;
		}
};

int main(){
	LinkedList ll;
	
	bool check = true;
	int choice;
	int x;
	int val;
	int choose;
	int key;
	
	while(check==true){
		cout<<"\t\t\t\t\t1--Insert at start"<<endl;
		cout<<"\t\t\t\t\t2--Insert at End"<<endl;
		cout<<"\t\t\t\t\t3--Insert after value"<<endl;
		cout<<"\t\t\t\t\t4--Insert Before value"<<endl;
		cout<<"\t\t\t\t\t5--Delete Head Value"<<endl;
		cout<<"\t\t\t\t\t6--Delete Tail Value"<<endl;
		cout<<"\t\t\t\t\t7--Delete After Value"<<endl;
		cout<<"\t\t\t\t\t8--Delete Before Value"<<endl;
		cout<<"\n\n";
		
		cout<<"Enter your choice:- ";
		cin>>choice;
		switch(choice){
			
			case 1:
				cout<<"\nHow many values you want to enter at start: ";
				cin>>x;
				for(int k=0; k<x; k++){
					cout<<"Enter the value no. "<<(k+1)<<" : ";
					cin >> val;
					ll.start(val);
				}
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 2:
				cout<<"\nHow many value you want to enter at end: ";
				cin>>x;
				for(int k=0; k<x; k++){
					cout<<"Enter the value no. "<<(k+1)<<" : ";
					cin>>val;
					ll.end(val);
				}
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 3:
				cout<<"\nEnter the key: ";
				cin>>key;
				cout<<"Enter the value: ";
				cin>>val;
				ll.after(key, val);
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 4:
				cout<<"\nEnter the key: ";
				cin>>key;
				cout<<"Enter the value: ";
				cin>>val;
				ll.before(key, val);
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 5:
				ll.removeHead();
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 6:
				ll.removeTail();
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 7:
				cout<<"\nEnter the key: ";
				cin>>key;
				ll.removeAfter(key);
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			case 8:
				cout<<"\nEnter the key: ";
				cin>>key;
				ll.removeBefore(key);
				cout<<endl;
				ll.display();
				cout<<"\n\n";
				break;
			
			default:
				cout<<"Enter Correct value!!!";
		}
		
		cout<<"\nDo You Want To Continue? Press 1, Else Press 0: ";
		cin >> choose;
		if(choose!=1)
			check=false;
		cout<<"\n";
	}
}