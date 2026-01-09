#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=upper_bound(arr,arr+n,x-arr[i]);
            int ele=it-arr;

            if(*it > arr[i]){
                //arr[i] is included itself - so it has to be removed 
                ele--;
            }
            ans+=ele;
        }

        cout<<ans<<"\n";

    }
    return 0;
}