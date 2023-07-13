#include<iostream>
using namespace std;

class Stack{
	private:
		int A[10];
		int top;
	public:
		Stack(){
			top = 0;
		}
		bool isempty(){
			return (top==0);
		}
		bool isfull(){
			return (top==10);
		}
	
	void push(int v){
		if(!isfull()){
			A[top++] = v;
		}
	}
	
	void pop(){
		if(!isempty()){
			top--;
		}
	}
	
	int peek(){
		if(!isempty()){
			return A[top-1];
		}
		else{
			return -1;
		}
	}
	
	void primeFactor(int num){
		for(int i=2; i<=num/2; i++){
			bool ch = true;
			bool m = true;
			if(i>3){
				while(ch==true && m==true){
					for(int j=2; j<=i/2; j++){
						if(i%j==0){
							ch = false;
							break;
						}
					}
					m = false;
				}	
				if(ch==true){
					if(num%i==0)
						push(i);
				}
			}else{
				if(i==2 || i==3){
					if(num%i==0){
						push(i);
						cout<<"h";
					}
				}
			}
		}
		
	}
};

int main(){
	Stack s;
	Stack s1;
	for(int k=1; k<=5; k++){
		int a = k*10;
		s.push(a);
	}
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.push(50);
	
	while(!s.isempty()){
		cout<<s.peek()<<endl<<"__"<<"\n\n";
		s.pop();
	}
	cout<<s.peek();
	cout<<"\n\n";
	
	s1.primeFactor(49);
	while(!s1.isempty()){
		cout<<s1.peek()<<endl;
		s1.pop();
	}
	
}