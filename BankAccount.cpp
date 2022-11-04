//
// Created by DELL on 11/4/2022.
//
#include "BankAccount.h"
BankAccount :: BankAccount(double currentBalance) {
    this->currentBalance = currentBalance;
}
BankAccount :: BankAccount() {
    this->currentBalance = 0.0;
}

void BankAccount::setAccountID(int accountID) {
    this->accountID = accountID;
}

int BankAccount::getAccountID() {
    return accountID;
}

void BankAccount::setCurrentBalance(double currentBalance) {
    this->currentBalance = currentBalance;
}

double BankAccount::getCurrentBalance() {
    return currentBalance;
}

void BankAccount::withdraw(double amount) {
    if (amount > currentBalance) {
        cout << "You can't withdraw more than your current balance" << endl;
    } else {
        currentBalance -= amount;
    }
}

void BankAccount :: deposit(double amount) {
    currentBalance += amount;
}