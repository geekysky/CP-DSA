#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> is_prime(1e7 + 1, 1);
    for (int i = 2; i <= 1e7; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 1e7; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    vector<int> prime_sum;
    prime_sum.push_back(0);
    int s = 0;
    for (int i = 2; i <= 1e7; i++)
    {
        if (is_prime[i])
        {
            s += i;
            prime_sum.push_back(s);
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            sum += arr[i];
        }

        sort(arr.begin(), arr.end());

        // n <= 4e5 so first 4e5 primes
        if (sum >= prime_sum[n])
        {
            cout << 0 << endl;
            continue;
        }

        // else keep removing from start so that the largest values result in >= prime_sum[n-removed]
        int rem = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum -= arr[i];
            rem++;

            if (sum >= prime_sum[n - rem])
            {
                break;
            }
        }

        cout << rem << endl;
    }

    return 0;
}