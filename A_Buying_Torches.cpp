#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll x, y, k;
        cin>>x>>y>>k;
        
        // the value x-2 is added because to ensure ceil values wrt x-1 division 
        //so that it gets rounded off to it's next integer 
        //for second case it's giving incorrect ans when not rounded off 
        
        ll ans = (((y+1)*k - 1 + (x-2))/(x-1));
        ans+=k;
        cout<<ans<<"\n";
    }

    return 0;
}
