#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, m;
        cin >> n >> x >> m;

        int left = -1, right = -1;

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;

            if (left == -1 and right == -1)
            {
                // uninitialized
                if (x >= l and x <= r)
                {
                    // first valid range
                    left = l;
                    right = r;
                }
            }
            else
            {
                // the intersection of the largest and current segment should not be null
                int x1 = max(left, l);
                int x2 = min(right, r);

                if (x1 <= x2)
                {
                    // valid intersection
                    // stretch the segment as far as possible
                    left = min(left, l);
                    right = max(right, r);
                }
            }

            // cout << left << " " << right << endl;
        }

        cout << max(1ll, right - left + 1) << endl;
    }
    return 0;
}