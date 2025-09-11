// Bubble sort//
#include<iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    int n =size;
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void display(int arr[], int size){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<size;i++){
     cin>>arr[i];
    }

    cout<<"Before sorting: "<<endl;
    display(arr,size);
    BubbleSort(arr,size);
    cout<<endl;
    cout<<"After sorthing: "<<endl;
    display(arr,size);
    return 0;
}