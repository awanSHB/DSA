#include<iostream>
#include<stack>
using namespace std;

template <class T>
struct Queue{
	stack<T> s1;
	stack<T> s2;
	
	void enque(T v){
		s1.push(v);
	}
	
	void deque(){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	
	T getFront(){
		T k;
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		k = s2.top();
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		
		cout<<"\n\nThe Front element is : ";
		return k;
	}
	
	void show(){
		cout<<"\n\n";
		stack<T> st = s1;
		display(s1);
		cout<<"\n";
	}
	
	void display(stack<T> s){
		if(s.empty())
			return;
		int k = s.top();
		s.pop();
		display(s);
		cout<<"[ "<<k<<" ]";
	}
};

int main(){
	Queue<int> q;
	q.enque(10);
	q.enque(20);
	q.enque(30);
	q.enque(40);
	q.enque(50);
	q.show();
	
	cout<<q.getFront();
	
	q.deque();
	q.show();
	
	cout<<q.getFront();
}