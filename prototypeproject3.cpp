#include<iostream>
#include<fstream>       //for file handling 
#include<conio.h>       // for getch()
#include<windows.h>     // to include Sleep()fxn
#include<string>        // for getline(),length() fxn
#include <iomanip>      //for setw() 
#include<stdlib.h>        // for System() fxn
using namespace std;

 class hostel {
    string pswd, name, branch, uniqueId,email,roll_No;;
    char z;
     public :
     
     void Main_menu();
     void admin();
     void Mess_info();
     void Hostel_info();
     void complaint();  
     void exitt();
     void add();
     void search();
     void del();
     void modify();
     void display();
     void comp();
     void show_menu();
     void show_spl_menu();
     void exittt();
     void room();
     void amenities ();
    
     
 };
 void hostel::Main_menu (){ 
     int option;
     system("cls");
     
     cout<<setw(52)<<"****************************"<<endl;   //use setw manipulator in place of \t 
     cout<<setw(52)<<"| HOSTEL MANAGEMENT SYSTEM |"<<endl;
     cout<<setw(52)<<"****************************"<<endl;
     cout<<setw(40)<<" 1. Admin Login "<<endl;
     cout<<setw(38)<<" 2. Mess info "<<endl;
     cout<<setw(40)<<" 3. Hostel info "<<endl;
     cout<<setw(47)<<" 4. Register Complaint "<<endl;
     cout<<setw(33)<<" 5. Exit "<<endl;
     cout<<endl;

     cout<<setw(48)<<" Enter Your Choice : ";
      cin>>option;
     switch(option){
         case 1 :
         admin();
         break;

         case 2:
         Mess_info();
         break;

         case 3:
         Hostel_info();
         break;

         case 4:
         complaint();
         break;

         case 5:
         exitt();
         break;

         default :
         cout<<endl<<setw(42)<<"Invalid input." << endl; 
         cout <<setw(50)<<"Returning to Main menu";
            Sleep(2500);        //  a fxn of windows.h header file ,used to suspend the execution  of the program for some time
            Main_menu();
         break;
           
     }
 }
 void hostel :: admin(){
     int i;
     char x,p;
     system("cls");
     cout<<setw(60)<<"***************** ADMIN LOGIN *****************"<<endl;
     cout<<"\n";
     cout<<setw(30)<<" Enter password : ";
     cin>>pswd;
      cout<<" Verifying password , Please wait ";
          for(int i =0; i<3;i++){
            cout<<".";
            Sleep(750);
          }
          if(pswd=="admin"){
           cout<<endl<<" Login successful.Press any key to continue...";
           z= getch();
            start:     
           system("cls");
            cout<<setw(80)<<"************ Welcome Admin ****************\n\n";
            cout<<setw(50)<<" 1. Add a record"<<endl;
            cout<<setw(53)<<" 2. Search a record"<<endl;
            cout<<setw(53)<<" 3. Delete a record"<<endl;
            cout<<setw(53)<<" 4. Modify a record"<<endl;
            cout<<setw(54)<<" 5. Display a record"<<endl;
            cout<<setw(52)<<" 6. View Complaint"<<endl;
            cout<<setw(45)<<" 7. Exit \n\n";
            cout<<setw(50)<<"Enter your choice : ";
            cin>>i;
            switch(i){
                case 1:
                do {
                     add();
                     cout<<"\n\t\t\tAdd another student record (Y/N) :";
                     cin>>p;
                 } while(p=='Y'||p=='y');
                 if (p=='N'|| p =='n'){
                     cout<<"\n\t\t\t returning to main menu...";
                     Sleep(2000);
                     Main_menu();
                 }
                  break;
        
                  case 2:
                  do {
                     search();
                     cout<<"\n\t\t\tSearch another student record (Y/N) :";
                     cin>>p;
                 } while(p=='Y'||p=='y');
                 if (p=='N'|| p =='n'){
                     cout<<"\n\t\t\t returning to main menu...";
                     Sleep(2000);
                     Main_menu();
              }     break;
                  break;

                  case 3:
                  do {
                     del();
                     cout<<"\n\t\t\tDelete another student record (Y/N) :";
                     cin>>p;
                 } while(p=='Y'||p=='y');
                 if (p=='N'|| p =='n'){
                     cout<<"\n\t\t\t returning to main menu...";
                     Sleep(2000);
                     Main_menu();
              }     break;

                  case 4:
                   do{
                       modify();

                     cout<<"\n\t\t\t Modify another student record (Y/N) :";
                     cin>>p;
                 } while(p=='Y'||p=='y');
                 if (p=='N'|| p =='n'){
                     cout<<"\n\t\t\t returning to main menu...";
                     Sleep(2000);
                     Main_menu();
              }     break;
                  break;

                  case 5:
                  display();
                  break;

                  case 6:
                  comp();
                  break;

            default:
            cout<<endl<<"\t\t\tInvalid input.\n\t\t\tPlease choose correct option...";
            Sleep(2500);
            goto start;    //dont use goto keyword , it is a bad programming:)
         break; 
            }
       }
           else {
           cout<<"\nInvalid password.Enter the correct password..."<<endl;
            Sleep(1000);
            admin();
           } 
         }
 
 
 void hostel :: add(){
     char m;
     
     system ("cls");

     cout<<"\t\t\t-------------Add a student record----------\n\n\n";
      ofstream add;           //ofstream class jo ki fstream header file se mili hai , uska object bnaya hai add

      cout<<"\t\t\t Enter the name of student:";
      cin.ignore(256,'\n');     // it ignores one or more characters till a new line is found
      getline(cin,name);         // reads the input from whole line
      cout<<"\t\t\t Enter the Branch :";
      cin>>branch;
      cout<<"\t\t\t Enter unique ID (must be 8 characters) :";
      cin>>uniqueId;
     try                //Exception Handling: To be added in other part also
     {
          switch(uniqueId.length()){
          case 8 : 
          {
     cout<<"\t\t\t Enter  Hostel roll no. of student :";
      cin>>roll_No;
      cout<<"\t\t\t Enter the email address :";
      cin>>email;
      add.open("Student.txt", ios::app | ios::out);    //opening a Student text file that appends to end of file
      add<< name<<"   " <<branch <<"   "<<uniqueId << "   "<<roll_No<<"   "<<email<<"\n ";
      cout<<"\n\t\t\tStudent record added successfully.....";
        
      add.close();
             break;
          } 
          default : 
          {
              throw 'c';
          }
          }}
     catch(char c)
     {
          cout<<"\n\t\t\t Invalid ID Format!(*must be 8 characters)";
          cout<<"\n\t\t\tEnter details again...";
          Sleep(2500);
          admin();
     }}

