#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Stk{
	public:
		stack<T> s1;
		stack<T> s2;
		int count = 0;
		
		void createStack(T A[], int n){
			for(int k=0; k<n; k++){
				s1.push(A[k]);
				count++;
			}
			cout<<"\nOriginal:";
			display(s1);
			reverse(s1);
			
		}
		
		void reverse(stack<T> &s1){
			T k;
			int m = 0;
			T b;
			
			while(m!=count){
				k = s1.top();
				s1.pop();
				
				while(!s1.empty() && s1.top()!=b){
					s2.push(s1.top());
					s1.pop();
				}
				
				s1.push(k);
				b = s1.top();
				while(!s2.empty()){
					s1.push(s2.top());
					s2.pop();
				}
				m++;
			}
			cout<<"\nReversed: ";
			display(s1);
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
	
	int A[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	s.createStack(A, 8);
	
	Stk<char> c;
	char B[5] = {'A', 'B', 'C', 'D', 'E'};
	c.createStack(B, 5);
}