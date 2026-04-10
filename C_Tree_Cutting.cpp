#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;

int dfs(int root, int par, int &x, int &k)
{

    int sz = 1;
    for (auto nb : tree[root])
    {
        if (nb == par)
            continue;

        int ch_sz = dfs(nb, root, x, k);

        if (ch_sz >= x)
        {
            // we can cut this node's edge to it's parent
            // we will not add it's contribution to it's parent

            if (k)
            {
                k--;
            }
            else
            {
                sz += ch_sz;
            }
        }
        else
        {
            sz += ch_sz;
        }
    }

    return sz;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        tree.assign(n + 1, vector<int>{});

        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int low = 1;
        int high = 1e8;
        int ans = high + 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cuts = k;

            int root_sz = dfs(1, -1, mid, cuts);

            if (root_sz >= mid and cuts==0)
            {
                // last remaining component also >= mid in size...
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}