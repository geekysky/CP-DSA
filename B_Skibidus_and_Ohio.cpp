#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n=s.size();
        int last_processed=-1;
        int ans=0;

        vector<pair<int,int>> process;
        int temp=1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                temp++;
            }
            else{
                process.push_back({temp,i+1});
                temp=1;
            }
        }
        process.push_back({temp,n});

        if(process.size()==1){
            cout<<1<<"\n";
        }
        else{
            int idx=-1;
            for(int i=process.size()-1;i>=0;i--){
                if(process[i].first>1){
                    idx=process[i].second;
                    break;
                }
            }

            if(idx==-1){
                cout<<n<<"\n";
            }
            else{
                cout<<1<<"\n";
            }
        }

    }
    return 0;
}