#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> mp;

        if (n < 3)
        {
            cout << n * 3 << endl;
            continue;
        }

        while (n > 0)
        {
            int p = 1;
            int cnt = 0;
            while (p * 3 <= n)
            {
                p *= 3;
                cnt++;
            }

            int q = n / p;
            mp[cnt] += q;

            n -= q * p;
        }

        int val = 0;

        for (auto x : mp)
        {
            int exp = x.first;
            int q = x.second;

            int term1 = 1;
            for (int i = 0; i < exp + 1; i++)
                term1 *= 3;

            int term2 = 0;
            if (exp > 0)
            {
                int pow3 = 1;
                for (int i = 0; i < exp - 1; i++)
                    pow3 *= 3;
                term2 = exp * pow3;
            }

            val += q * (term1 + term2);
        }

        cout << val << endl;
    }

    return 0;
}
