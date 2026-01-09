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

        vector<int> arr(2 * n);
        int s = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            s += arr[i];
        }

        sort(arr.begin(), arr.end());
        int even = 0;
        for (int i = 1; i < n; i++)
        {
            even += arr[i];
        }

        int odd = 0;
        for (int i = n; i < 2 * n - 1; i++)
        {
            odd += arr[i];
        }

        int lst_even = odd + arr[0] + arr[2 * n - 1] - even;

        vector<int> res(2 * n + 1, -1);

        int ctr = 1;
        for (int i = 1; i < n; i++)
        {
            res[ctr] = arr[i];
            ctr += 2;
        }

        // for (auto x : res)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        res[ctr] = lst_even;

        ctr = 2;
        for (int i = n; i < 2 * n - 1; i++)
        {
            res[ctr] = arr[i];
            ctr += 2;
        }
        // for (auto x : res)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        res[0] = arr[0];
        res.back() = arr.back();
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
        }

    return 0;
}