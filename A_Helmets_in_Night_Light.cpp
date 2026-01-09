#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }

    return a.first<b.first;
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,p;
        cin>>n>>p;

        int share[n],cost[n];
        for(int i=0;i<n;i++){
            cin>>share[i];
        }

        for(int i=0;i<n;i++){
            cin>>cost[i];
        }

        vector<pair<int,int>> cost_share;

        for(int i=0;i<n;i++){
            cost_share.push_back({cost[i],share[i]});
        }

        sort(cost_share.begin(),cost_share.end());
        
        int all_p=n*p;

        if(cost_share[0].first>p or (cost_share[0].first==p and cost_share[0].second<(n-1))){
        cout<<all_p<<"\n";
        continue;
        }

        int rem_res=n-1;
        int mixed_cost=p;

        for(int i=0;i<n;i++){
            pair<int,int> curr=cost_share[i];

            if(curr.first>=p){
                //same cost bhi hua to aage jaake share karne k baad chief ko hi share karna padega
                mixed_cost+=(rem_res * p);
                break;
            }
            
            if(rem_res>0){
                int share_ability=min(curr.second,rem_res);

                mixed_cost+=(share_ability * curr.first);
                rem_res-=share_ability;

            }
    
        }

        cout<<mixed_cost<<"\n";


    }
    return 0;
}