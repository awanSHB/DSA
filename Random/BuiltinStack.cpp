#include <stack>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyStack{
	private:
		stack<int> s;
//		stack t;
	public:
		bool isEmpty(){
			return s.empty();
		}
		
		int getTop(){
			return s.top();
		}
		
		void pop(){
			s.pop();
		}
		
		int peek(){
			if(!s.empty())
				return int(s.top());
		}
		
		void pushhh(int v){
			stack <int>t;
			if(v < s.top() || s.empty())
				s.push(v);
			else{
				while(!s.empty() && s.top() < v){
					t.push(s.top());
					s.pop();
				}
				s.push(v);
				while(!t.empty()){
					s.push(t.top());
					t.pop();
				}
			}	
		}
		
		void disp(){
			while(!s.empty()){
				cout<<s.top()<<endl;
				s.pop();
			}
		}
};

int main(){
	MyStack ms;
	ms.pushhh(4);
	ms.pushhh(2);
	ms.pushhh(1);
	ms.pushhh(3);
	ms.disp();
	while(!ms.isEmpty()){
		cout<<ms.peek()<<endl;
		ms.pop();
	}
}