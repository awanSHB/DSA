#include<iostream>
using namespace std;

class Node{
	public:
		char data;
		Node *next;
		Node(){
			data = NULL;
			next = NULL;
		}
		Node(char v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	private:
		Node *head;
	public:
		LinkedList(){
			head = NULL;
		}
		
	bool isEmpty(){
		return head==NULL;
	}
	
	void insert(char v){
		Node *n = new Node(v);
		if(head==NULL){
			head = n;
			return;
		}
		n->next = head;
		head=n;
	}
	
	void removeHead(){
		Node *dl = head;
		head = head->next;
		delete dl;
	}
	
	char getHead(){
		return head->data;
	}
};

class Stack{
	public:
		LinkedList l;
	
	bool isEmpty(){
		return l.isEmpty();
	}
	
	void push(char v){
		l.insert(v);
	}
	void pop(){
		if(!l.isEmpty())
			l.removeHead();
	}
	char peek(){
		if(!l.isEmpty())
			l.getHead();
	}
};

bool isOperator(char c){
	return (c=='^' || c=='/' || c=='*' || c=='+' || c=='-')? true : false;
}
int priority(char c){
	return (c=='^')? 2 : (c=='/' || c=='*')? 1: 0;
}

void toPostfix(string exp){
	char c;
	string postfix;
	Stack s;
	
	for(int i=0; i<exp.length(); i++){
		c = exp[i];
		if(c=='(')
			s.push(c);
		else if(c==')'){
			while(s.peek()!='('){
				postfix+=s.peek();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(c)){
			if(s.isEmpty() || s.peek()=='(')
				s.push(c);
			else if(priority(c) > priority(s.peek()))
				s.push(c);
			else{
				postfix+=s.peek();
				s.pop();
				s.push(c);
			}
		}
		else
			postfix+=c;
	}
	while(!s.isEmpty()){
		postfix+=s.peek();
		s.pop();
	}
		
	
	cout<<"\nThe Infix Expression is   :  "<<exp<<"\nThe postfix Expression is :  "<<postfix<<endl;
}

int main(){
	string s = "a+b*(c-d)/e";
	toPostfix(s);
}