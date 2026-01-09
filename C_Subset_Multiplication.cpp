#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        int gcd = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            gcd = __gcd(arr[i],gcd);
        }

        int x = 1e9;
        bool fnd = false;
        for(int i=0;i<n;i++){
            arr[i]/=gcd;

            if(i>0 and arr[i]<arr[i-1]){
                x=arr[i-1];
            }
        }




    }
    return 0;
}