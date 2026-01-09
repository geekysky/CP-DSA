#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, k, m;
    cin >> n >> m >> k;

    vector<vector<int>> ans;

    int row = 1;
    int x = 1, y = 1;
    int cnt = 0;
    for (int layers = 0; layers < k - 1; layers++)
    {
        // k-1 two cells each
        vector<int> temp;
        for (int i = 0; i < 2; i++)
        {
            if (row % 2)
            {
                // odd row -> left to right
                if (y == m)
                {
                    row = 0;
                    temp.push_back(x);
                    temp.push_back(y);
                    // odd row -> even row
                    x++;
                }
                else
                {
                    temp.push_back(x);
                    temp.push_back(y);
                    y++;
                }

                cnt++;
            }
            else
            {
                // even row -> right to left
                if (y == 1)
                {
                    row = 1;
                    temp.push_back(x);
                    temp.push_back(y);

                    // even row -> odd row
                    x++;
                }
                else
                {
                    temp.push_back(x);
                    temp.push_back(y);
                    y--;
                }

                cnt++;
            }
        }

        ans.push_back(temp);
    }

    // FOR LAST TUBE
    vector<int> temp;
    while (cnt != n * m)
    {
        if (row % 2)
        {
            // odd row -> left to right
            if (y == m)
            {
                row = 0;
                temp.push_back(x);
                temp.push_back(y);
                x++;
            }
            else
            {
                temp.push_back(x);
                temp.push_back(y);
                y++;
            }

            cnt++;
        }
        else
        {
            // even row -> right to left
            if (y == 1)
            {
                row = 1;
                temp.push_back(x);
                temp.push_back(y);
                x++;
            }
            else
            {
                temp.push_back(x);
                temp.push_back(y);
                y--;
            }

            cnt++;
        }
    }
    ans.push_back(temp);

    for (auto x : ans)
    {
        cout << x.size() / 2 << " ";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
