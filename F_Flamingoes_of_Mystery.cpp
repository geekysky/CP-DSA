#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sum_of_range(int l,int r){
    int sum;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>sum;

    return sum;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;

    int x=sum_of_range(1,2);
    int y=sum_of_range(2,3);
    int z=sum_of_range(1,3);

    int mid=(x+y-z);
    //cout<<mid<<endl;
    arr.push_back(x-mid);
    arr.push_back(mid);
    arr.push_back(y-mid);

    for(int i=4;i<=n;i++){
        int temp=sum_of_range(i-1,i);
        arr.push_back(temp-arr.back());
    }
    
    cout<<"! ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}