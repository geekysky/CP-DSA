#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            mp[arr[i]]++;
        }

        int ans=1;
        for(auto v:mp){
            ans=max(ans,v.second);
        }

        cout<<n-ans<<"\n";

    }
    return 0;
}