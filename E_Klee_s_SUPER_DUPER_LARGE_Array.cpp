#include <bits/stdc++.h>
using namespace std;
#define int long long int

int prefixSum(int i, int k)
{
    return i * k + (i * (i - 1)) / 2;
}

// f(i) = |2*S(i) - T|
int fval(int i, int k, int T)
{
    return llabs(2 * prefixSum(i, k) - T);
}

pair<int, int> findMinIndex(int n, int k)
{
    int T = n * k + (n * (n - 1)) / 2;

    long double disc = (2.0L * k - 1.0L) * (2.0L * k - 1.0L) + 4.0L * T;
    long double root = (-(2.0L * k - 1.0L) + sqrt(disc)) / 2.0L;

    int i1 = max(1LL, min(n, (int)floor(root)));
    int i2 = max(1LL, min(n, (int)ceil(root)));

    int val1 = fval(i1, k, T);
    int val2 = fval(i2, k, T);

    if (val1 <= val2)
        return {i1, val1};
    return {i2, val2};
}

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        pair<int, int> result = findMinIndex(n, k);

        cout << result.second << endl;
    }
}
