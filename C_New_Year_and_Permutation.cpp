#include <bits/stdc++.h>
using namespace std;
#define int long long int

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
    int n, m;
    cin >> n >> m;
    int mod = m;

    vector<int> factorial(n + 1), inverse(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial[i] = modular_multiply(factorial[i - 1], i, mod);
    }

    // Calculate modular inverses if needed

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int good = n - i + 1;
        int rem = n - i;

        int contribution = modular_multiply(modular_multiply(modular_multiply(good, good, mod), factorial[rem], mod), factorial[i], mod);
        ans = (ans + contribution) % mod;
    }

    cout << ans << endl;
    return 0;
}