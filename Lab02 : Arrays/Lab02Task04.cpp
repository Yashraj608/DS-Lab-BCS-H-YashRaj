#include<iostream>
using namespace std;
int* resizeMonth(int* oldarr, int newsize, int oldsize){
    if(newsize == oldsize){
        return oldarr;
    }
        int* newarr = new int[newsize];

        int limit = (oldsize<newsize) ? oldsize : newsize;
        for(int i =0;i<limit;i++){
            newarr[i] = oldarr[i];
        }

        delete[]oldarr;
        return newarr;
    
}
int main(){
int n;
cout<<"Enter the number of months"<<endl;
cin>>n;
int *arr = new int[n];
cout<<"Enter the elements of months"<<endl;
for(int i =0;i<n;i++){
 cin>>arr[i];
}

string answer;
cout<<"Do you want to resize the month: "<<endl;
cin>>answer;
if(answer == "YES"|| answer == "yes"){
    int newsize;
    cout<<"Enter the new size of months: "<<endl;
    cin>>newsize;
    arr = resizeMonth(arr,newsize,n);
    cout<<"Enter the elements of new month: "<<endl;
    for(int i =n ;i<newsize;i++){
        cin>>arr[i];
    }
    cout<<"Elements of months are: "<<endl;
    for(int i =0;i<newsize;i++){
        cout<<arr[i]<<" ";
    }
}
else{
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
    return 0;
}