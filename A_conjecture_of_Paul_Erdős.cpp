#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e7 + 1;
signed main()
{
    int t;
    cin >> t;

    vector<int> ans(N, 0), prefix(N, 0);
    vector<int> is_prime(N, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

    for (int x = 1; x * x <= N; x++)
    {
        for (int y = 1; y * y * y * y <= N; y++)
        {
            // check if x2 + y4 is a prime
            int tmp = pow(x, 2) + pow(y, 4);
            if (is_prime[tmp])
            {
                ans[tmp] = 1;
            }
        }
    }

    // create prefix
    for (int i = 2; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + ans[i];
    }

    while (t--)
    {
        int n;
        cin >> n;

        cout << prefix[n] << "\n";
    }
    return 0;
}