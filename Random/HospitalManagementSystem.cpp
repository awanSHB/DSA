/*                              
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    @@ ______________________________________________________________________ @@
    @@|                                                                      |@@
    @@|                 *** DATA STRUCTURES AND ALGORITHM ***                |@@
    @@|                           (SEMISTER PROJECT)                         |@@
    @@|                                                                      |@@
    @@|                                                                      |@@
    @@|                   SUBMITTED BY: AALLIYAN WAHEED ALVI                 |@@
    @@|                   SUBMITTED TO: DR. INAYAT-UR-REHMAN                 |@@
    @@|                                                                      |@@
    @@|                                                                      |@@
    @@|      PROJECT NAME:                                                   |@@
    @@|                    ### HOSPITAL MANAGEMENT SYSTEM ###                |@@
    @@|                                                                      |@@
    @@|                                                                      |@@
    @@|      DATE: 30-JUNE, 2021.                                            |@@
    @@|                                                                      |@@
    @@|                                     ~Code By Alliyan Waheed Alvi     |@@
    @@|______________________________________________________________________|@@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

*/

# include <iostream>
#include<climits>       // dijkstra's Algo...
# include <conio.h>      
using namespace std;


class Register{
  public:
    string username, password;
};

class Login{
  public:
    string inpUsername, inpPassword;
};
  
// **************** patients structue ****************

struct patients{

    int p_id;
    string p_name;
    string p_adderess;
    string p_contact_num;
    string p_age;
    string p_sex;
    string p_blood_group;
    string p_any_major_disease_earlier;
    
    patients *left = NULL;
    patients *right = NULL;
    patients *next = NULL;   // For implementation of priority queue
};

patients *root = NULL;
patients *p;
patients *k;
// for priority queue
patients *front = NULL;
patients *rear = NULL;

void traverse_patients_list(patients *root);
//void pre_order(patients *root);
//void post_order(patients *root);
void search_specific_patient(int key);
void remove_specific_patient(int val);
int total_num_of_patients(patients* root);
void dlisplay_patients_priority();
void enqueue(patients *curr);
void add_new_patient();
void corona_hospital();
void patients_bill();


// *************** Doctors Structure ****************

struct doctors{

    int d_id;
    string d_name;
    string d_sex;
    string d_age;
    string d_qualification;
    string d_specialization;
    string d_experience;
    string d_contact_num;
    string d_adderess;
    
    doctors *d_left = NULL;
    doctors *d_right = NULL;
};

doctors *d_root = NULL;
doctors *dp;
doctors *dk;

void add_new_doctor();
void traverse_doctors_list(doctors *d_root);
//void d_pre_order(doctors *d_root);
//void d_post_order(doctors *d_root);
void search_specific_doctor(int key);
void remove_specific_doctor(int val);
int total_num_of_doctors(doctors* d_root);




