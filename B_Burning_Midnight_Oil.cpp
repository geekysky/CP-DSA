#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(int v,int n,int k){
    //check if 
    int rem=n;
    int val=v;
    while(rem>0 and val>0){
        rem-=val;

        val=val/k;
    }

    if(rem>0){
        return false;
    }
    else{
        return true;
    }

}


signed main(){
    int n,k;
    cin>>n>>k;

    //binary search for the samellest value of v
    int low=1,high=1e18;
    int ans=high+1;

    // PF : FFFFTTTT...

    while(low<=high){
        int mid=(low+high)/2;

        if(checker(mid,n,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<ans<<'\n';

    return 0;

}