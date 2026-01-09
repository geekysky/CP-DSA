#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        if(b>=a){
            cout<<b<<"\n";
        }
        else if(c<=d){
            //sleep not possible 
            cout<<-1<<"\n";
        }
        else{
            ll time_for_every_alarm=c-d;
            ll no_of_alarms_other_than_b=((a-b)+(time_for_every_alarm-1))/(time_for_every_alarm);

            ll ans=no_of_alarms_other_than_b * c + b;

            cout<<ans<<"\n";
            
            
        }
    }
    return 0;
}