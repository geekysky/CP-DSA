#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==1)
        cout<<2<<"\n";

        else if(n==2 || n==3 )
        cout<<1<<"\n";
        
        else 
        cout<<(n+2)/3<<"\n";


    }
    return 0;
}