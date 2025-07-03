// this is my first semster project named as society management system 
// these are the headers of my project!!
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>

using namespace std;
//-------------prototype starts-----------------
void mainheader ();
void clearscreen ();
string login_user ();
char adminmenu ();
char residentmenu ();
void setcolor (int);
void addresident();
void changepassword (string);

void adduser (string , string , string );
void viewallresidents ();
void removeresidents ();
void searchresidents ();
void postannouncements ();
void viewannouncements ();

void viewcomplaints ();
void viewmaintainancereq ();
void viewduestatus ();
void viewresidentsdues ();
void submitcomplaints ();
void submitmaintainacereq ();
void paydues ();
void viewcomplainstatus ();
void viewmaintainancestatus ();
void viewprofile ();
void viewsocietyrules ();


int  findresidentindexbyusername(string);
int findresidentindexbyname(string);

void saveresidentstoFile();
void loadresidentsfromFile();
void sortresidentsbyname();

//-------------prototype ends-------------------

//-------------data structure starts------------
const int TOTAL_USER = 20;
int user_count =0;

string usernameA[TOTAL_USER];
string passwordA[TOTAL_USER];
string rolesA[TOTAL_USER];

string residentname [TOTAL_USER];
string residentcnic [TOTAL_USER];
string residentphone [TOTAL_USER];
string residentflatno [TOTAL_USER];
bool duespaid [TOTAL_USER] = {false};
int residentcount = 0;

string complaints[TOTAL_USER];
bool complaintresolved[TOTAL_USER];
int complaintcount =0 ;
string complaintuser[TOTAL_USER];
string maintenanceuser[TOTAL_USER];

string maintaincereq [TOTAL_USER];
bool maintainceresolved [TOTAL_USER];
int maintaincecount = 0;

string announcements [  TOTAL_USER];
int announcemnetcount = 0 ;
string currentuser = "";
//-------------data structure ends---------------

//-------------main function starts--------------
int main (){
    while (true){
        loadresidentsfromFile();
        adduser ("admin", "123", "ADMIN");
        adduser ("resident", "123", "RESIDENT");

        string role = "";
        while (true){
            role = login_user();
            if (role == "ADMIN" || role == "admin"){
                char option;
                while (true){
                    system("cls");
                    option = adminmenu();
                    if (option =='1')
                    addresident();
                    else if (option ==  '2')
                    viewallresidents();
                    else if (option == '3')
                    removeresidents ();
                    else if (option =='4')
                    searchresidents ();
                    else if (option == '5')
                    postannouncements ();
                    else if (option == '6')
                    viewcomplaints ();
                    else if (option == '7')
                    viewmaintainancereq ();
                    else if (option == '8')
                    viewduestatus();
                    else if  (option == '9')
                    changepassword (currentuser);
                    else if (option == 'S' || option == 's'){
                    saveresidentstoFile ();
                    cout<<"DATA IS SAVED IN FILES "<<endl;
                    exit (0);}

                    else if (option == '0')
                    break ;
                    else 
                    cout<<"INVALID OPTION ENTERED "<<endl;
                    clearscreen ();
                    
                }
            }

        else if (role == "RESIDENT") {
            char option;
            while (true) {
                system("cls");
                option = residentmenu();
                if (option == '1') viewprofile();
                else if (option == '2') submitcomplaints();
                else if (option == '3') submitmaintainacereq();
                else if (option == '4') viewannouncements();
                else if (option == '5') paydues();
                else if (option == '6') viewcomplainstatus();
                else if (option == '7') viewmaintainancestatus();
                else if (option == '8') changepassword(currentuser);
                else if (option == '9') viewresidentsdues();
                else if (option == '0') viewsocietyrules();
                else if (option == 'Q' || option == 'q') break;
                else cout << "Invalid option!" << endl;
               clearscreen();
            }
        } else {
            cout << "Login failed or invalid user." << endl;
            clearscreen();
        }
    }
    return 0;

    }
}
//-------------main function ends----------------

