#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> factorial(1e6 + 1), inverse(1e6 + 1);
factorial[0] = 1;
for (int i = 1; i <= 1e6; i++) {
    factorial[i] = ((factorial[i - 1] % mod) * (i % mod)) % mod;
}

inverse[1e6] = power(factorial[1e6], mod - 2);
for (int i = 1e6 - 1; i >= 0; i--) {
    inverse[i] = ((i + 1) % mod * inverse[i + 1] % mod) % mod;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> p(n + 1), used(n + 1), taken(n + 1);

        for (int i = 1; i <= n; i++)
        {
            if ((i | x) == x && !used[i])
            {
                int j = x ^ i;
                if (j >= 1 && j <= n && !used[j])
                {
                    p[i] = j;
                    p[j] = i;
                    used[i] = used[j] = 1;
                    taken[i] = taken[j] = 1;
                }
            }
        }

        vector<int> left, vals;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
                left.push_back(i);
            if (!taken[i])
                vals.push_back(i);
        }

        for (int i = 0; i < left.size(); i++)
        {
            p[left[i]] = vals[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}
