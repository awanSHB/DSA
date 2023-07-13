#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int top;
		int size;
		char *x;
	public:
		Stack(int s){
			top = 0;
			size = s;
			x = new char[size];
		}
		bool isEmpty(){
			return (top==0);
		}
		bool isFull(){
			return (top==size);
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
	char pr[] = "b^2-4*a*c";
//	char pr[] = "a*(b+c)";
//	char pr[] = "(((s-a)^2+(s-b)^2+(s-c)^2)^1/3)/3*s";
//	char pr[] = "(x^3+3*(x^2))/(2*x+9)";
//	char pr[] = "a/b*(x^2)-x/d+k";
//	char pr[] = "(((s-a)^2+(s-b)^2+(s-c)^2)^(1/3))/3*s";
//	char pr[] = "((((((s-a)^2)+(((s-b)^2)+((s-c)^2)))^(1/3))/3)*s)";
	string postfix = "";
	Stack s(sizeof(pr));
	
	for(int i=0; i<sizeof(pr); i++){
		ch = pr[i];
		if(ch=='(')
			s.push(ch);
		else if(ch==')'){
			while(s.peek()!='('){
				postfix += s.peek();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(ch)){
			if(s.isEmpty() || s.peek()=='(')
				s.push(ch);
			else if(priority(ch) > priority(s.peek()))
				s.push(ch);
			else{
				postfix+=s.peek();
				s.pop();
				s.push(ch);
			}
		}else
			postfix += ch;
	}
	
	while(!s.isEmpty()){
		postfix += s.peek();
		s.pop();
	}
	
	cout <<"The Infix is  ===> "<<pr<<endl;
	cout <<"The postfix is ==> "<<postfix<<"\n\n\n";
	
}