//-------------functions starts------------------
string login_user(){ 
    mainheader ();        //-----this function decides wheather the logged person is admin or user
    string username, password;
    cout<<"ENTER YOUR USERNAME: ";
    cin>>username;
    cout<<"ENTER YOUR PASSWORD: ";
    cin>>password;
    for (int i = 0 ; i < user_count ; i++){
        if (usernameA[i] == username && passwordA[i] == password){
            currentuser = username;  //
            return rolesA[i];
        }
    }
    return "INVALID";
}

// -----this function increase the usercount 
 void adduser( string username, string password, string role){
    if (user_count < TOTAL_USER){
        usernameA[user_count] = username;
        passwordA[user_count] = password;
        rolesA[user_count] = role;
        user_count++;

    }
    else 
    cout<<"no more space to add new users";
 }
 // ---------------this functions displays the main header of the project
 void mainheader (){
    cout << "--------------------------------------------" << endl;
    cout << "--- Society Management System ---" << endl;
    cout << "--------------------------------------------" << endl;
}
 // ----------------------this function displays the admin's menu
 char adminmenu (){
    mainheader();

    cout<<"ADMIN MENU\n";
    cout << "1. Add New Resident\n";
    cout << "2. View All Residents\n";
    cout << "3. Remove Resident\n";
    cout << "4. Search Resident\n";
    cout << "5. Post Announcement\n";
    cout << "6. View Complaints\n";
    cout << "7. View Maintenance Requests\n";
    cout << "8. View Due Payment Status\n";
    cout << "9. Change Your Password\n";
    cout << "S. Save & Exit\n";
    cout << "0. Logout\n";
    cout << "Choose an option: ";
    char option;
    cin >> option;
    return option;
 }
// ---------------------this function displays the resident's menu
 char residentmenu (){
    mainheader();
    cout << "Resident Menu:\n";
    cout << "1. View Profile\n";
    cout << "2. Submit Complaint\n";
    cout << "3. Submit Maintenance Request\n";
    cout << "4. View Announcements\n";
    cout << "5. Pay Dues\n";
    cout << "6. View Complaint Status\n";
    cout << "7. View Maintenance Status\n";
    cout << "8. Change Password\n";
    cout << "9. View Dues Status\n";
    cout << "0. View Society Rules\n";
    cout << "Q. Logout\n";
    cout << "Choose an option: ";
    char option;
    cin >> option;
    return option;
 }
// -------------------this function clear the screen when it's applied 
 void clearscreen(){
    cout<<"\npress any key to continue ";
    getch();
    system ("cls");
 }
 // -------------------this function gives colors to the output 
 void setcolor (int color){
    HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

 }
// ---------------------this function add residents 
 void addresident (){
    if (residentcount >= TOTAL_USER){
        cout<<"RESIDENT LIMIT REACHED "<<endl;
        return ;
    }
     string name, cnic, phone, flatNo, usernamee, password;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter CNIC: "; cin >> cnic;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Flat No: "; cin >> flatNo;
    cout << "Set Username: "; cin >> usernamee;
    cout << "Set Password: "; cin >> password;

    residentname[residentcount] = name;
    residentcnic[residentcount] = cnic;
    residentphone[residentcount] = phone;
    residentflatno[residentcount] = flatNo;
    duespaid[residentcount] = false;
    adduser(usernamee, password, "RESIDENT");
    residentcount++;
    cout << "Resident added." << endl;
 }

