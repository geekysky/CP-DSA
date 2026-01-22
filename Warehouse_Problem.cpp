#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> dist;

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, k;
        cin >> m >> k;

        graph.assign(m + 2, {});
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= m + 1 ; i++)
        {
            dist.assign(m + 2, 1e9);

            // source is i
            dist[i] = 0;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                if (dist[node] < k)
                {
                    // useful node
                    for (auto nb : graph[node])
                    {
                        if (dist[nb] == 1e9)
                        {
                            dist[nb] = dist[node] + 1;
                            q.push(nb);

                            if (dist[nb] == k)
                            {
                                ans++;
                            }
                        }
                    }
                }
            }

        }

        cout << ans / 2 << endl;
    }

    return 0;
}