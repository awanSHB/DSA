#include<iostream>
#include<stack>
using namespace std;

struct Tnode{
	int data;
	Tnode *left;
	Tnode *right;
};

Tnode *insertAt(Tnode *root, Tnode *n);

void insert(Tnode **root, int v){
	Tnode *n = new Tnode;
	n->data = v;
	n->left = NULL;
	n->right = NULL;
	if(*root==NULL)
		*root = n;
	else
		*root = insertAt(*root, n);
}

Tnode *insertAt(Tnode *r, Tnode *n){
	if(r==NULL)
		return n;
	if(r->data > n->data)
		r->left = insertAt(r->left, n);
	if(r->data <= n->data)
		r->right = insertAt(r->right, n);
	
	return r;
}

void preOrder(Tnode *root){
	cout<<"\nPreOrder: \n";
	stack<Tnode*> s;
	s.push(root);
	
	while(!s.empty()){
		Tnode *t = s.top();
		s.pop();
		
		cout<<t->data<<"  ";
		if(t->right)	
			s.push(t->right);
		if(t->left)
			s.push(t->left);
	}
}

void inOrder(Tnode *root){
	cout<<"\n\n\nInOrder: \n";
	stack<Tnode*> s;
	Tnode *c = root;
	while(!s.empty() || c!=NULL){
		while(c!=NULL){
			s.push(c);
			c = c->left;
		}
		c = s.top();
		s.pop();
		cout<<c->data<<"  ";
		c = c->right;
	}
}

void postOrder(Tnode *root){
	cout<<"\n\n\nPostOrder: \n";
	stack<Tnode *> s1, s2;
	
	s1.push(root);
	while(!s1.empty()){
		Tnode *t = s1.top();
		s1.pop();
		s2.push(t);
		
		if(t->left)
			s1.push(t->left);
		if(t->right)
			s1.push(t->right);
	}
	while(!s2.empty()){
		Tnode *t = s2.top();
		cout<<t->data<<"  ";
		s2.pop();
	}
}


int main(){
	struct Tnode *root = NULL;
	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 70);
	insert(&root, 20);
	insert(&root, 40);
	insert(&root, 60);
	insert(&root, 80);
	preOrder(root);
	inOrder(root);
	postOrder(root);
}









