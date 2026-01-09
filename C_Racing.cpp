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
        int n;
        cin >> n;

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
        }

        vector<int> low(n + 1), high(n + 1);
        low[0] = 0;
        high[0] = 0;

        bool possible = true;
        for (int i = 1; i <= n; i++)
        {
            int lo = low[i - 1];
            int hi = high[i - 1];
            int new_lo, new_hi;

            if (arr[i] == 0)
            {
                new_lo = lo;
                new_hi = hi;
            }
            else if (arr[i] == 1)
            {
                new_lo = lo + 1;
                new_hi = hi + 1;
            }
            else
            {
                new_lo = lo;
                new_hi = hi + 1;
            }

            new_lo = max(new_lo, l[i]);
            new_hi = min(new_hi, r[i]);

            if (new_lo > new_hi)
            {
                possible = false;
                break;
            }

            low[i] = new_lo;
            high[i] = new_hi;
        }

        if (!possible)
        {
            cout << -1 << "\n";
            continue;
        }

        vector<int> result = arr;
        vector<int> height(n + 1);
        height[n] = low[n];

        for (int i = n; i >= 1; i--)
        {
            int curr = height[i];
            int prev_lo = low[i - 1];
            int prev_hi = high[i - 1];

            if (arr[i] == 0)
            {
                height[i - 1] = curr;
            }
            else if (arr[i] == 1)
            {
                height[i - 1] = curr - 1;
            }
            else
            {
                if (curr >= prev_lo && curr <= prev_hi)
                {
                    result[i] = 0;
                    height[i - 1] = curr;
                }
                else
                {
                    result[i] = 1;
                    height[i - 1] = curr - 1;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << result[i];
            if (i != n)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
