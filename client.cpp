#include "client.h"

void client::set_name(string n){
    name = n ;
}   
string client::getname(){
    return name; 
}

void client::set_address(string d){
    address = d ;
}

string client::getaddress(){
    return address ;  
}

void client::set_phone(string p){
    phone = p;
} 

string client::get_phone(){
    return phone ; 
}

// void client::setaccount(string A){
//     account = A ; 
// }

// string client::get_account(){
//     return account ;
// }
