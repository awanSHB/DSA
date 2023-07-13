#include <iostream>
using namespace std;

int main()
{
	int val[3] = {4, 5, 6};
	int *p;
	p = val;
	
	cout <<"Elements:"<<endl;
	cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
	
	cout<<"Adresses are:";
	cout<<&p[0]<<" "<<&p[1]<<" "<<&p[2]<<" ";
}