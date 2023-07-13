#include<iostream>
#include<queue>
using namespace std;

template <class T>
struct Stack{
	queue<T> q1;
	queue<T> q2;
	
	void push(T v){
		q1.push(v);
	}
	
	void pop(){
		while(!q1.empty()){
			T k = q1.front();
			q1.pop();
			if(!q1.empty())
				q2.push(k);
		}
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
	}
	
	int peek(){
		T k = 0;
		while(!q1.empty()){
			k = q1.front();
			q1.pop();
			q2.push(k);
		}
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		cout<<"\n\nThe Top Element is : ";
		return k;
	}
	
	void show(){
		cout<<"\n\n";
		queue<int> tq = q1;
		display(tq);
	}
	
	void display(queue<int> &q){
		if(q.empty())
			return;
		int k = q.front();
		q.pop();
		display(q);
		cout<<"\t\t|_"<<k<<"_|\n";
	}
	
};

int main(){
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.show();
	
	s.pop();
	s.show();
	
	cout<<s.peek();
	
}