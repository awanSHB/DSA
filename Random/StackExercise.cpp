#include <iostream>
#include <stack>
using namespace std;

class Sta{
	public:
		stack <int> s1;
		stack <int> s2;
		stack <int> s3;
		void insert(int A[], int n){
			for(int i=0; i<n; i++)
				s1.push(A[i]);
//			reverseOrderTwoStacks(s1);
		}
		
//		void show(){
//			display(s1);
//		}
		void display(stack<int> T){
			cout<<"\n\n";
			while(!T.empty()){
				cout<<"\t\t|   |"<<endl;
				cout<<"\t\t|_"<<T.top()<<"_|"<<endl;
				T.pop();
			}
		}
		
		void transfer(stack<int> X, stack<int> Y){
			while(!X.empty()){
				Y.push(X.top());
				X.pop();
			}
		}
		
		void reverseOrderTwoStacks(){
			
			
			transfer(s1, s2);
			transfer(s2, s3);
			transfer(s3, s1);
			
			
			
			
		}
};

int main(){
	Sta s;
	int A[5] = {1, 3, 7, 5, 9};
	s.insert(A, 5);
//	s.show();
	s.reverseOrderTwoStacks();
}