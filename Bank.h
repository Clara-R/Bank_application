#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#include"Account.h"


class Bank
{
private:
    map<int,Account> accounts; //Map where all the accounts are going to be stored with their account numbers (identifiers).
    int c=0; //Counter (to indicate the account number for the accounts that are created -sequential order).
public:
    void start_program ();
    void add_account();
    int balance_enquiry();
    void deposit();
    void withdraw();
    void close_account();
    void show_accounts();
    void quit();
    void check_account_number(int n);
};

#endif // BANK_H_INCLUDED
