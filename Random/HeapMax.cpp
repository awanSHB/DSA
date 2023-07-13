#include <iostream>
using namespace std;

class MaxHeap{
	
	private:
		int n;
		int *A;
	
	public:
		MaxHeap(){
			n = 0;
			A = new int[10];
		}
		MaxHeap(int a){
			n = 0;
			A = new int[a];
		}
		
		void heapUp(int child){
			if(child==0)
				return;
			int parent;
			
			if(child%2==1)					//Left child 
				parent = (child-1)/2;		//Finding parent of the left child 
			else
				parent = (child-2)/2;		//Findding parent of the right child 
			
			
			if(A[child] > A[parent]){		//Now checking if the child is greater than parent
				int t = A[child];
				A[child] = A[parent];
				A[parent] = t;
				heapUp(parent);				//Recursive call by passing parent as argument
			}								//This parent will become child, will find its parent
		}
		
		void heapDown(int parent){
			if(parent<=1)
				return;
			
			int left = 2 * parent + 1;
			int right = 2 * parent + 2;
			int child;
			
			//Checking whether the childs exist or not
			if(left<n)
			{
				if(right<n)				//Checking whether the right child exists or not
				{
					if(A[left]>A[right])
						child = left;
					else
						child = right;
				}
				else
					child = left;
			}else
				return;
				
			if(A[child] > A[parent]){
				int t = A[child];
				A[child] = A[parent];
				A[parent] = t;
				heapDown(child);
			}
		}
		
		void enque(int v){
			A[n++] = v;
			heapUp(n-1);
		}
		
		void remove(){
			A[0] = A[n-1];
			n--;
			heapDown(0);
		}
		
		void display(){
			cout<<"\n\n\t\t\t";
			for(int i=0; i<n; i++){
				cout<<" "<<A[i];
			}
			cout<<"\n\n";
		}
		
};

int main(){
	MaxHeap mx;
//	int arr[] = {10, 11, 12, 8, 9, 80, 60};
	int arr[] = {35, 33, 30, 23, 38, 32};
	for(int i=0; i<6; i++)
		mx.enque(arr[i]);
//	mx.remove();
	mx.display();
}