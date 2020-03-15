#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#include"Bank.h"
#include"Account.h"

void Bank::start_program()
{
   ifstream infile;
   infile.open("Accounts.txt");
   if (infile)
   {
   while  (!infile.eof())
   {
    string str,str2; //Garbage strings
    int b; //Balance
    string n1, n2; //Names
    infile>>str>>str2>>c;
    infile>>str>>str2>>n1;
    infile>>str>>str2>>n2;
    infile>>str>>b;
    Account acc (n1,n2,b);
    accounts.insert(pair <int,Account> (c, acc));
    }
   infile.close();
   }
}


void Bank::add_account()
 {
        string n1, n2;
        int b;
        cout<<"Enter first name: ";
        cin>>n1;
        cout<<"Enter last name: ";
        cin>>n2;
        cout<<"Enter initial balance: ";
        cin>>b;
        Account acc (n1,n2,b); //Account is created
        accounts.insert(pair <int,Account> (++c, acc)); //Account is stored in the map
        cout<<endl<<"Congratulation! Account is created with the following data: "<<endl<<endl; //Account data is displayed in the screen
        cout<<"Account number: "<<c<<endl;
        cout<<acc;
 }

int Bank::balance_enquiry()
{
     int ni=0; //The key that indicates the account the user wants to access to.
     cout<<"Enter account number: ";
     cin>>ni;
     try
     {
     check_account_number(ni);
     Account acc = accounts.at(ni);
     cout<<endl<<"Balance of account "<<ni<<" is "<<acc.getBalance()<<endl<<endl;
     }
       catch(int e)
     {
         cout<<endl<<"That account number does not identify any of the available accounts."<<endl;
         cout<<"Please go to option 6(show all accounts) to know the available accounts."<<endl<<endl;

     }
}

void Bank::deposit()
{
      int n=0, b_add=0;
      cout<<"Enter account number :";
      cin>>n;
      try
      {
      check_account_number(n);
      cout<<"Enter the balance that you want to add:";
      cin>>b_add;
      Account acc = accounts.at(n);
      acc.setBalance(b_add+acc.getBalance());
      accounts.at(n)=acc;
      cout<<endl<<"Balance is deposited"<<endl;
      cout<<"Account number: "<<n<<endl;
      cout<<acc;
      }
      catch(int e)
      {
         cout<<endl<<"That account number does not identify any of the available accounts."<<endl;
         cout<<"Please go to option 6(show all accounts) to know the available accounts."<<endl<<endl;
      }

}

 void Bank::withdraw()
 {
      int n=0, b_min=0;
      cout<<"Enter account number :";
      cin>>n;
      try
      {
      check_account_number(n);
      cout<<"Enter the balance that you want to withdraw:";
      cin>>b_min;
      Account acc = accounts.at(n);
      acc.setBalance(acc.getBalance()-b_min);
      accounts.at(n)=acc;
      cout<<endl<<"Balance is withdrawn"<<endl;
      cout<<"Account number: "<<n<<endl;
      cout<<acc;
      }
      catch(int e)
      {
         cout<<endl<<"That account number does not identify any of the available accounts."<<endl;
         cout<<"Please go to option 6(show all accounts) to know the available accounts."<<endl<<endl;
      }

 }

void Bank::close_account()
{
     int nerase=0;
     cout<<"Tell me the number of the account you want to close: ";
     cin>>nerase;
     try
     {
         check_account_number(nerase);
         accounts.erase(nerase);
         cout<<endl<<"That account has been closed!"<<endl<<endl;
     }
     catch(int e)
     {
         cout<<endl<<"That account number does not identify any of the available accounts."<<endl;
         cout<<"Please go to option 6(show all accounts) to know the available accounts."<<endl<<endl;
     }
}

 void Bank::show_accounts()
 {
     if (accounts.empty())
     {
         cout<<"No accounts have been registered yet."<<endl<<endl;
     }
     else
     {
     map<int,Account>::iterator itr;
     cout <<endl<< "The accounts that have been registered are: "<<endl<<endl;
     for (itr = accounts.begin(); itr !=  accounts.end(); ++itr)
     {
         cout<<"Account number: "<<itr->first<<endl<<itr->second<<endl;
     }
     }
 }

 void Bank::quit()
 {
    ofstream outfile ("Accounts.txt");
    map<int,Account>::iterator itr;
    for (itr = accounts.begin(); itr !=  accounts.end(); ++itr)
    {
       outfile<<"Account number: "<<itr->first<<endl<<itr->second<<endl ;
     }
     outfile.close();
      cout<<"Good bye! Everything has been saved in a file called Accounts.txt"<<endl;
 }


 void Bank::check_account_number(int n)
{
    if (accounts.find(n) == accounts.end())
		throw 1;
}
