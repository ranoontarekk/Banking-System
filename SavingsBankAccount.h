#include "BankAccount.h"
#include "BankAccount.cpp"

class SavingsBankAccount : public BankAccount {
    private:
        double minimumBalance ;
    public:
        SavingsBankAccount() :BankAccount();
        SavingsBankAccount(double currentBalance , double min_balance) :BankAccount(currentBalance);
        void set_minimum_balance(int min);
        int get_minimum_balance();
        void withdraw(double amount);
        void deposit(double amount);
};
