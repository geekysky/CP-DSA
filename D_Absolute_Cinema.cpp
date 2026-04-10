#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> f[i];
    }

    int S = (f[1] + f[n]) / (n - 1);

    vector<int> a(n + 1);

    a[1] = (f[2] - f[1] + S) / 2;
    a[n] = (S - (f[n] - f[n - 1])) / 2;

    for (int i = 2; i < n; ++i)
    {
        a[i] = (f[i - 1] - 2 * f[i] + f[i + 1]) / 2;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}