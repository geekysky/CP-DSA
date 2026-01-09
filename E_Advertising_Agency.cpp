#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int nCr(int n, int r, vector<int> &factorial, vector<int> &inverse)
{
    if (r > n)
        return 0;
    return (factorial[n] * inverse[r] % mod * inverse[n - r] % mod) % mod;
}

signed main()
{
    int t;
    cin >> t;

    // Precompute factorials and inverses
    vector<int> factorial(1e6 + 1);
    vector<int> inverse(1e6 + 1);

    factorial[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    inverse[1000000] = power(factorial[1000000], mod - 2);
    for (int i = 999999; i >= 0; i--)
    {
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
    }

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int ans = 1;
        int req = k;

        vector<int> keys;
        for (auto it : mp)
        {
            keys.push_back(it.first);
        }

        sort(keys.begin(), keys.end(), greater<int>());
        for (auto key : keys)
        {
            if (req <= 0)
                break;

            ans = (ans * nCr(mp[key], min(req, mp[key]), factorial, inverse)) % mod;
            req -= min(req, mp[key]);
        }

        cout << ans << "\n";
    }
    return 0;
}