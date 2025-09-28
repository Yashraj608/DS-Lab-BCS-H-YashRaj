#include<iostream>
using namespace std;

void FunctionA(int n );
void FunctionB(int n );
void FunctionA(int n){
     if(n<=0){
        return;
    }
    cout<<"A: "<<n<<endl;
    FunctionB(n-1);
}

void FunctionB(int n ){
    if(n<=0){
        return;
    }
    cout<<"B is: "<<n<<endl;
    FunctionA(n-1);
}

void printNumber(int n){
    cout<<"Num : "<<n<<endl;;
    if(n==1){
        return;
    }
    printNumber(n-1);
}
int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    printNumber(n);


    FunctionA(n);
    FunctionB(n);
    return 0;
}