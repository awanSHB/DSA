#include <iostream>
using namespace std;


class BT{
	private:
		int n;
		char *A;
	public:
		BT(){
			n = 0;
			A = new char[15];
		}
		BT(int s){
			n = 0;
			A = new char[s];
		}
		
		bool isOperator(char ch){
			if(ch=='^' || ch=='/' || ch=='*' || ch=='+' || ch=='-')
				return true;
			else
				return false;
		}
		
		bool isOperand(char ch){
			if(ch>='0' && ch<='9' || ch>='a' && ch<='z' || ch>='A' && ch<='Z')
				return true;
			else
				return false;
		}
		
		void insert(char v){
			A[n++] = v;
		}
		
		void d1(){
			cout<<"\t\t\t          "<<A[0]<<endl;
		}
		void d2(){
			cout<<"\t\t\t       "<<" /"<<"    "<<"\\"<<endl;
			cout<<"\t\t\t      "<<" /"<<"      "<<"\\"<<endl;
			cout<<"\t\t\t      "<<"/"<<"        "<<"\\"<<endl;
			cout<<"\t\t\t     "<<A[1]<<"          "<<A[2]<<endl;
		}
		void d3(){
			cout<<"\t\t\t   "<<" /"<<"  "<<"\\"<<"      "<<"  /"<<" "<<"\\"<<endl;
			cout<<"\t\t\t  "<<" /"<<"\t"<<"\\"<<"    "<<"  /"<<"   "<<"\\"<<endl;
			cout<<"\t\t\t "<<A[3]<<"       "<<A[4]<<"     "<<A[5]<<"    "<<A[6]<<endl;
		}
		
		void preOrder(int p){
			if(p>=n)
				return;
			int l = 2*p+1;
			int r = 2*p+2;
			cout<<A[p]<<"  ";
			if(l<n)
				preOrder(l);
			if(r<n)
				preOrder(r);
		}
		
		void postOrder(int p){
			if(p>=n)
				return;
			int l = 2*p+1;
			int r = 2*p+2;
			if(l<n)
				postOrder(l);
			if(r<n)
				postOrder(r);
			cout<<A[p]<<"  ";
		}
};

int main(){
	string s = "a-b/2";
	BT b(s.length());
	
	for(int i=0; i<s.length(); i++)
		b.insert(s[i]);
	b.d1();
	b.d2();
	b.d3();
	cout<<"PreOrder"<<endl;
	b.preOrder(0);
	
	cout<<"\nPostOrder"<<endl;
	b.postOrder(0);
	
}