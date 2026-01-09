#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool possible(int mid,int c,int m,int x){
    if(c<mid){
        return false;
    }
    else if(m<mid){
        return false;
    }
    else{
        int rem=(c-mid)+(m-mid)+x;

        if(rem>=mid)
        return true;

        else
        return false;
    }
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int c,m,x;
        cin>>c>>m>>x;

        int low=1;
        int high=1e18;

        int ans=high+1;

        for(int i=0;i<100;i++){
            int mid=(low+high)/2;

            if(possible(mid,c,m,x)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}