int main(){    

    // Register Screen
    Register newUser;
    
    cout<<"\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ ______________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                            		                                 |@@\n";
    cout<<"\t\t\t\t\t@@|                            *** WELCOME TO ***                        |@@\n";
    cout<<"\t\t\t\t\t@@|                    *** HOSPITAL MANAGEMENT SYSTEM ***                |@@\n";
    cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
    cout<<"\t\t\t\t\t@@|                        ### Register Your Account ###                 |@@\n";
    cout<<"\t\t\t\t\t@@|                                           	                         |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|   Please Register Your Account, then Login Below...                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|     Press Any Key to continue...                                     |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                     ~Code By Alliyan Waheed Alvi     |@@\n";
    cout<<"\t\t\t\t\t@@|______________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
      
    getch();

    cout<<"\t\t\t\t\t   *** Register Your Account ****"<<endl;
    cout<<"\t\t\t\t\t   ------------------------------"<<endl<<endl;
    
    cout<<"\t\t\t\t\t   Enter Your Username: ";  
    getline(cin, newUser.username);    

    cout<<"\t\t\t\t\t   Enter Your Password: ";  
    cin>>newUser.password;    
    
    cout<<endl<<"\t\t\t\t\t ******************************************"<<endl;


    cout<<"\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ ______________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                            		                                 |@@\n";
    cout<<"\t\t\t\t\t@@|                    *** HOSPITAL MANAGEMENT SYSTEM ***                |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                    * Information Saved Successfully! *               |@@\n";
    cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
    cout<<"\t\t\t\t\t@@|                                           	                         |@@\n";
    cout<<"\t\t\t\t\t@@|                      Your Username: "  << newUser.username;   
    cout<<"\t\t\t\t |@@\n";
    cout<<"\t\t\t\t\t@@|                      Your Passsword: " << newUser.password;   
    cout<<"\t\t\t\t |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|   Account Registered Successfully, Login Below...                    |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|          Press Any Key to continue...                                |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
    cout<<"\t\t\t\t\t@@|                                     ~Code By Alliyan Waheed Alvi     |@@\n";
    cout<<"\t\t\t\t\t@@|______________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
        
    getch();
        
    login_menu:
    // Login Screen
    Login newLogin;
    
    cout<<"\t\t\t\t\t   *** Login to Your Account ****"<<endl;
    cout<<"\t\t\t\t\t   ------------------------------"<<endl<<endl;
    
    cout<<"\t\t\t\t\t   Enter Your Username: ";  
    cin.ignore();
    getline(cin, newLogin.inpUsername);    

    cout<<"\n\t\t\t\t\t   Enter Your Password: ";  
    getline(cin, newLogin.inpPassword);    
    
    cout<<endl<<"\t\t\t\t\t ******************************************"<<endl;


    if(newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password){
        cout<<"\n\n\n\t\t\t\t\t\t  Successfully logged in, loading your dashboard...";
    }
    else {
        cout<<"\n\t\t\t\t\t  Login Failed due to Invalid entries, Please try again!!!\n\n\n";
        cout << "";
        goto login_menu;
    }
 
    
    
    int dashboard_choice;
    dashboard_menu:
    do  
    {
        
            cout<<"\n\n\t\t\t\t\t\t\t     *###* HOSPITAL MANAGEMENT SYSTEM *###*";	
            cout<<"\n\t\t\t\t\t\t\t                *** DASHBOARD ***\n";	
        
        cout<<"\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >> Enter into Patients Database                  |\n";
        cout<<"\t\t\t\t\t\t|             2  >> Enter into Doctors Database                   |\n";
        cout<<"\t\t\t\t\t\t|             3  >> Information About Hospital                    |\n";
        cout<<"\t\t\t\t\t\t|             0  >> Exit the Program                              |\n";
        cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        
        
        cout<<"\n\t\t\t\t\t\tEnter your choice: ";
        cin>>dashboard_choice;
        
        switch (dashboard_choice)
        {
        
        case 1:
        
        int p_choice;
        do{
        
            cout<<"\n\n\t\t\t\t\t\t\t     *###* HOSPITAL MANAGEMENT SYSTEM *###*\n";	
            cout<<      "\t\t\t\t\t\t\t\t   *** (Patients Database) ***\n";	
        
            cout<<"\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\t\t\t\t\t\t|                                           	                  |\n";
            cout<<"\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
            cout<<"\t\t\t\t\t\t|             2  >> List of patients in the hospital              |\n";
            cout<<"\t\t\t\t\t\t|             3  >> Search a patient with his ID                  |\n";
            cout<<"\t\t\t\t\t\t|             4  >> Discharge a patient                           |\n";
            cout<<"\t\t\t\t\t\t|             5  >> Total number of Patients in the Hospital      |\n";
            cout<<"\t\t\t\t\t\t|             6  >> Priority wise appointments of Patients        |\n";
            cout<<"\t\t\t\t\t\t|             7  >> Generate Patient Bill                         |\n";
            cout<<"\t\t\t\t\t\t|             8  >> Go back to Dashboard                          |\n";
            cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        
        
            cout<<"\n\t\t\t\t\t\tEnter your choice: ";
            cin>>p_choice;
        
            switch (p_choice)
            {
                case 1:
                    add_new_patient();
                    break;
        
                case 2:
                    // In-Order Traversal
                    cout<<"\nList of Patients in the hospital"<<endl;
                    traverse_patients_list(root);
                    break;
            
                case 3:
                    int key;
                    cout<<"\nEnter ID No to searched for Specific Patient: ";
                    cin>>key;
                    search_specific_patient(key);
                    break;
            
                case 4:
                    int val;
                    cout<<"\nEnter Patient ID to be discharged: ";
                    cin>>val;
                    remove_specific_patient(val);
                    break;
                
                case 5:
                    total_num_of_patients(root);
                    cout<<"\n\nTotal Number of Patients in the Hospital: "<<total_num_of_patients(root)<<endl<<endl;
                    break;

                case 6:
                    dlisplay_patients_priority();
                    break;
                
                case 7:
                    patients_bill();
                    break;
                
                case 8:
                    goto dashboard_menu;
                    break;
        
                default:
                    // if(p_choice==0){
                    //         cout<<"\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                    // cout<<"\t\t\t\t\t@@ ______________________________________________________________________ @@\n";
                    // cout<<"\t\t\t\t\t@@|                            		                                 |@@\n";
                    // cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                    // cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                           	                         |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                          THANKS FOR USING OUR                        |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                       HOSPITAL MANAGEMENT SYSTEM                     |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    // cout<<"\t\t\t\t\t@@|                                     ~Code By Alliyan Waheed Alvi     |@@\n";
                    // cout<<"\t\t\t\t\t@@|______________________________________________________________________|@@\n";
                    // cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                    
                    // }
                    
                    // else{
                    //     cout<<"\n\t\t\t\t\t\tInvalid Entry, Please try again...";
                    // }
            
                    break;
            }
    
        }while(p_choice!=5);
    

    
        // ************** Doctors Case ************
        case 2:
        
        int d_choice;
        do{
        
                cout<<"\n\n\t\t\t\t\t\t\t    *###* HOSPITAL MANAGEMENT SYSTEM *###*";	
                cout<<"\n\t\t\t\t\t\t\t            *** Doctors Database ***\n";	
            
            cout<<"\n\t\t\t\t\t\t Please,  Choose from the following Options: \n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\t\t\t\t\t\t|                                           	                  |\n";
            cout<<"\t\t\t\t\t\t|             1  >> Add New Doctor's Record                       |\n";
            cout<<"\t\t\t\t\t\t|             2  >> List of Doctors in the hospital               |\n";
            cout<<"\t\t\t\t\t\t|             3  >> Search a Doctor with his ID                   |\n";
            cout<<"\t\t\t\t\t\t|             4  >> Remove a doctor's record from the list        |\n";
            cout<<"\t\t\t\t\t\t|             5  >> Total number of Docters in the Hospital       |\n";
            cout<<"\t\t\t\t\t\t|             6  >> Go back to Dashboard                          |\n";
            cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        

        
        cout<<"\n\t\t\t\t\t\tEnter your choice: ";
        cin>>d_choice;
        
        switch (d_choice)
        {
            case 1:
                add_new_doctor();
                break;
        
            case 2:
                // In-Order Traversal
                cout<<"\nList of Doctors in the hospital"<<endl;
                traverse_doctors_list(d_root);
                break;
            
            case 3:
                int key;
                cout<<"\nEnter ID No to searched for Specific Doctor: ";
                cin>>key;
                search_specific_doctor(key);
                break;
            
            case 4:
                int val;
                cout<<"\nEnter Doctor ID to be removed: ";
                cin>>val;
                remove_specific_doctor(val);
                break;
            
            case 5:
                total_num_of_doctors(d_root);
                cout<<"\n\nTotal Number of Doctors in the Hospital: "<<total_num_of_doctors(d_root)<<endl<<endl;
                break;
            
            case 6:
                goto dashboard_menu;
                break;
        
            default:
                
                // if(d_choice==0){
                //         cout<<"\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                //     cout<<"\t\t\t\t\t@@ ______________________________________________________________________ @@\n";
                //     cout<<"\t\t\t\t\t@@|                            		                                 |@@\n";
                //     cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                //     cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                           	                         |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                          THANKS FOR USING OUR                        |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                       HOSPITAL MANAGEMENT SYSTEM                     |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                //     cout<<"\t\t\t\t\t@@|                                     ~Code By Alliyan Waheed Alvi     |@@\n";
                //     cout<<"\t\t\t\t\t@@|______________________________________________________________________|@@\n";
                //     cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                // }
                // else{
                //     cout<<"\n\t\t\t\t\t\tInvalid Entry, Please try again...";
                // }
                break;            
        
        }
        
        }while(d_choice != 5);
        
        // case 2 break
            break;
    
        // dashboard case 3
        case 3:
            cout<<"\nHospital Info..."<<endl;
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\nabc............................................xyz";
            cout<<"\n\nHospital Wards: "<<endl;
            cout<<"-----------------------";
            cout<<"\n>> Out Patient Door ward";
            cout<<"\n>> In Patient Door ward";
            cout<<"\n>> Emergency ward";
            cout<<"\n\nTotal Rooms Awailable: 50"<<endl;
            
            total_num_of_patients(root);
            cout<<"\nTotal Number of Patients in the Hospital: "<<total_num_of_patients(root)<<endl;
            
            total_num_of_doctors(d_root);
                cout<<"\nTotal Number of Doctors in the Hospital: "<<total_num_of_doctors(d_root)<<endl;

            cout<<"\nPress any key to continue..."<<endl;
            getch();
            
            break;
        
        // dashboard default
        default:
            if(dashboard_choice==0){
                        cout<<"\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                    cout<<"\t\t\t\t\t@@ ______________________________________________________________________ @@\n";
                    cout<<"\t\t\t\t\t@@|                            		                                 |@@\n";
                    cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                    cout<<"\t\t\t\t\t@@|                               		                         |@@\n";
                    cout<<"\t\t\t\t\t@@|                                           	                         |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                          THANKS FOR USING OUR                        |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                       HOSPITAL MANAGEMENT SYSTEM                     |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                                                      |@@\n";
                    cout<<"\t\t\t\t\t@@|                                     ~Code By Alliyan Waheed Alvi     |@@\n";
                    cout<<"\t\t\t\t\t@@|______________________________________________________________________|@@\n";
                    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                }
                
                else{
                    cout<<"\n\t\t\t\t\t\tInvalid Entry, Please try again...";
                }
                break;
        }    
    
    } while (dashboard_choice != 0);

}
    
