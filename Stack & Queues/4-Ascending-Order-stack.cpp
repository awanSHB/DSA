#include<iostream>
#include<stack>
using namespace std;

class Stack{
	public:
		int top;
		int *A;
		int size;
	public:
		Stack(int s){
			size = s;
			top = 0;
			A = new int[size];
		}
	
	bool isEmpty(){
		return top==0;
	}
	bool isFull(){
		return top==size;
	}
	
	void push(int v){
		if(!isFull())
			A[top++] = v;
	}
	
	void pop(){
		if (!isEmpty())
			top--;
	}
	
	int peek(){
		if(!isEmpty()){
			return A[top-1];
		}else
			return int();
	}
	
	void display(){
		if(!isEmpty()){
			cout<<"\n\n";
			for(int i=top-1; i>=0; i--)
				cout<<"\t\t|_"<<A[i]<<"_|\n";
		}else
			cout<<"\n\n\t\t\tStack is Empty!!!\n\n";
	}
};

class Stk{
	public:
		Stack s1{8};
		stack<int> s2;
		
		void insert(int v){
			
			if(s1.isEmpty() || s1.peek() < v){
				s1.push(v);
				return;
			}
			while(!s1.isEmpty() && s1.peek() > v){
				s2.push(s1.peek());
				s1.pop();
			}
			s1.push(v);
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
		}
	
};


int main(){
	Stk s;
	int value = -1;
	
	while(value!=0){
		cout<<"\nEnter the Value: ";
		cin>>value;
		if(value==0)
			break;
		s.insert(value);
	}
	s.s1.display();
}








