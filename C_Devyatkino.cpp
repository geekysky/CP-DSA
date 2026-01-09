#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool check(int n)
{
    // how many digits at max ? 18...19
    while (n)
    {
        int dig = n % 10;

        if (dig == 7)
        {
            return true;
        }

        n /= 10;
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ans = LLONG_MAX;
        for (int k = 0; k <= 9; k++)
        {
            int num = n - k;
            int mn = 7;
            while (num)
            {
                mn = min(mn, (7 - num % 10 + 10) % 10);
                num /= 10;
            }
            if (mn <= k)
            {
                ans = min(ans, k);
            }
        }

        cout << ans << endl;
    }
    return 0;
}