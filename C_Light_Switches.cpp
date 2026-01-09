#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int maxi = arr.back();

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int inc = (maxi - arr[i]) / (2 * k);

            arr[i] += inc * (2 * k);
        }

        // now all end points are at diff < 2k
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
            mp[arr[i] + k]--;
            mp[arr[i] + (2 * k)]++;
            mp[arr[i] + (3 * k)]--;
        }

        int on_cnt = 0;
        int ans = -1;
        for (auto x : mp)
        {
            on_cnt += x.second;

            if (on_cnt == n)
            {
                ans = x.first;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
