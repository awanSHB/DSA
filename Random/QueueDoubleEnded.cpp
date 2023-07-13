#include <iostream>
using namespace std;

template <class T>

class DeQue{
	private:
		int size;
		int front;
		int rear;
		int count;
		T *A;
	public:
		DeQue(){
			size = 20;
			front = 0;
			rear = 0;
			count = 0;
			A = new T[size];
		}
		
		DeQue(int s){
			size = s;
			A = new T[size];
			front = 0;
			rear = 0;
			count = 0;
		}
		
	void insert_beg(T v){
		if(count==size){
			cout<<"Sorry!!! Cannot insert at Beginning!!"<<"\n\n";
			return;
		}
//		if(front==0)
//		{
////			rear = rear+1;
//			A[front++] = v;
//			count++;
//			rear++;
//		}
//		else if(front!=0)
//		{
////			front = front - 1;
//			A[front++] = v;
//			count++;
//			rear++;
//		}else{
//			cout<<"Front restriction - Sorry! Cannot Insert Elements At Beginning"<<endl;
//		}
		A[front--] = v;
		count++;
		
	}
	
	void insert_end(T v){
		if(count==size){
			cout<<"Sorry cannot insert at End!!!"<<"\n\n";
			return;
		}
		if(rear<=size-1){
//			rear = rear+1;
			A[++rear] = v;
			count++;
		}
		else {
			if(rear==size-1){
				A[rear] = v;
				count++;
			}
			
	 	}
	}
	
	void remove_beg(){
//		if(front!=0){
			cout<<"The deleted element is: "<<A[front]<<endl;
//			if(front==rear){
//				front = rear = 0;
//				return;
//			}
//		}else{
//			front = front+1;
//		}
		front ++;
		count--;
		
	}
	
	void remove_end(){
//		if(rear==size-1){
			cout<<"The deleted element is: "<<A[rear]<<endl;
//			if(front==rear){
//				front = rear = 0;
//				return;
//			}
//			else{
//				rear--;
//			}
//		}
//		rear = rear - 1;
		rear--;
		count--;
	}
	
	void display(){
		cout<<"\n\n\t\t\t| ";
		for(int i=front+1; i<=rear; i++)
			cout<<A[i]<<" | ";
	}
};

int main(){
	DeQue <int> q1(10);
	DeQue <char> q2;
	
	bool choice = true;
	bool decision = true;
	int a;
	int v;
	int b;
	int count;
	
	
	while(decision){
		count = 0;
		do{
			cout<<"\n\n\n1:- Insert Beginning: "<<endl;
			cout<<"2:- Insert End: "<<endl;
			cout<<"3:- Remove Beginning: "<<endl;
			cout<<"4:- Remove End: "<<"\n\n";
			cout<<"Enter You Choice : ";
			cin>>a;
			switch(a){
				case 1:
					cout<<"\nEnter the Value: ";
					cin>>v;
					q1.insert_beg(v);
					count++;
					break;
				case 2:
					cout<<"\nEnter the Value: ";
					cin>>v;
					q1.insert_end(v);
					count++;
					break;
				case 3:
					q1.remove_beg();
					count++;
					break;
				case 4:
					q1.remove_end();
					count++;
					break;
				default:
					cout<<"Plead Enter the correct Output"<<"\n\n";
			}
		}while(count<4);
		q1.display();
		cout<<"\n\nDo You want to Try Again?? Press 1 : ";
		cin>>b;
		if(b!=1)
			decision = false;
	}
}