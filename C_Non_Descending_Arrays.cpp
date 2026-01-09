#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 998244353;

int power(int base, int exp)
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

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        // int invalid_indices = 0;
        vector<int> invalid_indices(n, 0);

        for (int i = 1; i < n; i++)
        {
            if (min(a[i], b[i]) >= a[i - 1] and min(a[i], b[i]) >= b[i - 1])
            {
                continue;
            }
            else if (max(a[i], b[i]) < a[i - 1] and max(a[i], b[i]) < b[i - 1])
            {
                invalid_indices[i]++;
                invalid_indices[i - 1]++;
            }
            else
            {
                invalid_indices[i]++;
            }
        }

        int inv = 0;
        for (int i = 0; i < n; i++)
        {
            if (invalid_indices[i])
            {
                inv++;
            }
        }

        cout << power(2, n - inv) << endl;
    }

    return 0;
}

