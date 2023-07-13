#include<iostream>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node *next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(T d){
			data = d;
			next = NULL;
		}
};

template <class T>
class LinkedList{
	public:
		Node<T> *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void display(){
			Node<T> *last = head;
			
			cout<<"\n\nhead\n | \n";
			while(last!=NULL){
				cout<<"["<<last->data<<"] --> ";
				last = last->next;
			}
			cout<<"NULL\n";
		}
		
		void show(Node<T> *n){
			if(n==NULL)
				return;
			cout<<"["<<n->data<<"] --> ";
			show(n->next);
		}
		
		void add(T v){
			Node<T> *n = new Node<T>(v);
			if(head==NULL){
				head = n;
				return;
			}
			Node<T> *d = head;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void joinRemove(LinkedList<T> la, LinkedList<int> lb, LinkedList<int> lc){
			
			if(la.head == NULL || (lb.head==NULL && lc.head==NULL))
				return;
			
			Node<T> *prev = NULL;
			Node<T> *l1 = la.head;
			Node<int> *l2 = lb.head;
			Node<int> *l3 = lc.head;
			
			int track = 1;
			
			while(l1!=NULL && (l2!=NULL || l3!=NULL)){
				if(track==l2->data){
					if(l2->data == l3->data){
						l3 = l3->next;
					}
					Node<T> *rand = l1;
					prev->next = l1->next;
					l1 = l1->next;
					delete rand;
					l2 = l2->next;
					track+=1;
				}else if(track==l3->data){
					
					if(l3->data==l2->data){
						l2 = l2->next;
					}
					Node<T> *rand = l1;
					prev->next = l1->next;
					l1 = l1->next;
					delete rand;
					l3 = l3->next;
					track+=1;	
				}else{
					prev = l1;
					l1 = l1->next;
					track++;
					cout<<"\nprev--"<<prev->data;
					cout<<"\nl1------"<<l1->data;
				}
			}
		}
};

int main(){
	LinkedList<char> l1;
	LinkedList<int> l2;
	LinkedList<int> l3;
	
	l1.add('A');
	l1.add('B');
	l1.add('C');
	l1.add('D');
	l1.add('E');
	
	l1.display();

	l2.add(2);
	l2.add(6);
	l2.add(8);
	
	l2.display();
	
	l3.add(3);
	l3.add(5);
	
	l3.display();
	
	l1.joinRemove(l1, l2, l3);
	l1.display();
}

















