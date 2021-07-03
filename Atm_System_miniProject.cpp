#include<iostream>
#include<conio.h>
//#include<windows.h>
//#include<stdio.h>
//#include <cstdlib>
//#include <ctime>
#include <string>
#include<fstream>
#include<math.h>
using namespace std;

class Bank
{
protected:

private:
      //  long accNo=123232123211;

public:
    double balance=0;
    int pin=2431;
    char name[50];
    char cno[10];
    int age,a;
    int d=0;
    char atmNo[12];
    char accNo[11]={123232123211};

    void getdetails();
    void getUserDetails();
    void displayUserDetails();
    void displayMenu();
/*void generateNo()
    {
        for(int i=1;i<=11;i++)
        {
            d=rand();
            accNo=accNo*10+d;
        }

    }*/
    Bank()
    {
        displayMenu();
        getUserDetails();

    }
};

//*****************************Display welcome menu*****************************//

void Bank::displayMenu()
{
    cout<<"\n\t\t    ==========================================="<< endl;
    cout<<"\t\t    ==========================================="<< endl;
    cout<<"\t\t          ||   WELCOME TO ATM SIMULATOR   ||"<< endl;
    cout<<"\t\t    ==========================================="<< endl;
    cout<<"\t\t    ===========================================\n\n"<< endl<< endl;

}
//***************************GetUser details*******************************//
void Bank::getUserDetails()
{
    cout<<"Firstly lets create an account for you... :) "<<endl;
    getch();
    cout<<endl<<"Enter your name : ";cin>>name;
    cout<<endl<<"Enter your age  : ";cin>>a;
    cout<<endl<<"Enter your contact no. : ";cin>>cno;
    cout<<endl<<"That's enough details for us to create your account ... :)"<<endl;

    ofstream outf("UserDetails");
    outf<<endl<<"Name : "<<name;
    outf<<endl<<"Age  : "<<a;
    outf<<endl<<"Contact no. : "<<cno<<endl;

    displayUserDetails();
}
//*****************************Display user details*****************************//
void Bank::displayUserDetails()
{

    //cout<<"your ATM Card no. is "<<endl;
    //srand((unsigned)time(0));       //generating random number
   // cno=(rand()%6)+1;
    //cno=(accNo%6)+1;
   // cout<<cno;
    cout<<endl<<endl<<"**************************User Details***************************"<<endl<<endl;
    cout<<"User name           : "<<name<<endl;
    cout<<"A/c number          : "<<accNo<<endl;
    cout<<"User age            : "<<a<<endl;
    cout<<"User contact number : "<<cno<<endl;
    cout<<"Balance             : "<<balance<<endl<<endl;
    cout<<"**************************User Details***************************"<<endl<<endl<<endl;
}


//#####################**********ATM PART**********#####################//



class Atm:public Bank
{
public:

    int option,amt,attempt=0;
    void displayATMmenu();
    Atm()
    {
        displayATMmenu();
    }

    void operate(int option);
    int getPin();
    void ChangePin();
    void getReciept(int);
    void deposite();
    void withdraw();
    void Balance();
    void Transact(int);
   // void Transactions(int);
    void goback();
};

//************************** Display Atm's menu  ******************************//

void Atm::displayATMmenu()
{
    cout<<"\n\n************************Select option*********************"<<endl;
    cout<<"* "<<"                                                      *"<<endl;
    cout<<"* "<<"1.Get account details           4.Withdraw            *"<<endl;
    cout<<"* "<<"2.Balance inquiry               5.Change Pin          *"<<endl;
    cout<<"* "<<"3.Deposit                       6.Last transaction    *"<<endl;
    cout<<"* "<<"                                7.Exit                *"<<endl;
    cout<<"* "<<"                                                      *"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<endl<<"enter operation code "<<endl;
    cin>>option;
    operate(option);
}





//**************************ATM Menu***************************//

void Atm::goback()
{
    getch();
    cout<<"press any key to go back to ATM Menu ";
    displayATMmenu();
}



//************************switch to menu options************************//

void Atm::operate(int opt)
{
 int a=2;
    switch(opt)
    {

        case 1:
            displayUserDetails();
            goback();
            break;

        case 2:
            Balance();
            goback();
            break;

        case 3:
            deposite();
            goback();
            break;

        case 4:
            withdraw();
            goback();
            break;

        case 5:ChangePin();goback();
            break;

        case 6:Transact(a);
            goback();
            break;


        case 7:
            cout<<endl<<"Thank you for using our Atm System"<<endl<<"**********[exiting]**********"<<endl;
            break;

        default:
            cout<<"Invalid input "<<endl;
           // displayATMmenu();
            break;
    }
}




//********************** Balance inquiry *********************//
void Atm::Balance()
{
    int pincode=getPin();
    if(pincode==pin)
        cout<<"your current balance is"<<endl<<balance;
    else
        cout<<"Invalid password !\n";
}




