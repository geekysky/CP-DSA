#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        vector<pair<int, int>> arr(k);
        // int mat[a][b];
        // for (int i = 0; i < a; i++)
        // {
        //     for (int j = 0; j < b; j++)
        //     {
        //         mat[i][j] = 0;
        //     }
        // }

        for (int i = 0; i < k; i++)
        {
            cin >> arr[i].first;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i].second;
        }

        map<int, int> row_sum, col_sum;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> curr = arr[i];
            // mat[curr.first - 1][curr.second - 1] = 1;

            row_sum[curr.first]++;
            col_sum[curr.second]++;
        }

        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> curr = arr[i];

            ans += (k - row_sum[curr.first] - col_sum[curr.second] + 1);
            //mat[curr.first - 1][curr.second - 1] -> this will always be 1 
        }

        cout << ans / 2 << endl;
    }
    return 0;
}