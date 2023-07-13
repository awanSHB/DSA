#include "Stack.h"
#include "LinkedList.h"

class Stack{
	private:
		LinkedList ll;
	public:
		bool isEmpty(){
			return A.isEmpty();
		}
	void push(int v){
		A.insertAtbeginning(int v);
	}
	void pop(int v){
		A.removeFirst();
	}
	
	int peek(){
		if(!isEmpty()){
			return A.getFirst();
		}
		else{
			return -1;
		}
	}
	
};