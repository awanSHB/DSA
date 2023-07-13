#include <iostream>
using namespace std;
int main(){
	int v = 10;
	int *ptr;
	
	ptr = &v;
	cout << ptr << endl;
	
	int **gtr = &ptr;
	cout << gtr << endl;
	
	int *g = *&ptr;
	cout << g;
}
