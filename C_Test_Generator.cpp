#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s, m;
        cin >> s >> m;

        if ((s & 1) != (m & 1))
        {
            if (s % 2 == 0 and m % 2 == 1)
            {
                cout << (s + (m - 1)) / m << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (m > s)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << (s + (m - 1)) / m << endl;
        }
    }
    return 0;
}