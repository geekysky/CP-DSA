#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    if (n <= 2)
    {
        if (n == 2 && s[0] == s[1])
        {
            s[1] = (s[0] == 'z' ? 'a' : s[0] + 1);
        }
        cout << s << "\n";
        return 0;
    }

    vector<pair<int, int>> runs;
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            if (i - 1 > l)
                runs.emplace_back(l, i - 1);
            l = i;
        }
    }
    if (n - 1 > l)
        runs.emplace_back(l, n - 1);

    for (auto x : runs)
    {
        int p = x.first;
        int q = x.second;
        for (int i = p + 1; i <= q; i += 2)
        {
            char left = s[i - 1];
            char right = (i + 1 < n ? s[i + 1] : 0);
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c != left && c != right)
                {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";
    return 0;
}
