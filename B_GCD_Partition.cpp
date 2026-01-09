#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        int pref_sum=0;
        int max_ans=0;

        for(int i=0;i<n-1;i++){
            pref_sum+=arr[i];

            max_ans=max(max_ans,__gcd(pref_sum,sum-pref_sum));
        }

        cout<<max_ans<<'\n';


    }

    return 0;
}