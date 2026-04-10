#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> color;

void dfs(int node, int col)
{
    color[node] = col;

    for (auto nb : graph[node])
    {
        if (color[nb] == -1)
        {
            // unvisited
            dfs(nb, 1 - col);
        }
    }
}

signed main()
{
    int n;
    cin >> n;

    graph.resize(n + 1);
    color.assign(n + 1, -1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 1);

    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            x++;
        }
        else
        {
            y++;
        }
    }

    cout << (x * y) - (n - 1) << endl;

    return 0;
}