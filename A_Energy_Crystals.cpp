#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        int beg = 0;
        int ctr = -1;

        if (x == 1)
        {
            cout << 3 << endl;
            continue;
        }

        while (beg < x)
        {
            beg = 2 * beg + 1;

            ctr += 2;
        }

        cout << ctr + 2 << endl;
    }
    return 0;
}
