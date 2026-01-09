#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 and n < 27)
        {
            cout << -1 << "\n";
            continue;
        }
        else if (n % 2 == 0)
        {
            int ctr = 1;
            int len = 0;
            for (int i = 1; i <= n; i++)
            {
                cout << ctr << " ";

                len++;

                if (len % 2 == 0)
                {
                    ctr++;
                }
            }
            cout << "\n";
        }
        else
        {
            string s = "15 1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 15 1 ";
            cout << s;
            
            n-=27;
            for (int i = 0; i < n / 2; ++i)
            {
                int cur = 16 + i;
                cout << cur << ' ' << cur << ' ';
            }

            cout << "\n";
        }
        // odd part m wrong hai logic...most probably
    }
    return 0;
}