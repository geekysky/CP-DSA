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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        priority_queue<int> q;
        for(auto x:mp){
            q.push(x.second);
        }

        while(q.size()>1){
            int lar = q.top();
            q.pop();

            int sec_lar = q.top();
            q.pop();
            
            lar--;
            sec_lar--;

            if(lar>0)
            q.push(lar);

            if(sec_lar>0)
            q.push(sec_lar);
        }

        if(!q.empty())
        cout<<q.top()<<"\n";

        else 
        cout<<0<<"\n";

    }
    return 0;
}