//--------------------this function helps admin to view all residnets
void viewallresidents (){
    sortresidentsbyname ();
    cout <<"NAME\tCNIC\tPHONE\tflatNO\tDUES\n";
    cout<<"-------------------------------\n";
    for (int i = 0; i< residentcount; i++){
        cout << residentname[i]<< "\t" << residentcnic[i]<< "\t" <<residentphone[i]<< "\t" << residentflatno[i]<< "\t";
        if (duespaid[i])
        setcolor(10);
        else 
        setcolor (12);
        cout<<(duespaid[i] ? "paid" : "not paid");
        setcolor(7); 
        cout<<endl;
    }
}
//--------------------this function helps  admin to remove residents
void removeresidents (){
    string name;
    cout<<"ENTER THE RESIDENT NAME TO REMOVE ; ";
    cin>>name;
    int idx = findresidentindexbyname(name);
    if (idx == -1){
        cout<<"RESIDENT NOT FOUND \n";
        return ;
    }
    for (int i=idx ; i <residentcount -1 ; i ++){
        residentname[i] = residentname [i+1];
        residentcnic[i] = residentcnic[i + 1];
        residentphone[i] = residentphone[i + 1];
        residentflatno[i] = residentflatno[i + 1];
        duespaid[i] = duespaid[i + 1];
    }
    residentcount--;
    cout << "Resident removed.\n";
}
//----------------------this function helps adminn to search the residents
void searchresidents (){
    string name;
    cout<<"ENTER NAME TO SEARCH";
    cin>>name;
    int idx = findresidentindexbyname(name);
    if(idx == -1){
        cout <<"RESIDENTS NOT FOUND\n";
        return;
   }
    cout << "Name: " << residentname[idx] << "\nCNIC: " << residentcnic[idx]
         << "\nPhone: " << residentphone[idx]
         << "\nFlat: " << residentflatno[idx]
         << "\nDues: " << (duespaid[idx] ? "Paid" : "Not Paid") << endl;
}
//-----------------this function helps admin to post the particular announcements
void postannouncements (){
    if (announcemnetcount >= TOTAL_USER){
        cout<<"STORAGE FULL !!\\n";
        return;
    }
    cout<<"ENTER ANNOUNCEMENTS: ";
    cin.ignore();
    getline (cin, announcements[announcemnetcount]);
    announcemnetcount ++;
    cout<<"ANNOOUNCEMNET POSTED\n";
}
//----------------------this function helps residents to view the announcements
void viewannouncements (){
    cout<<"ANNOUNCEMENTS\n";
    for (int i =0; i <announcemnetcount; i++)
        cout<<i + 1 << " ." << announcements[i]<<endl;
}

