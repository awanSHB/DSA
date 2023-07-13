#include<iostream>
#include<queue>
using namespace std;

struct Tnode{
	int data;
	Tnode *leftchild;
	Tnode *rightchild;
};

void levelwise(Tnode *r){
	queue<Tnode *> q;
	
	q.push(r);
	
	while(!q.empty()){
		Tnode *x = q.front();
		q.pop();
		cout<<x->data<<"  ";
		if(x->leftchild!=NULL)	
			q.push(x->leftchild);
		if(x->rightchild!=NULL)
			q.push(x->rightchild);
	}
	cout<<"\n\n\n";
}

void preOrder(Tnode *r){
	if(r==NULL)
		return;
	
	cout<<r->data<<"  ";
	preOrder(r->leftchild);
	preOrder(r->rightchild);
}


void inOrder(Tnode *r){
	if(r==NULL)
		return;
	
	inOrder(r->leftchild);
	cout<<r->data<<"  ";
	inOrder(r->rightchild);
}


void postOrder(Tnode *r){
	if(r==NULL)
		return;
	
	postOrder(r->leftchild);
	postOrder(r->rightchild);
	cout<<r->data<<"  ";
}

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
	if((*r)->data <= n->data)
		insertAt(&(*r)->rightchild, n);
	if((*r)->data > n->data)
		insertAt(&(*r)->leftchild, n);
}

Tnode *removeAt(Tnode *r, int v);

void remove(Tnode *root, int v){
	root = removeAt(root, v);
}

int minval(Tnode *r){
	while(r->leftchild)			//r->leftchild!=NULL
		r = r->leftchild;
	return r->data;
}

Tnode *removeAt(Tnode *r, int v){
	if(r==NULL)
		return r;
	if(r->data > v)
		r->leftchild = removeAt(r->leftchild, v);
	else if(r->data < v)
		r->rightchild = removeAt(r->rightchild, v);
	else{
		if(r->leftchild==NULL)
			return r->rightchild;
		if(r->rightchild==NULL)
			return r->leftchild;
		r->data = minval(r->rightchild);
		r->rightchild = removeAt(r->rightchild, r->data);
	}
	return r;
}

int main(){
	struct Tnode *root1 = NULL;
	insert(&root1, 30);
	insert(&root1, 20);
	insert(&root1, 40);
	insert(&root1, 25);
	insert(&root1, 22);
	insert(&root1, 15);
	
	levelwise(root1);
	
	cout<<"\n\nPreOrder: \n\n";
	preOrder(root1);
	cout<<"\n\nInOrder: \n\n";
	inOrder(root1);
	cout<<"\n\nPostOrder: \n\n";
	postOrder(root1);
	cout<<"\n\n";
	
	remove(root1, 20);
	levelwise(root1);
}

















