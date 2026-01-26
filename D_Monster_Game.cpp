#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> strengths(n), monster_blows_req(n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> strengths[i];
            sum += strengths[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> monster_blows_req[i];
        }

        sort(strengths.begin(), strengths.end());

        vector<int> vals;

        // mean
        int mean_floor = sum / n;
        int mean_ceil = (sum + n - 1) / n;
        vals.push_back(mean_floor);
        vals.push_back(mean_ceil);

        // median
        if (n % 2 == 1)
        {
            int m = strengths[n / 2];
            vals.push_back(m);
            vals.push_back(m);
        }
        else
        {
            int a = strengths[n / 2 - 1];
            int b = strengths[n / 2];
            int s = a + b;
            vals.push_back(s / 2);
            vals.push_back((s + 1) / 2);
        }

        // mode
        int mode = strengths[0];
        int best_freq = 1;

        int curr = strengths[0];
        int curr_freq = 1;

        for (int i = 1; i < n; i++)
        {
            if (strengths[i] == curr)
            {
                curr_freq++;
            }
            else
            {
                if (curr_freq > best_freq)
                {
                    best_freq = curr_freq;
                    mode = curr;
                }
                curr = strengths[i];
                curr_freq = 1;
            }
        }
        if (curr_freq > best_freq)
        {
            best_freq = curr_freq;
            mode = curr;
        }

        vals.push_back(mode);

        // mid point
        int mn = strengths[0];
        int mx = strengths[n - 1];
        int s = mn + mx;

        int mid_floor = s / 2;
        int mid_ceil = (s + 1) / 2;

        vals.push_back(mid_floor);
        vals.push_back(mid_ceil);

        vector<int> prefix(n);
        prefix[0] = monster_blows_req[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + monster_blows_req[i];
        }

        int ans = LLONG_MIN;
        for (int i = 0; i < strengths.size(); i++)
        {
            int diff = strengths[i];

            auto it = lower_bound(strengths.begin(), strengths.end(), diff);
            int kills = n - (it - strengths.begin());

            auto it2 = upper_bound(prefix.begin(), prefix.end(), kills);
            int levels = it2 - prefix.begin();

            ans = max(ans, diff * levels);
        }

        for (int i = 0; i < 7; i++)
        {
            int diff = vals[i];

            auto it = lower_bound(strengths.begin(), strengths.end(), diff);
            int kills = n - (it - strengths.begin());

            auto it2 = upper_bound(prefix.begin(), prefix.end(), kills);
            int levels = it2 - prefix.begin();

            ans = max(ans, diff * levels);
        }

        cout << ans << endl;
    }

    return 0;
}
