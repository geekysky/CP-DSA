#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool not_multiple(int mid,int n,int k){
    int non_multiplies=mid- mid/n;

    return non_multiplies>=k;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int lb=1,ub=1e26;
        int ans=ub+1;
        while(lb<=ub){
            int mid=(lb+ub)/2;

            if(not_multiple(mid,n,k)){
                ans=mid;
                ub=mid-1;
            }
            else{
                lb=mid+1;
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}