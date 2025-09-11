#include<iostream>
using namespace std;

int Linearsearch(int arr[],int key,int size){
    for(int i =0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
        
    }
    return -1;

}
int main(){
    int size,element;
    cout<<"Enter the size of an array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
cout<<"Enter the elements to search in array: "<<endl;
    cin>>element;
    int result = Linearsearch(arr,element,size);
    if(result != -1){
        cout<<"Key found successfully at "<<result<<" index"<<endl;
    }else{
        cout<<"Key not found !"<<endl;
    }
    return 0;
}