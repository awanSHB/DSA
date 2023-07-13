#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack{
	private:
		int top;
		string x;
	public:
		Stack(){
			top = 0;
		}
		
		bool isEmpty(){
			return (top==0);
		}
		bool isFull(){
			return (top==15);
		}
		
		void push(char v){
			if(!isFull())
				x[top++] = v;		
		}
		
		void pop(){
			if(!isEmpty())
				top--;
		}
		
		char peek(){
			if(!isEmpty())
				return x[top-1];
			else
				return -1;
		}
};


int priority(char c){
	if(c=='^')
		return 2;
	else if(c=='*' || c=='/')
		return 1;
	else 
		return 0;
}

bool isOperator(char c){
	if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-')
		return true;
	else
		return false;
}

int main(){
	char ch;
	Stack s;
//	string x = "b^2-4*a*c";
	string x = "(a-b/c)*(a/k-l)";
	string postfix = "";
	
	for(int i=0; i<15; i++){
		ch = x[i];
		if(ch=='(')
			s.push(ch);
		else if(ch==')'){
			while(s.peek()!='('){
				postfix = postfix + s.peek();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(ch)){
			if(s.isEmpty() || s.peek()=='(')
				s.push(ch);
			else if(priority(s.peek()) < priority(ch)){
				s.push(ch);
			}else{
				postfix += s.peek();
				s.pop();
				s.push(ch);
			}
	 	}else
			postfix = postfix + ch;
	}
	
	while(!s.isEmpty()){
		postfix += s.peek();
		s.pop();
	}
	
	cout<<"The Infix is   ==>   "<<x<<"\n\n";
	cout<<"The postfix is ==>   "<<postfix;
}