#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;

        if(b%a==0)
        cout<<b*(b/a)<<"\n";

        else 
        cout<<(a*b)/__gcd(a,b)<<"\n";
    }
    return 0;
}