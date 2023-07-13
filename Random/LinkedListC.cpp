#include<bits/stdc++.h>
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
		
		//Displaying
		void display(){
			Node *l = head;
			cout<<"head"<<endl;
			cout<<" |"<<endl;
			while(l!=NULL){
				cout<<"["<<l->data<<"]"<<" --> ";
				l = l->next;
			}
			cout<<"NULL";
		}
		
		//Inserting at start
		void start(int v){
			Node *n = new Node(v);
			n->next = head;
			head = n;
		}
		
		//Inserting at end
		void end(int v){
			Node *n = new Node(v);
			Node *l = head;
			if(head==NULL){
				head = n;
				return;
			}
			while(l->next!=NULL)
				l = l->next;
			l->next = n;
			
			
		}
		
		//Inserting after a value
		void after(int k, int v){
			Node *n = new Node(v);
			Node *a = head;
			if(head==NULL)
				return;
			while(a->data!=k)
				a = a->next;
			n->next = a->next;
			a->next = n;
		}
		
		//Insert Before
		void before(int k, int v){
			Node *n = new Node(v);
			Node *a = head;
			Node *b = head;
			if(head==NULL)
				return;
			while(a->data!=k){
				b = a;
				a = a->next;
			}
			n->next = b->next;
			b->next = n;
		}
		
		//Remove HeadNode
		void removeStart(){
			if(head==NULL)
				return;
			Node *n = head;
			head = head->next;
			delete n;
		}
		
		//Remove LastNode
		void removeLast(){
			Node *n = head;
			Node *a = head;
			if(head==NULL)
				return;
			while(n->next!=NULL){
				a = n;
				n = n->next;
			}
			a->next = n->next;
			delete n;		
		}
		
		//remove Specific
		void removeSpecific(int v){
			Node *n = head;
			Node *a = head;
			if(head==NULL)
				return;
			if(n->data==v){
				head = head->next;
				delete n;
				return;
			}
			while(n->data!=v){
				a = n;
				n = n->next;
			}
			a->next = n->next;
			delete n;
		}
		
		//Count Total Nodes
		void countNodes(){
			Node *n = head;
			int count;
			if(head==NULL){
				cout<<"Total no. of Nodes are 0";
				return;
			}
			while(n!=NULL){
				count+=1;
				n = n->next;
			}
			cout<<"Total no. of Nodes are : "<<count<<endl; 
		}
		
		//Delete EvenNodes
		void deleteEven(){
			Node *n = head;
			Node *a = head;
			Node *m = head;
			if(head==NULL)
				return;
			if(n->next==NULL && n->data%2==0){
				n->data = 0;
				head = NULL;
				delete n;
				return;
			}
			while(n!=NULL){
				m = n;
				if(n==head && n->data%2==0){
					
					head = head->next;
					delete m;
					
				}else{
					if(n->data%2==0){
						
						a->next = m->next;
						delete m;
						n = n->next;
						
					}else{
						a = n;
						n = n->next;
					}
				}
			}
		}
		
		//Deleting Odd Nodes
		void deleteOdd(){
			Node *n = head;
			Node *a = head;
			Node *copy = head;
			if(head==NULL)
				return;
			if(n->next==NULL && n->data%2!=0){
				n->data = 0;
				head = NULL;
				delete n;
				return;
			}
			while(n!=NULL){
				copy = n;
				if(n==head && n->data%2!=0){
					
					head = head->next;
					delete copy;
					
				}else{
					if(n->data%2!=0){
						
						a->next = copy->next;
						delete copy;
						n = n->next;
						
					}else{
						
						a = n;
						n = n->next;
						
					}
				}
				
			}
		}
		
		//Reversing a linkedList
		void reverseLinked(){
			Node *curr = head;
			Node *prev = NULL;
			while(curr!=NULL){
				head = curr->next;
				curr->next = prev;
				prev = curr;
				curr = head;
			}
			head = prev;
		}
		
		//Swapping nodes
		void swap(int n1, int n2){
			Node *n = head;
			int c;
			if(head==NULL)
				return;
			while(n!=NULL){
				c++;
				n = n->next;
			}
			Node *a = head;
			Node *b = head;
			
			if(n1 < 1 || n1 > c || n2 < 1 || n2 > c)
				return;
				
			while(a->data!=n1)
				a = a->next;
			while(b->data!=n2)
				b = b->next;
			
			int val = a->data;
			a->data = b->data;
			b->data = val;
		}
		
		//Delete Nodes
		void removeAll(){
			Node *l = head;
			while(l!=NULL){
				l = head;
				head = head->next;
				delete l;
			}
		}
};

