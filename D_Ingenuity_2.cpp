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

        if (n == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        int m_h = 0, m_r = 0;

        vector<int> mp(4, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
            {
                mp[0]++;
            }
            else if (s[i] == 'S')
            {
                mp[1]++;
            }
            else if (s[i] == 'E')
            {
                mp[2]++;
            }
            else
            {
                mp[3]++;
            }
        }

        map<int, int> r, h;
        for (int i = 0; i < 3; i += 2)
        {
            // 0 - north
            // 2 - east

            int mini = min(mp[i], mp[i + 1]);

            if (mini > 1)
            {
                // distribute between rover and helicopter
                m_h++;
                m_r += (mini - 1);

                if (i == 0)
                {
                    h[0]++;
                    h[1]++;

                    r[0] += (mini - 1);
                    r[1] += (mini - 1);
                }
                else if (i == 2)
                {
                    h[2]++;
                    h[3]++;

                    r[2] += (mini - 1);
                    r[3] += (mini - 1);
                }

                mp[i] -= mini;
                mp[i + 1] -= mini;
            }
            else if (mini == 1)
            {
                // just one move
                if (m_h <= m_r)
                {
                    m_h++;

                    if (i == 0)
                    {
                        h[0]++;
                        h[1]++;
                    }
                    else if (i == 2)
                    {
                        h[2]++;
                        h[3]++;
                    }

                    mp[i] -= mini;
                    mp[i + 1] -= mini;
                }
                else
                {
                    m_r++;

                    if (i == 0)
                    {
                        r[0]++;
                        r[1]++;
                    }
                    else if (i == 2)
                    {
                        r[2]++;
                        r[3]++;
                    }

                    mp[i] -= mini;
                    mp[i + 1] -= mini;
                }
            }
        }

        // now all remaining occurences of any particular move must be even
        bool pos = true;
        for (int i = 0; i < 4; i++)
        {
            if (mp[i] % 2)
            {
                pos = false;
                break;
            }
            else
            {
                // distribute among both rover and helicopter
                r[i] += (mp[i] / 2);
                h[i] += (mp[i] / 2);

                // add to total individual moves performed yet...
                m_h += (mp[i] / 2);
                m_r += (mp[i] / 2);
            }
        }

        if (!pos or m_h == 0 or m_r == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<char> res(n);
        for (int i = 0; i < n; i++)
        {
            int curr;
            if (s[i] == 'N')
            {
                curr = 0;
            }
            else if (s[i] == 'S')
            {
                curr = 1;
            }
            else if (s[i] == 'E')
            {
                curr = 2;
            }
            else
            {
                curr = 3;
            }

            if (r[curr] != 0)
            {
                // assign this move to rover
                res[i] = 'R';
                r[curr]--;
            }
            else
            {
                res[i] = 'H';
                h[curr]--;
            }
        }

        for (auto x : res)
        {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}