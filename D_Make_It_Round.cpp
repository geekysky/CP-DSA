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

        int ans = 1;
        int val = 10;
        int ctr = 0;
        while (true)
        {
            int ops_req = val / __gcd(val, n);

            if (ops_req <= m)
            {
                ctr++;
                ans = ops_req;

                val *= 10;
            }
            else
            {
                break;
            }
        }

        // cout<<ans<<endl;
        cout << (m / ans) * (n * ans) << endl;
        // cout<<endl;
    }
    return 0;
}