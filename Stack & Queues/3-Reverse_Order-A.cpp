#include<iostream>
#include <stack>
using namespace std;

//Reversing the order of stack using two additional stacks
template<class T>
class Stk{
	public:
		stack<T> s;
		stack<T> s1;
		stack<T> s2;
		
		void createStack(T A[], int n){
			for(int i=0; i<n; i++)
				s.push(A[i]);
			display(s);
			transfer(s, s1);
			transfer(s1, s2);
			transfer(s2, s);
			display(s);
		}
		
		void transfer(stack<T> &x, stack<T> &y){
			while(!x.empty()){
				y.push(x.top());
				x.pop();
			}
		}
		
		void display(stack<T> t){
			cout<<"\n\n";
			while(!t.empty()){
				cout<<"\t\t|_"<<t.top()<<"_|\n";
				t.pop();
			}
		}
};

int main(){
	Stk<int> s;
	int A[5] = {1, 3, 5, 7, 9};
	s.createStack(A, 5);
}
