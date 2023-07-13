#include<iostream>
using namespace std;

const int size = 10;

class Node{
	public:
		int data;
		int next;
};

class LinkedList{
	public:
		Node nodes[size];
		int head;
		int tail;
		int count;
		int freelist;
		
		LinkedList(){
			head = -1;
			tail = -1;
			count = 0;
			freelist = 0;
			
			for(int i=0; i<size-1; i++)
				nodes[i].next = i+1;
			nodes[size-1].next = -1;
		}
		
		void display(){
			int n = head;
			cout<<"head\n  |\n";
			while(n!=-1){
				cout<<"["<<nodes[n].data<<"|"<<nodes[n].next<<"] ";
				n = nodes[n].next;
			}
			cout<<"---tail";
		}
		
		int createNode(int d){
			int node = freelist;
			freelist = nodes[node].next;
			nodes[node].data = d;
			nodes[node].next = -1;
			++count;
			return node;
		}
		
		void insert(int data){
			int node = createNode(data);
			if(head==-1)
				head = node;
			else
				nodes[tail].next = node;
			tail = node;
		}
		
};

int main(){
	LinkedList l;
	l.insert(10);
	l.insert(20);
	l.insert(30);
	l.insert(40);
	l.insert(50);
	
	l.display();
}















