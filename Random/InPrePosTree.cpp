#include <iostream>
using namespace std;

class TNode{
	public:
		char data;
		TNode *left;
		TNode *right;
		TNode(char v){
			data = v;
			left = right = NULL;
		}
};

//Here we are creating a dynamic node type stack
class Stack{
	public:
		TNode *treenode;
		Stack *next;
		Stack (TNode *treenode){
			this->treenode = treenode;
			next = NULL;
		}
};

class ExpressionTree{
	private:
		Stack *top;
	public:
		ExpressionTree(){
			top = NULL;
		}
		
		void push(TNode *nd){
			if(top==NULL){
				top = new Stack(nd);
			}else{
				Stack *n = new Stack(nd);
				n->next = top;
				top = n;
			}
		}
		
		TNode* pop(){
			TNode *p = top->treenode;
			top = top->next;
			return p;
		}
		
		TNode* peek(){
			return top->treenode;
		}
		
		void insert(char c){
			if(isOperand(c)){
				TNode *n = new TNode(c);
				push(n);
			}
			else if(isOperator(c)){
				TNode *n = new TNode(c);
				n->left = pop();
				n->right= pop();
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
//			cout<<"h";
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
	ExpressionTree t;
	string s;
	cout<<"Enter The Expression in Prefix Form  :  ";
	cin>>s;
	t.constructTree(s);
	cout<<"\nExpression is  :  "<<s<<"\n\n";
	t.infix();
	t.postfix();
	t.prefix();
}