void hostel::search()
{
    system("cls");
    fstream search;
    int total = 1;
    search.open("Student.txt", ios::in);
    if (!search)
    {
        cout << "\n File does not exist...";
        search.close();
    }
    else
    {
        string rollno;
        cout << "Search Student" << endl;
        cout << "\n Enter Roll No. you wish to Search Student: ";
        cin >> rollno;
        search >> name >> branch >> uniqueId >> roll_No >> email;
        while (!search.eof())
        {
            if (rollno == roll_No)
            {
            cout<<"\n\t Student Name : " << name << endl;
            cout<<"\n\t Student Branch: " << branch << endl;
            cout<<"\n\t Student ID : " << uniqueId << endl;
            cout<<"\n\t Student's hostel roll Number : " << roll_No << endl;
            cout<<"\n\t Student's email: " << email <<endl;
            cout<<"\n\t**************************";
        
            }
            search >> name >> branch >> uniqueId >> roll_No >> email;
        }
        if (total == 0)
        {
            cout << ("\n\t\t\t Student Record Not Found.");
        }
        search.close();
    }
}
    void hostel::display()
{
    system("cls");
    fstream show;
    int total = 1;
    show.open("Student.txt", ios::in);
    if (!show)        
    {
        cout << "\n\n file not found....";
        show.close();
    }
    else
    {
        show >> name >> branch >> uniqueId >> roll_No >> email;
        cout<<"\n";
        
        while (!show.eof())
        {
            cout<<"\n\t Student No. " << total++ << endl;
            cout<<"\n\t Student Name : " << name << endl;
            cout<<"\n\t Student Branch: " << branch << endl;
            cout<<"\n\t Student ID : " << uniqueId << endl;
            cout<<"\n\t Student's hostel roll Number : " << roll_No << endl;
            cout<<"\n\t Student's email: " << email <<endl;
            cout<<"\n\t**************************";
            show >> name >> branch >> uniqueId >> roll_No >> email;
        }

 }
        if (total == 0)
        {
            cout << "\n\t\t Data not found....";
        }
        show.close();
        cout<<"\nPress Enter to return to Main menu...";
    getch();
    Main_menu();
}
void hostel :: modify(){
    system("cls");
    fstream file, file1;
    string uniqueid;
    int match = 1;
    cout << "Edit Student Details" << endl;
    file.open("Student.txt", ios::in);
    if (!file)     //IF Student file does not exist
    {
        cout << "\n\t\t File does not exist...."; 
        file.close();
    }
    else
    {
        cout << "\n Enter the student ID ";
        cin >> uniqueid;
        file1.open("tmpo.txt", ios::app | ios::out);
        file >> name >> branch >> uniqueId >> roll_No >> email;
        while (!file.eof())
        {
            if (uniqueid != uniqueId)
            {
                file1 << name<<"   " <<branch <<"   "<<uniqueId << "   "<<roll_No<<"   "<<email<<"\n ";
            }
            else
            {
            cout<<"\t Student Name : " ;
            cin>>name;
            cout<<"\t Student Branch: ";
            cin>>branch;
            cout<<"\t Student ID : " ;
            cin>>uniqueId;
            cout<<"\t Student's hostel roll Number : " ;
            cin>>roll_No;
            cout<<"\t Student's email: " ;
            cin>>email;
            cout<<"\t**************************";
            file1 << name<<"   " <<branch <<"   "<<uniqueId << "   "<<roll_No<<"   "<<email<<"\n ";
                
               cout << "\n\t\t\t Student record modified successfully...";
                cout<< " \n "; 
            }
            file >> name >> branch >> uniqueId >> roll_No >> email;
            if (match == 0)
            {
                cout << "\n\t\t Student Not found, Invalid data!";
            }
        }
        file1.close();
        file.close();
        remove("Student.txt");
        rename("tmpo.txt", "Student.txt");
        
    }
}
 void hostel :: del(){
 
 system("cls");
    fstream file, file1;
    string roll;
    int match = 1;
    cout << "Delete Student Details" << endl;
    file.open("Student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t Data not found.";
        file.close();
    }
    else
    {
        cout << "\n Enter Roll No. of Student which you want to delete data: ";
        cin >> roll;
        file1.open("tmpo.txt", ios::app | ios::out);
        file >> name >> branch >> uniqueId >> roll_No >> email;
        while (!file.eof())
        {
            if (roll != roll_No)
            {
                file1 << " " << name << " " << branch << " " << uniqueId << " " << roll_No << " " <<email<< "\n";
            }
            else
            {
                match++;
                cout << "\n\t\t\t Student record deleted successfully...";
                cout<< " \n ";
            }
            file >> name >> branch >> uniqueId >> roll_No >> email;
        }
        if (match == 0)
        {
            cout << "\n\t\t Sorry ! Record not found.";
        }
        file1.close();
        file.close();
        remove("Student.txt");
        rename("tmpo.txt", "Student.txt");
        Sleep(2000);
    }
}
 void hostel :: comp(){
    system("cls");
    cout<<"                        |REGISTERED COMPLAINTS OF HOSTELLERS|\n\n";
     ifstream fin;
    string mystring;
    fin.open("complaint.txt",ios::in);
     if (!fin)        
    {
        cout << "\n\n file not found....";
        fin.close();
    }
    else{
    while(!fin.eof()){
        getline(fin,mystring);
        cout<<mystring<<endl;
    }
    fin.close();

}
 }  
 void hostel :: Mess_info(){
    
    system("cls");
    cout<<"\t\t\t\t\tWelcome to the Mess information page\n"<<endl
        <<"\t\t\t\t\t\tMess timings:\n\t\t\t\t\t\tLunch: 12:30pm-2:30pm\n\t\t\t\t\t\tDinner: 8:00pm-10:00pm"<<endl
        <<"What information do you need ?"<<endl
        <<"Enter the number corresponding to the information you require."<<endl
        <<"1. Daily Menu"<<endl<<"2. Special Menu"<<endl<<"3. Exit"<<endl;
        cout<<"Enter your choice : ";
    char choice;
    cin>>choice;
    switch(choice){
        case '1':
            show_menu();
            break;
        case '2':
            show_spl_menu();
            break;
        case '3':
            exittt();
            break;
        default: 
            cout<<"Invalid input. Please enter your choice again...";
            Sleep(1500);
            Mess_info();
            break;
    }
 }

   void hostel:: show_menu(){
    ifstream fin;
    string mystring;
    fin.open("Mess.txt",ios::in);
     if (!fin)        
    {
        cout << "\n\n file not found....";
        fin.close();
    }
    else{
    while(!fin.eof()){
        getline(fin,mystring);
        cout<<mystring<<endl;
    }
    fin.close();
    cout<<"\nPress Enter to return to Main menu...";
    getch();
    Main_menu();

}}

