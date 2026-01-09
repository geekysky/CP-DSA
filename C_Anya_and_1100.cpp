#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(const string &s, int pos)
{

    if (pos < 0 || pos + 3 >= s.size())
    {
        return false;
    }
    return s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        int q;
        cin >> q;

        int count = 0;
        for (int i = 0; i <= n - 4; ++i)
        {
            if (checker(s, i))
            {
                count++;
            }
        }

        while (q--)
        {
            int i, v;
            cin >> i >> v;
            i--;

            if (s[i] - '0' == v)
            {
                if (count > 0)
                {
                    cout << "YES" << "\n";
                }
                else
                {
                    cout << "NO" << "\n";
                }
                continue;
            }

            for (int j = i - 3; j <= i; ++j)
            {
                if (checker(s, j))
                {
                    count--;
                }
            }

            s[i] = v + '0';

            for (int j = i - 3; j <= i; ++j)
            {
                if (checker(s, j))
                {
                    count++;
                }
            }

            if (count > 0)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
