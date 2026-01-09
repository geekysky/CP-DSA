#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxi = 30;
int costs[maxi];
int powers[maxi];

const int sz = 1e6 + 1;
int factorial[sz];
int inverse[sz];

int modular_multiply(int a, int b, int mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

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

void precompute()
{
    powers[0] = 1;
    for (int i = 1; i < maxi; ++i)
    {
        if (LLONG_MAX / 3 < powers[i - 1])
        {
            powers[i] = LLONG_MAX;
        }
        else
        {
            powers[i] = powers[i - 1] * 3;
        }
    }

    costs[0] = 3;

    // 3^(x+1) + x * 3^(x-1)
    for (int i = 1; i < maxi; ++i)
    {
        if (i + 1 >= maxi)
            continue;
        costs[i] = powers[i + 1] + i * powers[i - 1];
    }
}

void f()
{
    int n, k;
    cin >> n >> k;

    vector<int> d(maxi, 0);
    int temp_n = n;
    int max_i = 0;

    for (int i = 0; i < maxi && temp_n > 0; ++i)
    {
        d[i] = temp_n % 3;
        temp_n /= 3;
        if (d[i] > 0)
        {
            max_i = i;
        }
    }

    int min_req = 0;
    int mini = 0;
    for (int i = 0; i <= max_i; ++i)
    {
        min_req += d[i];
        mini += d[i] * costs[i];
    }

    if (min_req > k)
    {
        cout << -1 << endl;
        return;
    }

    int curr = min_req;

    // greedy swap -> 9 becomes 3*3 , 3 becomes 3*1
    // largest power break into it's smaller power * 3
    // difference is larger between larger powers 1,3,....

    for (int i = maxi - 2; i >= 1; --i)
    {
        if (d[i] == 0)
            continue;

        int bestswaps = (k - curr) / 2;
        if (bestswaps == 0)
            break;

        int num_swaps = min(d[i], bestswaps);

        curr += 2 * num_swaps;
        mini -= num_swaps * powers[i - 1];

        d[i] -= num_swaps;
        d[i - 1] += 3 * num_swaps;
    }

    cout << mini << endl;
}

signed main()
{
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        f();
    }

    return 0;
}