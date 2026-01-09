#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> pos(m);
        for (int i = 0; i < m; i++)
        {
            cin >> pos[i];
        }

        vector<int> david(q);
        for (int i = 0; i < q; i++)
        {
            cin >> david[i];
        }
        
        sort(pos.begin(),pos.end());
        for (int i = 0; i < q; i++)
        {
            int d = david[i];

            auto it = lower_bound(pos.begin(), pos.end(), d);

            if (it == pos.end())
            {
                cout << n - pos.back() << endl;
            }
            else if (it == pos.begin())
            {
                cout << pos[0] - 1 << endl;
            }
            else
            {
                int e = *it;
                --it;
                int s = *it;

                cout << min(abs(e - ((s + e) / 2)), abs(s - ((s + e) / 2))) << endl;
            }
        }
    }
    return 0;
}