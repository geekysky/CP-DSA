#include<bits/stdc++.h>
using namespace std;
#define int long long int 

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[k];
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        
        int ans=0;
        int after_ones=0;
        int ones=0;

        sort(arr,arr+k);
        for(int i=0;i<k-1;i++){
            if(arr[i]!=1){
                after_ones+=arr[i];
                ans+=(arr[i]-1);
            }
            else{
                ones++;
            }
        }

        ans+=after_ones;
        ans+=ones;

        cout<<ans<<"\n";
        
    }
    return 0;
}