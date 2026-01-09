#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        mp[ele]++;
    }

    int doubles = 0, quads = 0;

    for (auto x : mp)
    {
        doubles += x.second / 2;

        quads += x.second / 4;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char ch;
        int x;

        cin >> ch >> x;
        // cout << ch << " " << x << endl;

        if (ch == '-')
        {
            quads -= mp[x] / 4;
            doubles -= mp[x] / 2;
            mp[x]--;

            quads += mp[x] / 4;
            doubles += mp[x] / 2;
        }
        else
        {
            quads -= mp[x] / 4;
            doubles -= mp[x] / 2;
            mp[x]++;

            quads += mp[x] / 4;
            doubles += mp[x] / 2;
        }

        bool rect = false, sq = false;
        if (quads >= 1)
        {
            rect = true;
            quads--;
            doubles -= 2;
        }

        if (quads >= 1 or doubles >= 2)
        {
            sq = true;
        }

        if (rect and sq)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        if (rect)
        {
            quads++;
            doubles += 2;
        }
    }

    return 0;
}