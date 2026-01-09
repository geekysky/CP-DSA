#include<bits/stdc++.h>
using namespace std;
#define int long long int 
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,l,r;
        cin>>n>>l>>r;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);

        int ans=0;

        for(int i=n-1;i>=0;i--){
            int rem_l=l-arr[i];
            int rem_r=r-arr[i];

            if(rem_r<=0)
            continue;

            auto one=lower_bound(arr,arr+n,rem_l);
            auto two=upper_bound(arr,arr+n,rem_r);
            two--;

            ans+=(two-arr)-(one-arr) + 1;

            if(i>=(one-arr) and i<=(two-arr)){
                ans--;
            }
        }
        
        //double pairs have been counted 
        cout<<ans/2<<"\n";


    }
    return 0;
}