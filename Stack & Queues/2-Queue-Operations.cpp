#include<iostream> 
using namespace std;

template <class T>
class Queue{
	private:
		int s;
		int rear;
		T *A;
	public:
		Queue(int size){
			s = size;
			rear = 0;
			A = new T[s];
		}
		
	bool isEmpty(){
		return rear==0;
	}
	bool isFull(){
		return rear==s;
	}
	
	void enque(T v){
		if(!isFull())
			A[rear++] = v;
	}
	
	T getFront(){
		if(!isEmpty())
			return A[0];
		else
			return T();
	}
	
	void deque(){
		for(int i=0; i<rear; i++)
			A[i] = A[i+1];
		rear--;
	}
	
	void display(){
		int k = 0;
		cout<<"\n\n\t\t[ ";
		while(k!=rear){
			cout<<A[k++]<<" | ";
		}
		cout<<"\b\b]";
	}
	
};

int main(){
	Queue<int>q1(10);
	q1.enque(10);
	q1.enque(20);
	q1.enque(30);
	q1.enque(40);
	q1.enque(50);
	q1.display();
	cout<<"\n\nThe First Element is : "<<q1.getFront();
	
	
	q1.deque();
	q1.display();
	
	cout<<"\n\nThe First Element is : "<<q1.getFront();
	
	Queue<char>q2(5);
	q2.enque('A');
	q2.enque('B');
	q2.enque('C');
	q2.enque('D');
	q2.enque('E');
	q2.display();
	cout<<"\n\nThe First Element is : "<<q2.getFront();
	
	q2.deque();
	q2.display();
	cout<<"\n\nThe First Element is : "<<q2.getFront();
}







