#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){

    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);                      \

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        int size=2e5+1;
        vector<int> multiples(size,0),trapped(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
            if(arr[i]<=n)
            multiples[arr[i]]++;
        }

        for(int h=1;h<=n;h++){
            for(int j=h;j<=n;j+=h){
                trapped[j]+=multiples[h];
            }
        }

        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(trapped[i],ans);
        }

        cout<<ans<<"\n";

    }

    return 0;
}