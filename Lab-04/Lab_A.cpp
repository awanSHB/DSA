#include<iostream>
#include<stack>
using namespace std;

void checkBalance(string exp){
	stack<char> s;
	char c;
	
	for(int i=0; i<exp.length(); i++){
		c = exp[i];
		if(c=='(' || c=='{' || c=='[')
			s.push(c);
		else{
			if(c==')' || c=='}' || c==']'){
				
				switch(c){
					
					case ')':
						if(s.empty() || s.top()!='(')
							return;
						else
							s.pop();
						break;
					case '}':
						if(s.empty() || s.top() != '{')
							return;
						else
							s.pop();
						break;
					case ']':
						if(s.empty() || s.top() != '[')
							return;
						else
							s.pop();
						break;
					
				}
			}
		}
	}
	if(s.empty())
		cout<<"\nThey Are Balanced ";
}

int main(){
	string e = "(a+b+c)*[{d+e}+f]";
	checkBalance(e);
}