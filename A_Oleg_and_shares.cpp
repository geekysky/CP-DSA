#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    int ans=0;

    for(int i=1;i<n;i++){
        if(arr[i]%k != arr[i-1]%k){
            ans=-1;
            break;
        }
    }

    if(ans==-1){
        cout<<ans<<endl;
    }
    else{
        for(int i=1;i<n;i++){
            ans+=(arr[i]-arr[0])/k;
        }

        cout<<ans<<endl;
    }

    return 0;
}