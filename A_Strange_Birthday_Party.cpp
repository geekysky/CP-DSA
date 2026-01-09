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

        vector<int> k(n), c(m), bought(m, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> k[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> c[i];
        }

        sort(k.rbegin(), k.rend());
        int cost = 0;

        for (int i = 0; i < n; i++)
        {
            int gift_index = k[i] - 1;

            auto it = lower_bound(bought.begin(), bought.begin() + gift_index + 1, 0);

            if (it == bought.begin() + gift_index + 1)
            {
                cost += c[gift_index];
            }
            else
            {
                int idx = it - bought.begin();
                cost += c[idx];
                bought[idx] = 1;
            }
        }

        cout << cost << "\n";
    }

    return 0;
}
