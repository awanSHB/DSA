#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int v){
			data = v;
			next = NULL;
		}
};

class LinkedList{
	private:
		Node *head;
	public:
		LinkedList()
		{
			head = NULL;
		}
	void insertbeginning(int v){
		Node *n = new Node(v);
		n->next = NULL;
		head = n;
	}
	
	void display(){
		Node *s = head;
		while (s!=NULL){
			cout << s->data;
			s = s->next;
		}
	}
	
	void Removeall()
	{
		head = NULL;
	}
};