#include <iostream>
using namespace std;

class BT{
	private:
		int *A;
		int n;
	public:
		BT(){
			A = new int[15];
			n = 0;
		}
		BT(int s){
			A = new int[s];
			n = 0;
		}
		
	void insert(int v){
		A[n++] = v;
	}
	
	
	//Level wise display
	void display(){
		cout<<"Level Wise :- \t\t\t";
		for(int i=0; i<n; i++)
			cout<<A[i]<<"  ";
	}
	
	void d1(){
		cout<<"\t\t\t          "<<A[0]<<endl;
	}
	void d2(){
		cout<<"\t\t\t       "<<" /"<<"    "<<"\\"<<endl;
		cout<<"\t\t\t      "<<" /"<<"      "<<"\\"<<endl;
		cout<<"\t\t\t      "<<"/"<<"        "<<"\\"<<endl;
		cout<<"\t\t\t     "<<A[1]<<"         "<<A[2]<<endl;
	}
	void d3(){
		cout<<"\t\t\t   "<<" /"<<"  "<<"\\"<<"      "<<"  /"<<" "<<"\\"<<endl;
		cout<<"\t\t\t  "<<" /"<<"\t"<<"\\"<<"    "<<"  /"<<"   "<<"\\"<<endl;
		cout<<"\t\t\t "<<A[3]<<"    "<<A[4]<<"     "<<A[5]<<"    "<<A[6]<<endl;
	}
	
	void d4(){
		cout<<"\t\t        "<<"/"<<""<<"\\"<<"     "<<"/"<<""<<"\\"<<"     "<<"/"<<""<<"\\"<<"     "<<"/"<<""<<"\\"<<endl;
		cout<<"\t\t       "<<"/"<<"  "<<"\\"<<"   "<<"/"<<"  "<<"\\"<<"   "<<"/"<<"  "<<"\\"<<"   "<<"/"<<"  "<<"\\"<<endl;
		cout<<"\t\t      "<<A[7]<<"   "<<A[8]<<"  "<<A[9]<<"    "<<A[10]<<"  "<<A[11]<<" "<<A[12]<<"  "<<A[13]<<"   "<<A[14]<<"\n\n";
	}
	void show(){
		d1();
		d2();
		d3();
		d4();
	}
	

	
	// Parent left Right
	void preOrder(int p){
		if(p>=n)
			return;
		int l;
		int r;
		l = 2*p+1;
		r = 2*p+2;
		
		cout<<A[p]<<"  ";
		if(l<n)
			preOrder(l);
		if(r<n)
			preOrder(r);
	}
	
	//Left Parent Right
	void inOrder(int p){
		if(p>=n){
			cout<<"-"<<A[p-1];
			return;
		}
		int l = 2*p+1;
		int r = 2*p+2;
		
		if(l<n)
			inOrder(l);
		cout<<A[p]<<"  ";
		if(r<n)
			inOrder(r);
	}
	
	//Left Right Parent
	void postOrder(int p){
		if(p>=n)
			return;
		int l = 2*p+1;
		int r = 2*p+2;
		
		if(l<n)
			postOrder(l);
		if(r<n)
			postOrder(r);
		cout<<A[p]<<"   ";
	}
	
	int height(int p){
		if(p>=n)
			return 0;
		
		int left = 2*p+1;
		int left_height = height(left);
		
		int right = 2*p+2;
		int right_height = height(right);
		return max(left_height, right_height)+1;
	}
	
	
	int heighta(int p){
		if(p>=n)
			return 0;
		
		int left = 2*p+1;
		int left_height = height(left);
		
		int right = 2*p+2;
		int right_height = height(right);
		return left_height+right_height+1;
	}
	
	
	int diameter(int p){
		if(p>=n)
			return 0;
		
		int left = 2*p+1;
		int l_h = height(left);
		
		int right = 2*p+2;
		int r_h = height(right);
		
		int ld = diameter(left);
		int rd = diameter(right);
		return max((l_h+r_h+1), max(ld, rd));
	}
	
	int checkEqual(int p1, int p2){
//		p1 = p.n;
//		p2 = pn.n;
		if(p1>=n || p2>=n){
			return 0;
		}
//		if(p1)
	}
};

int main(){
	BT b;
	BT b1;
	BT c;
	
	int A[] = {50, 40, 60, 30, 20, 70, 80, 0, 0, 0, 0, 94, 95, 0, 0};
	for(int i=0; i<15; i++)
		b.insert(A[i]);
	b.display();
	cout<<"\n\n";
	b.d1();
	b.d2();
	b.d3();
	b.d4();
	cout<<"\n\n\nPreOrder :- \t\t\t";
	b.preOrder(0);
	
	cout<<"\n\n\nPostOrder:- \t\t\t";
	b.postOrder(0);
	
	cout<<"\n\n\nInOrder  :- \t\t\t";
	b.inOrder(0);
	cout<<"\n\n";
	
	cout<<"\n\tThe height of the tree is     =======>    ";
	cout<<b.height(0);
	
	cout<<"\n\n\tThe diameter of tree is       =======>    ";
	cout<<b.diameter(0);
	cout<<"\n\n\n";
	
	int B[] = {50, 40, 60, 30, 20, 70, 80};
	for(int i=0; i<7; i++)
		b1.insert(B[i]);
	
	cout<<c.checkEqual(A[0], B[0]);
}