int main(){
	LinkedList ll;
	
	bool check = true;
	int choice;
	int x;
	int val;
	int decision;
	int key;
	
	while(check==true){
		cout<<endl;
		cout<<"\t\t\t1---Inserting at start"<<endl;
		cout<<"\t\t\t2---Inserting at end"<<endl;
		cout<<"\t\t\t3---Inserting after value"<<endl;
		cout<<"\t\t\t4---Inserting before value"<<endl;
		cout<<"\t\t\t5---Delete HeadNode"<<endl;
		cout<<"\t\t\t6---Delete LastNode"<<endl;
		cout<<"\t\t\t7---Delete SpecificNode"<<endl;
		cout<<"\t\t\t8---Count Total Nodes"<<endl;
		cout<<"\t\t\t9---Delete Even Nodes"<<endl;
		cout<<"\t\t\t10---Delete Odd Nodes"<<endl;
		cout<<"\t\t\t11---Reversing LinkedList"<<endl;
		cout<<"\t\t\t12---Swapping two nodes"<<endl;
		cout<<"\t\t\t13---Delete All Nodes"<<endl;
		cout<<"\n\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"\nEnter the number of values you want to enter at start : ";
				cin>>x;
				for(int k=0; k<x; k++){
					cout<<"Enter the value no "<<(k+1)<<" : ";
					cin >> val;
					ll.start(val);
				}
				cout<<endl;
				ll.display();
				cout<<"\n\n\n";
				break;
				
			case 2:
				cout<<"\nEnter the number of values you want to enter at end : ";
				cin>>x;
				for(int k=0; k<x; k++){
					cout<<"Enter the value no "<<(k+1)<<" : ";
					cin >> val;
					ll.end(val);
				}
				cout<<endl;
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 3:
				cout<<"\nEnter the key and the value : "<<endl;
				cout<<"Key : ";
				cin>>key;
				cout<<"Value : ";
				cin >> val;
				cout<<"\n";
				ll.after(key, val);
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 4:
				cout<<"\nEnter the key and the value : "<<endl;
				cout<<"Key : ";
				cin>>key;
				cout<<"Value : ";
				cin >> val;
				cout<<"\n";
				ll.before(key, val);
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 5:
				cout<<endl;
				ll.removeStart();
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 6:
				cout<<endl;
				ll.removeLast();
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 7:
				cout<<"\nEnter the value you want to delete :";
				cin>>val;
				ll.removeSpecific(val);
				cout<<endl;
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 8:
				cout<<endl;
				ll.countNodes();
				cout<<"\n\n";
				break;
			
			case 9:
				cout<<endl;
				ll.deleteEven();
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 10:
				cout<<endl;
				ll.deleteOdd();
				ll.display();
				cout<<"\n\n\n";
				break;
			
			case 11:
				cout<<endl;
				ll.reverseLinked();
				ll.display();
				cout<<"\n\n";
				break;
			
			case 12:
				cout<<endl;
				ll.swap(3, 6);
				ll.display();
				cout<<"\n\n";
				break;
			
			case 13:
				cout<<endl;
				ll.removeAll();
				ll.display();
				cout<<"\n\n";
				break;
				
			default:
				cout<<"Please Enter the correct Input"<<"\n\n";
		}
		cout<<"\nDo you want to continue? Press 1, else Press 0: ";
		cin>>decision;
		if(decision==0)
			check=false;
	}
}