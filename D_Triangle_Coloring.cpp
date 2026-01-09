#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 998244353;

int power(int a, int b)
{
    int result = 1;
    while (b)
    {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int nCr(int n, int r)
{
}

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute factorial and inverse factorial
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

    int ans = ((factorial[n / 3] * inverse[n / 6]) % mod * inverse[n / 6]) % mod;
    for (int i = 0; i < n - 2; i += 3)
    {
        map<int, int> mp;
        mp[arr[i]]++;
        mp[arr[i + 1]]++;
        mp[arr[i + 2]]++;

        int smallest = mp.begin()->second;
        ans = (ans * smallest) % mod;
    }

    cout << ans << "\n";

    return 0;
}