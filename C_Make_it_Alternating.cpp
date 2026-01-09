#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 998244353;

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
        string s;
        cin >> s;

        int ans = 0;
        int temp = 1;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                temp++;
            }
            else
            {
                if (temp >= 2)
                {
                    ans += (temp - 1);
                }

                temp = 1;
            }
        }
        if (temp >= 2)
        {
            ans += (temp - 1);
        }

        // backward answer and forward answer is same as we are counting group size -1 where group size >=2
        temp = 1;
        int val = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                temp++;
            }
            else
            {
                if (temp >= 2)
                {
                    val = (temp % mod * val % mod) % mod;
                }

                temp = 1;
            }
        }
        if (temp >= 2)
        {
            val = (temp % mod * val % mod) % mod;
        }
        
        val=(val%mod * factorial[ans]%mod)%mod;
        if (ans == 0)
        {
            cout << ans << " " << 1 << endl;
        }
        else
        {
            cout << ans << " " << val << endl;
        }
    }
    return 0;
}