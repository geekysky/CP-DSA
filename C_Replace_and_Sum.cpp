#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> ans, bwd_maxi_a(n);

        // forward pass
        // for (int i = 0; i < n; i++)
        // {
        //     if (i == 0 or i == n - 1)
        //     {
        //         fwd_maxi_a[i] = max(a[i], b[i]);
        //     }
        //     else
        //     {
        //         fwd_maxi_a[i] = max(a[i], a[i + 1], b[i]);
        //     }
        // }

        // backward pass
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = a[i];
            int b_val = b[i];

            if (i == n - 1)
            {
                bwd_maxi_a[i] = max(curr, b_val);
            }
            else
            {
                bwd_maxi_a[i] = max({bwd_maxi_a[i + 1], curr, b_val});
            }
        }

        vector<int> prefix(n);
        prefix[0] = bwd_maxi_a[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + bwd_maxi_a[i];
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            if (l == 0)
            {
                ans.push_back(prefix[r]);
            }
            else
            {
                ans.push_back(prefix[r] - prefix[l - 1]);
            }
        }

        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}