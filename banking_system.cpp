// #include "BankAccount.h"
// #include "BankAccount.cpp"
#include <iostream>
#include <string>
using namespace std;



class BankAccount {
    private:
        string accountID;
        double currentBalance;
    public:
        BankAccount() {
            currentBalance = 0.0;
        }

        BankAccount(double currentBalance) {
                    currentBalance = currentBalance;
        }

        void setAccountID(string accountID) {
            accountID = accountID;
        }

        string getAccountID() {
            return accountID;
        }

        void setCurrentBalance(double currentBalance) {
            currentBalance = currentBalance;
        }

        double getCurrentBalance() {
            return currentBalance;
        }

        void withdraw(double amount) {
            if (amount > currentBalance) {
                cout << "You can't withdraw more than your current balance." << endl;
            } else {
                currentBalance -= amount;
            }
        }

        void  deposit(double amount) {
            currentBalance += amount;
        }

};

class client{
    private:
        string name ;
        string address ;
        string phone ;
        //string account ; 
    public:
        void set_name(string n){
            name = n ;
        }   
        string getname(){
            return name; 
        }

        void set_address(string d){
            address = d ;
        }

        string getaddress(){
            return address ;  
        }

        void set_phone(string p){
            phone = p;
        } 

        string get_phone(){
            return phone ; 
        }

        // void setaccount(string A){
        //     account = A ; 
        // }

        // string get_account(){
        //     return account ;
        // }

};

class SavingsBankAccount : public BankAccount {
    private:
        double minimumBalance ;
    public:
        SavingsBankAccount() :BankAccount(){
            minimumBalance = 1000 ;
        }

        SavingsBankAccount(double currentBalance , double min_balance) :BankAccount(currentBalance){
            if(currentBalance >= min_balance){
                minimumBalance = min_balance ;
            }
            else{
                cout<< "Initial balance should be >= min balance." << endl ;
            }
        }

        void set_minimum_balance(int min){
            minimumBalance = min ;
        }
        
        int get_minimum_balance(){
            return minimumBalance ;
        }

        void withdraw(double amount){
            if(amount < minimumBalance){
                cout<< "can't withdraw below the minimum balance." << endl ;
            }
            else{
                BankAccount::withdraw(amount);
            }
        }

        void deposit(double amount){
            if(amount >= 100){
                BankAccount::deposit(amount);
            }
            else{
                cout<< "can't deposit less than 100." << endl ;
            }
        }
};

int main(){

    return 0 ;
}