// ************* Patients Functions ***************    


void add_new_patient(){
    
    patients *current = new patients; 
    
    cout<<"\nPatient Name: ";
    cin.ignore();
    getline(cin, current->p_name);
    
    cout<<"Sex: ";
    //cin.ignore();
    getline(cin, current->p_sex);
    
    cout<<"Age: ";
    //cin.ignore();
    getline(cin, current->p_age);
    
    cout<<"Blood Group: ";
    //cin.ignore();
    getline(cin, current->p_blood_group);
    
    cout<<"Contact No: ";
    //cin.ignore();
    getline(cin, current->p_contact_num);
    
    cout<<"Address: ";
    cin.ignore();
    getline(cin, current->p_adderess);
    
    cout<<"Any Major Disease Earlier: ";
    //cin.ignore();
    getline(cin, current->p_any_major_disease_earlier);

    cout<<"\nEnter ID number by reffering to the disease from the given table: ";
    cout<<("\nPlease Refer this Table for your disease!\n");
    cout<<"\n---------------------------------------------"<<endl;
    cout<<("1.Heart attack\n");
    cout<<("2.Severe wound/Bleeding\n");
    cout<<("3.Cancer\n");
    cout<<("4.Corona (Covid-19)\n");
    cout<<("5.Fracture\n");
    cout<<("6.Diabetes Checkup\n");
    cout<<("7.Infection\n");
    cout<<("8.Viral Fever\n");
    cout<<("9.Common Cold/Head ache\n");
    
    cout<<"\nID Number: ";
    cin>>current->p_id;
    if(current->p_id == 4){
        // We don't have Corona ward in our hospital
        // so we have to reffer the patient to the nearest Corona Hospital 
        cout<<"\n*** We have no Corona Ward in Our Hospital ***";
        cout<<"\n # Reffring patient to the nearest Corona Hospital # "<<endl<<endl;
        // using Dijkstra's Algorithm
        corona_hospital();
    }
    cout<<endl<<"******************************************"<<endl;
    cout<<"Information Saved Successfully!";

    // remove record of corona patient:
    if(current->p_id == 4){
        remove_specific_patient(current->p_id);    
    }
    
    // Patients priorities:
    // calling priority queue's enqueue functionl
    enqueue(current);
    
    cout<<"\nPress Any Key To Continue...";
    getch();

    
    
    if (root==NULL)
        root=current;
    else{
        patients *p = root;
        patients *k=p;           // we used the k to point the previous node of the *p 
        while(p!=NULL){
            k=p;               // updating k
            if(current->p_id > p->p_id)
                p=p->right;
            else
                p=p->left;
        }
            if(current->p_id > k->p_id)
                k->right=current;
            else
                k->left=current;
    }
                    
}


