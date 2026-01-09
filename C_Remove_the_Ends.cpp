#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // suffix se positive elements ka sum
        // and prefix se negative elements ka sum
        vector<int> neg_suffix(n, 0), pos_prefix(n, 0);
        neg_suffix[n - 1] = min(0ll, arr[n - 1]);
        pos_prefix[0] = max(0ll, arr[0]);

        for (int i = n - 2; i >= 0; i--)
        {
            neg_suffix[i] = neg_suffix[i + 1] + min(0ll, arr[i]);
        }

        for (int i = 1; i < n; i++)
        {
            pos_prefix[i] = pos_prefix[i - 1] + max(0ll, arr[i]);
        }

        // neg_suffix[i] has negative suffix sum
        int ans = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                ans = max({ans, abs(neg_suffix[i]) + ((i == 0) ? 0 : abs(pos_prefix[i - 1]))});
            }
            else
            {
                ans = max({ans, pos_prefix[i] + ((i == n - 1) ? 0 : abs(neg_suffix[i + 1]))});
            }
        }

        cout << ans << "\n";
    }
    return 0;
}