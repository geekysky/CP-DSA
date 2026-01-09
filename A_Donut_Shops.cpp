#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;

        if(a==c){
            cout<<-1<<" "<<b<<"\n";
        }
        else if(a>c){
            cout<<-1<<" "<<b<<"\n";
        }
        else{
            // c > a
            int var=(a*b > c) ? b : -1 ;

            cout<<1<<" "<<var<<"\n";
        }
    }
    return 0;
}