#include <iostream>
using namespace std;

class TNode{
	public:
		int data;
		TNode *left;
		TNode *right;
		
		TNode (){
			data = 0;
			left = right = NULL;
		}
		
		TNode(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

class AVL{
	private:
		TNode *root;
	public:
		AVL(){
			root = NULL;
		}
		
		void insert(int v){
			TNode *n = new TNode(v);
			root = insertAt(root, n);
		}
		TNode* insertAt(TNode *parent, TNode *node){
			if(parent==NULL)
				return node;
			
			if(node->data >= parent->data)
				parent->right = insertAt(parent->right, node);
			else
				parent->left = insertAt(parent->left, node);
			
			return parent;
		}
		
		int height(TNode *p){
			if(p==NULL)
				return 0;
			
			int hleft = height(p->left);
			int hright = height(p->right);
			
			return(max(hleft, hright)+1);
		}
		
		bool calculate_balance(TNode *cn){
			if(cn==NULL)
				return true;
			
			int balance_left = height(cn->left);
			int balance_right = height(cn->right);
			
			int r = balance_left-balance_right;
			
			return (r==-1 || r==0 || r==1)? true : false;
		}
		
		TNode* findParent(TNode *parent, TNode *node, TNode *temp){
			if(parent==NULL)
				return 0;
			
			if(parent->data==node->data)
				return temp;
			else{
				findParent(parent->left, node, parent);
				findParent(parent->right, node, parent);	
			}
		}
		
		void postOrder(TNode *par){
			if(par==NULL)
				return;
			
			postOrder(par->left);
			postOrder(par->right);
			
			bool check = calculate_balance(par);
			if(check==false)
				rotation(par);
		}
		
		void rotation(TNode *cn){
			TNode *node_parent = findParent(root, cn, cn);
			if(cn->left==NULL)
				leftRotation(cn, cn);
			else
				rightRotation(cn, cn);
		}
		
		void leftRotation(TNode *par, TNode *cn){
			TNode *t1 = findParent(root, par, cn);
			TNode *t2 = cn->right;
			t2->left = cn;
			if(cn->data >= t1->data)
				t1->right = t2;
			else
				t1->left = t2;
		}
		
		void rightRotation(TNode *par, TNode *cn){
			TNode *t1 = findParent(root, par, cn);
			TNode *t2 = cn->left;
			
			t2->right = cn;
			
			if(cn->data >= t1->data)
				t1->right = t2;
			else
				t1->left = t2;
		}
		
		void show(){
			postOrder(root);
			display(root);
		}
		
		void display(TNode *nodee){
			if(nodee==NULL)
				return;
			
			display(nodee->left);
			cout<<nodee->data<<"  ";
			display(nodee->right);
		}
};

int main(){
	AVL av;
	
	av.insert(30);
	av.insert(20);
	av.insert(15);
	av.insert(10);
	av.insert(40);
	
	av.show();
}