#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int top;
		int size;
		string *x;
	public:
		Stack(int s){
			top = 0;
			size = s;
			x = new string[size];
		}
		bool isEmpty(){
			return (top==0);
		}
		bool isFull(){
			return (top==size);
		}
		
		void push(string v){
			if(!isFull())
				x[top++] = v;
		}
		
		void pop(){
			if(!isEmpty())
				top--;
		}
		
		string peek(){
			if(!isEmpty())
				return x[top-1];
			else
				return "";
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
//	string k = "ab*c+";
	string k = "sa-2^sb-2^sc-2^++13/^3/s*";
	Stack s1(k.length());
	for(int i=0; i<k.length(); i++)
	{
		if(isOperator(k[i]))
		{
			string op2 = s1.peek();
			s1.pop();
			string op1 = s1.peek();
			s1.pop();
			s1.push("("+op1+k[i]+op2+")");
		}
		else
		{
			string op(1, k[i]);
			s1.push(op);
		}
	}
	cout<<"Infix is----- "<<s1.peek()<<"\n";
}