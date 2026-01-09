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

        vector<pair<int, int>> a(n), b(n), c(n);

        // Input and store values with indices
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].first;
            b[i].second = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i].first;
            c[i].second = i;
        }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        int maxSum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (a[i].second != b[j].second &&
                        b[j].second != c[k].second &&
                        c[k].second != a[i].second)
                    {
                        maxSum = max(maxSum,
                                     a[i].first + b[j].first + c[k].first);
                    }
                }
            }
        }

        cout << maxSum << "\n";
    }
    return 0;
}