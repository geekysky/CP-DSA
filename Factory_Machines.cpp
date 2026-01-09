#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool is_valid(int arr[],int n,int t,int mid){
    int tot_prods_if_all_machines_on_for_x=0;

    for(int i=0;i<n;i++){
        if(tot_prods_if_all_machines_on_for_x >= t){
            return true;
        }
        
        tot_prods_if_all_machines_on_for_x += (mid/arr[i]);
    }

    return tot_prods_if_all_machines_on_for_x >= t;
}

signed main(){
    int n,t;
    cin>>n>>t;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int lo=1;
    int hi=1e18;
    int min_time_x=hi+1;

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(is_valid(arr,n,t,mid)){
            //good now look for better 
            min_time_x=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }

    cout<<min_time_x<<"\n";

    return 0;
}