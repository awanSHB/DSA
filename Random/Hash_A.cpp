#include <iostream>
#define TABLE_SIZE 10
using namespace std;

int h[TABLE_SIZE] = {NULL};

void insert(){
	int key;
	int index;
	int flag=0;
	int hkey;
	int i;
	
	cout<<"Enter The Value To Insert Into Hash Table : ";
	cin>>key;
	cout<<"\n";
	
	hkey = key % TABLE_SIZE;
	cout<<"Key-->"<<key<<" hkey-->"<<hkey<<"\n";
	
	for(i=0; i<TABLE_SIZE; i++){
		index = (hkey+i) % TABLE_SIZE;
		
		if(h[index]==NULL){
			h[index] = key;
			break;
		}
	}
	if(i==TABLE_SIZE){
		cout<<"Element Cannot Be inserted\n";
	}
}

void Search(){
	int key, index, flag = 0, hkey, i;
	cout<<"\nEnter Search Element : ";
	cin>>key;
	cout<<"\n";
	
	hkey = key%TABLE_SIZE;
	for(i=0; i<TABLE_SIZE; i++){
		index = (hkey+i) % TABLE_SIZE;
		if(h[index]==key){
			cout<<"Value is Found at index "<<index;
			break;
		}
	}
	if(i==TABLE_SIZE){
		cout<<"\nValue is Not Found\n";
	}
}

void display(){
	cout<<"\nElement in the Hash Table are: \n";
	for(int i=0; i<TABLE_SIZE; i++){
		cout<<"\nAt index "<<i<<"\tValue ==> "<<h[i];
	}
}

int main(){
	int opt, i;
	while(1){
		cout<<"\n\n1.Insert \t2.Display \t3.Search \t4.Exit\n\n";
		cin>>opt;
		
		switch(opt){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				Search();
				break;
			case 4:
				exit(0);
		}
	}
}