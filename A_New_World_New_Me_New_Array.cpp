#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,k,p;
        cin>>n>>k>>p;

        if(k<(n*(-p)) or k>(n*p)){
            cout<<-1<<"\n";
            continue;
        }

        k=abs(k);

        int ans=k/p;
        if(k%p!=0){
            ans++;
        }

        cout<<ans<<"\n";
    }
    return 0;
}