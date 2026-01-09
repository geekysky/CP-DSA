#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> factorial(1e6 + 1), inverse(1e6 + 1);
    factorial[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        factorial[i] = ((factorial[i - 1] % mod) * (i % mod)) % mod;
    }

    inverse[1e6] = power(factorial[1e6], mod - 2);
    for (int i = 1e6 - 1; i >= 0; i--)
    {
        inverse[i] = ((i + 1) % mod * inverse[i + 1] % mod) % mod;
    }
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        for (int l = 0; l < n; l++)
        {
            int prev = -1;

            for (int r = l; r < n; r++)
            {
                int curr = arr[r];
                int req = prev + 1;
                int half = (curr - 1) / 2;

                if (req <= half)
                {
                    prev = req;
                }
                else if (req <= curr)
                {
                    // ignore
                    prev = curr;
                }
                else
                {
                    break;
                }

                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
