//Interpolation Search//
//This is alternate of the binary search and used for the uniformly distribued data//
#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int size , int key){

   int start = 0;
   int end = size - 1;
   while(start <= end && key >= arr[start] && key <= arr[end]){
       
        if(arr[start] == arr[end]){
            if(arr[start] == key)
                return start;
            else
                return -1;
        }

         int pos = start +((key - arr[start]) * (end - start))/ (arr[end] - arr[start]);

         if(arr[pos] == key){
            return pos;
         }
         if(arr[pos] <key){
            start = pos+1;
         }else{
            end = pos -1;
         }

   }
   return -1;

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
    int *arr = new int[size];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key you want to find: "<<endl;
    cin>>key;
      

    cout<<"Original Array: "<<endl;
    display(arr,size);
    int result = interpolationSearch(arr,size,key);
    cout<<endl;
    if(result == -1){
        cout<<"Key Not Found ! "<<endl;
    }
    else{
        cout<<"Key found at: "<<result<<" index"<<endl;
    }

    return 0;
}