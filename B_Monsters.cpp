#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }

    return a.first>b.first;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<pair<int,int>> health_ind;
        for(int i=0;i<n;i++){
            if(arr[i]%k!=0){
                arr[i]%=k;
            }
            else{
                arr[i]=k;
            }
        }

        for(int i=0;i<n;i++){
            health_ind.push_back({arr[i],(i+1)});
        }

        sort(health_ind.begin(),health_ind.end(),cmp);

        for(auto p:health_ind){
            cout<<p.second<<" ";
        }
        cout<<"\n";
        

    }
    return 0;
}