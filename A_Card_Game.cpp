#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;

        bool f_p = false;
        for (int i = 0; i < k1; i++)
        {
            int ele;
            cin >> ele;

            if (ele == n)
            {
                f_p = true;
            }
        }

        for (int i = 0; i < k2; i++)
        {
            int ele;
            cin >> ele;

            if (ele == n)
            {
                f_p = false;
            }
        }

        if (f_p)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}