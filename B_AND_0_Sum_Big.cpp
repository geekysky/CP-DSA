#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

int modular_exp(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << modular_exp(n, k) << "\n";
    }
    return 0;
}