#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<int> subT, depth;

int dfs(int node, int par, int depth_without_itself)
{
    subT[node] = 1;
    depth[node] = depth_without_itself;

    for (auto nb : tree[node])
    {
        if (nb == par)
            continue;

        subT[node] += dfs(nb, node, depth_without_itself + 1);
    }

    return subT[node];
}

signed main()
{
    int n, k;
    cin >> n >> k;

    tree.resize(n + 1);
    subT.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    priority_queue<int> pq;

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1, 0);

    for (int i = 1; i <= n; i++)
    {
        pq.push(depth[i] - (subT[i] - 1));
    }

    int ans = 0;
    while (k)
    {
        ans += pq.top();
        pq.pop();

        k--;
    }

    cout << ans << endl;
    return 0;
}