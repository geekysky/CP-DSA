#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(int mid, int n, int m, int k)
{
    // no of blocks in each row of size mid+1
    int whole = m / (mid + 1);
    int rem = m % (mid + 1);
    if (rem == mid)
    {
        rem = 0;
        whole++;
    }
    if (m == mid)
    {
        whole = 1;
        rem = 0;
    }

    int total = whole*mid * n + rem * n;
    return k <= total;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int upper = (k + n - 1) / n;

        int low = 1, high = m, ans = m + 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(mid, n, m, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}