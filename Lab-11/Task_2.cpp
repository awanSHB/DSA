#include<iostream>
using namespace std;

struct edge {
	int data;
	edge* next;
};

struct node {
	int data;
	node* next;
	edge* head;
	edge* tail;
};

node* head = NULL;
node* tail = NULL;

void insert_vertex(int data) {
	node* n = new node;
	n->data = data;
	n->head = NULL;
	n->tail = NULL;

	if (head == NULL) {
		n->next = NULL;
		head = tail = n;
	}
	else {
		tail->next = n;
		tail = n;
		tail->next = NULL;
	}
}

bool check_uname(int data) {
	node* t = head;
	while (t != NULL && t->data != data)
		t = t->next;
	if (t == NULL) {
		cout << "\n\nThe 2nd vertex not found!!!\n\n";
		return false;
	}
	return true;
}

void add_edge(int vname, int uname) {
	node* t = head;
	while (t != NULL && t->data != vname)
		t = t->next;
	if (t == NULL) {
		cout << "\n\nSource Vertex not Found!!!\n\n";
		return;
	}

	if (!check_uname(uname)) {
		return;
	}

	edge* e = new edge;
	e->data = uname;
	if (t->head == NULL) {
		e->next = NULL;
		t->head = t->tail = e;
	}
	else {
		t->tail->next = e;
		t->tail = e;
		e->next = NULL;
	}
}

void display() {
	node* t = head;
	edge* e;

	while (t != NULL) {
		e = t->head;
		cout << t->data << " --> ";
		while (e != NULL) {
			cout << e->data << " ";
			e = e->next;
		}
		cout << "\n";
		t = t->next;
	}
}

int main() {
	insert_vertex(1);
	insert_vertex(2);
	insert_vertex(3);
	insert_vertex(4);
	insert_vertex(5);

	add_edge(1, 2);
	add_edge(2, 10);
	add_edge(1, 4);
	add_edge(4, 1);
	add_edge(1, 3);

	display();
}
