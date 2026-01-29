#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> graph;

signed main()
{
    int n, m, q;
    cin >> n >> m >> q;

    graph.assign(n + 1, vector<int>(n + 1, 1e18));

    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[v][u], w);
    }

    // all pair shortest path
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // all pairs covered , u-> v as weel as v-> u
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int ans = (graph[u][v] < 1e18 ? graph[u][v] : -1);

        cout << ans << endl;
    }

    return 0;
}