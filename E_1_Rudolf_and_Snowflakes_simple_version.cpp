#include <bits/stdc++.h>
using namespace std;
#define int long long

// power with early stop if it exceeds a limit
int power(int base, int exp, int limit)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            if (__builtin_mul_overflow(result, base, &result) || result > limit)
                return limit + 1;
        }
        if (exp > 1)
        {
            if (__builtin_mul_overflow(base, base, &base) || base > limit)
                return limit + 1;
        }
        exp >>= 1;
    }
    return result;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        bool found = false;

        for (int k = 2; k * k <= n; k++)
        {
            // start with y=3:
            int term = 1LL * k * k; // k^2
            int sum = 1 + k + term; // 1 + k+ k2...

            while (sum <= n)
            {
                if (sum == n)
                {
                    found = true;
                    break;
                }
                term *= k;
                sum += term;
            }
            if (found)
                break;
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}
