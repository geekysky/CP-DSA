#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            mp[x]++;
        }

        int ans=0;
        for(auto v:mp){
            if(v.second>1){
                ans+=(v.second/2);
            }
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}