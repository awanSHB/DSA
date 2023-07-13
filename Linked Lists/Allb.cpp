#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(int d){
			data = d;
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
			cout<<"\n\nhead\n  |\n  |\n";
			Node *n = head;
			while(n!=NULL){
				cout<<"["<<n->data<<"] --> ";
				n = n->next;
			}
			cout<<"NULL\n";
		}
		
		void insert(int val){
			Node *n = new Node(val);
			if(head==NULL){
				head = n;
				return;
			}
			Node *traverse = head;
			while(traverse->next!=NULL)
				traverse = traverse->next;
			traverse->next = n;
		}
		
		void reverse(){
			Node *curr = head;
			Node *prev = NULL;
			Node *next = NULL;
			
			while(curr!=NULL){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
		
		void passList(int key, int value){
			
			Node *l1 = head;
			
			while(l1!=NULL){
				if(l1->data==key){
					
					Node *prev = NULL;
					Node *curr = head;
					Node *nextnode = curr->next;
					
					insertBeforeAfter(prev, curr, nextnode, key, value);
					return;
				}
				l1 = l1->next;
			}
			
			cout<<"\n\nKey not Found!!!\n\n";
		}
		
		void insertBeforeAfter(Node *prev, Node *curr, Node *nextnode, int key, int val){
			
			if(curr->data==key){
				
				Node *n1 = new Node(val);
				
				if(prev==NULL){
					
					prev = n1;
					n1->next = curr;
					head = prev;
					
				}else{
					
					prev->next = n1;
					n1->next = curr;
					
				}
				
				Node *n2 = new Node(val);
				curr->next = n2;
				n2->next = nextnode;
				
				return;
			}
			
			insertBeforeAfter(curr, nextnode, nextnode->next, key, val);
		}
		
		void attachEnd(LinkedList la, LinkedList lb){
			Node *l1 = la.head;
			Node *l2 = lb.head;
			
			while(l1->next!=NULL)
				l1 = l1->next;
			
			while(l2!=NULL){
				l1->next = l2;
				l2 = l2->next;
				l1 = l1->next;
			}
		}
		
		int findMedian(){
			Node *l1 = head;
			int track = 0;
			int count = 0;
			
			while(l1!=NULL){
				l1 = l1->next;
				track++;
			}
			
			Node *r = head;
			Node *p = NULL;
			if(track%2!=0){
				while(count!=track/2){
					count++;
					r = r->next;
				}
				return r->data;
			}else{
				while(count!=track/2){
					p = r;
					count++;
					r = r->next;
				}
				return (p->data+r->data)/2;
			}
		}
};

int main(){
	LinkedList ll;
	LinkedList lb;
	ll.insert(10);
	ll.insert(20);
	ll.insert(30);
	ll.insert(40);
	ll.insert(50);
	
	ll.display();
	
	ll.reverse();
	ll.display();
	
	ll.reverse();
	ll.passList(10, 100);
	ll.display();
	
	ll.passList(20, 200);
	ll.display();
	
	ll.reverse();
	ll.display();
	
	lb.insert(60);
	lb.insert(70);
	lb.insert(80);
	
	ll.attachEnd(ll, lb);
	ll.display();
	
	cout<<"\n\nThe Median is : "<<ll.findMedian()<<endl;
	
	cout<<"\n\nThe Median is : "<<lb.findMedian()<<endl;
	
	
}