#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int res=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    res++;
                }
            }

            ans=min(ans,i+res);
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}