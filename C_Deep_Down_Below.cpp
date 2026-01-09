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

        vector<vector<int>> monsters;
        vector<pair<int, int>> powers;
        for (int i = 0; i < n; i++)
        {
            int sz;
            cin >> sz;

            vector<int> arr(sz);
            for (int j = 0; j < sz; j++)
            {
                cin >> arr[j];

                arr[j] = arr[j] - j + 1;
            }

            sort(arr.begin(), arr.end());
            powers.push_back({arr.back(), sz});
        }

        sort(powers.begin(), powers.end());

        // for (auto x : powers)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }

        int ans = powers[0].first;
        int totalMonsterstillnow = powers[0].second;

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, powers[i].first - totalMonsterstillnow);

            totalMonsterstillnow += powers[i].second;
        }

        cout << ans << endl;
    }
    return 0;
}