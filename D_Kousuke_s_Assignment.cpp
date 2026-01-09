#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

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

        mp[0].push_back(0);
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            p += arr[i];

            mp[p].push_back(i + 1);
        }

        vector<pair<int, int>> segments;
        for (auto it : mp)
        {
            vector<int> temp = it.second;

            if (temp.size() > 1)
            {
                for (int i = 1; i < temp.size(); i++)
                {
                    int l = temp[i - 1] + 1;
                    int r = temp[i];

                    segments.push_back({l, r});
                }
            }
        }

        int ans = 0;
        sort(segments.begin(), segments.end(), cmp);

        int l = -1, r = -1;
        for (int i = 0; i < segments.size(); i++)
        {
            int s = segments[i].first;
            int e = segments[i].second;

            if (s > l and s > r and e>l and e>r)
            {
                // non overlapping
                ans++;
                l = s;
                r = e;
            }
        }
        
        // for(auto x:segments){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        cout << ans << endl;
    }
    return 0;
}