#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll str[n],end[n];
        for(ll i=0;i<n;i++){
            cin>>str[i]>>end[i];
        }
        
        bool bad_pair=false;
        for(ll i=1;i<n;i++){
            if(str[i]>=str[0] and end[i]>=end[0]){
                bad_pair=true;
                break;
            }
        } 

        if(bad_pair)
        cout<<-1<<"\n";

        else
        cout<<str[0]<<"\n";
    }
    return 0;
}