void traverse_patients_list(patients* root)
{
    if (!root) {
		return;
	}
	
    traverse_patients_list(root->left);
	
    cout<<"\nID Number   :    "<<root->p_id;
    cout<<"\nName        :    "<<root->p_name;
    cout<<"\nSex         :    "<<root->p_sex;
    cout<<"\nAge         :    "<<root->p_age;
    cout<<"\nBlood group :    "<<root->p_blood_group;
    cout<<"\nContact Num :    "<<root->p_contact_num;
    cout<<"\nAddress     :    "<<root->p_adderess;
    cout<<"\nEarlier major Disease: "<<root->p_any_major_disease_earlier<<endl;
    cout<<"\n-------------------------------------"<<endl;
	
    traverse_patients_list(root->right);
}

// void pre_order(stu* root)
// {
//     if (!root) {
// 		return;
// 	}

//     cout<<"\nID Number   :    "<<root->id;
//     cout<<"\nName        :    "<<root->name;
//     cout<<"\nSex         :    "<<root->sex;
//     cout<<"\nAge         :    "<<root->age;
//     cout<<"\nBlood group :    "<<root->blood_group;
//     cout<<"\nContact Num :    "<<root->contact_num;
//     cout<<"\nAddress     :    "<<root->adderess;
//     cout<<"\nEarlier major Disease: "<<root->any_major_disease_earlier;	

