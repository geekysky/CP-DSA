#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        sort(arr,arr+n);
        int suffix[n];
        for(int i=0;i<n;i++){
            if(i==0)
            suffix[i]=arr[n-1-i];

            else{
                suffix[i]=suffix[i-1]+arr[n-1-i];
            }
        }

        //-1 tabhi hoga jab saare chocolte khake sugar consumption match nahi ho payi 
        while(q--){
            int x;
            cin>>x;
            auto it=lower_bound(suffix,suffix+n,x);

            if(it==(suffix+n))
            cout<<-1<<"\n";

            else{
                cout<<it - suffix + 1<<"\n";
            }

        }
    }
    return 0;
}