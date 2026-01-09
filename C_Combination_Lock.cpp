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

        if (n % 2 == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
            {
                cout << i << " ";
            }
            for (int i = 2; i <= n; i += 2)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}