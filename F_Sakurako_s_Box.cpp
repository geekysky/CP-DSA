#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

// Calculate (a * b) % mod
int modular_multiply(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}

// Calculate a^n % mod using binary exponentiation
int power(int a, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n & 1)
            result = modular_multiply(result, a);
        a = modular_multiply(a, a);
        n >>= 1;
    }
    return result;
}

// Calculate modular multiplicative inverse using Fermat's Little Theorem
int modular_inverse(int n)
{
    return power(n, mod - 2);
}

signed main()
{
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

        vector<int> suffix(n);
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = (suffix[i + 1] + arr[i]) % mod;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = (ans + modular_multiply(arr[i], suffix[i + 1])) % mod;
        }

        int one = modular_multiply(n, n - 1);
        int two = modular_inverse(2);
        int three = modular_multiply(one, two);
        ans = modular_multiply(ans, modular_inverse(three));

        cout << ans << endl;
    }
    return 0;
}