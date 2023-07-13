 #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack{
	private:
		int top;
		int count;
		int *A;
	public:
		Stack(){
			top = -1;
			count = 20;
			A = new int[count];
		}
		Stack(int s){
			top = -1;
			count = s;
			A = new int[count];
		}
		
		bool isEmpty(){
			return (top==-1);
		}
		bool isFull(){
			return (top==count);
		}
	
	void push(int c){
		if(!isFull())
			A[++top] = c;
	}
	
	void pop(){
		if(!isEmpty())
			top--;
	}
	
	int getTop(){
		if(!isEmpty())
			return A[--top];
		return A[top];
	}
	
	
	int peek(){
		if(!isEmpty()){
			return A[top--];
//			top--;
		}
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
	Stack s;
	int c;
//	string A = "23*54*+9-";        // 17
//	string A = "12345*+*+";		   // 47
//	string A = "23*5/4*+9-";
	string A = "82+3*164/-";
//	string A = "701445153/*--/6+";

	for(int i=0; i<A.length(); i++){
		int op1 = 0;
		int op2 = 0;
		c = int(A[i]);
		if(A.at(i) >= '0' && A.at(i) <= '9'){
			s.push(A[i]-'0');
			cout<<A[i]<<endl;
		}
		else if(isOperator(A[i])){
			op2 = s.peek();
			op1 = s.peek();
			cout<<"op2--"<<op2<<endl;
			cout<<"op1--"<<op1<<endl;
			cout<<"operation"<<A[i]<<endl;
			switch(A.at(i)){
				case '+':
					s.push(op1+op2);
					cout<<"res---"<<op1+op2<<endl;
					break;
				case '-':
					s.push(op1-op2);
					cout<<"res---"<<op1-op2<<endl;
					break;
				case '*':
					s.push(op1*op2);
					cout<<"res---"<<op1*op2<<endl;
					break;
				case '/':
					s.push(op1/op2);
					cout<<"res---"<<op1/op2<<endl;
					break;
				case '^':
					s.push(pow(op1, op2));
					cout<<"res---"<<pow(op1,op2)<<endl;
					break;
				default:
					break;
			}
		}
		
	}
	
	cout<<"h----------------"<<s.getTop()<<endl;
	
}