// 	pre_order(root->left);
// 	pre_order(root->right);
// }

// void post_order(stu* root)
// {
//     if (!root) {
// 		return;
// 	}
// 	post_order(root->left);
// 	post_order(root->right);

//     cout<<"\nID Number   :    "<<root->id;
//     cout<<"\nName        :    "<<root->name;
//     cout<<"\nSex         :    "<<root->sex;
//     cout<<"\nAge         :    "<<root->age;
//     cout<<"\nBlood group :    "<<root->blood_group;
//     cout<<"\nContact Num :    "<<root->contact_num;
//     cout<<"\nAddress     :    "<<root->adderess;
//     cout<<"\nEarlier major Disease: "<<root->any_major_disease_earlier;

// }


int total_num_of_patients(patients* root){
    

    if (root==NULL) {
		return 0;
	}
    return(1 + total_num_of_patients(root->left) + total_num_of_patients(root->right));
	
}




void search_specific_patient(int key){
    
    p=root;
    k=p;     
        while(p!=NULL && p->p_id != key){
            if(key < p->p_id){
                k=p;  p=p->left;
            }
            else{
                k=p;  p=p->right;        
            }
        }
        if (p==NULL){
            cout<<"\nPatient not found!";
        }
        else{
            cout<<"\nPatient Found!";
            cout<<"\nPatient Details and Records: ";
            cout<<"\n----------------------------- "<<endl;
            cout<<"\nID Number   :    "<<p->p_id;
            cout<<"\nName        :    "<<p->p_name;
            cout<<"\nSex         :    "<<p->p_sex;
            cout<<"\nAge         :    "<<p->p_age;
            cout<<"\nBlood group :    "<<p->p_blood_group;
            cout<<"\nContact Num :    "<<p->p_contact_num;
            cout<<"\nAddress     :    "<<p->p_adderess;
            cout<<"\nEarlier major Disease: "<<p->p_any_major_disease_earlier<<endl;
        }
}

void remove_specific_patient(int value){
    
    search_specific_patient(value);
    
    if (p==NULL){
        cout<<"\nInvalid Entry, patient not found";
    }
    else{
       
        cout<<"\nDeleted from the List Sucessfully, Patient Discharged!";
    
        //Case 1: Deleting a leaf node
        if(p->left==NULL && p->right==NULL){
            if(k->left==p){
                k->left=NULL;
                delete p;
            }
            else{
                k->right=NULL;
                delete p;
            }
        }

        //Case 2: Deleting a node having one child
        //Case 2a: 
        if(k->left == p && p->right == NULL){
            k->left=p->left;   delete p;
        }
        //Case 2b: 
        if(k->right == p && p->left == NULL){
            k->right=p->right;   delete p;
        }
        //Case 2c: 
        if(k->left == p && p->left == NULL){
            k->left=p->right;   delete p;
        }
        //Case 2d: 
        if(k->right == p && p->right == NULL){
            k->right=p->left;   delete p;
        }

        //Case 3: Deleting a node having 2 child
        //move one step to the right of p i.e p1, n then to the leftmost of p1
        if(p->right!=NULL && p->left!=NULL){
            patients *p1 = p->right;
            patients *k1=p;
            while(p1->left!=NULL){
                k1=p1;
                p1=p1->left;
            }
            p->p_id=p1->p_id;
            
            if (p1->left==NULL && p1->right==NULL){
                 k1->right=NULL;
                 delete p1;
            }
            else if(p1->right!=NULL){
                k1->left=p1->right;
                delete p1;
            }
            else{
                k1->left=NULL;
                delete p1;
            }

        }    
        
    }

}

// ************** Priority Queue Funtions ***************

// Implementation of Priority Queue
// Enqueue operation:
void enqueue(patients* current){

    if (front==NULL){
        front = rear = current;
    }
    else if (current->p_id < front->p_id){
        current->next = front;
        front = current;
    }

    else{
        patients *qp;
        qp = front;
        while(qp->next != NULL && qp->next->p_id <= current->p_id){
            qp=qp->next;
        }

        current->next = qp->next;
        qp->next = current;
        rear = current;

    }
}

// void dequeue(){
//     patients *current;
//     if(front == NULL)
//         cout<<"\nQueue Underfloaw"<<endl;
//     else{
//         current = front;
//         cout<<"\n<------------------------>";
//         cout<<"\nCalling patient: ";
//         cout<<"\n----------------";
//         cout<<"\nPatient ID: "<<current->p_id;
//         cout<<"\n<------------------------>"<<endl;
//         front = front->next;
//         delete current;
//     }
// }

