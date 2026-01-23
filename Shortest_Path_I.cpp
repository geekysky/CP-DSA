#include <bits/stdc++.h>
using namespace std;
#define int long long int
using state = pair<int, int>;
vector<vector<state>> graph;
vector<int> visited, dist;

signed main()
{
    // SSSP, single component
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.assign(n + 1, 0);
    dist.assign(n + 1, 1e18);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }

    priority_queue<state> min_heap;
    min_heap.push(make_pair(0, 1));
    dist[1] = 0;

    while (!min_heap.empty())
    {
        state ele = min_heap.top();
        min_heap.pop();

        // pair is of (distance,node) type

        if (!visited[ele.second])
        {
            int node = ele.second;
            visited[ele.second] = 1;

            for (auto nb : graph[node])
            {
                int neighbor = nb.first;
                int weight = nb.second;

                if (dist[neighbor] > dist[node] + weight)
                {
                    // shorter weight path found
                    // format is - update then push
                    dist[neighbor] = dist[node] + weight;
                    min_heap.push(make_pair(-dist[neighbor], neighbor));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}