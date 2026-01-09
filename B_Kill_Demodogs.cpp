#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
const int b = 2022;

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
    
        int ans=((((n*(n+1))%mod)*(4*n-1))%mod*337)%mod;

        cout<<ans<<'\n';
    }
    return 0;
}
