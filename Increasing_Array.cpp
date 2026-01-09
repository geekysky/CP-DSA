#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int prev=arr[0];
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    int moves=0;
    for(int i=1;i<n;i++){
        if(arr[i]<prev){
            moves+=(prev-arr[i]);
            arr[i]=prev;
        }

        prev=arr[i];
    }

    cout<<moves<<endl;
    return 0;
}