#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int ans = 0;
    if (mp.size() == n)
    {
        cout << -1 << "\n";
        return 0;
    }

    mp.clear();
    int beg = 1, end = -1;
    vector<pair<int, int>> segments;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
        {
            ans++;
            end = i + 1;
            segments.push_back({beg, end});
            mp.clear();
            beg = min(n, end + 1);
        }
    }
    
    //we will extend the last good segment till the end of the array if it is not already till the end
    if (segments.size() > 0 && segments[segments.size() - 1].second != n)
    {
        segments[segments.size() - 1].second = n;
    }
    
    cout << ans << "\n";
    for (auto x : segments)
    {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}