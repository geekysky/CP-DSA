#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        map<int,int> mp;
        vector<int> cost;
        int total_ans=0;
        for(int i=0;i<k;i++){
            int b,c;
            cin>>b>>c;

            mp[b]+=c;
            total_ans+=c;
        }

        if(mp.size()<=n){
            //all shelves can be used up 
            cout<<total_ans<<"\n";
        }
        else{
            int max_cost=0;
            for(auto it:mp){
                cost.push_back(it.second);
            }
            sort(cost.rbegin(),cost.rend());
            for(int i=0;i<n;i++){
                //pick top n values 
                max_cost+=cost[i];
            }

            cout<<max_cost<<"\n";
        }
    }
    return 0;
}