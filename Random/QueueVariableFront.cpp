# include <bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int A[6];
		int rear;
		int front;
	public:
		Queue(){
			rear = 0;
			front = 0;
		}
		
		bool isEmpty(){
			if(front==rear){
				front = rear = 0;
				return true;
			}else
				return false;
		}
		
		bool isFull(){
			return (front==0 && rear==6);
		}
		int getFront(){
			if(!isEmpty())
				return A[front];
			else
				return -1;
//			return (!isEmpty())? A[0] : -1;
		}
		
		void deque(){
			front++;
		}
		
		int enque(int v){
			if(!isFull())
				A[rear++] = v;
		}
		
		void display(){
			cout<<"\t\t\t\t\t| ";
			for(int i=front; i<rear; i++){
				cout<<A[i];
				cout<<" | ";
			}
		}
};

int main(){
	Queue q;
	int no;
	int val;
	
	for(int i=0; i<6; i++){
		cout<<"Enter the value no "<<(i+1)<<" : ";
		cin>>val;
		q.enque(val);
	}
	cout<<"\n\nThe front value is : ";
	cout<<q.getFront();
	cout<<"\n\n";
	
	
	q.display();
	cout<<"\n\n";
	
	
	q.deque();
	q.display();
}