void dlisplay_patients_priority(){
    patients *qp;
    if (front == NULL)
        cout<<"\nList is Empty"<<endl;
    else{
        qp = front;
        while(qp != NULL){
            cout<<"\nPatient name: "<<qp->p_name<<"\t\t\t\t\t\tPatient id: "<<qp->p_id<<endl;
            qp = qp->next;
        }
    }
}


void patients_bill(){

//     cout<<("1.Heart attack\n");
//     cout<<("2.Severe wound/Bleeding\n");
//     cout<<("3.Cancer\n");
//     cout<<("4.Corona (Covid-19)\n");
//     cout<<("5.Fracture\n");
//     cout<<("6.Diabetes Checkup\n");
//     cout<<("7.Infection\n");
//     cout<<("8.Viral Fever\n");
//     cout<<("9.Common Cold/Head ache\n");
        
    int bill_id;
    cout<<"\nEnter ID number of the patient to generate bill: ";
    cin>>bill_id;
    search_specific_patient(bill_id);
    
    int pharmacy_charges;
    int room_rent;
    int doctor_fee;
    
    if(bill_id == 1){
        pharmacy_charges = 5000; 
        room_rent = 5000; 
        doctor_fee = 10000; 
    }
    else if(bill_id == 2){
        pharmacy_charges = 500; 
        room_rent = 0; 
        doctor_fee = 500; 
    }
    else if(bill_id == 3){
        pharmacy_charges = 25000; 
        room_rent = 10000; 
        doctor_fee = 10000; 
    }
    else if(bill_id == 4){
        pharmacy_charges = 0; 
        room_rent = 0; 
        doctor_fee = 0;
        cout<<"\nNo Patient Charges because Corona patient was reffered to another branch of our Hospital"<<endl; 
    }
    else if(bill_id == 5){
        pharmacy_charges = 2000; 
        room_rent = 2000; 
        doctor_fee = 2000; 
    }
    else if(bill_id == 6){
        pharmacy_charges = 800; 
        room_rent = 0; 
        doctor_fee = 500; 
    }
    else if(bill_id == 7){
        pharmacy_charges = 350; 
        room_rent = 0; 
        doctor_fee = 300; 
    }
    else if(bill_id == 8){
        pharmacy_charges = 500; 
        room_rent = 0; 
        doctor_fee = 500; 
    }
    else if(bill_id == 9){
        pharmacy_charges = 300; 
        room_rent = 0; 
        doctor_fee = 300; 
    }
    else{
        pharmacy_charges = 500; 
        room_rent = 1000; 
        doctor_fee = 500; 
    }
    
    cout<<"\nPatient Bill:";
    cout<<"\n----------------------------"<<endl;
    cout<<"\nPharmacy Charges: "<<pharmacy_charges;
    cout<<"\nRoom Rent: "<<room_rent;
    cout<<"\nDoctor Fee: "<<doctor_fee;
    cout<<"\nTotal Hospital Charges: "<<(pharmacy_charges + room_rent + doctor_fee);
    cout<<"\n----------------------------"<<endl;
}


// **************** Doctors Functions ******************

void add_new_doctor(){
    
    doctors *current = new doctors; 
    
    cout<<"\nDoctor Name: ";
    cin.ignore();
    getline(cin, current->d_name);
    
    cout<<"\nID Number: ";
    cin>>current->d_id;
    
    cout<<"\nSex: ";
    cin.ignore();
    getline(cin, current->d_sex);
    
    cout<<"\nAge: ";
    getline(cin, current->d_age);
    
    cout<<"\nQualification: ";
    getline(cin, current->d_qualification);
    
    cout<<"\nSpecialization: ";
    getline(cin, current->d_specialization);
    cout<<"\nExperience: ";
    getline(cin, current->d_experience);
    
    cout<<"\nContact No: ";
    getline(cin, current->d_contact_num);
    
    cout<<"\nAddress: ";
    cin.ignore();
    getline(cin, current->d_adderess);
       

    cout<<endl<<"******************************************"<<endl;
    cout<<"Information Saved Successfully!";

    cout<<"\nPress Any Key To Continue...";
    getch();
    
    
    if (d_root==NULL)
        d_root=current;
    else{
        doctors *dp = d_root;
        doctors *dk = dp;           // we used the k to point the previous node of the *p 
        while(dp!=NULL){
            dk=dp;               // updating k
            if(current->d_id > dp->d_id)
                dp=dp->d_right;
            else
                dp=dp->d_left;
        }
            if(current->d_id > dk->d_id)
                dk->d_right=current;
            else
                dk->d_left=current;
    }
                    
}



