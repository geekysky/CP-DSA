#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> RootX, RootY;

void dfs(int node, int par, vector<int> &sz)
{

    sz[node] = 1;
    for (auto nb : graph[node])
    {
        if (nb == par)
            continue;

        dfs(nb, node, sz);
        sz[node] += sz[nb];
    }
}

signed main()
{
    int n, x, y;
    cin >> n >> x >> y;

    graph.assign(n + 1, {});
    RootX.assign(n + 1, 0);
    RootY.assign(n + 1, 0);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = n * (n - 1);

    dfs(x, -1, RootX);
    int val = RootX[y];

    //cout<<ans<<" "<<val<<endl;
    dfs(y, -1, RootY);
    
    cout<<(n*(n-1)) - (RootX[y]*RootY[x])<<endl;

    return 0;
}