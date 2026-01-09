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
        vector<int> freq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            mp[x]++;
        }

        for (auto ele : mp)
        {
            freq.push_back(ele.second);
        }

        sort(freq.rbegin(), freq.rend());

        int curr_pick = LLONG_MAX;
        int ans = 0;
        for (auto type : freq)
        {
            curr_pick = min(type, curr_pick - 1);

            if (curr_pick <= 0)
            {
                // no more can be picked
                break;
            }

            ans += curr_pick;
        }

        cout << ans << "\n";
    }
    return 0;
}