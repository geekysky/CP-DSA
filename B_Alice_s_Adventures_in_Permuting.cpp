#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, b, c;
        cin >> n >> b >> c;

        int ans;
        if (b == 0)
        {
            if (c < n - 2)
            {
                cout << -1 << endl;
            }
            else if (c >= n)
            {
                // all n
                cout << n << endl;
            }
            else
            {
                cout << n - 1 << endl;
            }
        }
        else if (c >= n)
        {
            cout << n << endl;
        }
        else
        {
            cout << max(0ll, n - (n - 1 - c + b) / b) << endl;
        }
    }
    return 0;
}
