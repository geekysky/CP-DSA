#include<bits/stdc++.h>
using namespace std;
#define int long long int

int ceil_div(int num,int den){
    return ((num+(den-1))/den);
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin()+1,arr.end());
        auto it=upper_bound(arr.begin()+1,arr.end(),arr[0]);

        if(it!=arr.end()){
            int start=it-arr.begin();
            int ans=0;
            for(int i=start;i<n;i++){
                int moves=ceil_div(arr[i]-arr[0],2);

                arr[0]+=moves;
                arr[i]-=moves;
            }

            cout<<arr[0]<<"\n";
        }
        else{
            cout<<arr[0]<<"\n";
        }


    }
    return 0;
}