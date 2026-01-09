#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

bool canAchieve(ld R, const vector<int> &a, const vector<int> &b, int k)
{
    int n = a.size();
    vector<ld> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = (ld)a[i] - R * (ld)b[i];
    }
    sort(diff.begin(), diff.end(), greater<ld>());
    ld sum = 0;
    for (int i = 0; i < k; i++)
        sum += diff[i];

    return sum >= 0.0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        ld err = 0.000000001;
        ld low = 0.0, high = 1e9;
        ld ans = high + err;

        while (abs(low - high) > 1e-9)
        {
            ld mid = (low + high) / 2.0;
            if (canAchieve(mid, a, b, k))
            {
                ans = mid;
                low = mid;
            }
            else
                high = mid;
        }

        cout << fixed << setprecision(6) << ans << endl;
    }

    return 0;
}
