#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first+a.second>b.first+b.second;
}
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>> arr(n);
        for(auto &i:arr){
            cin>>i.first;
        }
        for(auto &i:arr){
            cin>>i.second;
        }

        sort(arr.begin(),arr.end(),cmp);
        int a=0,b=0;

        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=(arr[i].first-1);
            }else{
                b+=(arr[i].second-1);
            }
        }

        cout<<a-b<<"\n";

    }
    return 0;
}