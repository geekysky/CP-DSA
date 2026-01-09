#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            sum+=arr[i];
        }

        //let's only solve the left side of the tree as the right tree at same depth is just -(s')
        int ans=sum;
        vector<int> cpy=arr;
        for(int depth=1;depth<=n-1;depth++){
            //depth no elements are removed 
            vector<int> next;
            int s_dash=0;
            for(int i=1;i<cpy.size();i++){
                next.push_back(cpy[i]-cpy[i-1]);

                s_dash+=(cpy[i]-cpy[i-1]);
            }

            ans=max({ans,s_dash,-1ll*s_dash});
            cpy=next;

        }

        cout<<ans<<endl;

    }
    return 0;
}