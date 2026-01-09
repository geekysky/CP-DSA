#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> solve(int a1, int b1, int c1, int a2, int b2, int c2)
{
    int det = a1 * b2 - a2 * b1;
    if (det == 0)
        return {LLONG_MAX, LLONG_MAX}; 

    int num_x = c1 * b2 - c2 * b1;
    int num_y = a1 * c2 - a2 * c1;

    if (num_x % det != 0 || num_y % det != 0)
        return {LLONG_MAX, LLONG_MAX}; 

    int x_sol = num_x / det;
    int y_sol = num_y / det;

    return {x_sol, y_sol};
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int sol_x = LLONG_MAX, sol_y = LLONG_MAX;
        bool ok = true;

        for (int i = 0; i < n - 1; i++)
        {
            pair<int, int> result = solve(i + 1, n - i, arr[i], i + 2, n - i - 1, arr[i + 1]);
            int curr_x = result.first;
            int curr_y = result.second;

            if (curr_x == LLONG_MAX || curr_y == LLONG_MAX || curr_x < 0 || curr_y < 0)
            {
                ok = false;
                break;
            }

            if (sol_x != LLONG_MAX && sol_y != LLONG_MAX)
            {
                if (curr_x != sol_x || curr_y != sol_y)
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                sol_x = curr_x;
                sol_y = curr_y;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
