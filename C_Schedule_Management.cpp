#include <bits/stdc++.h>
using namespace std;
#define int long long int

int solve_one(int n, int m, vector<int> &tasks)
{
    vector<int> pref(n + 1, 0);
    for (int x : tasks)
        pref[x]++;

    auto canDo = [&](long long T)
    {
        long long overflow = 0, totalCap = 0;
        for (int i = 1; i <= n; i++)
        {
            // preferred handled on i
            long long used = min<long long>(pref[i], T);
            overflow += max(0LL, (long long)pref[i] - T);
            // leftover time on i for unpreferred:
            totalCap += (T - used) / 2;
        }
        return totalCap >= overflow;
    };

    long long lo = 0, hi = 2LL * m, ans = hi;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (canDo(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return (int)ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> tasks(m);
        for (int i = 0; i < m; i++)
            cin >> tasks[i];

        // trivial
        if (m == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << solve_one(n, m, tasks) << "\n";
    }
}
