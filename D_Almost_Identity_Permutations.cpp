#include <bits/stdc++.h>
using namespace std;
#define int long long int

int combination(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n - r)
        r = n - r; // nCr = nC(n-r), use smaller r for efficiency

    int result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

signed main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int d[16];
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= 15; i++)
    {
        d[i] = (i - 1) * ((d[i - 1] + d[i - 2]));
    }
    for (int i = n - k; i <= n - 2; i++)
    {

        ans += (d[n-i] * combination(n, i));
    }

    cout << ans+1 << "\n";

    return 0;
}