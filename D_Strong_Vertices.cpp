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

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            arr[i].first -= x;
            arr[i].second = i + 1;
        }

        sort(arr.begin(), arr.end());
        vector<int> res;
        map<int, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            mp[arr[i].first].push_back(arr[i].second);

            if (mp.size() == 2)
            {
                mp.erase(mp.begin());
            }
        }

        for (auto x : mp)
        {
            for (auto y : x.second)
            {
                res.push_back(y);
            }
        }

        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}