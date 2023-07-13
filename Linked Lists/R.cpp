#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

class Node {
public:
    int data;
    int next;
};

class LinkedList {
public:
    Node nodes[MAX_SIZE];
    int head;
    int tail;
    int freeList;
    int count;

    LinkedList() {
        head = -1;
        tail = -1;
        freeList = 0;
        count = 0;
        for (int i = 0; i < MAX_SIZE - 1; ++i) {
            nodes[i].next = i + 1;
        }
        nodes[MAX_SIZE - 1].next = -1;
    }
	
	void display() {
	    int node = head;
	    while (node != -1) {
	        cout << "[" << nodes[node].data << "] -->";
	        node = nodes[node].next;
	    }
	    cout << endl;
	}
    int createNode(int data) {
        int node = freeList;
        freeList = nodes[node].next;
        nodes[node].data = data;
        nodes[node].next = -1;
        ++count;
        return node;
    }

    void insert(int data) {
        int node = createNode(data);
        if (head == -1) {
            head = node;
        } else {
            nodes[tail].next = node;
        }
        tail = node;
    }

    void deleteNode(int node) {
        nodes[node].next = freeList;
        freeList = node;
        --count;
    }
    
    void remove(int data) {
        int prev = -1;
        int node = head;
        while (node != -1 && nodes[node].data != data) {
            prev = node;
            node = nodes[node].next;
        }
        if (node != -1) {
            if (prev == -1) {
                head = nodes[node].next;
            } else {
                nodes[prev].next = nodes[node].next;
            }
            if (tail == node) {
                tail = prev;
            }
            deleteNode(node);
        }
    }
};

int main(){
	LinkedList l;
	l.insert(10);
	l.insert(20);
	l.insert(30);
	l.display();
}







