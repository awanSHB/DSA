#include <iostream>
using namespace std;

class TNode{
	public:
		int data;
		TNode *left;
		TNode *right;
		
		TNode (){
			data  = 0;
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
			
			if(node->data > parent->data)
				parent->right = insertAt(parent->right, node);
			else //if(node->data < parent->data)
				parent->left = insertAt(parent->left, node);
//			else
//				return parent;
				
			cout<<parent->data<<node->data<<endl;
			int balance = calculate_balance(parent);
			
			if(balance > 1 && node->data < parent->left->data){
				cout<<"node--"<<node->data<<endl;
				cout<<"parent--"<<parent->data<<endl;
				cout<<"parentright--"<<parent->right->data<<endl;
				
				return rightRotation(parent);
			}
			
			if(balance < -1 && node->data > parent->right->data){
				cout<<"node--"<<node->data<<endl;
				cout<<"parent--"<<parent->data<<endl;
				cout<<"parentright--"<<parent->right->data<<endl;
				
				return leftRotation(parent);
			}
			
			if(balance > 1 && node->data > parent->left->data){
				cout<<"node--"<<node->data<<endl;
				cout<<"parent--"<<parent->data<<endl;
				cout<<"parentright--"<<parent->right->data<<endl;
				
				parent->left = leftRotation(parent->left);
				return rightRotation(parent);
			}
			if(balance < -1 && node->data < parent->right->data){
				cout<<"llnode--"<<node->data<<endl;
				cout<<"llparent--"<<parent->data<<endl;
				cout<<"llparentright--"<<parent->right->data<<endl;
				parent->right = rightRotation(parent->right);
				return leftRotation(parent);
			}
			
			return parent;
			
		}
		
		int height(TNode *p){
			if(p==NULL)
				return 0;
			
			int hleft = height(p->left);
			int hright = height(p->right);
			
			return(max(hleft, hright)+1);
		}
		
		int calculate_balance(TNode *cn){
			if(cn==NULL)
				return 0;
			
			int balance_left = height(cn->left);
			int balance_right = height(cn->right);
			
			int r = balance_left-balance_right;
			
			return r;
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
		
		
		
		TNode* leftRotation(TNode *x){
			TNode *y = x->right;
			TNode *t2 = y->left;
			y->left = x;
			x->right = t2;
			
			return y;
		}
		
		TNode* rightRotation(TNode *y){
			TNode *x = y->left;
			TNode *t2 = x->right;
			x->right = y;
			y->left = t2;
				
			return x;
		}
		
		void show(){
			cout<<"\n\nPreOrder Code is : \n";
			preOrder(root);
			
			cout<<"\n\nInOrder Code is : \n";
			inOrder(root);
			
			cout<<"\n\nPostOrder Code is : \n";
			postOrder(root);
		}
		
		void preOrder(TNode *nodee){
			if(nodee==NULL)
				return;
			cout<<nodee->data<<"  ";
			preOrder(nodee->left);
			preOrder(nodee->right);
		}
		
		void inOrder(TNode *nodee){
			if(nodee==NULL)
				return;
				
			inOrder(nodee->left);
			cout<<nodee->data<<"  ";
			inOrder(nodee->right);
		}
		
		void postOrder(TNode *nodee){
			if(nodee==NULL)
				return;
			
			postOrder(nodee->left);
			postOrder(nodee->right);
			cout<<nodee->data<<"  ";
		}
};

int main(){
	AVL av;
	
	av.insert(10);
	av.insert(20);
	av.insert(30);
	av.insert(40);
	av.insert(50);
	av.insert(25);
	
	av.show();
}