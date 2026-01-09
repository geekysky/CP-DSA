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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] % k != 0)
            {
                mp[k - (arr[i] % k)]++;
            }
        }

        if (mp.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int x = 0;
        int ans = 0;
        while (!mp.empty())
        {
            auto it = mp.begin();

            if (it->first > x)
            {
                // use type 2 operation
                ans += (it->first - x);
                x = it->first;
            }

            // now use type 1 operation
            if (it->second > 1)
            {
                // shift to new key
                int new_key = it->first + k;
                mp[new_key] = it->second - 1;
            }
            ans++;
            x++;

            mp.erase(it->first);
        }

        cout << ans << endl;
    }
    return 0;
}