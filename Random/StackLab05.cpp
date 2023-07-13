#include <iostream>
using namespace std;

class Node{
	public:
		char data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(char v){
			data = v;
			next = NULL;
		}
};

class NodeI{
	public:
		int data;
		NodeI *next;
		NodeI(){
			data = 0;
			next = NULL;
		}
		NodeI(int v){
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
		void display(){
			Node *a = head;
			cout<<"\n\n\n";
			while(a!=NULL){
				cout<<"["<<a->data<<"]"<<" --> ";
				a = a->next;
			}
			cout<<"NULL";
		}
		
		void start(char v){
			Node *n = new Node(v);
			n->next = head;
			head = n;
		}
		
		char getTop(){
			if(head!=NULL){
				Node *l = head;
				head = head->next;
				return l->data;
			}		
		}
		
		void pop(){
			if(head!=NULL){
				Node *n = head;
				head = head->next;
			}
				
		}
};

class Stack{
	private:
		int top;
		int full;
		LinkedList ll;
		char V[];
	public:
		Stack(){
			top = 0;
		}
		Stack(int vals){
			top = 0;
			full = vals;
			V[vals];
		}
		
		bool isEmpty(){
			return (top==0);
		}
		
		bool isFull(){
			return (top==full);
		}
		
	void Insert(char v){
		ll.start(v);
	}
	
	char Top(){
		ll.getTop();
	}
	
	void show(){
		ll.display();
	}
	void push(char v){
		if(!isFull())
			V[top++] = v;
	}
	
	void pop(){
		if(!isEmpty())
			V[top--];
	}
	
	char peek(){
		return (!isEmpty())? V[top-1]: 3;
	}
	
	void display(){
		cout<<"\n\n\n";
		while(!isEmpty()){
			cout<<"\t\t\t\t|_"<<peek()<<"_|"<<endl;
			pop();
		}
	}
};


char priority(char c){
	if (c=='[')
		return 2;
	else if(c=='{')
		return 1;
	else if(c=='(')
		return 0;
}

bool isOperator(char c){
	if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-')
		return true;
	else
		return false;
}

void InfixToPrefix(string st){
	int A;
	int B;
	char ch;
	int res;
	Stack s;
	
	for(int i=0; i<st.length(); i++){
		ch = st[i];
		if(ch=='(')
			s.Insert(ch);
		else if(ch==')'){
			while(s.Top()!='('){
				if(isOperator(ch)){
					A = s.Top();
					B = s.Top();
					switch(ch){
						case '/':
							res = B/A;
							break;
						case '*':
							res = B*A;
							break;
						case '+':
							res = B+A;
							break;
						case '-':
							res = B-A;
							break;
					}
					s.Insert(ch);
				}
				
				
			}
		}
			
	}
}

//Method to check for the balanced paranthesis
bool isBalanced(string e){
	int ll = e.length();
	Stack *s = new Stack(ll);	//Creating a stack variable and calling parameterized constructor
	char ch;
	for(int i=0; i<ll; i++){
		if(e[i]=='(' || e[i]=='{' || e[i]=='['){
			if(priority(s->peek()) >= priority(e[i])){
				s->push(e[i]);
				continue;
			}
		}
		if(s->isEmpty())
			return false;
			switch(e[i]){
				case ')':
					ch = s->peek();
					s->display();
					s->pop();
					if(ch=='{' || ch=='[')
						return false;
						break;
				
				case '}':
					ch = s->peek();
					s->display();
					s->pop();
					if(ch=='('  || ch=='[')
						return false;
						break;
				
				case ']':
					ch = s->peek();
					s->display();
					s->pop();
					if(ch=='(' || ch=='{')
						return false;
						break;
				
			}
		return (s->isEmpty());
	}
}




int main(){
	Stack s;
	int noofchars;
	string exp;
	char ch;
	
	cout<<"Enter the number of characters you want to Enter: ";
	cin>>noofchars;
	Stack *s1 =  new Stack(noofchars);	
	cout<<"\n\n";
	
	for(int i=1; i<=noofchars; i++){
		cout<<"Enter the char no "<<i<<": ";
		cin>>ch;
		s1->push(ch);
	}
	cout<<"\n\nThe Top/Head values of Stack is: "<<s1->peek();
	s1->display();


//--For LinkedList----------------------------------------------
	cout<<"\\n\nEnter the Number of characters for LinkedList: ";
	cin>>noofchars;
	for(int i=1; i<=noofchars; i++){
		cout<<"Enter the char "<<i<<" : ";
		cin>>ch;
		s.Insert(ch);
	}
	s.show();
	cout<<"\n\nThe top char is "<<s.Top()<<"\n\n";
	cout<<"\n\n\n";
	
	
//--For Checking Balanced---------	
	cout<<"Enter the expression: ";
	cin>>exp;
	if (isBalanced(exp))
		cout<<"Balanced";
	else
		cout<<"Not balanced";
	cout<<"\n\n\n\n";
	
	
//--For Converting string------
	cout<<"Enter the string : ";
	
	char str[] = "I love Programming";
	int len = strlen(str);
	Stack *s2 = new Stack(len);
	for(int i=0; i<len; i++)
		s2->push(str[i]);
	s2->display();
	cout<<"\n\n\n";
}