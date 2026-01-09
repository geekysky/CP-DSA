#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,m;
    cin>>n>>m;

    map<int,int> one,two;
    vector<int> a(n),b(m);

    for(int i=0;i<n;i++){
        cin>>a[i];
        one[a[i]]++;
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
        two[b[i]]++;
    }

    int ans=0;
    for(auto it:one){
        if(two[it.first]!=0){
            ans+=(it.second*two[it.first]);
        }
    }

    cout<<ans<<"\n";

    return 0;
}