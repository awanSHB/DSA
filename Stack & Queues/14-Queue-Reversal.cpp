#include<iostream>
#include<stack>
#include<deque>
using namespace std;

template <class T>
struct Queue{
	int rear;
	int s;
	T *A;
	
	Queue(int size){
		rear = 0;
		s = size;
		A = new T[s];
	}
	
	bool isEmpty(){
		return rear==0;
	}
	bool isFull(){
		return rear==s;
	}
	
	void enqueue(T v){
		if(!isFull())
			A[rear++] = v;
	}
	void dequeue(){
		if(!isEmpty()){
			for(int i=0; i<rear; i++)
				A[i] = A[i+1];
			rear--;
		}	
	}
	T getFront(){
		if(!isEmpty())
			return A[0];
	}
	
	void display(){
		cout<<"\n\t\t[ ";
		for(int i=0; i<rear; i++)
			cout<<A[i]<<" | ";
		cout<<"\b\b]\n\n";
	}
};

// 1--> Reverse using a stack
void reverse1(Queue<int> q){
	stack<int> s;
	while(!q.isEmpty()){
		s.push(q.getFront());
		q.dequeue();
	}
	while(!s.empty()){
		q.enqueue(s.top());
		s.pop();
	}
	q.display();
}

// 2--> Reverse using a recursion
void reverse2(Queue<int> q, int t){
	if(q.isEmpty()){
		return;
	}
	int k = q.getFront();
	q.dequeue();
	reverse2(q, t);
	q.enqueue(k);
	if(k==t)
		q.display();
}

// 3--> Revese using two additional queues
void reverse3(Queue<int> q){
	Queue<int> q1(10);
	Queue<int> q2(10);
	
	while(!q.isEmpty()){
		if(q1.isEmpty()){
			q1.enqueue(q.getFront());
			q.dequeue();
		}else{
			while(!q1.isEmpty()){
				q2.enqueue(q1.getFront());
				q1.dequeue();
			}
			q1.enqueue(q.getFront());
			q.dequeue();
			while(!q2.isEmpty()){
				q1.enqueue(q2.getFront());
				q2.dequeue();
			}
		}
	}
	while(!q1.isEmpty()){
		q.enqueue(q1.getFront());
		q1.dequeue();
	}
	q.display();
}

// 4--> Using the deque (variable front)
void reverse4(Queue<int> q){
	deque<int> dq;
	while(!q.isEmpty()){
		dq.push_back(q.getFront());
		q.dequeue();
	}
	while(!dq.empty()){
		q.enqueue(dq.back());
		dq.pop_back();
	}
	q.display();
}


// Reverse the k elements in the queue
void reverseK(Queue<int> q, int k){
	stack<int> s;
	while(k-- > 0){
		s.push(q.getFront());
		q.dequeue();
	}
	int t = s.top();
	
	while(!s.empty()){
		q.enqueue(s.top());
		s.pop();
	}
	
	while(q.getFront()!=t){
		q.enqueue(q.getFront());
		q.dequeue();
	}	
	q.display();
}

// Reversing queue second method
int size(Queue<int> q){
	int f = q.getFront();
	q.dequeue();
	q.enqueue(f);
	int k = 1;
	
	while(q.getFront()!=f){
		q.enqueue(q.getFront());
		q.dequeue();
		k++;
	}
	return k;
}

void reverseQ(Queue<int> q, int k){
	if(k==0){
		return;
	}
	int A = q.getFront();
	q.dequeue();
	reverseQ(q, k-1);
	q.enqueue(A);
}

void reverseK2(Queue<int> q, int k){
	reverseQ(q, k);
	int s = size(q)-k;
	while(s-- > 0){
		q.enqueue(q.getFront());
		q.dequeue();
	}
	q.display();
}


int main(){
	Queue<int> q(10);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	
	reverse1(q); 					//Reverse Using Stack
	
	reverse2(q, q.getFront());		//Reverse Using Stack
	
	reverse3(q);					//Reverse Using additional Two Queues
	
	reverse4(q);					//Reverse Using Deque
	
	reverseK(q, 3);					//Reversing first k elements 1st method
	reverseK(q, 3);
	
	reverseK2(q, 3);				//Reversing the first k elements 2nd methods
	
}