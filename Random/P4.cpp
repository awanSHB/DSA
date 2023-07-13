#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void push(Node **head, int new_data){
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

void insertafter(Node *prev_node, int new_data){
	if (prev_node==NULL){
		cout<<"Cannot assign value: "<<endl;
		return;
	}
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void atlast(Node **head, int new_data){
	Node *new_node = new Node();
	Node *last = *head;
	new_node->data = new_data;
	new_node->next = NULL;
	
	if (*head==NULL){
		*head = new_node;
		return;
	}
	while(last->next!=NULL){
//		cout << " " << last->data;
		last = last->next;
	}
	last->next = new_node;
	return;
}

void printlist(Node *node){
	while(node!=NULL){
		cout << " " << node->data;
		node = node->next;
	}
}

int main(){
	Node *head = NULL;
	
	atlast(&head, 10);
	
	push(&head, 11);
	push(&head, 9);
	
	atlast(&head, 7);
//	push(&head, 1);
	
	insertafter(head->next, 12);
	cout << "Created list is :";
	printlist(head);
	return 0;
}