//
// Created by DELL on 11/4/2022.
//

#ifndef BANKSYESTEM_BANKACCOUNT_H
#define BANKSYESTEM_BANKACCOUNT_H
#include <iostream>

using namespace std;

class BankAccount {
        int accountID;
        double currentBalance;
public:
    BankAccount(double currentBalance);
    BankAccount();
    void setAccountID(int accountID);
    int getAccountID();
    void setCurrentBalance(double currentBalance);
    double getCurrentBalance();
    void withdraw(double amount);
    void deposit(double amount);

};


#endif //BANKSYESTEM_BANKACCOUNT_H
