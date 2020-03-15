/// BANK APPLICATION: Final course project

#include <iostream>
#include <map>
#include <fstream>
#include"Bank.h"
#include"Account.h"


using namespace std;


int main()
{
    Bank B;


    //0. When the program starts, it must read the data from the file!

    B.start_program();


    //1) Asking the user what to do:

    int choice=0;
    cout<<"Banking system: "<<endl<<endl;
    while (choice!=7)
    {
    cout<<"Select an option below "<<endl;
    cout<<"1. Open an account"<<endl;
    cout<<"2. Balance enquiry"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdrawal"<<endl;
    cout<<"5. Close an account"<<endl;
    cout<<"6. Show all accounts"<<endl;
    cout<<"7. Quit"<<endl<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;


    //2) Options depending on the user choice:

    switch (choice)
    {
    case 1: //Adding accounts
        {
        B.add_account();
        break;
        }
    case 2: //Balance enquiry
       {
        B.balance_enquiry();
        break;
       }
    case 3: //Deposit
       {
        B.deposit();
        break;
        }
    case 4: // Withdrawal
       {
        B.withdraw();
        break;
       }
    case 5: // Close an account:
       {
       B.close_account();
       break;
       }
//
    case 6: //Show all accounts:
        {
        B.show_accounts();
        break;
        }
//
    case 7: // Let's save the data!!!!!
       {
        B.quit();
       }
    }
   }
return 0; //Program ends here!
}


