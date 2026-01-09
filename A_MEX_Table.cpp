#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        int ans=max(n,m)+1;
        cout<<ans<<"\n";
    }

    return 0;
}