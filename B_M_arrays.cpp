#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= m;
            mp[arr[i]]++;
        }

        int ans = 0;

        // Handle remainder 0
        if (mp[0] > 0)
            ans++;

        // Handle pairs (i, m-i)
        int cnt = m / 2;
        for (int i = 1; i <= cnt; i++)
        {
            if (i != m - i) // Normal pairs
            {
                int count1 = mp[i];
                int count2 = mp[m - i];

                if (count1 > 0 || count2 > 0)
                {
                    ans++; // Add one group for this pair
                    if (count1 != count2)
                    {
                        ans += abs(count1 - count2) - 1;
                    }
                }
            }
            else
            {
                // Special case: i == m-i (only when m is even)
                if (mp[i] > 0)
                    ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
