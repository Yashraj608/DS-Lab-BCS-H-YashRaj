#include<iostream>
using namespace std;
int ackermann(int m , int n ){
    if(m==0){
        return n +1;
    }

    if(m>0 && n==0){
        return ackermann(m-1,1);
    }

    if(m>0 && n>0){
        return ackermann(m-1,ackermann(m,n-1));
    }
    return -1;
}
int main(){
    int n,m;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    cout<<"Enter the value of m :"<<endl;
    cin>>m;

    int result = ackermann(m,n);
    cout<<"Result is : "<<result<<endl;
    return 0;
}