#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll x,y;
    cin>>x>>y;

    ll col1[5]={0};
    ll col2[5]={0};

    for(ll i=1;i<=x;i++){
        col1[(i%5)]++;
    }

    //similarly for values till y
    for(ll i=1;i<=y;i++){
        col2[(i%5)]++;
    }

    ll ans=0;
    ans+=(1ll * (col1[0]*col2[0]));
    ans+=(1ll * (col1[1]*col2[4]));
    ans+=(1ll * (col1[2]*col2[3]));
    ans+=(1ll * (col1[3]*col2[2]));
    ans+=(1ll * (col1[4]*col2[1]));

    cout<<ans<<"\n";

    return 0;
}