//Insertion Sort//
#include<iostream>
using namespace std;

void InsertionSort(int arr[], int size){
for(int i =1;i<size;i++){
    int current = arr[i];
    int prev = i-1;
    while (prev >= 0 && arr[prev] > current )
    {
    arr[prev+1] = arr[prev];
    prev --;
    }
    arr[prev +1] = current;
    
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
   cout<<"Enter he elements of array: "<<endl;
   for(int i =0;i<size;i++){
    cin>>arr[i];
   }



   cout<<"Original Array is :"<<endl;
   display(arr,size);
   InsertionSort(arr,size);
   cout<<endl;
   cout<<"After sorting: "<<endl;
   display(arr,size);
    return 0;
}