#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>

//File handling
//user data ==> user.txt
//Flight booking ==> ticket.txt

using namespace std;

// ticket book block 
class FlightBooking {
private:
    static int ticketNumber;
    static string seatnum;
    string dt; 
    string rede;

public:
    void updateDate() {
     string ndt;
     ofstream inn("ticket.txt",ios:: binary|ios::app);
        cout<<"\n";
        cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
      
        cout << "Enter New Date for Booking (dd/mm/yyyy) : ";
        cin.ignore();
        getline(cin, ndt);
        dt=ndt;
        inn<<"\nYour Updated Ticket Date is "<<dt;
        cout<<"\nHave you booked your return ticket? (yes/no) : ";
        string uprebook;
        getline(cin,uprebook);
        if(uprebook=="yes"){
            cout<<"\nEnter New Return Booking Date (dd/mm/yyyy) : ";
            string uprede;
            getline(cin,uprede);
            rede=uprede;
            inn<<"\nYour Updated Return Ticket Date is "<<rede;
        cout<<"We will Send You Both Updated Ticket on Your Registered Email Id of Date "<<dt<<" and "<<rede<<"\n";
        }
        else
        {
            cout << "\nTicket Date Successfully Updated to " <<dt<< endl;
            
               // dt=ndt;ṇ
                
            cout<<"We Will Send You Updated Ticket on Your \nRegistered Email Id";
        }
        inn.close();
    }
 
