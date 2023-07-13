#include<iostream>
using namespace std;

class Nodet{
	public:
		int data;
		Nodet *next;
		
		Nodet(){
			data = 0;
			next = NULL;
		}
		
		Nodet(int v){
			data = v;
			next = NULL;
		}
};

class Nodec{
	public:
		char data;
		Nodec *next;
		
		Nodec(){
			data = 0;
			next = NULL;
		}
		
		Nodec(char v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	public:
		Nodet *headt;
		Nodec *headc;
	public:
		LinkedList(){
			headt=NULL;
			headc=NULL;
		}
		
		void displayt(){
			Nodet *ll = headt;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
		
		void displayc(){
			Nodec *ll = headc;
			cout<<"\nhead\n | \n";
			while(ll!=NULL){
				cout<<"["<<ll->data<<"] --> ";
				ll = ll->next;
			}
			cout<<"NULL\n\n\n";
		}
	
		void addt(int v){
			Nodet *n = new Nodet(v);
			if(headt==NULL){
				headt = n;
				return;
			}
			Nodet *d = headt;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void addc(int v){
			Nodec *n = new Nodec(v);
			if(headc==NULL){
				headc = n;
				return;
			}
			Nodec *d = headc;
			while(d->next!=NULL)
				d = d->next;
			d->next = n;
		}
		
		void joinRemove(LinkedList la, LinkedList lb){
			
			if(la.headc == NULL || lb.headt == NULL){
        		return;
    		}
			Nodec *l1 = la.headc;
			Nodet *l2 = lb.headt;
			Nodec *prev;
//			Nodec *rand;
			int k;
			int m = 1;
			k = l2->data;
			
			while(l1!=NULL){
				if(k==m){
					cout<<"k---"<<k<<endl;
					cout<<"m---"<<m<<endl;
					Nodec *rand = l1;
					prev->next = l1->next;
					prev = l1;
					l1 = l1->next;
					l2 = l2->next;
					k = l2->data;
					delete rand;
					m++;
				}else{
					prev = l1;
					l1 = l1->next;
					m++;
				}
			}
			
			while(l2!=NULL){
				cout<<"The index "<<l2->data<<" Does not exists in LinkedList 1\n";
				l2 = l2->next;
			}
		}
	
};

int main(){
	LinkedList l1;
	LinkedList l2;
	
	l1.addc('A');
	l1.addc('B');
	l1.addc('C');
	l1.addc('D');
	l1.addc('E');
	
	l1.displayc();
	
	l2.addt(2);
	l2.addt(3);
	l2.addt(4);
	
	l2.displayt();
	
	l1.joinRemove(l1, l2);
	l1.displayc();
}