#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool possible(int mid,vector<int> &arr,int k){
    int n=arr.size();
    int ops=0;
    for(int i=n/2;i<n;i++){
        ops+=(mid-arr[i]);

        if(ops>k){
            return false;
        }
    }

    return ops<=k;
}

signed main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());
    int low=arr[n/2];
    int high=1e18;
    
    int ans=low;
    for(int i=0;i<100;i++){
        int mid=(low+high)/2;

        if(possible(mid,arr,k)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    cout<<ans<<"\n";

    return 0;
}