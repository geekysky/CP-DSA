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

        vector<int> dp(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + i; j <= n; j += i)
            {
                if (arr[j - 1] > arr[i - 1])
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int ans = *max_element(dp.begin() + 1, dp.end());

        cout << ans << endl;
    }
    return 0;
}