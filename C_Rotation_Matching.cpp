#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n;
    cin>>n;

    vector<int> a(n), b(n);
    vector<pair<int,int>> mp(n+1);
    for(int i=0;i<n+1;i++){
        mp[i].first = -1;
        mp[i].second = -1;
    }

    for(int i=0; i<n; i++){
        cin>>a[i];

        mp[a[i]].first = i;
    }
    for(int i=0; i<n; i++){
        cin>>b[i];

        mp[b[i]].second = i;
    }

    map<int,int> diff;
    for(auto x: mp){
        if(x.first != -1 && x.second != -1){
            if(x.first >= x.second){
                diff[x.first - x.second]++;
            }
            else{
                diff[n - x.second + x.first]++;
            }
        }
    }

    //count the most freuqent difference from diff 
    int ans = LLONG_MIN;
    for(auto x: diff){
        ans = max(ans, x.second);
    }

    cout<<ans<<endl;

    

    return 0;
}