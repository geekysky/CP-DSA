#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n,k,m;
    cin>>n>>k>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> mod(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mod[i]=arr[i]%m;

        mp[mod[i]]++;
    }

    int max_cnt=-1;
    int mod_val;
    for(auto it:mp){
        if(it.second>max_cnt){
        max_cnt=max(max_cnt,it.second);
        mod_val=it.first;
        }
    }

    if(max_cnt<k){
        cout<<"No"<<"\n";
    }
    else{
        cout<<"Yes"<<"\n";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt<k){
                if(mod[i]==mod_val){
                    cout<<arr[i]<<" ";
                    cnt++;
                }
            }
        }
        cout<<"\n";
    }
    

    return 0;
}