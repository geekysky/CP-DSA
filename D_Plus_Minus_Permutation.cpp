#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (x == y)
        {
            cout << 0 << "\n";
            continue;
        }
        int lcm = (x * y) / __gcd(x, y);

        int multiples = n / lcm;
        int xm = 0, ym = 0;
        xm = n / x;
        ym = n / y;

        int xsum = ((2 * n - (xm - 1)) * xm) / 2;
        int smallestx = n + 1 - xm;
        int remove_sum = (multiples * (2 * smallestx + (multiples - 1))) / 2;
        ym -= multiples;

        // smallest ym values sum
        int ysum = (ym * (ym + 1)) / 2;

        cout << xsum - remove_sum - ysum << "\n";
    }
    return 0;
}