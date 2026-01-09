#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int b;
        cin >> b;

        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }

        bool possible = false;
        vector<int> curr(n);
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            curr[i] = b - a[i];
        }

        bool sorted = true;

        temp.push_back(min(curr[0], a[0]));
        for (int i = 1; i < n; i++)
        {
            if (min(curr[i], a[i]) >= temp.back())
            {
                temp.push_back(min(curr[i], a[i]));
            }
            else if (max(curr[i], a[i]) >= temp.back())
            {
                temp.push_back(max(curr[i], a[i]));
            }
            else
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}