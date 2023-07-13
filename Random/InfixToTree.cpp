#include <iostream>
#include <stack>
using namespace std;

//template <class T>
//class Node{
//	public:
//		int data;
//		Node *daat;
//		Node *next;
//		Node(){
//			data = 0;
//			next = NULL;
//		}	
//		Node(char v){
//			data = v;
//			next = NULL;
//		}
//		Node(Node *n){
//			daat = n;
//			next = NULL;
//		}
//};

//template <class T>
class TNode{
	public:
		char data;
		TNode *daat;
		TNode *left;
		TNode *right;
		TNode(){
			data = 0;
			left = right = NULL;
		}
		TNode(char v){
			data = v;
			left = right = NULL;
		}
//		TNode(TNode *tn){
//			daat = tn;
//			left = right = NULL;
//		}
};

//template <class T>
//class LinkedList{
//	private:
//		Node *head;
//	public:
//		linkedList(){
//			head = NULL;
//		}
//		
//		bool isEmpty(){
//			return head==NULL;
//		}
//		
//	void start(T v){
//		Node *n = new Node(v);
//		if(head==NULL){
//			head = n;
//			return;
//		}
//		n->next = head;
//		head = n;	
//	}
//	
//	T peek(){
//		return head->data;
//	}
//	
//	void popp(){
//		Node *l = head;
//		head = head->next;
//		delete l;
//	}
//};
//
//template <class T>
//class TLinkedList{
//	private:
//		TNode *root;
//	public:
//		TLinkedList(){
//			root = NULL;
//		}
//		
//	void insert(T v){
//		TNode *nn = new TNode(v);
//		root = insertAt(root, nn);
//	}
//	TNode* insertAt(TNode *r, TNode *n){
//		if(r==NULL)
//			return n;
//		
//		if(n->data>=r->data)
//			r->right = insertAt(r->right, n);
//		else
//			r->left = insertAt(r->left, n);
//		return r;
//	}
//	
//	void postOrder(){
//		if(root==NULL)
//			return;
//		stack <TNode*> s1, s2;
//		s1.push(root);
//		TNode *n;
//		while(!s1.empty()){
//			n = s1.top();
//			s1.pop();
//			s2.push(n);
//			
//			if(n->left)
//				s1.push(n->left);
//			if(n->right)
//				s1.push(n->right);
//		}
//	}
//};
//
//template <class T>
//class Stackn{
//	private:
//		LinkedList<T> ln;
//	public:
//		bool Empty(){
//			ln.isEmpty();
//		}
//		void push(T v){
//			ln.start(v);
//		}
//		
//		T getTop(){
//			ln.peek();
//		}
//		
//		void pop(){
//			ln.popp();
//		}
//};
//
//template <class T>
//class Stackt{
//	private:
//		TLinkedList<T> tl;
//	public:
//		
//		void push(T v){
//			tl.insert(v);
//		}
//		
//		void display(){
//			tl.postOrder();
//		}
//};

bool Oper(char v){
	if(v=='+' || v=='-' || v=='/' || v=='*' || v=='^')
		return true;
	else
		return false;
}

bool isOperand(char ch){
	if(ch>='0' && ch<='9' || ch>='a' && ch<='z' || ch>='A' && ch<='z')
		return true;
	else
		return false;
}

int priorty(char v){
	return (v=='^')? 3: (v=='/' || v=='*')? 2: (v=='+' || v=='-')? 1: 0;
}

class Expression{
	public:
	TNode *ExpressionTree(){
//		string s = "(a^b^(c/d/e-f)^(x*y-m*n))";
		string s = "b^2-4*a*c";
//		s = "("+s;
//		s+=")";
		stack <TNode*> st_node;
		stack <char> st_char;
		TNode * t;
		TNode * t1;
		TNode * t2;
		
		for(int i=0; i<s.length(); i++){
			if(s[i]=='(')
				st_char.push(s[i]);
			else if(isOperand(s[i])){
				cout<<s[i]<<endl;
				t = new TNode(s[i]);
				st_node.push(t);
				
			}
			else if(Oper(s[i])){
				while(!st_char.empty() && st_char.top()!='(' && (s[i]!='^' && 
				priorty(st_char.top()) >= priorty(s[i]))){
					cout<<"--->>>"<<s[i]<<endl;
					t = new TNode(st_char.top()); 
					st_char.pop();
					
					t1 = st_node.top();
					st_node.pop();
					
					t2 = st_node.top();
					st_node.pop();
					
					t->left = t2;
					t->right = t1;
					
					st_node.push(t);
					
					cout<<"t2--"<<t2->data<<endl;
					cout<<"t1--"<<t1->data<<endl;
				}
				st_char.push(s[i]);
				cout<<"--->"<<s[i]<<endl;
			}
			else if(s[i]==')'){
				while(!st_char.empty() && st_char.top()!='('){
					t = new TNode(st_char.top());
					st_char.pop();
					
					t1 = st_node.top();
					st_node.pop();
					
					t2 = st_node.top();
					st_node.pop();
					
					t->left = t2;
					t->right = t1;
					
					st_node.push(t);
					
				}
				st_char.pop();
			}
		}
		t = st_node.top();
		TNode *ab = t;
		postOrder(ab);
		return t;
	}
	
	void postOrder(TNode *root){
		if(root==NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<"  ";
	}
};

int main(){
	Expression et;
	et.ExpressionTree();
}