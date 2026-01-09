#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int l, r, x;
            cin >> l >> r >> x;
            arr.push_back({l, r, x});
        }

        sort(arr.begin(), arr.end());

        int ans = k;
        for(int i=0;i<n;i++){
            int l = get<0>(arr[i]);
            int r = get<1>(arr[i]);

            if(ans>=l and ans<=r){
                //i can play this round 
                ans= max(ans,get<2>(arr[i]));
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
