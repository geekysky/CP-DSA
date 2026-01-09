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

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            mp[ele]++;
        }

        int fwd = 0, bwd = 0;
        if (mp.size() == 1)
        {
            cout << 1 << endl;
            continue;
        }

        for (auto x : mp)
        {

            if (x.second == 1)
            { // either in fwd or in bwd or even common
                if (fwd <= bwd)
                {
                    fwd++;
                }
                else
                {
                    bwd++;
                }
            }
            else
            {
                // frequency >= 2
                bwd++;
                fwd++;
            }
        }

        if (fwd == bwd + 1)
        {
            // place single element to common part
            bwd++;
        }

        cout << min(fwd, bwd) << endl;
    }
    return 0;
}