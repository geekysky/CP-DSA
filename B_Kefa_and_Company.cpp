#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n, d;
    cin >> n >> d;
    
    vector<pair<int, int>> money_factor(n);
    for(int i = 0; i < n; i++) {
        cin >> money_factor[i].first >> money_factor[i].second;
    }

    sort(money_factor.begin(),money_factor.end());
    //build prefix sum upon this sorted money order 

    vector<int> friendship_prefix(n);
    friendship_prefix[0]=money_factor[0].second;

    for(int i=1;i<n;i++){
        friendship_prefix[i]=friendship_prefix[i-1]+money_factor[i].second;
    }
    
    int ans=-1;
    for(int i=0;i<n;i++){
        auto it=lower_bound(money_factor.begin(),money_factor.end(),make_pair(money_factor[i].first+d,0ll));
        it--;

        int r=it-money_factor.begin();
        int l=i;

        //sum of frienship factor from l to r 
        if(l==0){
            ans=max(ans,friendship_prefix[r]);
        }
        else{
            ans=max(ans,friendship_prefix[r]-friendship_prefix[l-1]);
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}
