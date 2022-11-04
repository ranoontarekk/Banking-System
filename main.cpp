#include <iostream>
#include "BankApplication.cpp"
int main() {
  BankAccount B1(5000.70);
  B1.setAccountID(20211039);
  cout << B1.getAccountID()<<endl;
  B1.setCurrentBalance(6000.70);
  cout << B1.getCurrentBalance() << endl;
  B1.withdraw(2000);
  B1.deposit(1000);
  cout << B1.getCurrentBalance() << endl;

    return 0;
}
