#include<iostream>
using namespace std;

int SumTail(int n , int Total=0){
    if(n==0){
        return Total;
    }
   return SumTail(n-1,Total+n);
}

int SumNonTail(int n){
    if(n==0){
        return 0;
    }
    return n +SumNonTail(n-1);
}

int main(){
int n;
cout<<"Enter the value of n: "<<endl;
cin>>n;
int total= 0;
int result1 = SumTail(n,total);
cout<<"Result of Sum Tail is: "<<result1<<endl;
int result2 = SumNonTail(n);
cout<<"Result of Non Tail sum: "<<result2<<endl;

    return 0;
}