#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL;

void display(){
	Node *l = head;
	cout<<"\nhead\n |\n";
	while(l!=NULL){
		cout<<"["<<l->data<<"] --> ";
		l = l->next;
	}
	cout<<"NULL\n\n\n\n";
}

void show(Node **head){
	Node *t = *head;
	cout<<"\n\nhead\n |\n";
	while(t!=NULL){
		cout<<"["<<t->data<<"] --> ";
		t = t->next;
	}
	cout<<"NULL\n";
}

//Inserting at end
void end(int v){
	Node *n = new Node;
	n->data = v;
	n->next = NULL;
	if(head==NULL){
		head = n;
		return;
	}
	
	Node *t = head;
	while(t->next!=NULL)
		t = t->next;
	t->next = n;
	
}

//Reverse Using Recursion
void reverse(Node *n){
	if(n==NULL)
		return;
	reverse(n->next);
	cout<<"[ "<<n->data<<" ]  ";
}

//Reverse Complete Structure
void inverse(){
	Node *n = head;
	Node *p = NULL;
	Node *t = NULL;
	while(n!=NULL){
		t = n->next;
		n->next = p;
		p = n;
		n = t;
	}
	head = p;
}

//Find The Number of occurrences of a certain element in a list
void findOccurences(int val){
	int c = 0;
	if(head==NULL)
		return;
	Node *t = head;
	while(t!=NULL){
		if(t->data==val)
			c++;
		t = t -> next;
	}
	cout<<"The Element ["<<val<<"] Occurs --> "<<c<<" Times in a List\n\n";
}


void insert(Node **head, int v){
	Node *n = new Node;
	Node *t = *head;
	n->data = v;
	n->next = NULL;
	
	if(*head==NULL){
		*head = n;
	}else if(v < t->data){
		n->next = *head;
		*head = n;
	}
	else{
		while (t->next != NULL && t->next->data <= v)
    		t = t->next;
		n->next = t->next;
		t->next = n;
	}
}

//Merging two LinkedList into a third linkedlist 
void merge(Node **head1, Node **head2){
	struct Node *head3 = NULL;
	Node *t1 = *head1;
	Node *t2 = *head2;
	
	while(t1!=NULL){
		insert(&head3, t1->data);
		t1 = t1->next;
	}
	
	while(t2!=NULL){
		insert(&head3, t2->data);
		t2 = t2->next;
	}
	show(&head3);
}

void removeSimilar(Node **head){
	Node *a = *head;
	Node *b = NULL;
	while(a->next!=NULL){
		b = a;
		while(b->next!=NULL){
			if(a->data==b->next->data){
				b->next = b->next->next;
			}else
				b = b->next;
		}
		a = a->next;
	}
}

int main(){
	end(10);
	end(20);
	end(30);
	end(40);
	end(50);
	end(30);
	end(30);
	end(40);
	display();
	
	findOccurences(30);
	
	inverse();
	display();
	
	reverse(head);
	
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	
	insert(&head1, 10);
	insert(&head1, 30);
	insert(&head1, 20);
	insert(&head1, 40);
	show(&head1);
	
	insert(&head2, 70);
	insert(&head2, 80);
	insert(&head2, 50);
	insert(&head2, 60);
	show(&head2);
	
	merge(&head1, &head2);
	
	struct Node *head4 = NULL;
	insert(&head4, 1);
	insert(&head4, 2);
	insert(&head4, 1);
	insert(&head4, 3);
	insert(&head4, 1);
	insert(&head4, 4);
	show(&head4);
	removeSimilar(&head4);
	show(&head4);
}