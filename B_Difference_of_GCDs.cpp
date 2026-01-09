#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        bool possible = true;
        vector<int> ans(n, -1);
        for (int i = 1; i <= n; i++)
        {
            int smallest = (l % i == 0) ? l : l + (i - (l % i));

            if (smallest > r)
            {
                possible = false;
                break;
            }
            else
            {
                ans[i - 1] = smallest;
            }
        }

        if (possible)
        {
            cout << "YES" << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}