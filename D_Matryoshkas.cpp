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

        map<int, int> mp;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        sort(arr.begin(), arr.end());

        int ans = mp[arr[0]];

        if (mp.size() == 1)
        {
            cout << ans << endl;
            continue;
        }

        auto it = mp.begin();
        it++;

        while (it != mp.end())
        {
            if (it->first - 1 != prev(it)->first)
            {
                ans += it->second;
            }
            else
            {
                ans += max(it->second - prev(it)->second, 0ll);
            }
            it++;
        }

        cout << ans << endl;
    }
    return 0;
}