#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int x = arr[i];
        int y = arr[i] - (i + 1);

        mp[y] += x;
    }

    int ans = LLONG_MIN;
    for (auto it : mp)
    {
        ans = max(ans, it.second);
    }

    cout << ans << endl;

    return 0;
}