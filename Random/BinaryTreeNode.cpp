#include <bits/stdc++.h>
#include <queue>
using namespace std;

class TNode{
	public:
		int data;
		int c;
		TNode *left;
		TNode *right;
		
		TNode(){
			data = 0;
			c = 0;
			left = right = NULL;
		}
		
		TNode(int v){
			data = v;
			c = 0;
			left = right = NULL;
		}
};

class BT{
	private:
		TNode *root;
	public:
		BT(){
			root = NULL;
		}
		
		void insert(int v){
			TNode *n = new TNode(v);
//			cout << "inserting value " << v <<endl;
			root = insertAt(root, n);
		}
		
		TNode* insertAt(TNode *r, TNode *n){
			if (r==NULL)
			    return n;
			
			if(n->data >= r->data){
				r->right = insertAt(r->right, n);
				
			}else{
				r->left = insertAt(r->left, n);
			}
			return r;
		}
		
		
		//Counting minimum
		int mini(){
			return minimum(root);
		}
		
		int minimum(TNode *r){
			if(r->left==NULL)
				return r->data;
			else
				return minimum(r->left);
//			cout<<r->data;
		}
		
		
		//Counting Maximum
		int maxi(){
			return maximum(root);
		}
		
		int maximum(TNode *r){
			if(r->right==NULL)
				return r->data;
			else
				return maximum(r->right);
		}
		
		
		//PRE_order
		void prOrder(){ 			//calling from main
			cout<<"PreOrder\n";
			preOrder(root);
		} 			
		
		void preOrder(TNode *p){
			if(p==NULL)
				return;
			
			cout<<p->data<<"  ";
			preOrder(p->left);
			preOrder(p->right);
		}
		
		
		//IN_order
		void iOrder(){				//calling from main
			cout<<"\n\nInOrder\n";
			inOrder(root);
		} 			
		
		void inOrder(TNode *p){
			if(p==NULL)
				return;
			
			inOrder(p->left);
			cout<<p->data<<"  ";
			inOrder(p->right);
		}
		
		//POST_order
		void posOrder(){ 			//calling from main
			cout<<"\n\nPostOrder\n";
			postOrder(root); 
		}		
		
		void postOrder(TNode *p){
			if(p==NULL)
				return;
			
			postOrder(p->left);
			postOrder(p->right);
			cout<<p->data<<"  ";
		}
		
		void levelWise(){
			cout<<"\n\nLevel_Wise\n";
			if(root==NULL)
				return;
			TNode *x;
			std::queue<TNode *> q;
			q.push(root);
			while(!q.empty()){
				x = q.front();
				q.pop();
				std:: cout << x->data <<"  ";
				if(x->left!=NULL)
					q.push(x->left);
				if(x->right!=NULL)
					q.push(x->right);
			}
		}
		
		
		//Counting The number of elements
		int count(){
			return Elements(root);
		}
		
		int Elements(TNode *r){
			if(r==NULL)
				return 0;
			return 1 + Elements(r->left) + Elements(r->right);
		}
		
		//SUM
		int sum(){
			return cal_sum(root);
		}
		
		int cal_sum(TNode *r){
			if(r==NULL)
				return 0;
			return r->data + cal_sum(r->left) + cal_sum(r->right);
		}
		
		//Identical trees
		bool call_identical(BT b, BT b1){
//			identical(b.root, b1.root);
			return identical(b.root, b1.root);
//			return identical(b.root, b1.root);
		}
		
		bool identical(TNode *a, TNode *b){
			if(a==NULL && b==NULL)
				return true;
			if(a==NULL || b==NULL)
				return false;
			
			if(a!=NULL && b!=NULL)
				return (identical(a->left, b->left) && identical(a->right, b->right) && a->data == b->data);
			
			return false;
		}

};

int main(){
	BT b;
	BT b1;
	BT d;
	int A[7] = {50, 60, 40, 30, 45, 55, 65};
	for(int i=0; i<7; i++)
		b.insert(A[i]);
	
	int B[7] = {50, 60, 40, 30, 45, 55, 65};
	for(int i = 0; i<7; i++)
		b1.insert(B[i]);
	
	b.prOrder();
	b.iOrder();
	b.posOrder();
	
	b.levelWise();
	
	cout<<"\n\n\nMinimum value is =====>  ";
	cout<<b.mini();
	
	cout<<"\n\n\nMaximum value is =====>  ";
	cout<<b.maxi();
	
	cout<<"\n\n\nThe number of Elements are  ====>  ";
	cout<<b.count();
	
	cout<<"\n\n\nThe Sum of the Elements are ====>  ";
	cout<<b.sum();
	
	if(d.call_identical(b, b1))
		cout<<"\n\nYES";
	else
		cout<<"\n\nNO";
}