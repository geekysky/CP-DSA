#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canMakeAllAtLeast(const vector<int> &arr, int mid, int k)
{
    int ops = 0;
    for (int freq : arr)
    {
        if (freq < mid)
        {
            ops += (mid - freq);
        }
    }
    return ops <= k;
}

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

        int min_val = *min_element(arr.begin(), arr.end());
        int low = min_val;
        int high = min_val + k;
        int mini = min_val;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (canMakeAllAtLeast(arr, mid, k))
            {
                mini = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        int used_ops = 0;
        for (auto &x : arr)
        {
            if (x < mini)
            {
                used_ops += (mini - x);
                x = mini;
            }
        }

        int extra = k - used_ops;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mini)
                extra++;
        }

        int ans = mini + (mini - 1) * (n - 1) + extra;

        cout << ans << "\n";
    }
    return 0;
}