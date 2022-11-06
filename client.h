#include "BankApplication.h"
#include "BankApplication.cpp"

class client : public BankApplication{
    private:
        string name ;
        string address ;
        string phone ;
        //string account ; 
    public:
        void set_name(string n);
        string getname();
        void set_address(string d);
        string getaddress();
        void set_phone(string p);
        string get_phone();
        // void setaccount(string A);
        // string get_account();
};
