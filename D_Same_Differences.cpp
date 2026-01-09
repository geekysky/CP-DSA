#include<bits/stdc++.h>
using namespace std;
#define int long long int 
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[(arr[i]-(i+1))]++;
        }
        
        int ans=0;
        for(auto x:mp){
            ans+=((x.second*(x.second-1))/2);
        }

        cout<<ans<<"\n";


    }
    return 0;
}