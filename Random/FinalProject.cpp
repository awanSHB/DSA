#include <iostream>
#include <cstdlib>
//#include <array>
#include <ctime>
#include <string>
//#in
using namespace std;

const int NUM_CITIES = 30;
    int ROWS=30;
    int COLS = 30;
void display(int array[30][30]){
	for (int i = 0; i < 30; i++) {
//    cout << "\n"<<cities[i] << ": ";
    for (int j = 0; j < 30; j++) {
      cout << array[i][j] << "   ";
    }
  }
}


int main(){
    



    string cities[60]= {"Islamabad ","Karachi ","Hyderabad ","Sukkur ","Mirpur Khas ","Larkana ",
 "Jacobabad ","Shikarpur ","Dadu ","Khairpur ","Naushero Feroze ","Sahiwal ","DG Khan ","Muzaffargarh ","Tando Allahyar "
 ,"Tando Muhammad Khan ","Matiari ","Jamshoro ","Thatta ","Badin ","Lahore ","Faisalabad ","Rawalpindi ","Multan "
 ,"Gujranwala ","Sialkot ","Bahawalpur ","Sargodha ","Jhang ","Sheikhupura " };



        string ind[30];
        int starting = 0;
        int ending =0;

        

    for (int i = 0; i < 30; i++) {
        cout<<(i+1)<<". "<< cities[i]<<"\n";
        ind[i] = cities[i];
        
    }
//    cout<<"\n\n";
//    cout<<"Select a Starting City from the list Above\n";
//    cin>> starting;
//
//    cout<<"\nSelect your Destiny\n";
//    cin>> ending;
//
//    cout<<"Starting city: "<<ind[starting-1]<<endl;
//    cout<<"Destiny : "<<ind[ending-1]<<endl;

//    string st = ind[starting-1];
//    string en = ind[ending-1];


    int array[ROWS][COLS];

  // Seed the random number generator
  srand(time(0));

  // Generate and store random values in the array
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == j) {
        array[i][j] = 0;
      } else {
        array[i][j] = rand() % 100;
      }
    }
  }
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      array[i][j] = array[j][i];

       }
  }
  //updating some values to 0 means no way directly there
  for (int i = 0; i < ROWS; i++) {
    for (int j = 20+i; j < COLS; j++) {
      array[i][j] = 0;

       }
  }


//        int start_index, end_index;
//
//        for (int i = 0; i < ROWS; i++) {
//            if (cities[i] == st) {
//              start_index = i;
//            }   
//            if (cities[i] == en) {
//                end_index = i;
//            }
//        }
       // Look up the distance in the array

//        int distance = array[start_index][end_index];
//        cout<<"Distance from "<<st<<" to "<<en<<" :" <<distance<<"\n\n\n ";

        //printing column names for heading
  for (int i = 0; i < COLS; i++) {
    cout << " " << cities[i];
  }
  cout << endl;
       
    display(array);

        // Print the array
  for (int i = 0; i < ROWS; i++) {
//    cout << "\n"<<cities[i] << ": ";
    for (int j = 0; j < COLS; j++) {
      cout << array[i][j] << "   ";
    }
  }
}



//        int start_index, end_index;
//
//        for (int i = 0; i < 30; i++) {
//            if (cities[i] == st) {
//              start_index = i;
//            }   
//            if (cities[i] == en) {
//                end_index = i;
//            }
//        }
       // Look up the distance in the array

//        int distance = array[start_index][end_index];
//        cout<<"Distance from "<<st<<" to "<<en<<" :" <<distance<<"\n\n\n ";


//    cout<<"\n\n";
//    cout<<"Select a Starting City from the list Above\n";
//    cin>> starting;
//
//    cout<<"\nSelect your Destiny\n";
//    cin>> ending;
//
//    cout<<"Starting city: "<<ind[starting-1]<<endl;
//    cout<<"Destiny : "<<ind[ending-1]<<endl;

//    string st = ind[starting-1];
//    string en = ind[ending-1];

	//printing column names for heading
//  for (int i = 0; i < 30; i++) {
//    cout << " " << cities[i];
//  }
//  cout << endl;

//lse{
//		for(int i=e; i>=s; i-=6){
//			int me = i-6;
//			if(i>=0 && i<6){
//				if(s < 6)
//					cout<<cit[i]<<" TO "<<cit[s]<< " :- [Faisal_movers]\n";
//				else
//					cout<<cit[i]<<" TO "<<cit[6]<< " :- [Faisal_movers]\n";
//			}else if(i>=6 && i<12){
//				if(s<12)
//					cout<<cit[6]<<" TO "<<cit[s]<< " :- [Daewoo]\n";
//				else
//					cout<<cit[6]<<" TO "<<cit[12]<< " :- [Daewoo]\n";
//			}else if(i>=12 && i<18){
//				if(s < 18)
//					cout<<cit[12]<<" TO "<<cit[s]<< " :- [Kohistan]\n";
//				else
//					cout<<cit[12]<<" TO "<<cit[18]<< " :- [Kohistan]\n";
//			}else if(i>=18 && i<24){
//				if(s < 24)
//					cout<<cit[18]<<" TO "<<cit[s]<< " :- [skyways]\n";
//				else
//					cout<<cit[18]<<" TO "<<cit[24]<< " :- [skyways]\n";
//			}
//			else if(i>=24 && i<30){
//				if(s < 30)
//					cout<<cit[24]<<" TO "<<cit[s]<< "  :- [sania_express]\n";
//				else
//					cout<<cit[24]<<" TO "<<cit[30]<< " :- [sania_express]\n";
//			}
//		}
//		
//	}

//else{
//		for(int i=e; i>=s; i--){
//			if(i>=24 && i<30)
//				buses[tr++] = "sania_express";
//			else if(i>=18 && i<24)
//				buses[tr++] = "skwyways";
//			else if(i>=12 && i<18)
//				buses[tr++] = "Kohistan";
//			else if(i>=6 && i<12)
//				buses[tr++] = "Daewoo";
//			else if(i>=0 && i<6)
//				buses[tr++] = "Faisal_movers";
//		}
//	}

	if(e >s){