#include<iostream>
using namespace std;

class BankAccount{
    double balance;
public:
BankAccount(){
    balance = 0.0;
}
BankAccount(double amount){
    balance = amount;
}
BankAccount(const BankAccount& other){
    balance = other.balance;
}

double withdraw(double amount){
    if(amount <= balance){
        balance -= amount;
    }else{
        cout<<"Insufficient Balance"<<endl;
    }
      return balance;
}

double getbalance(){
    return balance;
}
};
int main(){

    BankAccount account1;
    cout<<"Account 1 balance is: "<<account1.getbalance()<<endl;

    BankAccount account2(1000);
    cout<<"Balance of Account 2 is: "<<account2.getbalance()<<endl;

    BankAccount account3(account2);  //Copy constructor usage//
    cout<<"Balance of Account 3 is: "<<account3.getbalance()<<endl;

    account3.withdraw(200);
    cout<<"Balance of Account 3 after deducting : "<<account3.getbalance();



    return 0;
}