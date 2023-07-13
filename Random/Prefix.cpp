#include <bits/stdc++.h>
#include <iostream>
#include <typeinfo>
using namespace std;

class Stack{
	private:
		int top;
		int size;
		char *Ar;
	
	public:
		Stack(){
			top = 0;
			size = 8;
			Ar = new char[size];
		}
		
		Stack(int s){
			top = 0;
			size = s;
			Ar = new char[size];
		}
		bool isEmpty(){
			return (top==0);
		}
		bool isFull(){
			return (top==size);
		}
		
	void push(char c){
		if(!isFull())
			Ar[top++] = c;
	}
	
	void pop(){
		if(!isEmpty())
			top--;
	}
	
	char peek(){
		if(!isEmpty())
			return Ar[top-1];
		else
			return -1;
	}
};

bool isOperator(char c){
	if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-')
		return true;
	else
		return false;
}

int priority(char c){
	return (c=='^')? 2 : (c=='*' || c=='/')? 1 : 0;
//	if(c=='^')
//		return 2;
//	else if(c=='*' || c=='/')
//		return 1;
//	else
//		return 0;
}

int main(){
	int k;
	char ch;
//	char A[] = "(A - B/C) * (A/K-L)";
	char A[] = "(((s-a)^2+(s-b)^2+(s-c)^2)^(1/3))/3*s";
//	char A[] = "a/b*(x^2)-x/d+k";
//	char A[] = "(x^3+3*(x^2))/(2*x+9)";
	Stack s(sizeof(A));
	cout<<typeid(A).name()<<endl;

	string prefix = "";
	string gr = "";
	string pr = "";
	
	for(int i=0; i<sizeof(A); i++){
		gr = A[i] + gr;
	}
	pr = gr;
	for(int i=0; i<sizeof(A); i++){
		if(gr[i]=='(')
			pr[i] = ')';
		if(gr[i]==')')
			pr[i] = '(';
	}
	for(int i=0; i<sizeof(A); i++){
		ch = pr[i];
		if(ch=='(')
			s.push(ch);
		else if(ch==')'){
			while(s.peek()!='('){
				prefix += s.peek();
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
				prefix += s.peek();
				s.pop();
				s.push(ch);
			}
		}else
			prefix += ch;
	}
	
	while(!s.isEmpty()){
		prefix += s.peek();
		s.pop();
	}
	
	string pre = "";
	for(int i=0; i<sizeof(A); i++)
		pre = prefix[i] + pre;
	cout<<pre;
}