void traverse_doctors_list(doctors* d_root)
{
    if (!d_root) {
		return;
	}
	
    traverse_doctors_list(d_root->d_left);
	
    cout<<"\nID Number      :    "<<d_root->d_id;
    cout<<"\nName           :    "<<d_root->d_name;
    cout<<"\nSex            :    "<<d_root->d_sex;
    cout<<"\nAge            :    "<<d_root->d_age;
    cout<<"\nQualification  :    "<<d_root->d_qualification;
    cout<<"\nSpecialization :    "<<d_root->d_specialization;
    cout<<"\nExperience     :    "<<d_root->d_experience;
    cout<<"\nContact Num    :    "<<d_root->d_contact_num;
    cout<<"\nAddress        :    "<<d_root->d_adderess;
    cout<<"\n---------------------------------------------"<<endl;
	
    traverse_doctors_list(d_root->d_right);
}

// void pre_order(stu* root)
// {
//     if (!root) {
// 		return;
// 	}

//     cout<<"\nID Number   :    "<<root->id;
//     cout<<"\nName        :    "<<root->name;
//     cout<<"\nSex         :    "<<root->sex;
//     cout<<"\nAge         :    "<<root->age;
//     cout<<"\nBlood group :    "<<root->blood_group;
//     cout<<"\nContact Num :    "<<root->contact_num;
//     cout<<"\nAddress     :    "<<root->adderess;
//     cout<<"\nEarlier major Disease: "<<root->any_major_disease_earlier;	

// 	pre_order(root->left);
// 	pre_order(root->right);
// }

// void post_order(stu* root)
// {
//     if (!root) {
// 		return;
// 	}
// 	post_order(root->left);
// 	post_order(root->right);

//     cout<<"\nID Number   :    "<<root->id;
//     cout<<"\nName        :    "<<root->name;
//     cout<<"\nSex         :    "<<root->sex;
//     cout<<"\nAge         :    "<<root->age;
//     cout<<"\nBlood group :    "<<root->blood_group;l
//     cout<<"\nContact Num :    "<<root->contact_num;
//     cout<<"\nAddress     :    "<<root->adderess;
//     cout<<"\nEarlier major Disease: "<<root->any_major_disease_earlier;

// }


int total_num_of_doctors(doctors* d_root){
    

    if (d_root==NULL) {
		return 0;
	}
    return(1 + total_num_of_doctors(d_root->d_left) + total_num_of_doctors(d_root->d_right));
	
}


void search_specific_doctor(int key){
    
    dp=d_root;
    dk=dp;     
        while(dp!=NULL && dp->d_id != key){
            if(key < dp->d_id){
                dk=dp;  dp=dp->d_left;
            }
            else{
                dk=dp;  dp=dp->d_right;        
            }
        }
        if (dp==NULL){
            cout<<"\nRecord Not Found!!!";
            cout<<"\nInvalid Entries...";
        }
        else{
            cout<<"\nDoctor Found!";
            cout<<"\nDoctor Details and Records: ";
            cout<<"\n---------------------------------- "<<endl;
            cout<<"\nID Number      :    "<<dp->d_id;
            cout<<"\nName           :    "<<dp->d_name;
            cout<<"\nSex            :    "<<dp->d_sex;
            cout<<"\nAge            :    "<<dp->d_age;
            cout<<"\nQualification  :    "<<dp->d_qualification;
            cout<<"\nSpecialization :    "<<dp->d_specialization;
            cout<<"\nExperience     :    "<<dp->d_experience;
            cout<<"\nContact Num    :    "<<dp->d_contact_num;
            cout<<"\nAddress        :    "<<dp->d_adderess;
        }
    cout<<"\nPress any key to continue...";
    getch();
}

