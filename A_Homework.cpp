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

        string s;
        cin >> s;

        int m;
        cin >> m;

        string c;
        cin >> c;

        string d;
        cin >> d;

        string f = "";
        string r = "";
        for (int i = 0; i < m; i++)
        {
            if (d[i] == 'V')
            {
                f += c[i];
            }
            else
            {
                r += c[i];
            }
        }

        reverse(f.begin(), f.end());

        cout << f << s << r << endl;
    }
    return 0;
}