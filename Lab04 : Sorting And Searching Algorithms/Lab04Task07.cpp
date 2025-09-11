//Redix sort//
#include<iostream>
using namespace std;

void shellSort(int arr[], int size){
    int n = size;
    for(int gap = size/2;gap>0;gap = gap/2){
        for(int j = gap;j<size;j++){
            for(int i = j-gap;i>=0;i = i-gap){
                if(arr[i+gap] >= arr[i]){
                    break;
                }
                else{
                    swap(arr[i+gap],arr[i]);
                }
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

shellSort(arr,size);
display(arr,size);
    
    return 0;
}