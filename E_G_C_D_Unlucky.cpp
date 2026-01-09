#include <bits/stdc++.h>
using namespace std;
#define int long long int

int lcm(int a, int b)
{
    return (a * b / __gcd(a, b));
}
signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> prefix(n), suffix(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prefix[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> suffix[i];
        }

        vector<int> arr(n);
        arr[0] = prefix[0];
        arr[n - 1] = suffix[n - 1];

        for (int i = 1; i < n - 1; i++)
        {
            arr[i] = lcm(prefix[i], suffix[i]);
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        if (prefix[n - 1] != suffix[0])
        {
            cout << "NO" << endl;
            continue;
        }

        // now recheck
        int beg = arr[0], end = arr[n - 1];
        bool pos = true;
        for (int i = 1; i < n; i++)
        {
            beg = __gcd(beg, arr[i]);

            if (beg != prefix[i])
            {
                pos = false;
                break;
            }
        }

        if (pos)
        {
            for (int i = n - 2; i >= 0; i--)
            {
                end = __gcd(end, arr[i]);

                if (end != suffix[i])
                {
                    pos = false;
                    break;
                }
            }

            if (pos)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}