#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        string s;
        cin>>s;
        
        ll odd_dig=0,cnt=0;
        string ans="";
        for(ll i=0;i<n;i++){
            if((s[i]-'0')%2!=0){
            odd_dig++;

            if(cnt<2){
                ans+=s[i];
                cnt++;
            }
            }
        }

        if(odd_dig<2)
        cout<<-1<<"\n";

        else{
            //starting se 2 odd uthake daal do 
            cout<<ans<<"\n";
        }
    }
    return 0;
}