#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    sort(arr,arr+n);
    
    if(sum%2==0)
    cout<<sum<<"\n";

    else{
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            if((sum-arr[i])%2 == 0){
                cout<<sum-arr[i]<<"\n";
                break;
            }
            else{
                sum-=arr[i];
            }
        }
    }

    }
    return 0;
}