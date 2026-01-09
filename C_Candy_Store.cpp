#include <bits/stdc++.h>
using namespace std;
#define int long long

long long gcd1(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd1(b, a % b);
}

long long lcm1(int a, int b)
{
    return (a / gcd1(a, b)) * b;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }

        int gcd = a[0] * b[0];
        int lcm = b[0];
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            int x = a[i] * b[i];
            int y = b[i];
            gcd = gcd1(x, gcd);
            lcm = lcm1(y, lcm);
            if (gcd % lcm != 0)
            {
                ans++;
                gcd = a[i] * b[i];
                lcm = b[i];
            }
        }
        cout << ans << endl;
    }
}