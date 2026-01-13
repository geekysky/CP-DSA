#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    string s;
    cin >> s;
    if (s.size() < 4)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool ab = false, ba = false;

    for (int i = 0; i < s.size() - 3; i++)
    {
        if (s[i] == 'A' and s[i + 1] == 'B')
        {
            for (int j = i + 2; j < s.size() - 1; j++)
            {
                if (s[j] == 'B' and s[j + 1] == 'A')
                {
                    ab = true;
                    ba = true;
                    break;
                }
            }

            break;
        }
    }

    if (!ab)
    {
        // ab...ba not found
        // let's try for ba...ab order...

        for (int i = 0; i < s.size() - 3; i++)
        {
            if (s[i] == 'B' and s[i + 1] == 'A')
            {
                for (int j = i + 2; j < s.size() - 1; j++)
                {
                    if (s[j] == 'A' and s[j + 1] == 'B')
                    {
                        ab = true;
                        ba = true;
                        break;
                    }
                }

                break;
            }
        }
    }

    if (ab and ba)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}