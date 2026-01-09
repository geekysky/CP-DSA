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

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }

        for (int i = 0; i < n; i++)
        {
            y[i] = y[i] - x[i];
        }

        sort(y.begin(), y.end());
        int ans = 0, s = 0, e = n - 1;

        while (s < e)
        {
            if (y[s] + y[e] >= 0)
            {
                ans++;
                e--;
                s++;
            }
            else
            {
                // the y[s] < y[e]
                // we can't take any y[e] to make the sum positive
                // skip the y[s] and move to the next one
                s++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}