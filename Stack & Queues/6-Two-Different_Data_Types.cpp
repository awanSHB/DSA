#include<iostream>
using namespace std;

union stkData{
	int ival;
	float fval;
};

struct Stack{
	public:
		stkData *A;
		int s;
		int top;
//		bool isInt;
		
		Stack(int size){
			s = size;
			top = 0;
			A = new stkData[s];
//			isInt = true;
		}
		
		bool isFull(){
			return top==s;
		}
		bool isEmpty(){
			return top==0;
		}
	
	
	void push(stkData e){
		if(isFull()){
			cout<<"\n\nStack is Full!!!!\n\n";
		}else{
			A[top++] = e;
//			isInt = (e.ival==e.fval);//(sizeof(e)==sizeof(stkData));

		}
	}
	
	void push(int ival){
		stkData e;
		e.ival = ival;
		push(e);
	}
	
	void push(float fval){
		stkData e;
		e.fval = fval;
		push(e);
	}
	
	void pop(){
		if(!isEmpty())
			top--;
	}
	
	stkData peek(){
		if(!isEmpty())
			return A[top-1];
	}
	
	void display(){
		cout<<"\n\n";
		for(int i=top-1; i>=0; i--){
			if(sizeof(A[i])==sizeof(int))
				cout<<"\t\t|_"<<A[i].ival<<"_|\n";
			else{
				cout<<"\t\t|_"<<A[i].fval<<"_|\n";
			}
				
		}
	}
};

int main(){
	Stack s(10);
	
	s.push(1);
	s.push(1.5f);
	s.push(3);
	s.display();
}













