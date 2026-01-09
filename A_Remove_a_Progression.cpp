#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int ops = (n % 2) ? (n / 2 + 1) : n / 2;
        int rem = n - ops;

        // rem can never be >= ops + 1
        // only even numbers are left
        cout << x * 2 << "\n";
    }
    return 0;
}