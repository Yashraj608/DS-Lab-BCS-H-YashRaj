//Insertion Sort//
#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size- 1;
    while(start <= end){
        int mid = start +(end -start)/2;
          if(arr[mid]==key){
            return mid;
          }
          if(arr[mid]<key){
            start = mid +1;
          }else{
            end = mid-1;
          }
    }
    return -1;
}

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
   cout<<endl;
   cout<<"Enter the number you want to search in array"<<endl;
   int key;
   cin>>key;
   int result = binarySearch(arr,size,key);
   if(result){
    cout<<"Key Found"<<endl;
   }else{
    cout<<"Key not found"<<endl;
   }

    return 0;
}
