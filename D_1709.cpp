#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

signed main()
{
    // fast input output
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<int, int>> res;

        // sort a
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j + 1 < n; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    res.push_back({1, j + 1});
                }
            }
        }

        // sort b
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j + 1 < n; j++)
            {
                if (b[j] > b[j + 1])
                {
                    swap(b[j], b[j + 1]);
                    res.push_back({2, j + 1});
                }
            }
        }

        // if ai > bi
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                swap(a[i], b[i]);
                res.push_back({3, i + 1});
            }
        }

        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i].first << " " << res[i].second << '\n';
        }
    }

    return 0;
}
