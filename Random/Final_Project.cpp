
//------------------------- Route Planner ---------------------------------#
//----------------- Presented BY : Ubaid and Sohaib -----------------------#
//------------------ Data Structures And Algorithm -------------------------#


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define INF 99999

using namespace std;

const int NUM_CITIES = 30;
void display(int array[30][30]){
	for (int i = 0; i < 30; i++) {
    	for (int j = 0; j < 30; j++) {
    		cout <<"[" <<array[i][j] << "]";
    	}
    	cout<<endl;
  	}
}

void path(int G[30][30]){
	int selected[30];
	int total_distance = 0;
	int row = 0;
	int col = 0;
	int no_of_cities = 0;
	selected[1] = 1;
	
	//Creating a random matrix
	int T[30][30];
	
	for(int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			T[i][j] = 0;
		}
	}
	
	while(no_of_cities < 29){
		int min = INF;
		for(int i=0; i<30; i++){
			if(selected[i]){
				for(int j=0; i<30; j++){
					if(!selected[j] && G[i][j]!=0){
						if(G[i][j] < min){
							min = G[i][j];
							cout<<"min---"<<min<<endl;
							row = i;
							col = j;
						}
					}
				}
			}
		}
		no_of_cities++;
		selected[col] = 1;
		total_distance += min;
		T[row][col] = min;
	}
	cout<<total_distance<<endl;
	display(T);
}

void showroutes(string r[6]){
	cout<<r[0];
	for(int i=1; i<6; i++){
		if(r[i]!="")
			cout<<"<--->"<<r[i];
	}
	cout<<"\n\n";
}

void Operator(string city[30]){
	string faisal_movers[6];
	for(int i=0; i<6; i++){
		faisal_movers[i] = city[i];
	}
	
	string Daewoo[6];
	for(int i=0; i<6; i++){
		Daewoo[i] = city[i+6];
	}
	
	string Kohistan[6];
	for(int i=0; i<6; i++){
		Kohistan[i] = city[i+12];
	}
	
	string skyways[6];
	for(int i=0; i<6; i++){
		skyways[i] = city[i+18];
	}
	
	string sania_express[6];
	for(int i=0; i<6; i++){
		sania_express[i] = city[i+24];
	}
	
	cout<<"\nfaisal_movers routes are :- \n";
	cout<<"____________________________\n\n";
	showroutes(faisal_movers);
	
	cout<<"\nDaewoo routes are :- \n";
	cout<<"_____________________\n\n";
	showroutes(Daewoo);
	
	cout<<"\nKohistan routes are :- \n";
	cout<<"_______________________\n\n";
	showroutes(Kohistan);
	
	cout<<"\nskyways routes are :- \n";
	cout<<"______________________\n\n";
	showroutes(skyways);
	
	cout<<"\nsania_express routes are :- \n";
	cout<<"____________________________\n\n";
	showroutes(sania_express);
	
}

void show(string R[30], int noe){
	cout<<"["<<R[0];
	for(int i=1; i<noe; i++)
		cout<<", "<<R[i];
	cout<<"]";
}

void FindRoutes(string start, string end, int T[30], string cit[30]){
	int tt;
	int s = 0;
	int e = 0;
	cout<<"\n\nYour starting Destination is :- "<<start<<endl;
	cout<<"Your Ending Destination is :- "<<end<<"\n\n";
	for(int i=0; i<30; i++){
		string ns = cit[i];
		int x = start.compare(ns);
		if(x==0){
			s = i;
			break;
		}
	}
	for(int i=0; i<30; i++){
		string ne = cit[i];
		int y = end.compare(cit[i]);
		if(y==0){
			e = i;
			break;
		}
	}
	if(e > s){
		for(int i=s; i<e; i++){
			tt+=T[i];
		}
	}else{
		for(int i=e; i>s; i--){
			tt+=T[i];
		}
	}
	
	string buses[e-1+1];
	int tr = 0;
	

		for(int i=s; i<=e; i++){
			if(i>=0 && i<6)
				buses[tr++] = "Faisal_movers";
			else if(i>=6 && i<12)
				buses[tr++] = "Daewoo";
			else if(i>=12 && i<18)
				buses[tr++] = "Kohistan";
			else if(i>=18 && i<24)
				buses[tr++] = "skwyways";
			else if(i>=24 && i<30)
				buses[tr++] = "sania_express";
		}

	
	
	cout<<"\n\n";
	if(e > s){
		for(int i=s; i<=e; i+=6){
			int me = i+6;
			if(i>=0 && i<6){
				if(e < 6)
					cout<<cit[i]<<" TO "<<cit[e]<< " :- [Faisal_movers]\n";
				else
					cout<<cit[i]<<" TO "<<cit[6]<< " :- [Faisal_movers]\n";
			}else if(i>=6 && i<12){
				if(e<12)
					cout<<cit[6]<<" TO "<<cit[e]<< " :- [Daewoo]\n";
				else
					cout<<cit[6]<<" TO "<<cit[12]<< " :- [Daewoo]\n";
			}else if(i>=12 && i<18){
				if(e < 18)
					cout<<cit[12]<<" TO "<<cit[e]<< " :- [Kohistan]\n";
				else
					cout<<cit[12]<<" TO "<<cit[18]<< " :- [Kohistan]\n";
			}else if(i>=18 && i<24){
				if(e < 24)
					cout<<cit[18]<<" TO "<<cit[e]<< " :- [skyways]\n";
				else
					cout<<cit[18]<<" TO "<<cit[24]<< " :- [skyways]\n";
			}
			else if(i>=24 && i<30){
				if(e < 30)
					cout<<cit[24]<<" TO "<<cit[e]<< "  :- [sania_express]\n";
				else
					cout<<cit[24]<<" TO "<<cit[30]<< " :- [sania_express]\n";
			}
		}
	}
	
	cout<<"\n\n"<<buses[0];
	for(int i=0; i<e-1+1; i++){
		cout<<"---->"<<buses[i];		
	}
	
	if(e>s){
		cout<<"\n\nYour Traveling Routes will be : \n";
		cout<<cit[s];
		for(int i=s+1; i<=e; i++){
			cout<<"---->"<<cit[i];
		}
		cout<<"\b\b\b\b";
	}
	else if(s > e){
		cout<<"\n\nYour Traveling Routes will be : \n";
		cout<<cit[e];
		for(int i=e-1; i>=s; i--){
			cout<<"---->"<<cit[i];
		}
		cout<<"\b\b\b\b";
	}
	
	cout<<"\n\nThe Total distance from "<<start<<" To "<<end<<" is "<<tt<<"\n\n";
			
}

