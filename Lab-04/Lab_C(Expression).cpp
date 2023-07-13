#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int v){
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
	
	void insert(int v){
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
	
	int getHead(){
		return head->data;
	}
};

class Stack{
	public:
		LinkedList l;
	
	bool isEmpty(){
		return l.isEmpty();
	}
	
	void push(int v){
		l.insert(v);
	}
	void pop(){
		if(!l.isEmpty())
			l.removeHead();
	}
	int peek(){
		if(!l.isEmpty())
			return l.getHead();
		else
			return -1;
	}
};

int power(int b, int e){
	int p = 1;
	for(int i=1; i<=e; i++)
		p*=b;
	return p;
}

int evaluateExpression(string exp){
	Stack s;
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
					if(b!=0)
						s.push(int(a/b));
					break;
				case '^':
					s.push(power(a, b));
					break;
			}
		}
	}
	return s.peek();
}

int main(){
	string e = "235*+";
	cout<<"The PostFix Expression of "<< e <<" is "<<evaluateExpression(e);
}