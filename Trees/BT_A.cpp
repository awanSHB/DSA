#include<iostream>
#include <queue>
using namespace std;

struct Tnode{
	int data;
	Tnode *lc;
	Tnode *rc;
};

void display(Tnode *r){
	cout<<"\n\n\n";
	queue <Tnode*> q;
	q.push(r);
	
	while(!q.empty()){
		Tnode *n = q.front();
		q.pop();
		
		cout<<n->data<<"  ";
		
		if(n->lc)
			q.push(n->lc);
		if(n->rc)
			q.push(n->rc);
	}
}

Tnode *newNode(int d){
	Tnode *n = new Tnode;
	n->data = d;
	n->lc = NULL;
	n->rc = NULL;
	return n;
}

int noOfNodes(Tnode *r){
	if(r==NULL)
		return 0;
	return 1 + noOfNodes(r->lc) + noOfNodes(r->rc);
}

int sum_of_nodes(Tnode *r){
	if(r==NULL)
		return 0;
	return r->data + sum_of_nodes(r->lc) + sum_of_nodes(r->rc);
}

int count_leaf(Tnode *r){
	if(r==NULL)
		return 0;
	if(r->lc==NULL && r->rc==NULL)
		return 1;
	return count_leaf(r->lc) + count_leaf(r->rc);
}

int count_right_children(Tnode *r){
	if(r==NULL)
		return 0;
	int count = 0;
	if(r->rc!=NULL)
		count++;
	return count + count_right_children(r->lc) + count_right_children(r->rc);
}

int find_height(Tnode *r){
	if(r==NULL)
		return 0;
	int left_height = find_height(r->lc);
	int right_height = find_height(r->rc);
	
	return max(left_height, right_height) + 1;
}

Tnode *delete_leaf(Tnode *r){
	if(r==NULL)
		return NULL;
	if(r->lc==NULL && r->rc==NULL)
		return NULL;
	r->lc = delete_leaf(r->lc);
	r->rc = delete_leaf(r->rc);
	return r;
}

int main(){
	struct Tnode *root = NULL;
	root = newNode(50);
	root->lc = newNode(30);
	root->rc = newNode(60);
	root->lc->rc = newNode(20);
	root->lc->lc = newNode(80);
	root->rc->rc = newNode(90);
	
	display(root);
	
	cout<<"\n\n\nTotal Nodes are: "<<noOfNodes(root)<<endl;
	cout<<"\n\nSum of Nodes is: "<<sum_of_nodes(root)<<endl;
	cout<<"\n\nLeaf Nodes are : "<<count_leaf(root)<<endl;
	cout<<"\n\nRight Childrens: "<<count_right_children(root)<<endl;
	cout<<"\n\nHeight is : "<<find_height(root)<<endl;
	root = delete_leaf(root);
	display(root);
}