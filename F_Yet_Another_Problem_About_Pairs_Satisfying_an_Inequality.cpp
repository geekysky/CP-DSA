#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        vector<int> res;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            if(i+1>arr[i]){
                res.push_back(i+1);
            }
        }

        int ans=0;
        for(auto x:res){
            auto it=lower_bound(res.begin(),res.end(),arr[x-1]);
            ans+=(it-res.begin());
        }

        cout<<ans<<"\n";

    }

    return 0;
}