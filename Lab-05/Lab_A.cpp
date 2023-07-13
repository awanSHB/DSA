#include<iostream>
using namespace std;

template <class T>
class Queue{
	public:
		int size;
		int front;
		int rear;
		T *A;
		
		Queue(){
			size = 10;
			front = rear = 0;
			A = new T[size];
		}
		Queue(int s){
			size = s;
			front = rear = 0;
			A = new T[size];
		}
		
		bool isEmpty(){
			return (rear=0);
		}
		bool isFull(){
			return rear==size;
		}
		
		void enqueu(T v){
			if(!isFull())
				A[rear++] = v;
			else
				cout<<"\nThe Queue is Full\n";
		}
		T deque(){
			if(!isFull())
				return A[front--];
		}
		
		void display(){
			cout<<"\n\t\t\t[ ";
			for(int i=0; i<rear; i++){
				cout<<A[i]<<" | ";
			}
			cout<<"\b\b]";
		}
};

int main(){
	Queue<int> q;
	Queue<char> q1(10);
	Queue<string> q2(15);
	
	q.enqueu(10);
	q.enqueu(20);
	q.enqueu(30);
	q.enqueu(40);
	q.display();
	
	q1.enqueu('a');
	q1.enqueu('b');
	q1.enqueu('c');
	q1.display();
	
	q2.enqueu("Hello");
	q2.enqueu("My");
	q2.enqueu("is");
	q2.enqueu("Sohaib");
	q2.display();
}