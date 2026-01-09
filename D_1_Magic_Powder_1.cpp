#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(vector<int> a,vector<int> b,vector<int> cookies,int mid,int n,int k){
    int req=0;

    for(int i=0;i<n;i++){
        if(cookies[i]<mid){
            int extra=(mid*a[i])-b[i];
            if(req+extra >k){
                return false;
            }
            req+=extra;
        }
    }

    return req<=k;
}

signed main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> a(n),b(n),cookies(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){
        cookies[i]=b[i]/a[i];
    }

    int low=0;
    int high=2e9;
    int ans=high+1;

    while(low<=high){
        int mid=(low+high)/2;

        if(checker(a,b,cookies,mid,n,k)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}