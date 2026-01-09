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
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            mp[arr[i]].push_back(i);
        }

        vector<int> ans(n + 1, LLONG_MAX);

        for (auto x : mp)
        {
            vector<int> idx = x.second;

            int beg = -1;
            int mini_length = LLONG_MIN;
            for (int i = 0; i < idx.size(); i++)
            {
                int diff = idx[i] - beg;

                mini_length = max(mini_length, diff);
                beg = idx[i];
            }

            mini_length = max(mini_length, n - idx.back());

            ans[mini_length] = min(ans[mini_length], x.first);
        }

        int min_non = -1;
        int idx = -1;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] != LLONG_MAX and min_non == -1)
            {
                min_non = ans[i];
                idx = i;
                break;
            }
        }

        for (int i = idx; i <= n; i++)
        {
            min_non = min(min_non, ans[i]);
            ans[i] = min_non;
        }

        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == LLONG_MAX)
            {
                ans[i] = -1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}