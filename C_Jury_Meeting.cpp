#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 998244353;

int power(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int modular_multiply(int a, int b, int mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

signed main()
{
    vector<int> factorial(2e5 + 1), inverse(2e5 + 1);
    factorial[0] = 1;
    for (int i = 1; i <= 2e5; i++)
    {
        factorial[i] = ((factorial[i - 1] % mod) * (i % mod)) % mod;
    }

    inverse[2e5] = power(factorial[2e5], mod - 2, mod);
    for (int i = 2e5 - 1; i >= 0; i--)
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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            mp[arr[i]]++;
        }

        sort(arr.begin(), arr.end());

        // more than one occurence of largest element so no clash...as enumeration occurs
        // simultaneously
        if (mp.rbegin()->second > 1)
        {
            cout << factorial[n] << endl;
            continue;
        }


        // find the second largest key in the map
        auto it = mp.rbegin();
        it++;
        int c = it->second;
        
        if(it->first+1 < mp.rbegin()->first)
        {
            cout << 0 << endl;
            continue;
        }
        
        int one = factorial[n];
        int two = modular_multiply(factorial[n], power(c + 1, mod - 2, mod), mod);

        cout << (one - two + mod) % mod << endl;
    }
    return 0;
}