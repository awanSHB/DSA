#include <iostream>
#include <string.h>
using namespace std;

class Student{
	public:
		string name;
		string reg_no;
		double gpa;
		
		Student(){
			name = "";
			reg_no = "";
			gpa = 0.0;
		}
		
		Student(string n, string rn, double g){
			name = n;
			reg_no = rn;
			gpa = g;
		}
};

class MaxHeap{
	private:
		Student *A[10];
		int n;
		
	public:
		MaxHeap(){
			n = 0;
		}

		
	void insert(string nn, string rn, double g){
		Student *s = new Student(nn, rn, g);
		A[n++] = s;
		heapUp(n-1);
	}
	
	void heapUp(int c){
		if(c==0)
			return;
		
		int p;
		
		if(c%2==1)
			p = (c-1)/2;
		else
			p = (c-2)/2;
		
		if(A[c]->gpa == A[p]->gpa){
			cout<<"hh";
			int r = A[c]->reg_no.compare(A[p]->reg_no);
			if(r > 0){
				Student *t = A[p];
				A[p] = A[c];
				A[c] = t;
			}
		}
		
		if(A[c]->gpa > A[p]->gpa){
			Student *t = A[c];
			A[c] = A[p];
			A[p] = t;
			
			heapUp(p);
		}
		
	}
	
	void remove(){
		A[0] = A[n-1];
		n--;
		heapDown(0);
	}
	
	void heapDown(int p){
		if(n<=1)
			return;
		
		int l = 2*p+1;
		int r = 2*p+2;
		int c;
		
		if(l<n){
			if(r<n){
				if(A[l]->gpa > A[r]->gpa){
					c = l;
				}else{
					c = r;
				}
			}else{
				c = l;
			}
		}else
			return;
		
		if(A[c]->gpa > A[p]->gpa){
			Student *t = A[c];
			A[c] = A[p];
			A[p] = t;
			
			heapDown(c);
		}
			
	}
	
	void display(){
		for(int i=0; i<n; i++){
			cout<<"\n______________"<<endl;
			cout<<"Name   :- "<<A[i]->name<<"  "<<endl;
			cout<<"Reg_no :- "<<A[i]->reg_no<<"  "<<endl;
			cout<<"GPA    :- "<<A[i]->gpa<<"  "<<endl;
			cout<<"______________"<<endl;
		}
	}
};

int main(){
	MaxHeap mh;
	
	mh.insert("A", "123", 3.5);
	mh.insert("B", "1234", 3.3);
	mh.insert("C", "145", 3.0);
	mh.insert("E", "122", 3.0);
	mh.insert("D", "132", 2.3);
	mh.insert("F", "543", 3.2);
	mh.insert("G", "130", 2.4);
	
//	mh.remove();
	
	mh.display();
}