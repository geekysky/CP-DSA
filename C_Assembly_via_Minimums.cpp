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

        int len = (n * (n - 1)) / 2;
        vector<int> arr(len);
        map<int, int> mp;
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        if (mp.size() == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << mp.begin()->first << " ";
            }
            cout<<"\n";
            continue;
        }

        vector<int> res;
        for (int i = 1; i <= n - 1; i++)
        {
            int ele = mp.begin()->first;
            mp[ele] -= (n - i);

            if (mp[ele] == 0)
            {
                mp.erase(ele);
            }

            res.push_back(ele);
        }

        res.push_back(1e9);
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout<<"\n";
    }
    return 0;
}