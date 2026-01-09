#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pair<int, int>> hurdles;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;

            hurdles.push_back({l, r});
        }
        vector<pair<int, int>> powerups;
        for (int i = 0; i < m; i++)
        {
            int x, v;
            cin >> x >> v;

            powerups.push_back({x, v});
        }

        sort(powerups.begin(), powerups.end(), cmp);
        multiset<int,greater<int>> ms;

        int i = 0, j = 0;
        int cnt = 0;
        int x = 1;
        bool possible = true;
        while (i < n and j < m)
        {
            if (powerups[j].first < hurdles[i].first)
            {
                // we have encountered a powerup
                ms.insert(powerups[j].second);
                j++;
            }
            else if (powerups[j].first > hurdles[i].first)
            {
                // we have encountered a hurdle
                int req_len = (hurdles[i].second - hurdles[i].first + 2);
                while (x < req_len and !ms.empty())
                {
                    x += (*ms.begin());
                    ms.erase(ms.find(*ms.begin()));
                    cnt++;
                }

                if (x < req_len)
                {
                    // ms got empty but required length could not be achieved
                    possible = false;
                    break;
                }

                i++;
            }
        }

        // could be that powerups got finished but there are remaining hurdles
        // check till last hurdle if we can cross it as well...
        while (i < n)
        {
            int req_len = (hurdles[i].second - hurdles[i].first + 2);
            while (x < req_len and !ms.empty())
            {
                x += (*ms.begin());
                ms.erase(ms.find(*ms.begin()));
                cnt++;
            }

            if (x < req_len)
            {
                // ms got empty but required length could not be achieved
                possible = false;
                break;
            }

            i++;
        }
        if(!possible)
        cout<<-1<<"\n";

        else
        cout<<cnt<<"\n";

    }

    return 0;
}