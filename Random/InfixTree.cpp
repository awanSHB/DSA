#include <iostream>
using namespace std;

/*
==================>>>> 4 3 +
|			|
|___________|
|	 +		|
|	/ \		|
|  3   4	|
|___________|



|			|
|___________|
|	|3|		|
|	/ \		|
|NULL  NULL	|
|___________|
|	|4|		|
|	/ \		|
|NULL  NULL	|
|___________|
*/


class TNode {
	public:
		char data;
		TNode *left;
		TNode *right;
		TNode(char v){
			data = v;
			left = right = NULL;
		}
};

//This is a dynamic stack of node Type
class Stack{
	public:
	TNode *node;
	Stack *next;
	Stack(TNode *ne){
		node = ne;
		next = NULL;
	}	
};

class StackExpression{
	private:
		Stack *top;
	public:
		StackExpressionExpression(){
			top = NULL;
		}
		
		void push(TNode *d){
			Stack *n = new Stack(d);
			if(top==NULL){
				top = n;
			}else{
				n->next = top;
				top = n;
			}
		}
		
		TNode *pop(){
			TNode *n = top->node;
			top = top->next;
			return n;
		}
		
		TNode *peek(){
			return top->node;
		}
		
		void insert(char c){
			if(isOperand(c)){
				TNode *n = new TNode(c);
				push(n);
			}
			else if(isOperator(c)){
				TNode *n = new TNode(c);
				n->left = pop();
				n->right = pop();
				push(n);
			}
		}
		
		bool isOperand(char ch){
			return ch>='0' && ch<='9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
		}
		bool isOperator(char ch){
			return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
		}
		
		void constructTree(string s){
			for(int i = s.length()-1; i>=0; i--)
				insert(s[i]);
		}
		
		void infix(){
			cout<<"InFix:\n";
			inOrder(peek());
			cout<<"\n\n";
		}
		
		void inOrder(TNode *r){
			if(r==NULL)
				return;
			inOrder(r->left);
			cout<<r->data<<"  ";
			inOrder(r->right);
		}
		
		void postfix(){
			cout<<"PostFix:\n";
			postOrder(peek());
			cout<<"\n\n";
		}
		void postOrder(TNode *r){
			if(r==NULL)
				return;
			postOrder(r->left);
			postOrder(r->right);
			cout<<r->data<<"  ";
		}
		
		void prefix(){
			cout<<"PreFix:\n";
			preOrder(peek());
			cout<<"\n\n";
		}
		void preOrder(TNode *r){
			if(r==NULL)
				return;
			cout<<r->data<<"  ";
			preOrder(r->left);
			preOrder(r->right);
		}
};

int main(){
	StackExpression s;
	string st;
	cout<<"Enter the expression in Prefix form  :  ";
	cin>>st;
	s.constructTree(st);
	cout<<"\nPrefix Expression Is  :  "<<st<<"\n\n";
	s.infix();
	s.prefix();
	s.postfix();
}