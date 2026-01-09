#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n,c,d;
        cin>>n>>c>>d;
        
        int m=n;
        vector<int> arr(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            mp[arr[i]]++;
        }
        
        vector<int> res;
        for(auto it:mp){
            res.push_back(it.first);
        }

        sort(res.begin(),res.end());
        int push=0;
        int pop=0;
        
        n=res.size();
        int req=(m-n)*c;

        int ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            
            int temp=0;
            if(i!=0)
            temp=(res[i]-res[i-1])-1;

            else
            temp=res[i]-1;

            pop=n-i-1;

            int cost=0;
            push+=temp;

            cost+=(push*d)+(pop*c);

            ans=min(ans,cost);
        }
        
        ans=min(req+ans,m*c + d);
        cout<<ans<<"\n";

    }
    return 0;
}