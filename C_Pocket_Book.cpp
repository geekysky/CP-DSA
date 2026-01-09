#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

signed main()
{
    int n, m;
    cin >> n >> m;

    map<int, map<char, int>> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            mp[j][s[j]]++;
        }
    }

    int ans = 1;
    for (int i = 0; i < m; i++)
    {
        int cnt = mp[i].size();
        ans = (ans * cnt) % mod;
    }

    cout << ans << endl;

    return 0;
}