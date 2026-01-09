#include <bits/stdc++.h>
using namespace std;
#define int long long int

int sumOfAbsoluteDifferences(vector<int> a)
{
    sort(a.begin(), a.end());
    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        ans += a[i] * (2ll * i - n + 1);
    }
    return ans;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    map<int, pair<vector<int>, vector<int>>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            (mp[arr[i][j]].first).push_back(i + 1);
            (mp[arr[i][j]].second).push_back(j + 1);
        }
    }

    int ans = 0;
    for (auto it : mp)
    {
        // for particular color it's x and y coordinates
        vector<int> x = (it.second).first;
        vector<int> y = (it.second).second;

        ans += (sumOfAbsoluteDifferences(x));
        ans += (sumOfAbsoluteDifferences(y));
    }

    cout << ans << endl;

    return 0;
}