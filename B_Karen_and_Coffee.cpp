#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n,k,q;
    cin>>n>>k>>q;
    
    int size=200000;
    vector<int> delta(size+1,0);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        
        delta[l] += 1;
        delta[r + 1] -= 1;
    }
    vector<int> coverage(size + 1, 0);
    coverage[0] = delta[0];
    for (int i = 1; i <= size+1; i++) {
        coverage[i] = coverage[i - 1] + delta[i];
    }

    for(int i=1;i<=size+1;i++){
        if(coverage[i]<k){
            //no use of this in final answer 
            coverage[i]=0;
        }
        else{
            coverage[i]=1;
        }
    }
    vector<int> good_prefix(size+1);
    for(int i=1;i<=size+1;i++){
        good_prefix[i]=good_prefix[i-1]+coverage[i];
    }
    
    // for(int i=89;i<=101;i++){
    //     cout<<coverage[i]<<" ";
    // }

    // cout<<endl;

    // for(int i=89;i<=101;i++){
    //     cout<<good_prefix[i]<<" ";
    // }
    
    // cout<<endl;

    int ans=0;
    for(int queries=1;queries<=q;queries++){
        int l,r;
        cin>>l>>r;

        cout<<good_prefix[r]-good_prefix[l-1]<<"\n";
    }

    return 0;
}