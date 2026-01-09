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

        vector<int> c;
        c.push_back(1);
        for (int i = 0; i < n - 1; i++)
        {
            int ele;
            cin >> ele;

            c.push_back(ele);
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(c.begin(), c.end());
        sort(b.begin(), b.end());

        if (b.back() == 1)
        {
            cout << n << endl;
            continue;
        }

        int ans = 0;
        int a_last = n - 1;
        int b_last = n - 1;
        int b_front = 0;

        while (a_last >= 0 and (b_last - b_front >= 0))
        {
            if (c[a_last] >= b[b_last])
            {
                // remove element from the front of b
                ans++;
                a_last--;
                b_front++;
            }
            else
            {
                // strictly samller
                a_last--;
                b_last--;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}