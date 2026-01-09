#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        if (a == 1 and b == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (k >= max(a, b))
        {
            cout << 1 << endl;
        }
        else if (__gcd(a, b) == 1)
        {
            cout << 2 << endl;
        }
        else
        {
            bool found = false;
            if (a / __gcd(a, b) <= k and b / __gcd(a, b) <= k)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}