int Atm::getPin()
{
    int pincode;
    cout<<"please enter your 4 digit pin ";cin>>pincode;cout<<endl;
    return pincode;
}



//***********************Deposite*****************************//

void Atm::deposite()
{
    int pincode=getPin();
    if(pincode==pin)
    {
        attempt=0;
        cout<<"your current balance is "<<balance<<endl;
        cout<<"enter amount to deposit "<<endl;cin>>amt;
        //SetConsoleTextAttribute(hConsole,10);
        if(amt<100)
        //{
           // HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
            //SetConsoleTextAttribute(hConsole,10);
            cout<<"minimum amount to deposit is 100 ";
        //}
        else
        {
            balance+=amt;
            cout<<"amount deposited successfully \n";
            getch();
            getReciept(1);
           // Transactions(1);

        }

    }else
    {
        if(attempt<=3)
        {
            cout<<"Invalid pin... !!"<<endl;
            attempt+=1;
            displayATMmenu();
        }else if(attempt>3)
        {
            cout<<"you have cross the maximum limit of wrong pin"<<endl<<"now your account will be locked : ";
        }


    }


}

//************************Withdraw******************************//

void Atm::withdraw()
{
    int pincode=getPin();
    if(pincode==pin)
    {
        attempt=0;
        cout<<"your current balance is "<<balance<<endl;
        cout<<"enter amount to withdraw "<<endl;cin>>amt;
        if(balance<199 && amt>0 || balance<amt)
            cout<<"Sorry :(  your balance is very low , "<<endl<<"you can't withdraw money "<<endl;
        else if(amt<200 )
            cout<<"Sorry :(  minimum limit to withdraw is 100rs , "<<endl<<"you can't withdraw money "<<endl;
        else
        {
            balance-=amt;
            cout<<amt<<" has been withdrawn "<<endl;
            getch();
            getReciept(2);
            //Transactions(2);
            Transact(2);
        }
    }
    else
    {
        if(attempt<=3)
        {
            cout<<"Invalid pin... !!\n";
            attempt++;
            displayATMmenu();
        }else if(attempt>3)
        {
            cout<<"you have cross the maximum limit of wrong pin\n now your account will be locked : ";
        }
    }


}






void Atm::getReciept(int i)
            {
            int c,type=i;
            cout<<"Do you want recipt "<<endl;
            cout<<"1.Yes\n2.No\n";
            cin>>c;
            if(c==1)
            {
                ofstream outf("RECIEPT");
//outf<<"Name                A/c no.               Credit              Debit           Total\n\n";
                if(type==1)
                {
                   outf<<"Name         :"<<name<<"\nA/c No.    :"<<accNo<<"\nDeposited  :"<<amt<<".00 Cr."<<"\nBalanced   :"<<balance<<".00 Cr.\n\n";
                }
                else if(type==2)
                {
                    outf<<"Name         :"<<name<<"\nA/c No.    :"<<accNo<<"\nWithdrawn  :"<<amt<<".00 Cr."<<"\nBalanced   :"<<balance<<".00 Cr.\n\n";
                }

            }

}


/*void Atm::Transactions(int i)*/
void Atm::Transact(int i)
{
    int type=i;
    ofstream outf("Transactions");
                outf<<"Name                A/c no.               Credit              Debit           Total\n\n";
                if(type==1)
                {
                    //outf.open("Transactions",ios::app<<name<<"                      //outf.open("Transactions",ios::app<<name<<"                 "<<accNo<<"               +"<<amt<<".00 Cr.                              "<<balance<<"Cr.\n\n");               "<<accNo<<"               +"<<amt<<".00 Cr.                              "<<balance<<"Cr.\n\n");                    //outf.open("Transactions",ios::app<<name<<"                 "<<accNo<<"               +"<<amt<<".00 Cr.                              "<<balance<<"Cr.\n\n");
                    outf<<"-----------------------------------------------------------------------------------------------------------------------";
                    outf<<endl<<name<<"        |         "<<accNo<<"        |       +"<<amt<<".00 Cr.      |               |        "<<balance<<"Cr.\n\n";
                }
                else if(type==2)
                {
                    outf<<"-----------------------------------------------------------------------------------------------------------------------";
                    outf<<endl<<name<<"        |         "<<accNo<<"        |               |         -"<<amt<<".00 Cr.    |        "<<balance<<"Cr.\n\n";
                }

}

void Atm::ChangePin()
{
    int p,np,vp;
    cout<<endl<<endl<<"please enter your 4 digit pin \n";
    cin>>p;
    if(p==pin)
    {
        cout<<"enter new pin\n";
        cin>>np;
        cout<<"\nverify new pin\n";
        cin>>vp;
        if(vp==np)
        {
            pin=vp;
            cout<<"pin has changed \n";
        }
        else
            cout<<"\n incorrect pin \n\n";
    }
    else
    {
        cout<<"incorrect pin \n\n";
    }
}


int main()
{
   // Bank obj;
    Atm atmobj;
    getch();
    return 0;
}
