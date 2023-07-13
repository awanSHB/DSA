#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//Reversing the order of stack using one additional queue

template <class T>
class Stk{
	public:
		stack<T> s;
		queue<T> q;
		
		void createStack(T A[], int n){
			for(int i=0; i<n; i++)
				s.push(A[i]);
				
			display(s);
			transferToQueue(s, q);		//CalltoQueue		
		}
		
		void transferToQueue(stack<T> &s, queue<T> &q){		//It will transfer stack to queue
			while(!s.empty()){
				q.push(s.top());
				s.pop();
			}
			transferToStack(q, s);		//CallToStack		
		}
		
		void transferToStack(queue<T> &q, stack<T> &s){		//It will transfer queue to stack
			while(!q.empty()){
				s.push(q.front());
				q.pop();
			}
			display(s);
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
	int A[5] = {1, 2, 3, 4, 5};
	s.createStack(A, 5);
}










