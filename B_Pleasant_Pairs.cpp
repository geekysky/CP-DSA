#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        vector<int> index(2*n+1,-1);
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            index[a] = i;
        }
        
        for(int sum=3;sum<2*n;sum++){
            for(int i=1;i*i<=sum;i++){
                if(sum%i==0 and i*i!=sum and index[i]!=-1 and index[sum/i]!=-1 and index[i]+index[sum/i]==sum){
                    ans++;
                }
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}