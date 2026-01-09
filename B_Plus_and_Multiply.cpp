#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (a == 1)
        {
            if ((n - 1) % b == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            continue;
        }
        else
        {
            int val = 1;

            while (val <= n)
            {
                if ((n - val) % b == 0)
                {
                    cout << "Yes" << endl;
                    break;
                }
                if (val > n / a)
                {
                    cout << "No" << endl;
                    break;
                }
                val *= a;
            }
        }
    }
    return 0;
}