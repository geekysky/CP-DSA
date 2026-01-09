#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> is_prime(n + 2, 1);  // Size adjusted to n + 2 to avoid overflow
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i * i <= n + 1; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n + 1; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    if (n == 1)
    {
        cout << 1 << "\n1\n";
    }
    else if (n == 2)
    {
        cout << 1 << "\n1 1\n";
    }
    else
    {
        cout << 2 << "\n";
        for (int i = 2; i <= n + 1; i++)
        {
            if (is_prime[i])
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 2 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
