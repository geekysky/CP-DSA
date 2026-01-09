#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = 0, len = 0, strength = 1, mini = INT_MAX;

        for (int i = n - 1; i >= 0; i--)
        {
            len++;
            mini = min(mini, arr[i]);
            if (mini * len >= x)
            {
                ans++;
                len = 0;
                mini = INT_MAX;
            }
        }

        cout << ans << endl;
    }
    return 0;
}