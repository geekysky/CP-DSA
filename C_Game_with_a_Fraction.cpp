#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p, q;
        cin >> p >> q;

        int d = 3 * p - 2 * q;

        if (p == q)
        {
            cout << "Alice" << endl;
        }
        else if (d >= 0 && d % 2 == 0)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }

    return 0;
}