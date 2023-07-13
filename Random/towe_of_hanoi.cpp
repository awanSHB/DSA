//c++ program to implement tower of hanoi problem
#include<iostream>
using namespace std;

/*
In this case we are moving it All disks to B.

	|		|		|
	|		|		|
	-		|		|
   ---		|		|
  -----		|		|
  -------------------
	A		B		C
	
The output will be:


	|		|		|
	|		|		|
	|		-		|
    |	   ---		|
    |	  -----		|
	-----------------
	A		B		C

*/


//recursive funtion
void TowerOfHanoi(int n, char from, char tr, char ar){
	if(n==1){
		printf("\nMove dist 1 from %c to %c", from, tr);
		return;
	}
	TowerOfHanoi(n-1, from, ar, tr);
	printf("\nMove disk %d from %c to %c", n, from, tr);
	TowerOfHanoi(n-1, ar, tr, from);
}
//main funtion
int main(){
  int numOfDisk;
  cout<<"Enter the no. of disks"<<endl;
  cin>>numOfDisk;
  
  //calling recursive funtion
  TowerOfHanoi(numOfDisk,'A','B','C');//A is the source rod , C is destination rod ,B is auxiliary rod
  cout<<endl;
}