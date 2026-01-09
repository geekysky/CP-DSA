#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{   
    // fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = LLONG_MIN;

    for (int i = 0; i <= (n / a); i++)
    {
        for (int j = 0; j <= (n / b); j++)
        {
            int k = n - (i * a + j * b);
            if (k >= 0 && k % c == 0)
            {
                ans = max(ans, i + j + k / c);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}