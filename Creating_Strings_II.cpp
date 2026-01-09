#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

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

signed main()
{
    string s;
    cin >> s;

    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
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

    int num = factorial[n];
    for (auto it : mp)
    {
        num = ((num % mod) * (inverse[it.second] % mod)) % mod;
    }

    cout << num << "\n";

    return 0;
}