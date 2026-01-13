#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> factorial(1e6 + 1), inverse(1e6 + 1);
int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main()
{
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
    return 0;
}