    void bookFlight() {
        string dt,reIFSC,IFSC, passenger, seclass;
        int reacc,acc;
        string passize;
        string passnum;
        string st, de, temp;
        
        cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
  
        ofstream in("ticket.txt",ios::binary|ios::app); 
        
        in << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        in<<"================================================\n";
        in << "                 Flight  Ticket\n ";
        
        in << "\nTicket no. : " << ticketNumber++ << "         Flight no. : OOPS106\n";
         
        cout<<"\nEnter Number of passengers : ";
        cin>>passize;
         int passsize = stoi(passize);
          in<<"Passengers are : "<<passsize<<"\n";
          
        cout << "Enter Name of Passenger : ";
        cin.ignore();
        getline(cin, passenger);
        in << "Name : " << passenger;
        
        cout << "Enter Mobile no. : ";
        getline(cin, passnum);
        in<< "      Mobile no. : " << passnum;
      
        cout << "Enter Date for Booking (dd/mm/yyyy) : ";
        getline(cin, dt);
        in << "\nDate : " << dt << "        Depart. Time : 3:30 pm\n";
         
        cout << "Enter Your Station : ";
        getline(cin, st);
        in<<"From : "<<st; 
        
        cout << "Enter Your Destination : ";
        getline(cin, de);
        in<<"             To : "<<de;
        
        
 cout << "Seat Class Type \n1. Business Class\n2. Premium Economy\n3. Economy Class\nEnter Code : ";
       string classchoice;
       int ticketprice;
       
 do{
             cin>>classchoice; 
        
        if(classchoice=="1"){
            seclass="Business";
            ticketprice=750*passsize;
      
           }
        else if(classchoice=="2"){
            seclass="Premium Economy";
            ticketprice=500*passsize;
                
        }
        else if(classchoice=="3"){
            seclass="Economy";
            ticketprice=350*passsize;
            
        }
        else{
            cout<<"Invalid Input! try again : ";
       }
       in<< "\nSeat no. : " << seatnum << "          Class Type : " << seclass << endl;
        int seatInt = stoi(seatnum);
        seatInt++;
        seatnum = to_string(seatInt);
    } while (classchoice != "1" && classchoice != "2" && classchoice != "3");
    
        in<<"\n:::::::::::::::::HAPPY  JOURNEY:::::::::::::::::\n";
        in<<"\n================================================\n";
        in<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  
        cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
  
        cout<<"\nTicket Price is "<<ticketprice<<" INR for "<<passsize<<" Passenger ";
       
        cout << "\n\n***********************************************";
        cout << "\n           Enter Your Bank Details :          \n";
        cout << "***********************************************\n\n";
        
        cout << "Enter Your Account Number : ";
        while (!(cin >> acc)) {
            cout << "Please Enter Correct Account Number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        cout << "Enter IFSC Code : ";
        getline(cin, IFSC);
        
          string acOTP;
            
                cout << "Enter OTP Send on Your Number : ";
                do{
                getline(cin,acOTP);
                if (acOTP == "2026") {
                    cout << "\n";
                    break;
                } else {
                    cout << "Enter Correct OTP. Try Again." << endl;
                }
            } while (true);
      //  in<<"Ticket Number is "+ticketNumber;
      //  in<<"Seat Number is "+seatnum;
        cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"================================================\n";
        cout << "                 Flight  Ticket\n ";
        cout << "\nTicket no. : " << ticketNumber++ << "         Flight no. : OOPS106\n";
        cout << "Date : " << dt << "        Depart. Time : 3:30 pm\n";
        cout << "Name : " << passenger << "      Mobile no. : " << passnum;
        cout<<"\nFrom : "<<st<<"             To : "<<de;
        
        cout << "\nSeat no. : " << seatnum << "          Class Type : " << seclass << endl;
        
        int seatInt = stoi(seatnum);
        seatInt++;
        seatnum = to_string(seatInt);
        cout<<"\n:::::::::::::::::HAPPY  JOURNEY:::::::::::::::::\n";
        cout<<"\n================================================\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        // return ticket 
        cout<<"\n Do You Want to Book Return Ticket (yes/no) : ";
        string rebook;
        getline(cin,rebook);
        in<<" Is Return Ticket Required "+rebook;
        if(rebook=="yes"){
            cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
            cout<<"\nEnter Return Booking Date (dd/mm/yyyy) : ";
          //  string rede;
            getline(cin,rede);
            in<<"\nReturn Ticket Data is "<<rede;
      
        cout<<"\nReturn Ticket Price is "<<ticketprice<<" INR for "<<passsize<<" Passenger ";
       
        cout << "\n\n***********************************************";
        cout << "\n           Enter Your Bank Details :          \n";
        cout << "***********************************************\n\n";
        
        cout << "Enter Your Account Number : ";
        while (!(cin >> reacc)) {
            cout << "Please Enter Correct Account Number :";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
        cin.ignore();

        cout << "Enter IFSC Code : ";
        getline(cin, reIFSC);
        
          string reacOTP;
            
                cout << "Enter OTP Send on Your Number : ";
                do{
                getline(cin,reacOTP);
                if (reacOTP == "2022") {
                    cout << "\n";
                    break;
                } else {
                    cout << "Enter Correct OTP. Try Again." << endl;
                }
            } while (true);
            
        in<<"\nReturn Ticket Number is "+ticketNumber;
        in<<"\nReturn Ticket Seat Number is "+seatnum;
        in.close();
        cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
      
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"================================================\n";
        cout << "                 Return Ticket\n ";
        cout << "\nTicket no. : " << ticketNumber++ << "         Flight no. : OOPS106\n";
        cout << "Date : " << rede << "        Depart. Time : 8:30 am\n";
        cout << "Name : " << passenger << "      Mobile no. : " << passnum;
        temp=st;
        st=de;
        de=temp;
        cout<<"\nFrom : "<<st<<"             To : "<<de;
        
        cout << "\nSeat no. : " << seatnum << "          Class Type : " << seclass << endl;

     //   int seatInt = stoi(seatnum);
     //   seatInt++;
     //  seatnum = to_string(seatInt);
        cout<<"\n-----------------HAPPY  JOURNEY-----------------\n";
        cout<<"\n================================================\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";       
       
        cout << "\nYour Flight Ticket Booked Successfully\n";
        cout << "\nYour E-TICKET Will be Sent to Your Registered Email Id\n";

        }
        else{
        
            cout << "\nYour Flight Ticket Booked Successfully\n";
            cout << "\nYour E-TICKET Will be Sent to Your Registered \nEmail Id\n";
           // cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
        }
    }
    void ticketview(){
    cout << "\033[2J\033[1;1H";
    
    cout<<"\nThis Tickets Will Not be Concluded as Original\n";
    string view;
        ifstream out("ticket.txt",ios::in|ios:: binary);
        
        while(getline(out,view)){
        cout<<view<<"\n";
        }
        
        out.close();
    }
};

int FlightBooking::ticketNumber = 101;
string FlightBooking::seatnum = "0131";

// flight cancel 
class FlightCancellation {
public:
    void cancelFlight() {
    cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear console
      
        int caltc;
        
        cout << "Enter Your Ticket no : ";

        // Validate Ticket Number
        while (!(cin >> caltc)) {
            cout << "Invalid input. Please enter a numeric value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }//     cout << "Your Ticket of no. " << caltc << " is Cancelled\nWe Will Refund Your Amount within 48 Hours";

                 int cotp; 
                 
            bool verified = false;
            do {
                cout << "Enter 6 Digit OTP Sent to Your Number : ";

                // otp checking 
                while (!(cin >> cotp)) {
                    cout << "Invalid input. Please enter a numeric value: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (cotp) {
                    case 221106:
                    cout << "Your Ticket of no. " << caltc << " is Cancelled\nWe Will Refund Your Amount within 48 Hours";

                        verified = true;
                        break;
                    default:
                        cout << "Please Enter Correct OTP. Try Again." << endl;
                        break;
                }
            } while (!verified);
     }
};

class UserAuthentication {
public:
    void authenticate() {
        int ss1;
        cout << "Are You Already Signed in?\nIf Signed in Then Enter 1 Otherwise Enter 2 : ";
        cin >> ss1;

        if (ss1 < 2) {
            string em, iemail, pass, iuserPass;
            ifstream iumail("useremail.txt");
            ifstream iupass("user_pass.txt");
do{
            cout << "\nEnter Your Email ID : ";
            cin >> em;
            cout << "Enter Your Passcode : ";
            cin >> pass;

            iumail >> iemail;
            iupass >> iuserPass;

            if ((em == "coderofoopm@gmail.com" || em == iemail) && (pass == "9310" || pass == iuserPass)) {
                cout << "\033[2J\033[1;1H";  // Clear console
                cout << "\nWelcome Coder of OOPM ";
            } else {
                cout << "\nPlease Enter Correct Email or Password" << endl;
            }}while((em != "coderofoopm@gmail.com" && em != iemail) || (pass != "9310" && pass!=iuserPass));

            iumail.close();
            iupass.close();
        } else {
            string num, email, name;
            int otp;

            ofstream umail("useremail.txt", ios::app);
            ofstream uin("user.txt", ios::app);
            ofstream upass("user_pass.txt", ios::app);

            cout << "\nEnter Your Email Address : ";
            cin >> email;
            umail << email << "\n";

            uin << "\nUser Email " << email;

            cout << "Enter Your Mobile Number : ";
            cin >> num;
            uin << "\nUser Number " << num;

            cin.ignore();
            cout << "Enter Your Full Name : ";
            getline(cin, name);
            uin << "\nUser Name " << name << "\n";

            cout << "Enter OTP Sent to Your Number : ";
            cin >> otp;
            if (otp == 9109) {
                int userPass;
                cout << "Create Password : ";
                cin >> userPass;
                upass << userPass << "\n";

                cout << "\033[2J\033[1;1H";  // Clear console
                cout << "Sign Up Successfully! Welcome " << name;
            } else {
                cout << "Please Enter Correct OTP. Try Again." << endl;
            }

            umail.close();
            uin.close();
            upass.close();
        }
    }

    void userId() {
        cout << "\033[2J\033[1;1H";
        cout << "User Profile \n\n";
        string uview;
        ifstream userview("user.txt", ios::in);
        while (getline(userview, uview)) {
            cout << uview << "\n";
        }
        userview.close();
    }
};

// main page display block

void userChoice()
{
FlightBooking booking;
    int choice;

do 
{
    cout << "\n\n_______________________________________________\n";
    cout << "\nFlight Booking System Menu" << endl;
    cout << "\n1. Book a flight" << endl;
    cout << "2. Update Date in Booked Ticket \n";
    cout << "3. Show all the Tickets \n";
    cout << "4. Cancel a flight" << endl;
    cout << "5. Exit";
    cout << "\n________________________________________________\n";

    cout << "\nEnter Code of your Choice : ";
  
     while (!(cin >> choice))
    {
          //  cout << "Invalid input. Please enter a numeric value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch (choice) 
        {
            case 9696:
            cout<<"\n";
              UserAuthentication id;
              id.userId();
              break;
            
            case 1:
              booking.bookFlight();
                break;
            case 2:
              booking.updateDate();
               break;
            
            case 3:
              booking.ticketview();
              break;
               
            case 4:
                FlightCancellation cancellation;
                cancellation.cancelFlight();
                break;
            case 5:
                cout << "\033[2J\033[1;1H";
                cout << "\nExiting the program. Thank you!\nTEAM : CODERS OF OOPM ";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
} 
while (choice != 5);
}
void dis(){
    //system("cls");
    cout<<"\033[2j\033[1;1H";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"::::: Welcome in Our Flight Booking System :::::";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void pro(){

 cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<" "<<setw(30)<<"This Program\n"<<setw(31)<<"is Created \n"<<setw(28)<<"by TEAM\n";
 cout<<"::::::::::::::::: CODER OF OOPM ::::::::::::::::";
 cin.get();
 system("cls");
dis();

UserAuthentication auth;
auth.authenticate();

userChoice();
}

int main()
{
pro();

return 0;
}