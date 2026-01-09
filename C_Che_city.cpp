#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,r;
    cin>>n>>r;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=0;
    int len=0;
    int left=0;
    for(int right=0;right<n;right++){
        len=arr[right]-arr[left];

        while(len>r){
            ans+=(n-right);

            left++;
            len=arr[right]-arr[left];
        }
    }

    cout<<ans<<"\n";


    return 0;
}