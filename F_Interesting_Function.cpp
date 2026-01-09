#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int l,r;
        cin>>l>>r;
        
        int ans = 0;
        while(l || r) {
            ans += r-l;
            l /= 10;
            r /= 10;
        }
        
        cout << ans << "\n";
    }
    return 0;
}