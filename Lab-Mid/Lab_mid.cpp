#include <iostream> // This library provides input and output stream functionalities. It allows you to 
					// perform input/output operations using cin and cout objects
#include <fstream>  // This library provides file stream functionalities. It allows you to perform 
				    // input/output operations on files.you can create, open, read, write, and close files
#include <sstream>  // This library provides string stream functionalities. It allows you to treat strings 
					// as streams, which is useful for parsing and manipulating strings
#include <vector>	// This library provides a dynamic array implementation called vector. It allows you to 
					// create and manipulate dynamic arrays that can grow or shrink in size as needed
#include <string>	// This library provides string manipulation functionalities.

using namespace std;

struct Node{
	string name;
	string team;
	int age;
	int weight;
	int salary;
	Node *next;
	Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void add(string nm, string t, int a, int w, int s){
	Node *n = new Node;
	n->name = nm;
	n->team = t;
	n->age = a;
	n->weight = w;
	n->salary = s;
	n->next = NULL;
	
	if(head==NULL){
		head = n;
		tail = n;
		n->next = NULL;
		return;
	}
	
	n->prev = tail;
	tail->next = n;
	tail = n;
}

void display(){
	if(head==NULL)
		return;
	cout<<"\nPlayer_name,      Team_name,      Age,      Weigth,      Salary"<<endl;
	cout<<"\n--------------------------------------------"<<endl;
	for(Node *h = head; h!=NULL; h = h->next)
		cout<<h->name<<",      "<<h->team<<",      "<<h->age<<",      "<<h->weight<<",      "<<h->salary<<endl;
}

// Show the info of the specific player
void showPlayer(string n){
	if(head==NULL)
		return;
	
	for(Node *h = head; h!=NULL; h = h->next){
		if(h->name==n){
			cout<<"\nName   :  "<<h->name<<"\n";
			cout<<"Team   :  "<<h->team<<"\n";
			cout<<"Age    :  "<<h->age<<"\n";
			cout<<"Weight :  "<<h->weight<<"\n";
			cout<<"salary :  "<<h->salary<<"\n";
			return;
		}
	}
	cout<<"\n\nThe Player "<<n<<" Doesn't Exists in the given dataset!!!!\n";
}

//show the info of those players whose salary is greater than the given amount
void showPlayerSalary(int s){
	if(head==NULL)
		return;
	cout<<"\n\n\nThe Players with salary greater than "<<s<<" are :\n\n";
	for(Node *h = head; h!=NULL; h = h->next){
		if(h->salary > s){
			cout<<"\nName   :  "<<h->name<<"\n";
			cout<<"Team   :  "<<h->team<<"\n";
			cout<<"Age    :  "<<h->age<<"\n";
			cout<<"Weight :  "<<h->weight<<"\n";
			cout<<"salary :  "<<h->salary<<"\n";
		}
	}
}


//Show those players who play in the given team
void showPlayerTeam(string t){
	if(head==NULL)
		return;
	cout<<"\n\nPlayer who play in "<<t<<" are :\n";
	for(Node *h = head; h!=NULL; h = h->next){
		if(h->team==t){
			cout<<"\n\nName   :  "<<h->name<<"\n";
			cout<<"Age    :  "<<h->age<<"\n";
			cout<<"Weight :  "<<h->weight<<"\n";
			cout<<"salary :  "<<h->salary;
		}
	}
	
	
}


//Delete those players whose salary is less than provided amount
void deleteNode(int s){
	if(head==NULL)
		return;
	
	for(Node *h = head; h!=NULL; h = h->next){
		
		if(h==head || h==tail && head==tail)
			head = tail = NULL;
		else if(h==head){
			head = head->next;
			head->prev = NULL;
		}
		else if(h==tail){
			tail = tail->prev;
			tail->next = NULL;
		}
		else{
			h->prev->next = h->next;
			h->next->prev = h->prev;
		}
	}
}


int main(){
	ifstream F;
	F.open("D:\\PROGRAMMING\\DATASETS\\nba.csv");
	
	string line, word;
	vector<string> linedata;
	int lines = 0;
	
	while(!F.eof()){
		getline(F, line);
		stringstream s(line);
		while(getline(s, word, ',')){
			linedata.push_back(word);
		}
		
		stringstream s2(linedata[4]);
		int age;
		s2>>age;
		
		stringstream s3(linedata[6]);
		int weight;
		s3>>weight;
		
		stringstream s4(linedata[8]);
		int salary;
		s4>>salary;
		
		if(lines!=0)
			add(linedata[0], linedata[1], age, weight, salary);
		
		linedata.clear();
		lines++;
	}
	
//	display();
	cout<<"\nEnter the name of the player : ";
	string nm;
	getline(cin, nm);

	showPlayer(nm);
	
//	showPlayerTeam("New York Knicks");
//	
//	showPlayerSalary(9000000);

//	deleteNode(900000);
	
	cout<<"\n\nDo You want to continue:y/n ";
	char choice = 'y';
	while(choice=='y'){
		
		
	}
	
		
}