void remove_specific_doctor(int value){
    
    search_specific_patient(value);
    
    if (dp==NULL){
        cout<<"\nInvalid Entry, Doctor not found";
    }
    else{
        cout<<"\nDoctor Details and Records: ";
        cout<<"\nID Number      :    "<<dp->d_id;
        cout<<"\nName           :    "<<dp->d_name;
        cout<<"\nSex            :    "<<dp->d_sex;
        cout<<"\nAge            :    "<<dp->d_age;
        cout<<"\nQualification  :    "<<dp->d_qualification;
        cout<<"\nSpecialization :    "<<dp->d_specialization;
        cout<<"\nExperience     :    "<<dp->d_experience;
        cout<<"\nContact Num    :    "<<dp->d_contact_num;
        cout<<"\nAddress        :    "<<dp->d_adderess;
        cout<<"\nDeleted from the List Sucessfully, (Doctor resigned the Job / fired from the job)";
        
        cout<<"\nPress Any Key To Contunue...";
        getch();
    
        //Case 1: Deleting a leaf node
        if(dp->d_left==NULL && dp->d_right==NULL){
            if(dk->d_left==dp){
                dk->d_left=NULL;
                delete dp;
            }
            else{
                dk->d_right=NULL;
                delete dp;
            }
        }

        //Case 2: Deleting a node having one child
        //Case 2a: 
        if(dk->d_left == dp && dp->d_right == NULL){
            dk->d_left=dp->d_left;   delete dp;
        }
        //Case 2b: 
        if(dk->d_right == dp && dp->d_left == NULL){
            dk->d_right=dp->d_right;   delete dp;
        }
        //Case 2c: 
        if(dk->d_left == dp && dp->d_left == NULL){
            dk->d_left=dp->d_right;   delete dp;
        }
        //Case 2d: 
        if(dk->d_right == dp && dp->d_right == NULL){
            dk->d_right=dp->d_left;   delete dp;
        }

        //Case 3: Deleting a node having 2 child
        //move one step to the right of p i.e p1, n then to the leftmost of p1
        if(dp->d_right!=NULL && dp->d_left!=NULL){
            doctors *dp1 = dp->d_right;
            doctors *dk1=dp;
            while(dp1->d_left!=NULL){
                dk1=dp1;
                dp1=dp1->d_left;
            }
            dp->d_id=dp1->d_id;
            
            if (dp1->d_left==NULL && dp1->d_right==NULL){
                 dk1->d_right=NULL;
                 delete dp1;
            }
            else if(dp1->d_right!=NULL){
                dk1->d_left=dp1->d_right;
                delete dp1;
            }
            else{
                dk1->d_left=NULL;
                delete dp1;
            }

        }    
        
    }

}



// ************ Applying Dijkstr's Algorithm ************


/*                  (Graph)
        (Map)        
                   C-------E (Corona Hospital)
                  / \     /  \--1
              20 /   \ 20/      |
                /     \ /       F (Corona Hospital) 
(Our Hospital) A       \       /     
                \  10 / \     /        
              10 \   /   \   /2         
                  \ /     \ /         
                   B-------D (Corona Hospital)
                       50

From figure:
>> Hospital A is our Hospital i.e Source point
>> Hospital E F and D are Corona Hospitals
>> We have to find nearest Corona hospital
   for Covid-19 patient 

*/


int minimumDist(int dist[], bool Tset[]) 
{
	int min=INT_MAX,index;
              
	for(int i=0;i<6;i++) 
	{
		if(Tset[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[6][6],int src) 
{
	int dist[6];                         
	bool Tset[6];	// to check visited vertex
	 
	for(int i = 0; i<6; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;	
	}
	
	dist[src] = 0;             
	
	for(int i = 0; i<6; i++)                           
	{
		int m=minimumDist(dist,Tset); 
		Tset[m]=true;
		for(int i = 0; i<6; i++)                  
		{
			if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
				dist[i]=dist[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	int minh = INT_MAX;    // for comparison of hospitals Distances
    for(int i = 0; i<3; i++)                      
	{   
        //Printing 
        char str = 65+i;
		cout<<"Point "<<str<<"\t\t\t"<<dist[i]<<endl;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"Corona Hospitals:"<<endl;
    for(int i = 3; i<6; i++)                      
	{   
        //Printing 
        char str = 65+i;
		cout<<"Hospital "<<str<<"\t\t"<<dist[i]<<endl;
    }
    
    char count = 68;
    for(int i = 3; i<6; i++){
        if(dist[i+1] < minh){
            minh = dist[i+1];
            count++;
        }
    }    
    cout<<"\n\nClosest Corona Hospital is: ";
    cout<<"Hospital "<<count<<", That is "<<minh<<"km away from our Hospital i.e Hospital A"<<endl;
    cout<<"<------------------------------------------------------------------->"<<endl;

}

void corona_hospital()
{
    
    cout<<"\n                     (Graph)                         ";
    cout<<"\n         (Map)                                       ";      
    cout<<"\n                    C--------E (Corona Hospital)     ";
    cout<<"\n                   / \\     / \\ 1                   ";
    cout<<"\n               20 /   \\20 /   \\                    ";
    cout<<"\n                 /     \\ /     F (Corona Hospital)  ";
    cout<<"\n (Our Hospital) A       \\      /                    ";
    cout<<"\n                 \\  10 / \\    /                    ";  
    cout<<"\n               10 \\   /   \\  /2                    "; 
    cout<<"\n                   \\ /     \\/                      ";
    cout<<"\n                    B-------D (Corona Hospital)      ";
    cout<<"\n                        50                           ";

        
	cout<<endl<<endl;
    int graph[6][6]={
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0}};    

	Dijkstra(graph,0);	                        
}

