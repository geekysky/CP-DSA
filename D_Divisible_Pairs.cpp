#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        map<pair<int, int>, int> mp;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        mp[{arr[0] % x, arr[0] % y}]++;
        for (int j = 1; j < n; j++)
        {
            int common = mp[{(x - (arr[j] % x)) % x, arr[j] % y}];

            ans += common;
            mp[{arr[j] % x, arr[j] % y}]++;
        }

        cout << ans << "\n";
    }
    return 0;
}