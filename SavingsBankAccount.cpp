#inculde "SavingsBankAccount.h"

        SavingsBankAccount::SavingsBankAccount() :BankAccount(){
            minimumBalance = 1000 ;
        }

        SavingsBankAccount::SavingsBankAccount(double currentBalance , double min_balance) :BankAccount(currentBalance){
            if(currentBalance >= min_balance){
                minimumBalance = min_balance ;
            }
            else{
                cout<< "Initial balance should be >= min balance." << endl ;
            }
        }

        void SavingsBankAccount::set_minimum_balance(int min){
            minimumBalance = min ;
        }
        
        int SavingsBankAccount::get_minimum_balance(){
            return minimumBalance ;
        }

        void SavingsBankAccount::withdraw(double amount){
            if(amount < minimumBalance){
                cout<< "can't withdraw below the minimum balance." << endl ;
            }
            else{
                BankAccount::withdraw(amount);
            }
        }

        void SavingsBankAccount::deposit(double amount){
            if(amount >= 100){
                BankAccount::deposit(amount);
            }
            else{
                cout<< "can't deposit less than 100." << endl ;
            }
        }
