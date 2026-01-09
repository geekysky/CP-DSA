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

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        int c = 0;
        for (int i = 0; i <= n; i++)
        {
            if (mp[i] == 1)
                c++;
            if (c == 2 || mp[i] == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}