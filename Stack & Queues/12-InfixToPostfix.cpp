#include<iostream>
using namespace std;

template <class T>
struct Stack{
	int top;
	int s;
	T *A;
	
	Stack(int size){
		top = 0;
		s = size;
		A = new T[s];
	}
	
	bool isEmpty(){
		return top==0;
	}
	bool isFull(){
		return top==s;
	}
	
	void push(T v){
		if(!isFull())
			A[top++] = v;
	}
	
	void pop(){
		if(!isEmpty())
			top--;
	}
	
	T peek(){
		if(!isEmpty())
			return A[top-1];
	}
};


bool isOperator(char c){
	if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-')
		return true;
	else
		return false;
}

int priority(char c){
	if(c=='^')
		return 2;
	else if(c=='/' || c=='*')
		return 1;
	else
		return 0;
}

void toPostfix(string exp){
	Stack<char> s(exp.length());
	string prefix;
	char ch;
	
	for(int i=0; i<exp.length(); i++){
		ch = exp[i];
		if(ch=='(')
			s.push(ch);
		else if(ch==')'){
			while(s.peek()!='('){
				prefix+=s.peek();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(ch)){
			
			if(s.isEmpty() || s.peek()=='(')
				s.push(ch);
			else if(priority(s.peek()) < priority(ch)){
				s.push(ch);
			}
			else{
				prefix+=s.peek();
				s.pop();
				s.push(ch);
			}
		}else
			prefix+=ch;
	}
	prefix+=s.peek();
	s.pop();
	
	cout<<"The Infix Expression is  : "<<exp<<endl;
	cout<<"The Postfix Expression is: "<<prefix<<endl;
}

int main(){
	string s = "m*n+(p-q)+r";
	toPostfix(s);
}