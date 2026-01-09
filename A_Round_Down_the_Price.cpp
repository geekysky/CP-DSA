#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll find_nearest_power(ll num){
    //1e9 tak hi hai num ki value 
    if(num<10)
    return 1;

    //starting from 1e0 
    ll power=1;

    while(power*10 <= num){
        power*=10;
    }

    return power;
}

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll m;
        cin>>m;

        ll ans=m-find_nearest_power(m);

        cout<<ans<<"\n";


    }
    return 0;
}