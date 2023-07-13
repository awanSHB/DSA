#include<iostream>
#include<stack>
using namespace std;

void show(stack<int> s){
	cout<<"\n\n";
	while(!s.empty()){
		cout<<"\t\t|_"<<s.top()<<"_|\n";
		s.pop();
	}
}

void sort(stack<int> &s){
	if(!s.empty()){
	
		int A = s.top();
		s.pop();
		
		sort(s);
		stack<int> t;
		while(!s.empty() && s.top() > A){
			t.push(s.top());
			s.pop();
		}
		s.push(A);	// or t.push(a);
		while(!t.empty()){
			s.push(t.top());
			t.pop();
		}
	}
}

int main(){
	stack<int> s;
	s.push(4);
	s.push(5);
	s.push(2);
	s.push(3);
	s.push(1);
	s.push(9);
	s.push(7);
	s.push(8);
	s.push(0);
	s.push(6);
	show(s);
	sort(s);
	show(s);
}