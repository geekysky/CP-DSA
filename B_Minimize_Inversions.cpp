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

        vector<pair<int, int>> perms(n);
        for (int i = 0; i < n; i++)
        {
            cin >> perms[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> perms[i].second;
        }

        sort(perms.begin(), perms.end());

        for (int i = 0; i < n; i++)
        {
            cout << perms[i].first << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << perms[i].second << " ";
        }
        cout << "\n";
    }
    return 0;
}