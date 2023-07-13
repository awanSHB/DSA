#include <iostream>
using namespace std;

int BinarySearchAsc(int A[], int lower, int upper, int key){
	int middle = (lower+upper)/2;
	
	if(upper < lower)
		return -1;
	
	if(A[middle]==key)
		return middle;
	
	if(key < A[middle])
		return BinarySearchAsc(A, lower, middle-1, key);
	else
		return BinarySearchAsc(A, lower+1, upper, key);
}

int BinarySearchDsc(int A[], int lower, int upper, int key){
	int middle = (lower+upper)/2;
	
	if(upper < lower)
		return -1;
	
	if(A[middle]==key)
		return middle;
	
	if(key > A[middle])
		return BinarySearchDsc(A, lower, middle-1, key);
	else
		return BinarySearchDsc(A, lower+1, upper, key);
}


int main(){
	int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int res = BinarySearchAsc(A, 0, 9, 70);
	cout<<res<<endl;
	
	int B[10] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	res = BinarySearchDsc(B, 0, 9, 70);
	cout<<res<<endl;
}