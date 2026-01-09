#include <bits/stdc++.h>
using namespace std;
#define int long long int 

signed main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, q;
        cin >> n >> q;

        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<long long> k(q);
        for (int i = 0; i < q; i++) {
            cin >> k[i];
        }

        map<int,int> mp;

        for(int i=0;i<n;i++){
            int temp1=i;
            int temp2=n-i-1;

            int result=temp1+temp2 + temp1*temp2;

            mp[result]++;

            //now for points b/w the two poits 
            int between_points=x[i+1]-x[i]-1;
            int segments=(temp1+1)*temp2;

            mp[segments]+=between_points;
        }

        for(int i=0;i<q;i++){
            cout<<mp[k[i]]<<" ";
        }
        cout<<"\n";
        
    }


}