#include<iostream>
#include<stack>
using namespace std;


//We are transfering the elements in s1 to s2 in the same order with using one addtional stack
//and non array variables
class Stk{
	public:
		stack<int> s1;
		stack<int> s2;
		
		void display(stack<int> T){
			cout<<"\n\n";
			while(!T.empty()){
				cout<<"\t\t|_"<<T.top()<<"_|\n";
				T.pop();
			}
		}
		
		void insert(int A[], int n){
			for(int i=0; i<n; i++)
				s1.push(A[i]);
			display(s1);
			int a;
			int b = 0;
			int c=0;
			
			while(c<n){
				a = s1.top();
				s1.pop();
				while(!s1.empty() && s1.top()!=b){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(a);
				while(!s2.empty()){
					s1.push(s2.top());
					s2.pop();
				}
				b = a;
				c++;
			}
			
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			display(s2);
		}
};


int main(){
	Stk s;
	int A[7] = {1, 3, 5, 2, 4, 7, 8};
	s.insert(A, 7);
}