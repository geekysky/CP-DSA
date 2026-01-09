#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    vector<int> spf(1e6 + 1);
    for (int i = 1; i <= 1e6; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i <= 1e6; i++)
    {
        if (spf[i] == i)
        {
            // it is a prime no
            for (int j = i * i; j <= 1e6; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<int, int> primes;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 1)
            {
                int x = arr[i];

                while (x != 1)
                {
                    int p = spf[x];
                    int cnt = 0;
                    while (x % p == 0)
                    {
                        x /= p;
                        cnt++;
                    }

                    primes[p] += cnt;
                }
            }
        }

        bool flag = true;
        for (auto it : primes)
        {
            if (it.second % n != 0)
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}