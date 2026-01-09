#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, m;
    cin >> n >> m;

    int pairs = min(n, m);
    if (m > ((2 * pairs) + 2))
    {
        cout << -1 << "\n";
    }

    else if (n > pairs + 1)
    {
        cout << -1 << "\n";
    }

    else
    {
        int extra = m - pairs;
        string ans = "";
        if (n < m)
        {
            for (int i = 1; i <= pairs; i++)
            {
                string temp = "01";

                if (extra)
                {
                    temp += "1";
                    extra--;
                }
                ans += temp;
            }

            if (extra)
            {
                string curr(extra, '1');
                ans = curr + ans;
            }

            cout << ans << "\n";
        }
        else if (n > m)
        {
            // just one extra zero is present
            string ans = "";
            for (int i = 1; i <= pairs; i++)
            {
                string temp = "01";
                ans += temp;
            }
            ans += "0";

            cout << ans << "\n";
        }
        else
        {
            string ans = "";
            for (int i = 1; i <= pairs; i++)
            {
                string temp = "01";
                ans += temp;
            }

            cout << ans << "\n";
        }
    }
    return 0;
}