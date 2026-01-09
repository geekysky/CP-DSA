#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int arr[n][m];
        map<int, int> moves;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                moves[arr[i][j]] = 1;
            }
        }

        // kis color k liye kitne moves lagenge
        vector<pair<int, int>> directions;
        directions.push_back({1, 0});
        directions.push_back({-1, 0});
        directions.push_back({0, 1});
        directions.push_back({0, -1});

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = arr[i][j];
                for (auto p : directions)
                {
                    int x = i + p.first;
                    int y = j + p.second;

                    if ((x >= 0 and x < n and y >= 0 and y < m) and arr[x][y] == val)
                    {
                        // edge sharing ho rahi hai and neighboring elements are having the same colors
                        // either cell needs to be processed separately
                        moves[val] = 2;
                    }
                }
            }
        }

        bool sharing = false;
        int ans = 0;
        for (auto colors : moves)
        {
            ans += colors.second;

            if (colors.second == 2)
            {
                sharing = true;
            }
        }

        if (sharing)
        {
            cout << ans - 2 << "\n";
        }
        else
        {
            //agar sharing nahi hai to ek color constant rahega
            cout << ans - 1 << "\n";
        }
    }
    return 0;
}