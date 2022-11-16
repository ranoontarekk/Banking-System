#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

//class for basic user's account.
class BankAccount {
private:
    string AccountID;
    double CurrentBalance;
public:
    BankAccount() {
        CurrentBalance = 0.0;
    }

    BankAccount(double currentBalance ,string accountID) {
        CurrentBalance = currentBalance;
        AccountID = std::move(accountID) ;
    }

    void setAccountID(string accountID) {
        AccountID = std::move(accountID);
    }

    virtual string getAccountID() {
        return AccountID;
    }

    void setCurrentBalance(double currentBalance) {
        CurrentBalance = currentBalance;
    }

    double getCurrentBalance() const{
        return CurrentBalance;
    }

    virtual void withdraw(double amount) {

        if (amount > CurrentBalance) {
            cout << "You can't withdraw more than your Current Balance (" << CurrentBalance << " L.E.)" << endl;
            exit(1);
        } else {
            CurrentBalance -= amount;
            cout << "Withdrawn successfully." << endl;
            cout << "Current Balance: " << getCurrentBalance() << " L.E." << endl;

        }
    }

    virtual void  deposit(double amount) {
        CurrentBalance += amount;
        cout << "Deposited successfully." << endl;
        cout << "Current Balance: " << getCurrentBalance() << " L.E." << endl;
    }

};

//class for saving user's account
class SavingsBankAccount : public BankAccount {
private:
    double MinimumBalance ;
public:
    SavingsBankAccount() :BankAccount(){
        MinimumBalance = 1000 ;
    }

    SavingsBankAccount(double currentBalance ,string accountID, double& min_balance) :BankAccount(currentBalance , std::move(accountID)){
        if(currentBalance >= min_balance){
            MinimumBalance = min_balance ;
        }
        else{
            cout<< "Initial balance should be >= Minimum balance." << endl ;
            exit(1);
        }
    }

    void setMinimumBalance(int min){
        MinimumBalance = min ;
    }

    double getMinimumBalance() const{
        return MinimumBalance ;
    }
//This might be wrong we will check it later
    void withdraw(double amount){

        if(amount < MinimumBalance){
            cout<< "can't withdraw below the Minimum balance ("<< MinimumBalance << " L.E.)" << endl ;
            exit(1);
        }
        else{
            BankAccount::withdraw(amount);

        }
    }

    void deposit(double amount) override{
        if(amount >= 100){
            BankAccount::deposit(amount);
        }
        else{
            cout<< "can't deposit less than 100 L.E." << endl ;
            exit(1);
        }
    }
};

//class for client information.
class Client {
private:
    string Name ;
    string Address ;
    string Phone ;
    BankAccount* Account{} ;
public:

    void set_name(string n){
        Name = std::move(n) ;
    }
    string get_name(){
        return Name;
    }

    void set_address(string d){
        Address = std::move(d) ;
    }

    string get_address(){
        return Address ;
    }

    BankAccount* getBankAcc(){
        return Account;
    }

    void set_phone(string p){
        Phone = std::move(p);
    }

    string get_phone(){
        return Phone ;
    }

    void set_BankAccount(BankAccount& account){
        Account = &account ;
    }

    void set_SavingsBankAccount(SavingsBankAccount& account){
        Account = &account ;
    }

    string get_client_AccountID(){
        return Account->getAccountID() ;
    }

};
vector<Client> basClients_List ;
vector<BankAccount> BankAccounts_list ;
vector<SavingsBankAccount> SavingsBankAccounts_list ;
vector<Client> savClients_List ;
class BankApplication{
private:
    static int indexOfBasic,indexOfSaving;
public:
    BankApplication(){
        cout<< "Welcome to FCAI Banking Application" << endl ;
        cout << "Please choose one of the following options:" << endl ;
        cout << "1. Create a new Account" << endl ;
        cout << "2. List Clients and accounts" << endl ;
        cout << "3. Withdraw Money" << endl ;
        cout << "4. Deposit Money" << endl ;
        cout << "5. Exit" << endl ;
        cout << "Enter your choice: " ;}
    static void addClient(){Client a ; string ad , ph , na ; char answer ;
        cin.ignore();
        bool ret = false;
        cout << "Please Enter Client Name =========> " ;
        getline(cin,na);

        cout << "Please Enter Client Address =======> " ;
        getline(cin,ad);
        //to check if the email is valid
        regex emailformat ("^[a-zA-Z0-9+_.-]+@[a-zA-Z.-]+$") ;
        ret = regex_match(ad, emailformat) ;
        while(!ret)
        {

            cout <<"invalid email please enter again: ";
            getline(cin,ad);
            ret = regex_match(ad, emailformat) ;

        }

        cout << "Please Enter Client Phone =========> " ;
        getline(cin,ph);
        //to check if the phone number is valid.
        regex phoneNumformat ("(011|012|010|015)+[0-9]{8}") ;
        ret = regex_match(ph, phoneNumformat) ;
        while(!ret)
        {

            cout <<"invalid phoneNum please enter again: ";
            getline(cin,ph);
            ret = regex_match(ph, phoneNumformat) ;
        }
        a.set_name(na);
        a.set_address(ad);
        a.set_phone(ph);

        cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> " ;
        cin >> answer;

        //if the user choose the basic account.
        if(answer == '1'){
            double bal ;
            cout << "Please Enter the Starting Balance =========> " ;
            cin>> bal ;
            //put ID for user.
            BankAccount account(bal,("FCAI-" + to_string(indexOfBasic++))) ;
            BankAccounts_list.push_back(account);
            a.set_BankAccount(BankAccounts_list[BankAccounts_list.size()-1]);
            cout<< "An account was created with ID "<< account.getAccountID() << " and Starting Balance " <<account.getCurrentBalance() << " L.E.\n" ;
            basClients_List.push_back(a);
        }

        //if the user choose the saving account.
        else if(answer == '2'){
            double bal , min_bal ;
            cout << "Please Enter the Starting Balance =========> " ;
            cin>> bal ;
            cout << "Please Enter the Starting Minimum balance ==> " ;
            cin>> min_bal ;
            SavingsBankAccount account(bal, ("FCAI-" + to_string(++indexOfSaving)), min_bal) ;
            SavingsBankAccounts_list.push_back(account);
            a.set_SavingsBankAccount(SavingsBankAccounts_list[SavingsBankAccounts_list.size()-1]);
            cout<< "An account was created with ID "<< account.getAccountID() << " and Starting Balance " <<account.getCurrentBalance() << " and Minimum balance "<< account.getMinimumBalance() <<" L.E.\n" ;
            savClients_List.push_back(a);
        }

        cin.ignore();

    }
    static string getUserId() {
        string id;
        //print this message for one time
        cout << "Please, enter your Id==========> ";
        cin >> id;
        return id;
    }

