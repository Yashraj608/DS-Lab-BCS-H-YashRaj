#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of Array: "<<endl;
    cin>>size;
    int *arr = new int[size]{0};
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Elements are: "<<endl;
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    } 

    delete[]arr;
    return 0;
}