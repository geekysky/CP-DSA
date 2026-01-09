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
        vector<int> order;
        map<int, deque<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // let's remove consecutive duplicates and have only distinct consecutive values
        order.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                order.push_back(arr[i]);
            }
        }
        if (order.size() == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]].push_back(i);
        }

        // 1 -> 1,6,7
        vector<int> processed(order.size(), -1);
        int ans = 0;
        while (!mp.empty())
        {
            auto it = mp.rbegin();

            int idx = (it->second).front();
            (it->second).pop_front();
            if ((it->second).empty())
            {
                // erase this element
                mp.erase(it->first);
            }

            if (idx == 0)
            {
                // check only for the right
                if (processed[1] == -1)
                {
                    // new clone
                    ans++;
                }
                processed[0] = 0;
            }
            else if (idx == order.size() - 1)
            {
                // check only for the left
                if (processed[order.size() - 2] == -1)
                {
                    // new clone
                    ans++;
                }
                processed[order.size() - 1] = 0;
            }
            else
            {
                if (processed[idx + 1] == -1 and processed[idx - 1] == -1)
                {
                    // new clone
                    ans++;
                }
                processed[idx] = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}