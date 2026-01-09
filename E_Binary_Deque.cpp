#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        vector<int> arr(n), pref_sum(n);
        int sum = 0;

        // Calculating array sum and prefix sum
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];

            if (i != 0)
            {
                pref_sum[i] = pref_sum[i - 1] + arr[i];
            }
            else
            {
                pref_sum[i] = arr[i];
            }
        }

        // If total sum of array is less than s, output -1
        if (sum < s)
        {
            cout << -1 << "\n";
            continue;
        }

        int ans = 0;
        int max_distance = 0;

        for (int i = 0; i < n; i++)
        {
            auto it = pref_sum.end();

            if (arr[i] == 0)
            {
                it = upper_bound(pref_sum.begin() + i, pref_sum.end(), pref_sum[i] + s);
            }
            else if (arr[i] == 1)
            {
                it = upper_bound(pref_sum.begin() + i, pref_sum.end(), pref_sum[i] + s - 1);
            }

            int dist = it - (pref_sum.begin() + i);

            if (dist > max_distance)
            {
                max_distance = dist;
                ans = n - dist;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
