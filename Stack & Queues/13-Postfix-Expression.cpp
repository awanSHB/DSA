#include<iostream>
using namespace std;

struct Stack{
	int top;
	int size;
	int *A;
	
	Stack(int s){
		top = 0;
		size = s;
		A = new int[size];
	}
	
	void push(int d){
		A[top++] = d;
		size++;
	}
	int peek(){
		return A[top-1];
	}
	
	void pop(){
		top--;
	}
};

int pow(int base, int exponent){
	int r = 1;
	for(int i=0; i<exponent; i++)
		r*=base;
	return r;
}


int postFix(string exp){
	
	Stack s(exp.length());
	for(char&c: exp){
		
		if(isdigit(c))
			s.push(c-'0');
		else{
			
			int b = s.peek();
			s.pop();
			int a = s.peek();
			s.pop();
			
			switch(c){
				
				case '+':
					s.push(a+b);
					break;
				case '-':
					s.push(a-b);
					break;
				case '*':
					s.push(a*b);
					break;
				case '/':
					s.push(a/b);
					break;
				case '^':
					s.push(pow(a,b));
					break;
					
			}
		}
	}
	return s.peek();
}

int main(){
	string s = "((3_4)*2)/7";
	cout<<"\nThe postfix Expression of "<<s<<" is ---->  "<<postFix(s);
}