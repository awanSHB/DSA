#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int val){
		data = val;
		next = NULL;
	}
};

void start(Node *&head, int val){
	Node *n = new Node(val);
	n->next = head;
	head = n;
}

void after(Node *head, int key, int val){
	Node *n = new Node(val);
	if(key == head->data){
		n->next = head->next;
		head->next = n;
		return;
	}
	
	Node *temp = head;
	while(temp->data!=key){
		temp = temp->next;
		if(temp==NULL){
			return;
		}
	}
	
	n->next = temp->next;
	temp->next = n;
}

void atend(Node *&head, int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
		return;
	}
	
	Node *t = head;
	while(t->next!=NULL){
		t = t->next;
	}
	t->next = n;
}

void print(Node *&head){
	Node *t = head;
	while(t!=NULL){
		cout << t->data << " ";
		t = t->next;
	}
}

int main(){
	Node *head = NULL;
	start(head, 1);
	start(head, 2);
	cout << "After first insertion: ";
	print(head);
	cout << endl;
	
	atend(head, 5);
	atend(head, 6);
	cout << "After appending :";
	print(head);
	cout<<endl;
	
	after(head, 1, 3);
	after(head, 3, 4);
	cout << "The complete list: ";
	print(head);
}