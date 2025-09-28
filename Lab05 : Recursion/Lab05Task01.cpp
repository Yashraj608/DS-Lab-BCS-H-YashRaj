#include<iostream>
using namespace std;

int CalculateFactorial(int n ){
    if(n==0 ||n==1){
        return 1;
    }
     return n*CalculateFactorial(n-1);
}
int main(){
int n;
cout<<"Enter the number to find the factorial"<<endl;
cin>>n;

int result = CalculateFactorial(n);
cout<<"Factorial is: "<<result<<" ";
    return 0;
}