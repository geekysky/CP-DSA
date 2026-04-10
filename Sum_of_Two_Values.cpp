#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int j = 0; j < n; j++)
    {
        int comp = x - arr[j];

        if (mp[comp].size() != 0)
        {
            cout << mp[comp].back() << " " << j + 1 << endl;
            return 0;
        }

        mp[arr[j]].push_back(j + 1);
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}