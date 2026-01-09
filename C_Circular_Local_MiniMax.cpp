#include <bits/stdc++.h>
using namespace std;
#define int long long int

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

        sort(arr.begin(), arr.end());
        if (n % 2)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<int> res(n);
        // res[0] = arr[0];
        // res[n - 1] = arr[n - 1];

        int idx = 0;
        int ctr = 0;
        bool pos = true;
        while (idx < n / 2)
        {
            int left = arr[idx];
            int right = arr[n - 1 - idx];

            // cout << left << " " << right << endl;
            if (right == res[ctr - 1])
            {
                pos = false;
                break;
            }

            res[ctr] = right;
            res[ctr + 1] = left;

            idx++;
            ctr += 2;
        }

        if (!pos)
        {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int left = ((i - 1) == -1 ? res[n - 1] : res[i - 1]);
            int right = ((i + 1) == n ? res[0] : res[i + 1]);

            if ((res[i] > left and res[i] > right) or (res[i] < left and res[i] < right))
            {
                continue;
            }
            else
            {
                pos = false;
                break;
            }
        }

        // for (auto x : res)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        if (!pos)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}