#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, l, a;
    cin >> n >> l >> a;

    //3 type k breaks hai 
    //first is first customer k aane k pehle 
    //second is between customers 
    //third is after the last customer has left 
    vector<ll> in(n), out(n); // Vectors to store the start and end times

    for(ll i = 0; i < n; i++){
        cin >> in[i];
        cin >> out[i];
    }

    ll start=0,ans=0;

    for(ll i=0;i<n;i++){
        ans+=((in[i]-start)/a);

        //start ko shift karna padega uske out time se 
        start=in[i]+out[i];
    }

    //ab baaki hai last customer jaane k baad kitne breaks le sakte hai 
    //start is pointing to the minute the last customer left --- can he take breaks from here ?
    ans+=(l-start)/a;

    cout<<ans<<"\n";
    return 0;
}
