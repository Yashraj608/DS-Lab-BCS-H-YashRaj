//Selection sort//
#include<iostream>
using namespace std;
void SelectionSort(int arr[], int size){
    for(int i =0;i<size -1;i++){
        int smallestIndex = i;
        for(int j =i+1;j<size;j++){
            if(arr[j]< arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
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

cout<<"Original Array is:"<<endl;
display(arr,size);
cout<<endl;
SelectionSort(arr,size);
cout<<"Sorted Array is: "<<endl;
display(arr,size);
    return 0;
}