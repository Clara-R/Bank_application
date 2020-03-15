#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#include"Account.h"


Account::Account(string name1, string name2, int balance)
 {
        this->name1=name1;
        this->name2=name2;
        this->balance=balance;
}

ostream & operator<<(ostream &o, Account &acc)
{
     o<<"First name: "<<acc.name1<<endl;
     o<<"Second name: "<<acc.name2<<endl;
     o<<"Balance: "<<acc.balance<<endl<<endl;
}
