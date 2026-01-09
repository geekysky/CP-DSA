#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n,m;
    cin>>n>>m;

    int arr[n],b[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    sort(arr,arr+n);

    int ans=0;
    for(int i=0;i<m;i++){
        auto it=upper_bound(arr,arr+n,b[i]);

        cout<<it-arr<<" ";
    }

    cout<<"\n";

    
    return 0;
}