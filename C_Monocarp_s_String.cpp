#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<int> fwd_eq_idx;
        vector<int> bwd_eq_idx(n+2);
        int a = 0,b = 0;

        fwd_eq_idx.push_back(0);
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
            else{
                b++;
            }

            fwd_eq_idx.push_back(a-b);
        }

        fwd_eq_idx.push_back(a-b);

        a=0,b=0;
        
        bwd_eq_idx[n+1]=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                a++;
            }
            else{
                b++;
            }

            bwd_eq_idx[i+1]=(a-b);
        }

        bwd_eq_idx[0]=(a-b);

        int min_rem = LLONG_MAX;
        // for(auto x:fwd_eq_idx){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:bwd_eq_idx){
        //     cout<<x<<" ";
        // }
        // cout<<endl;


        map<int,vector<int>> complimentary;
        for(int i=0;i<n+2;i++){
            complimentary[bwd_eq_idx[i]].push_back(i);
        }

        for(int i=0;i<n+2;i++){
            int req= -1ll * fwd_eq_idx[i];

            if(complimentary[req].size()!=0){
                //if it exists
                auto it = upper_bound(complimentary[req].begin(),complimentary[req].end(),i);

                if(it!=complimentary[req].end()){
                    min_rem=min(min_rem,*it-i-1);
                }
            }
        }

        cout<<(min_rem==n?-1:min_rem)<<endl;

        

    }
    return 0;
}