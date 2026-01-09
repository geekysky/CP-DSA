#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;

        set<int> ans;
        ans.insert(x);
        for (int i = 0; i < m; i++)
        {
            int r;
            char ch;
            cin >> r >> ch;

            set<int> temp;
            if (ch == '0')
            {
                // clockwise
                // all possible candidates move r places clockwise
                for (auto it : ans)
                {
                    int val = (it + r) % n;

                    if (val == 0)
                    {
                        temp.insert(n);
                    }
                    else
                    {
                        temp.insert(val);
                    }
                }

                ans = temp;
            }
            else if (ch == '1')
            {
                // anticlockwise
                // all possible candidates move r places anticlockwise
                for (auto it : ans)
                {
                    int val = (it - r + n) % n;

                    if (val == 0)
                    {
                        temp.insert(n);
                    }
                    else
                    {
                        temp.insert(val);
                    }
                }

                ans = temp;
            }
            else
            {
                //? type we need to explore both clockwise and anticlockwise
                for (auto it : ans)
                {
                    int val = (it + r) % n;

                    if (val == 0)
                    {
                        temp.insert(n);
                    }
                    else
                    {
                        temp.insert(val);
                    }
                }

                for (auto it : ans)
                {
                    int val = (it - r + n) % n;

                    if (val == 0)
                    {
                        temp.insert(n);
                    }
                    else
                    {
                        temp.insert(val);
                    }
                }

                ans = temp;
            }
        }

        cout << ans.size() << "\n";
        for (auto ele : ans)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}