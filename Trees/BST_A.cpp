#include<iostream>
#include<queue>
using namespace std;

struct Tnode{
	int data;
	Tnode *leftchild;
	Tnode *rightchild;
};

void levelWise(Tnode *r){
	queue<Tnode*> q;
	q.push(r);
	while(!q.empty()){
		Tnode *x = q.front();
		q.pop();
		cout<<x->data<<" ";
		if(x->leftchild!=NULL)
			q.push(x->leftchild);
		if(x->rightchild!=NULL)
			q.push(x->rightchild);
	}
	cout<<"\n\n\n";
}

// 1st

void insertAt(Tnode **r, Tnode *n);

void insert(Tnode **root, int v){
	Tnode *n = new Tnode;
	n->data = v;
	n->leftchild = NULL;
	n->rightchild = NULL;
	if(*root==NULL)
		*root = n;
	else
		insertAt(root, n);
}

void insertAt(Tnode **r, Tnode *n){
	if(*r==NULL){
		*r = n;
		return;
	}
	if((*r)->data > n->data)
		insertAt(&(*r)->leftchild, n);
	if((*r)->data <= n->data)
		insertAt(&(*r)->rightchild, n);
}

// 2nd)

Tnode* insertAtb(Tnode *r, Tnode *n);

void insertb(Tnode **root, int v){
	Tnode *n = new Tnode;
	n->data = v;
	n->leftchild = NULL;
	n->rightchild = NULL;
	if(*root==NULL)
		*root = n;
	else
		*root = insertAtb(*root, n);
}

Tnode* insertAtb(Tnode *r, Tnode *n){
	if(r==NULL)
		return n;
	if(r->data > n->data)
		r->leftchild = insertAtb(r->leftchild, n);
	if(r->data <= n->data)
		r->rightchild = insertAtb(r->rightchild, n);
	
	return r;
}

int main(){
	struct Tnode *root = NULL;
	insert(&root, 10);
	insert(&root, 9);
	insert(&root, 12);
	insert(&root, 13);
	insert(&root, 11);
	levelWise(root);
	
	struct Tnode *root1 = NULL;
	insertb(&root1, 20);
	insertb(&root1, 15);
	insertb(&root1, 25);
	insertb(&root1, 16);
	insertb(&root1, 23);
	insertb(&root1, 21);
	levelWise(root1);
}