void  hostel :: show_spl_menu(){
    ifstream show_spl;
    string s;
    show_spl.open("Spl_Menu.txt",ios::in);
     if (!show_spl)        
    {
        cout << "\n\n file not found....";
        show_spl.close();
    }
    while(!show_spl.eof()){
        getline(show_spl,s);
        cout<<s<<endl;
    }
    show_spl.close();

}
void hostel:: exittt(){
     cout<<"\nProgram terminated.Returning to main menu...";
     Sleep(1200);
     Main_menu();

}
void hostel :: complaint(){
    system("cls");
    cout<<"\n\t\t\t COMPLAINT REGISTER SECTION"<<endl;
    fstream search;

    search.open("Student.txt", ios::in);
    if (!search)
    {
        cout << "\n File does not exist...";
        search.close();
    }
    else
    { string id;
        cout << "\n Enter unique Student ID to register your complaint : ";
        cin >>id ;
        search >> name >> branch >> uniqueId >> roll_No >> email;
        while (!search.eof())
        {
            if (id == uniqueId)
            { 
                cout<<" Student record found...\n\n";
                cout<<" Student Name :"<<name<<endl
                <<" Hostel roll number :"<<roll_No<<endl;
                cout<<"\n______ENTER YOUR COMPLAINT HERE______\n\n";
                string com;
                ofstream insert;
                cin.ignore();
                getline(cin,com);
                insert.open("complaint.txt", ios::app | ios::out); 
                insert<< "\t\tStudent name :"<<name<<endl<<"\t\tHostel roll number :"<<roll_No<<endl
                <<"\t\tRegistered Complaint : "<<com<<endl<<"\t\t-------------------"<<endl;
                ;
                cout<<"\n\t\t Complaint registered successfully";
                cout<<"\n\t\t Press any key to return to Main menu...";
                getch();
                if(1){
                    Main_menu();
                }

             }
            search >> name >> branch >> uniqueId >> roll_No >> email;
     }

} 
}
 void hostel :: Hostel_info(){
    start:
    system("cls");
    cout<<"\n\t\t|************ GENERAL INFORMATION REGARDING HOSTEL ************|\n\n";
    cout<<"\t\t 1.Info related to rooms and fees structure\n";
    cout<<"\t\t 2.Info related to hostel amenities and timings\n";
    cout<<"\t\t 3.Return to main menu\n\n";
    cout<<"\t\t Enter your choice : ";
    char i;
    cin>>i;
    switch(i){
        case '1':
            room();
            break;
        case '2':
            amenities();
            break; 
            case '3':
            Main_menu();
            break; 
           default :
           cout<<"\n\t\tInvalid input...Please enter the valid input..";
           Sleep(1000);
           goto start;
           break;
    }

 }
 void hostel :: room(){
    ifstream room;
    string s;
    room.open("ROOM.txt",ios::in);
     if (!room)        
    {
        cout << "\n\n file not found....";
        room.close();
    }
    while(!room.eof()){
        getline(room,s);
        cout<<s<<endl;
    }
    room.close();
    cout<<"\nPress Enter to return to Main menu...";
    getch();
    Main_menu();

 }
 void hostel:: amenities(){
    ifstream amt;
    string s;
    amt.open("Amenities.txt",ios::in);
     if (!amt)        
    {
        cout << "\n\n file not found....";
        amt.close();
    }
    while(!amt.eof()){
        getline(amt,s);
        cout<<s<<endl;
    }
    amt.close();
    cout<<"\nPress Enter to return to Main menu...";
    getch();
    Main_menu();

 }
 void hostel :: exitt(){
     system("cls");
     cout<<"\n       ....Program terminated....";
     exit(0);
 }
 class student : public hostel{
 }
 ;
int main (){
    student display;
    display.Main_menu();
    
return 0 ;
}