#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll arr[n];
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        //make rest all values 0 except arr[0]

        for(ll i=1;i<n;i++){
            arr[0]=arr[0]|arr[i];

            arr[i]=0;
        }
        
        ll new_sum=0;
        for(ll i=0;i<n;i++){
            new_sum+=arr[i];
        }

        cout<<min(new_sum,sum)<<"\n";


    }
    return 0;
    
}