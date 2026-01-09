#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

signed main()
{
    string s;
    cin >> s;

    vector<int> groups;
    int len = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            len++;
        }
        else if (s[i] == 'b')
        {
            if (len != 0)
            {
                groups.push_back(len);
                len = 0;
            }
        }
    }

    if (len != 0)
    {
        groups.push_back(len);
    }

    int ans = 1;
    for (int i = 0; i < groups.size(); i++)
    {
        ans = (ans * (groups[i] + 1)) % mod;
    }

    cout << ans - 1 << "\n";
    
    return 0;
}
