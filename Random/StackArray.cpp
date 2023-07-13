#include<bits/stdc++.h>
using namespace std;


class Stack{
	private:
		int A[5];
		int top;
	public:
		Stack(){
			top = 0;
		}
		
		bool isEmpty(){
			return (top==0);
		}
		bool isFull(){
			return (top==5);
		}
		
	void push(int v){
		if(!isFull())
			A[top++] = v;
	}
	
	void pop(){
		if(!isEmpty())
			top--;
	}
	
	int peek(){
		if(!isEmpty())
			return A[top-1];
		else
			return -1;
	}
	
//	void display(){
//		cout << "\n\n";
//		int i = 0;
//		while(!isEmpty()){
//			cout<<"\t\t\t\t| "<<"  |"<<endl;
//			cout<<"\t\t\t\t|_"<<peek()<<"_|"<<endl;
//			pop();
//		}
//		cout<<"\n\n";
//	}
	
};

int main(){
	Stack s;
	int vals;
	int v;
	
	for(int i=0; i<5; i++){
		cout<<"Enter the value no  "<<(i+1)<<" : ";
		cin>>v;
		s.push(v);
	}
	
	
	cout<<"\n\nThe Top/Head value is: "<<s.peek();
	
	
	cout << "\n\n";
	int i = 0;
	while(!s.isEmpty()){
		cout<<"\t\t\t\t| "<<"  |"<<endl;
		cout<<"\t\t\t\t|_"<<s.peek()<<"_|"<<endl;
		s.pop();
	}
	cout<<"\n\n";
}