#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;

class TNode{
	public:
		int data;
		TNode *left;
		TNode *right;
		
		TNode(int v){
			data = v;
			left = right = NULL;
		}
};

template <class T>
class Stack{
	public:
		int top;
		T *A;
		Stack(int v){
			top = v;
			A = new T[16];
		}
	bool isEmpty(){
		return top==0;
	}
	
	void push(T v){
		A[top++] = v;
	}
	
	void pop(){
		top--;
	}
	
	T getTop(){
		return A[top-1];
	}
};

class BST{
	private:
		TNode *root;
	public:
		BST(){
			root = NULL;
		}
		
	//INSERTION
	void insert(int v){
		TNode *n = new TNode(v);
		root = insertAt(root, n);
	}
	TNode* insertAt(TNode *r, TNode *nn){
		if(r==NULL)
			return nn;
		
		if(nn->data >= r->data){
			r->right = insertAt(r->right, nn);
		}else{
			r->left = insertAt(r->left, nn);
		}
		return r;
	}
	
	
	//DISPLAYING
	void show(){
		cout<<"\nDisplay in Descending:\n\n";
		display(root);
	}
	void display(TNode *r){
		if(r==NULL)	
			return;
		display(r->right);
		cout<<r->data<<"  ";
		display(r->left);
	}
	
	
	//LEVEL_WISE
	void levelWise(){
		cout<<"\n\nLevel-Wise Traversal:\n\n";
		if(root==NULL)
			return;
//		TNode* node = NULL;
		std::queue <TNode *> q;
		q.push(root);
		while(q.empty() == false){
			TNode *node = q.front();
			q.pop();
			cout<<node->data<<"  ";
			if(node->left!=NULL)
				q.push(node->left);
			if(node->right!=NULL)
				q.push(node->right);
		}
	}
	
	//PREORDER
	void preOrder(){
		cout<<"\n\nPreOrder:\n\n";
		if(root==NULL)
			return;
		
		stack <TNode*> s;
		s.push(root);
		
		while(!s.empty()){
			TNode *n = s.top();
			cout<<n->data<<"  ";
			s.pop();
			
			if(n->right)
				s.push(n->right);
			if(n->left)
				s.push(n->left);
		}
	}
	
	//InOrder
	void inOrder(){
		cout<<"\n\nInOrder:\n\n";
		if(root == NULL)
			return;
		
		stack <TNode*> s;
		TNode *current = root;
		
		while(current!=NULL || !s.empty()){
			
			while(current!=NULL){
				s.push(current);
				current = current->left;
			}
		
			current = s.top();
			s.pop();
			
			cout<<current->data<<"  ";
			current = current->right;	
		}
	}
	
	//POST-Order
	void postOrder(){
		cout<<"\n\nPostOrder:\n\n";
		if(root==NULL)
			return;
		
		stack <TNode*> s1, s2;
		s1.push(root);
		TNode *n;
		
		while(!s1.empty()){
			n = s1.top();
			s1.pop();
			s2.push(n);
			
			if(n->left)
				s1.push(n->left);
			if(n->right)
				s1.push(n->right);
		}
		
		while(!s2.empty()){
			TNode *v = s2.top();
			cout<<v->data<<"  ";
			s2.pop();
		}
	}
	
	//Inorder Without Stack 
	void MorrisInorder(){
		cout<<"\n\nMorris InOrder:\n\n";
		if(root==NULL)
			return;
		TNode *curr, *pre;
		curr = root;
		
		while(curr!=NULL)
		{
			if(curr->left==NULL)
			{
				cout<<curr->data<<"  ";
				curr = curr->right;
			}
			else
			{
				pre = curr->left;
				while(pre->right!=NULL && pre->right!=curr)
					pre = pre->right;
				
				if(pre->right==NULL)
				{
					pre->right = curr;
					curr = curr->left;
				}
				else
				{
					pre->right = NULL;
					cout<<curr->data<<"  ";
					curr = curr->right;
				}
			}
			
		}
	}
	
	
	//
	void morrisPreorder(){
		cout<<"\n\nMorris PreOrder:\n\n";
		if(root==NULL)
			return;
		while(root!=NULL)
		{
			if(root->left==NULL)
			{
				cout<<root->data<<"  ";
				root = root->right;
			}
			else
			{
				TNode *curr = root->left;
				while(curr->right && curr->right!=root)
					curr = curr->right;
				if(curr->right==root)
				{
					curr->right = NULL;
					root = root->right;
				}
				else
				{
					cout<<root->data<<"  ";
					curr->right = root;
					root = root->left;
				}
			}
		}
	}
	
	
	//DELETION
	void remove(int v){
		root = deleteNode(root, v);
		cout<<"\n\nAfter Removing "<<v<<" : \n\n";
		display(root);
	}
	TNode* deleteNode(TNode *r, int v){
		if(r==NULL)
			return r;
		if(v < r->data)
			r->left = deleteNode(r->left, v);
		else if(v > r->data)
			r->right = deleteNode(r->right, v);
		else{
			if(r->left==NULL)
				return r->right;
			else if(r->right == NULL)
				return r->left;
			else{
				r->data = miniVal(r->right);
				r->right = deleteNode(r->right, r->data);
			}
		}
		return r;
	}
	int miniVal(TNode *r){
		while(r->left)		//r->left!=NULL
			r = r->left;
		return r->data;
	}
};

int main(){
	BST b;
	b.insert(30);
	b.insert(40);
	b.insert(20);
	b.insert(10);
	b.insert(25);
	b.insert(35);
	b.insert(45);
	b.show();
	b.levelWise();
	b.preOrder();
	b.morrisPreorder();
	b.inOrder();
	b.MorrisInorder();
	b.postOrder();
	b.remove(40);
	
}