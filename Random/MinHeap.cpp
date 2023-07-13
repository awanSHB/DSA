#include <iostream>
using namespace std;

class MinHeap{
	private:
		int n;
		int *A;
	
	public:
		MinHeap(){
			n = 0;
			A = new int[10];
		}
		
		MinHeap(int s){
			n = 0;
			A = new int[s];
		}
		
		//In heapUp child is compared with its parent
		void heapUp(int child){
			if(child==0)
				return;
			int parent;
			
			if(child%2==1)
				parent = (child-1)/2;
			else
				parent = (child-2)/2;
			
			if(A[child] < A[parent]){
				int t = A[child];
				A[child] = A[parent];
				A[parent] = t;
				heapUp(parent);
			}
		}
		
		//In heapDown parent is compared with its childs
		void heapDown(int parent){
			if(parent<=1)
				return;
			
			int child;
			int left = 2*parent-1;
			int right = 2*parent-2;
			
			//Checking if the childs exists or not
			//Checking if the left child exists
			if(left < n){
				//Checking if the right child exists
				if(right < n){
					if( A[left] < A[right])
						child = left;		//The smaller value will become a child
					else
						child = right;
				}else
					child = right;
			}else
				return;
			
			if(A[child] < A[parent]){
				int t = A[parent];
				A[parent] = A[child];
				A[child] = t;
				heapDown(child);
			}
		}
		
		void enqueue(int v){
			A[n++] = v;
			heapUp(n-1);
		}
		
		void dequeue(){
			A[0] = A[n-1];
			n--;
			heapDown(0);
			A[n] = 0;
		}
		
//		void display(){
//			cout<<"\t\t\t";
//			int k;
//			for(int i=0; i<7; i++){
//				cout << A[i] << " ";
//			}
//		}
		void d1(){
			cout<<"\t\t\t          "<<A[0]<<endl;
		}
		void d2(){
			cout<<"\t\t\t        "<<" /"<<"  "<<"\\"<<endl;
			cout<<"\t\t\t        "<<"/"<<"    "<<"\\"<<endl;
			cout<<"\t\t\t       "<<A[1]<<"      "<<A[2]<<endl;
		}
		void d3(){
			cout<<"\t\t\t    "<<" /"<<"\t"<<"\\"<<"  "<<"  /"<<"  "<<"\\"<<endl;
			cout<<"\t\t\t    "<<A[3]<<"\t"<<A[4]<<"  "<<A[5]<<"\t "<<A[6]<<"\n\n";
		}
		void show(){
			d1();
			d2();
			d3();
		}
};

int main(){
	MinHeap mn;
	int arr[] = {10, 11, 12, 8, 9, 80, 60};
	for(int i=0; i<7; i++)
		mn.enqueue(arr[i]);
	mn.show();
	
	mn.dequeue();
	mn.show();
	mn.enqueue(199);
	mn.show();
}