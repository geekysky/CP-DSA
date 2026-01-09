#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool is_valid(int n,int mid){
    int valid_nos=(n*n + 1)/2 ;
    int count_ele_lessorequal=0;

    for(int i=1;i<=n;i++){

        if(count_ele_lessorequal>=valid_nos)
        return true;

        count_ele_lessorequal+=min(n,mid/i);
    }

    return count_ele_lessorequal>=valid_nos;

}

signed main(){
    int n;
    cin>>n;

    int lb=1,ub=n*n;
    int ans=ub+1;

    while(lb<=ub){
        int mid=(lb+ub)/2;

        if(is_valid(n,mid)){
            ans=mid;
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
} 