#include<iostream>
using namespace std;

template <class T>
class Stack{
	private:
		int top;
		T *A;
		int size;
		int count;
	public:
		Stack(int s){
			top = 0;
			size = s;
			A = new T[size];
			count = 0;
			
		}
	
	void display(){
		cout<<"\n\n";
		int k = count-1;
		while(k>=0){
			cout<<"\t\t|_"<<A[k]<<"_|\n";
			k--;
		}
	}
		
	bool isEmpty(){
		return top==0;
	}
	
	bool isFull(){
		return (top==size);
	}
	
	void push(T v){
		if(!isFull()){
			A[top++] = v;
			count++;
		}
	}
	
	void pop(){
		if(!isEmpty()){
			top--;
			count--;
		}
	}
	
	T peek(){
		if(!isEmpty())
			return A[top-1];
		else
			return -1;
	}
	
};


int main(){
	Stack<int>s1(10);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.display();
	
	s1.pop();
	s1.display();
	
	cout<<"\n\nThe top Element is : "<<s1.peek();
	
	s1.push(50);
	s1.push(60);
	s1.push(70);
	s1.display();
	
	cout<<"\n\nThe top Element is : "<<s1.peek();
	
	
	Stack<char>s2(10);
	
	s2.push('A');
	s2.push('B');
	s2.push('C');
	s2.push('D');
	s2.display();
	
	cout<<"\n\nThe top Element is : "<<s2.peek();
	
	s2.pop();
	s2.display();
	
}



