// this functionm helps the admin to view the complaints
void viewcomplaints (){
        if (complaintcount == 0) cout << "No complaints.\n";
    else {
        for (int i = 0; i < complaintcount; i++)
            cout << i + 1 << ". " << complaints[i] << " - "
                 << (complaintresolved[i] ? "Resolved" : "Pending") << endl;
    }
}
//------------------this function helps the admin to view the maintaince records 
void viewmaintainancereq (){
if (maintaincecount== 0) cout << "No requests.\n";
    else {
        for (int i = 0; i < maintaincecount; i++)
            cout << i + 1 << ". " << maintaincereq[i] << " - "
                 << (maintainceresolved[i] ? "Resolved" : "Pending") << endl;
    }
}
//---------------------this function helps the admin to view wheather the dues are paid or not 
void viewduestatus (){
    for (int i = 0; i < residentcount; i++) {
    cout << residentname[i] << ": ";
    setcolor(duespaid[i] ? 10 : 12);
    cout << (duespaid[i] ? "Paid" : "Not Paid");
    setcolor(7);
    cout << endl;
    }
}
// -----------------------this functio helps residents to submit the complaints
void submitcomplaints (){
    if (complaintcount >= TOTAL_USER) {
    cout << "Complaint storage full.\n";
    return;
}
cout << "Enter complaint: ";
cin.ignore();
getline(cin, complaints[complaintcount]);
complaintresolved[complaintcount] = false;
complaintcount++;
cout << "Complaint submitted.\n";

}
//----------------------this function hepls to submit the maintaince requests
void submitmaintainacereq (){
   if (maintaincecount >= TOTAL_USER) {
    cout << "Storage full.\n";
    return;
}
cout << "Enter request: ";
cin.ignore();
getline(cin, maintaincereq[maintaincecount]);
maintainceresolved[maintaincecount] = false;
maintaincecount++;
cout << "Request submitted.\n";
}
//--------------------this function helps the residents to pay the dues
void paydues (){
    int idx = findresidentindexbyusername(currentuser);
if (idx == -1) {
    cout << "Profile error.\n";
    return;
}
if (duespaid[idx]) cout << "Already paid.\n";
else {
    duespaid[idx] = true;
    cout << "Dues paid.\n";
}
}
//--------------this function hepls the admin to view the complain status/ to check the complaints 
void viewcomplainstatus (){
    bool found = false;
    for (int i = 0; i < complaintcount; i++) {
        if (complaints[i].find(currentuser) != string::npos) {
            cout << complaints[i] << " - "
                 << (complaintresolved[i] ? "Resolved" : "Pending") << endl;
            found = true;
        }
    }
    if (!found) cout << "No complaints.\n";
}
//----------------------this function helps the admin to view the maintainace status 
void viewmaintainancestatus (){
    bool found = false;
    for (int i = 0; i < maintaincecount; i++) {
        if (maintaincereq[i].find(currentuser) != string::npos) {
            cout << maintaincereq[i] << " - "
                 << (maintainceresolved[i] ? "Resolved" : "Pending") << endl;
            found = true;
        }
    }
    if (!found) cout << "No maintenance requests.\n";
}
//-----------------------this function helps the  resients to view their profile
void viewprofile (){
    int idx = findresidentindexbyusername(currentuser);
if (idx == -1) cout << "Profile not found.\n";
else {
    cout << "Name: " << residentname[idx]
            << "\nCNIC: " << residentcnic[idx]
            << "\nPhone: " << residentphone[idx]
            << "\nFlat: " << residentflatno[idx]
            << "\nDues: " << (duespaid[idx] ? "Paid" : "Not Paid") << endl;
    }
}
//--------------------this function helps the residents to view the security rules  
void viewsocietyrules (){
    cout << "Rules:\n1. No noise after 10 PM\n2. Pay dues on time\n3. Respect others\n";

}
//---------------------------this function helps to change the password 
void changepassword (string username){

    cout << "Enter old password: ";
    string oldPass; cin >> oldPass;
    for (int i = 0; i < user_count; i++) {
        if (usernameA[i] == username && passwordA[i] == oldPass) {
            cout << "Enter new password: ";
            cin >> passwordA[i];
            cout << "Password updated.\n";
            return;
        }
    }
    cout << "Incorrect password.\n";
}
//--------------------------this function helps the admin to check the residnets view
void viewresidentsdues (){

    int idx = findresidentindexbyusername(currentuser);
    if (idx != -1) {
        cout << "Your dues: ";
        setcolor(duespaid[idx] ? 10 : 12);
        cout << (duespaid[idx] ? "Paid" : "Not Paid");
        setcolor(7);
        cout << endl;
    }
}
//------------------------this function helps  to find the resident's index  by their username
int  findresidentindexbyusername(string username){
    for (int i = 0, r = 0; i < user_count; i++) {
        if (rolesA[i] == "RESIDENT") {
            if (usernameA[i] == username)
                return r;
            r++;
        }
    }
    return -1;
}
//---------------------this function helps to find the the resiident's index by their names
int findresidentindexbyname(string name){
    for (int i = 0; i < residentcount; i++)
        if (residentname[i] == name) return i;
    return -1;
}
//-----------------------this function helps to save the residents data to file 
void saveresidentstoFile(){
        ofstream out("residents.txt");
    for (int i = 0; i < residentcount; i++) {
        out << residentname[i] << "," << residentcnic[i] << ","
            << residentphone[i] << "," << residentflatno[i] << ","
            << duespaid[i] << endl;
    }
    out.close();
}
//----------------this fucntion helps to load the residents  form the file incase of any problem
void loadresidentsfromFile(){
        ifstream in("residents.txt");
    string line;
    while (getline(in, line)) {
        int idx = 0;
        size_t pos = 0;
        string values[5];
        while ((pos = line.find(',')) != string::npos && idx < 4) {
            values[idx++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        values[4] = line;
        residentname[residentcount] = values[0];
        residentcnic[residentcount] = values[1];
        residentphone[residentcount] = values[2];
        residentflatno[residentcount] = values[3];
        duespaid[residentcount] = (values[4] == "1");
        residentcount++;
    }
    in.close();
}
//-------------------------this function helps sorting the residents by their names
void sortresidentsbyname(){
    for (int i = 0; i < residentcount - 1; i++) {
        for (int j = i + 1; j < residentcount; j++) {
            if (residentname[i] > residentname[j]) {
                swap(residentname[i], residentname[j]);
                swap(residentcnic[i], residentcnic[j]);
                swap(residentphone[i], residentphone[j]);
                swap(residentflatno[i], residentflatno[j]);
                swap(duespaid[i], duespaid[j]);
            }
        }
    }
}

//-------------functions ends---------------------


