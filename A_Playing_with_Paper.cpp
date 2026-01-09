#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll a,b;
    cin>>a>>b;

    ll ans=0;
    while(a!=1 or b!=1){
        ans+=(a/b);

        a%=b;
        
        if(b>a)
        swap(a,b);
    }
    
    cout<<ans<<"\n";
    return 0;
}