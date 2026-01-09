#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            mp[arr[i]]++;
        }

        if(n==1){
        cout<<0<<"\n";
        continue;
        }

        int lar_freq=INT_MIN;

        for(auto p:mp){
            if(p.second > lar_freq)
            lar_freq=p.second;
        }

        if(lar_freq==1)
        cout<<1<<"\n";

        else{
            int rem=mp.size()-1;

            int one=min(rem+1,lar_freq-1);
            int two=min(rem,lar_freq);

            cout<<max(one,two)<<"\n";
        }

        

        


    }
    return 0;
}