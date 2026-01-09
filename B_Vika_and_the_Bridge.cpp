#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(arr[i]) == m.end())
            {
                vector<int> s;
                s.push_back(i + 1);
                m[arr[i]] = s;
            }
            else
            {
                m[arr[i]].push_back(i + 1);
            }
        }

        vector<multiset<int, greater<int>>> mp;
        for (auto x : m)
        {
            vector<int> v = x.second;
            multiset<int, greater<int>> s;

            for (int i = 0; i < v.size(); i++)
            {
                if (i == 0)
                {
                    s.insert(v[i] - 1);
                }
                else
                {
                    s.insert(v[i] - v[i - 1] - 1);
                }
            }

            s.insert(n - v[v.size() - 1]);
            mp.push_back(s);
        }

        int mini = LLONG_MAX;
        if (mp.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < mp.size(); i++)
        {
            multiset<int, greater<int>> curr = mp[i];

            // Get the largest element
            int val = *curr.begin();

            // Remove one occurrence of this value
            curr.erase(curr.begin());

            // Calculate new value and insert it
            int newVal = (val % 2) ? (val - 1) / 2 : val / 2;
            curr.insert(newVal);

            // Find the new maximum after modification
            if (!curr.empty())
            {
                mini = min(mini, *curr.begin());
            }

            // for (auto x : curr)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
        }

        // cout<<endl;
        cout << mini << endl;
    }
    return 0;
}