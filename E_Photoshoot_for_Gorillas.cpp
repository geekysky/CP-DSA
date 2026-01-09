#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int w;
        cin >> w;
        vector<int> arr(w);
        for (int i = 0; i < w; i++)
        {
            cin >> arr[i];
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> V(n + 1), H(m + 1);
        for (int i = 1; i <= n; i++)
        {
            int up = min(i, n - k + 1);
            int down = max(i - k + 1, 1ll);
            V[i] = max(0ll, up - down + 1);
        }
        for (int j = 1; j <= m; j++)
        {
            int left = min(j, m - k + 1);
            int right = max(j - k + 1, 1ll);
            H[j] = max(0ll, left - right + 1);
        }
        vector<vector<int>> freq(n + 1, vector<int>(m + 1));
        vector<int> order;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                freq[i][j] = V[i] * H[j];
                order.push_back(freq[i][j]);
            }
        }

        sort(order.rbegin(), order.rend());
        int sum = 0;
        for (int i = 0; i < w; i++)
        {
            sum += (order[i] * arr[i]);
        }

        cout << sum << endl;
    }
    return 0;
}