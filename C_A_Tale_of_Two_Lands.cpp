#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n;
    cin>>n;
    vector<int> arr;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        arr.push_back(abs(x));
    }

    sort(arr.begin(),arr.end());
    bool one_present=false;
    if(arr[0]==1){
        one_present=true;
    }
    //valid are us element + 1 se leke 2*ele tak jitne bhi elements hai vo 
    int ans=0;
    for(int i=0;i<n;i++){
        auto u=upper_bound(arr.begin(),arr.end(),2*arr[i]);
        u--;
        
        //cout<<*itself<<" "<<*u<<endl;

        //cout<<u-arr.begin()-i<<endl;

        ans+=(u-arr.begin()-i);
    }

    cout<<ans<<"\n";

    return 0;
}