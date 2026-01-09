#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool is_valid_predicate(int arr[], int n, int k, int mid) {
    int tot_subarrays = 1;
    int sub_sum = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) {
            return false;  // If a single element is greater than mid, it's not possible
        }

        if(sub_sum + arr[i] > mid) {
            tot_subarrays++;
            sub_sum = arr[i];
        } else {
            sub_sum += arr[i];
        }
    }

    return tot_subarrays <= k;
}

signed main(){
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    int hi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hi+=arr[i];
    }

    int lo=0;
    int ans=hi+1;
    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(is_valid_predicate(arr,n,k,mid)){
            ans=mid;
            //look for better on the left 
            hi=mid-1;

        }
        else{
            lo=mid+1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}