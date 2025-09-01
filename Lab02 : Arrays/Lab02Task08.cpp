#include<iostream>
using namespace std;
int main(){
  int  n; //days(rows)
  int m;//m different times(cols)
  cout<<"Enter the number of days:"<<endl;
  cin>> n;
  cout<<"Enter the times : "<<endl;
  cin>>m;
  int** arr = new int*[n];
  for(int i =0;i<n;i++){
    arr[i] = new int[m];
  }
  cout<<"Enter the temperatures: "<<endl;
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
        cin>>arr[i][j];
    }
  }

  cout<<"Temperatures for "<<n<<" days: at different times: "<<endl;
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }


  int* avg = new int[n];
  for(int i =0;i<n;i++){
    int sum=0;
    for(int j =0;j<m;j++){
      sum += arr[i][j];
    }
    avg[i] = sum/m;
  }
  cout<<"Average temperature is: "<<avg<<endl;

  int hottestDay=0;
  int coldestDay =0;
  for(int i =0;i<n;i++){
    if(avg[i] > avg[hottestDay]){
        hottestDay = i;
    }
    if(avg[coldestDay]<avg[i]){
        coldestDay = i;
  }
  }
  cout<<"Hottest day is : "<<hottestDay<<endl;
  cout<<"Coldest Day is: "<<coldestDay<<endl;

  for(int i =0;i<n;i++){
    delete[]arr[i];
  }
  delete[]arr;
return 0;
}
