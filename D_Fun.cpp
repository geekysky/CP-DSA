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

        int ans = 0;
        for (int i = 1; i <= x; i++)
        {
            int bmax = min(x - i, n / i);

            // nested loop se b max tak iterate kar lenge
            for (int j = 1; j <= bmax; ++j)
            {
                int cmax = min((x - i - j), ((n - i * j) / (i + j)));
                ans += max(0ll, cmax);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}