void Algorithm(int Graph[30][30], string city[30]){
	int S = 30;
	int no_of_edges = 0;
	int selected[S];
	for(int i=0; i<S; i++)
		selected[i] = 0;
	
	selected[0] = 1;
	
	int T[30][30];
	
	for(int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			T[i][j] = 0;
		}
	}
	
	string R[30];
	for(int i=0; i<30; i++)
		R[i] = "";
		
	int dis[30];
	
	int row;
	int col;
	int total_sum = 0;
	
	while(no_of_edges < S-1){
		int min = INF;
		for(int i=0; i<S; i++){
			if(selected[i]){
				for(int j=0; j<S; j++){
					if(!selected[j] && Graph[i][j]!=0){
						if(Graph[i][j] < min){
							min = Graph[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
		}
		
//		cout<<edges[row]<<" - "<<edges[col]<<" = "<<Graph[row][col]<<"\n";
		R[no_of_edges] = city[col];
		dis[no_of_edges] = min;
		no_of_edges++;
		selected[col] = 1;
		total_sum+=min;
//		cout<<"T["<<row<<"]["<<col<<"]---"<<min<<endl;
		T[row][col] = min;
	}
	Operator(R);
	cout<<"\n\nTotal MinDistance is:- "<<total_sum<<"\n\n";
	cout<<"\n\nYour Routes are:\n\n";
	show(R, no_of_edges);
	cout<<"\n\n";
	
	string start;
	string end;
	
	cout<<"Enter the starting destination:  ";
	cin>>start;
	cout<<"\nEnter the Ending destination:  ";
	cin>>end;
	
	FindRoutes(start, end, dis, R);
}


int main(){
    
    cout << "------------------------- Route Planner ---------------------------------#\n";
	cout << "----------------- Presented BY : Ubaid and Sohaib -----------------------#\n";
	cout << "------------------ Data Structures And Algorithm -------------------------#\n\n\n";
	

    string cities[60]= {"Islamabad","Karachi","Hyderabad","Sukkur","Mirpur Khas ","Larkana",
 "Jacobabad","Shikarpur","Dadu","Khairpur","Naushero Feroze ","Sahiwal","DG Khan","Muzaffargarh","Tando_Allahyar "
 ,"Tando_Muhammad_Khan ","Matiari","Jamshoro","Thatta","Badin","Lahore","Faisalabad","Rawalpindi","Multan"
 ,"Gujranwala","Sialkot","Bahawalpur","Sargodha","Jhang","Sheikhupura" };



        string ind[30];
        int starting = 0;
        int ending =0;



    int array[30][30];

  // Seed the random number generator
  srand(time(0));

  // Generate and store random values in the array
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++) {
      if (i == j) {
        array[i][j] = 0;
      } else {
        array[i][j] = rand() % 1000;
      }
    }
  }
	for (int i = 0; i < 30; i++) {
    	for (int j = i+1; j < 30; j++) {
      		array[j][i] = array[i][j];
		}
	}
  //updating some values to 0 means no way directly there
  for (int i = 0; i < 30; i++) {
    for (int j = 20+i; j < 30; j++) {
      array[i][j] = 0;

       }
  }



	for (int i = 0; i < 30; i++) {
    	for (int j = i+1; j < 30; j++) {
      		array[j][i] = array[i][j];
		}
	}
	
	Algorithm(array, cities);


}
