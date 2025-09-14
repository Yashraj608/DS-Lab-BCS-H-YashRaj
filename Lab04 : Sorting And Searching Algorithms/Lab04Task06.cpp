//comb sort is the advance version of bubble sort//
//bubble sort compares and swaps with the adjacent element while comb sort compares with the gap>1//
#include<iostream>
using namespace std;

void CombSort(int arr[], int size, int &comparison, int&swaps){
    int gap = size;
    bool swapped = true;
    comparison = 0,swaps = 0;
    while(gap >1 ||swapped){
        gap = int(gap/1.3);
        if( gap <1){
            gap = 1;
        }
        swapped = false;
        for(int i =0;i+gap < size;i++){
            comparison ++;
            if(arr[i]>arr[i+gap]){
                swap(arr[i],arr[i+gap]);
                swapped = true;
                swaps++;
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
    int *arr = new int[size];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Orginal Array: "<<endl;
    display(arr, size);
    cout<<endl;
    int Totalcomparison = 0, swaps = 0;
    CombSort(arr, size,Totalcomparison,swaps);
      cout<<"Array After Sorting: "<<endl;
    display(arr, size);
    cout<<"Total Comparisons: "<<Totalcomparison<<endl;
    cout<<"Total Swaps: "<<swaps<<endl;


    delete[]arr;

    return 0;
}
