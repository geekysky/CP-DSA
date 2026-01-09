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

        string s;
        cin >> s;

        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
        }

        if (ones == n)
        {
            cout << 1 << "\n";
            continue;
        }
        else if (ones == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        int groups = 0;
        if (s[0] != '0')
        {
            groups++;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                groups++;
            }
        }

        cout << groups << "\n";
    }
    return 0;
}