    //method to erase FCAI and convert to int.
    static int converToInt(string id){
        //delete all characters and spaces  except numbers
        id.erase(remove_if(id.begin(), id.end(), [](char c) { return !isdigit(c); }), id.end());
        //convert string to int and return it
        return stoi(id);
    }

    //if the user choose to print the list.
    static void caseList(){
        string id=getUserId();
        if ((converToInt(id)) > 100) {
            listClients(savClients_List[converToInt(id)]);
        } else {
            listClients(basClients_List[converToInt(id)]);
        }
    }

    //if the user choose withdraw.
    static void casewithdraw(){
        string id=getUserId();
        if ((converToInt(id)) > 100) {
            double withdraw;
            cout << "Please, enter the amount you want to withdraw=========> ";
            cin >> withdraw;
            savClients_List[converToInt(id)].getBankAcc()->withdraw(withdraw);
        } else {
            double withdraw;
            cout << "Please, enter the amount you want to withdraw=========> ";
            cin >> withdraw;
            basClients_List[converToInt(id)].getBankAcc()->withdraw(withdraw);
        }
    }

    //if the user choose depsit.
    static void casedeposit(){
        string id=getUserId();
        if ((converToInt(id))> 100) {
            double deposit;
            cout << "Please, enter the amount you want to add===========> ";
            cin >> deposit;
            savClients_List[(converToInt(id))].getBankAcc()->deposit(deposit);
        } else {
            double deposit;
            cout << "Please, enter the amount you want to add===========> ";
            cin >> deposit;
            basClients_List[(converToInt(id))].getBankAcc()->deposit(deposit);
        }
    }
    static void listClients(Client cli){
        cout<< " client name: " << cli.get_name() <<endl ;
        cout<< " client address: " << cli.get_address() <<endl ;
        cout<< " client phone: " << cli.get_phone() <<endl ;
        cout<< " client accountID: " << cli.get_client_AccountID() <<endl ;
    }
//overriding withdraw function
    static void menu(int choice) {
        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                caseList();
                break;
            case 3:
                casewithdraw();
                break;
            case 4:
                casedeposit();
                break;
            case 5:
                exit(1);
            default:
                cout << "Invalid choice" << endl;
                cout<< "Please select a choice from [0, 1, 2, 3, 4, 5]:";
        }
        cout << "Please choose one of the following options:" << endl ;
        cout << "1. Create a new Account" << endl ;
        cout << "2. List Clients and accounts" << endl ;
        cout << "3. Withdraw Money" << endl ;
        cout << "4. Deposit Money" << endl ;
        cout << "5. Exit" << endl ;
        cout << "Enter your choice: " ;
    }
};



ostream& operator<< (ostream& out , Client cli){
    out<< " client name: " << cli.get_name() <<endl ;
    out<< " client address: " << cli.get_address() <<endl ;
    out<< " client phone: " << cli.get_phone() <<endl ;
    out<< " client accountID: " << cli.get_client_AccountID() <<endl ;
    return out ;
}
int BankApplication::indexOfBasic = 0 ;
int BankApplication::indexOfSaving = 100;

int main(){

    BankApplication a ;
    int choice ;
    while (cin >> choice){
        BankApplication::menu(choice);
    }
    cout<< " \n";
    for(auto & i : basClients_List){
        cout << i ;
    }


}
