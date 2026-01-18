#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.begin()+k);

        sort(arr.begin()+k,arr.end(),greater<int>());

        for(auto val:arr){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}