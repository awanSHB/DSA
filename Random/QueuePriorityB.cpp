#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Element{
	public:
		
		int data;
		int priority;
		
		Element(){
			data = priority = 0;
		}
		
		Element(int d, int p){
			data = d;
			priority = p;
		}
};

class PQ{
	private:
		
		Element *A[10];
		int rear;
		
	public:
		
		PQ(){
			rear = 0;
		}
		
		void enqueue(int v, int p){
			Element *e = new Element(v, p);
			Element *a;
			int i=0;
			if(rear==0)
				A[rear++] = e;
			else if(e->priority <= A[rear-1]->priority)
				A[rear++] = e;
			else{
//				for (int i=0; i<rear; i++){
//					if(e->priority > A[i]->priority){
//						a = e;
//						e = A[i];
//						A[i] = a;
//					}	
//				}
//				A[rear++] = e;
				for(i=rear-1; i>=0; i--){
					if(e->priority > A[i]->priority){
						A[i+1] = A[i];
					}else{
						break;
					}
				}
				A[i+1] = e;
				rear++;
			}
		}
		
		void display(){
			cout<<"\n\t\tData===>\t";
			for(int i=0; i<rear; i++)
				cout<<"[ "<<A[i]->data<<" ]";
			cout<<"\n\t\tPriority==>\t ";
			for(int i=0; i<rear; i++)
				cout<<A[i]->priority<<"    ";
		}
};

int main(){
	PQ p;
	
	p.enqueue(99, 10);
	p.enqueue(50, 8);
	p.enqueue(30, 5);
	p.enqueue(20, 30);
	p.enqueue(70, 40);
	p.enqueue(80, 4);
	p.enqueue(90, 50);
//	p.enqueue(2000, 3);
	p.enqueue(2, 101);
	p.enqueue(34, 35);
	p.enqueue(98, 9);
	p.display();
}
		

