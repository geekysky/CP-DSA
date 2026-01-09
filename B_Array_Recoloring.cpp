#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.first > b.first;
    }
};

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n), mark(n, 0);

        multiset<pair<int, int>, cmp> ms;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            ms.insert({arr[i], i});
        }

        vector<int> temp = arr;

        int cnt = 0, ans = 0;
        sort(arr.rbegin(), arr.rend());

        if (k == n)
        {
            for (int i = 0; i < n; i++)
            {
                cnt += arr[i];
            }

            cout << cnt << "\n";
        }
        else if (k > 1)
        {
            for (int i = 0; i < k + 1; i++)
            {
                ans += arr[i];
            }
            cout << ans << "\n";
        }
        else
        {
            int val = temp[0] + temp.back();
            for (int i = 1; i < n - 1; i++)
            {
                val = max({val, temp[0] + temp[i], temp.back() + temp[i]});
            }
            cout << val << "\n";
        }
    }

    return 0;
}