#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED


#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class Account
{
private:
    string name1;
    string name2;
    int balance;
public:
    Account (string name1, string name2, int balance);
    void setBalance (int b){balance=b;};
    int getBalance (){return balance;};
    friend ostream& operator<<(ostream &o, Account &acc);

};


#endif // ACCOUNT_H_INCLUDED
