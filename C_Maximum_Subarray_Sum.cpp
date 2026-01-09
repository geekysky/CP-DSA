#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int mx = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            mx = max(mx + v[i], v[i]);
            res = max(res, mx);
        }
        else
        {
            mx = 0;
        }
    }
    if (res > k)
    {
        cout << "NO" << endl;
    }
    else if (res == k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                v[i] = -1e18;
            }
        }
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        int zer = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zer = i;
                break;
            }
        }
        if (zer == -1)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        int pref = 0;
        int psum = 0;
        int ssum = 0;
        for (int i = zer - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                break;
            }
            else
            {
                psum += v[i];
                pref = max(psum, pref);
            }
        }

        int suff = 0;
        for (int i = zer + 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                break;
            }
            else
            {
                ssum += v[i];
                suff = max(ssum, suff);
            }
        }
        v[zer] = k - pref - suff;
        // DEBUG(pref);
        // DEBUG(suff);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && i != zer)
            {
                v[i] = -1e18;
            }
        }

        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}