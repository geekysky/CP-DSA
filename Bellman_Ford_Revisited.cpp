#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int INF = 1e17; // Use a value smaller than 1e18 to prevent overflow

struct Edge {
    int u, v, w;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v); // Needed for BFS cycle propagation
    }

    // 1. Initialize distances to negative infinity
    vector<int> dist(n + 1, -INF);
    dist[1] = 0;

    // 2. Standard Bellman-Ford (Relax N-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // 3. Find nodes that are part of a positive cycle
    // (A positive cycle allows you to increase the score infinitely)
    queue<int> q;
    vector<bool> is_inf(n + 1, false);

    for (auto &e : edges) {
        if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
            // This node can still be relaxed, so it's part of a cycle
            if (!is_inf[e.v]) {
                is_inf[e.v] = true;
                q.push(e.v);
            }
        }
    }

    // 4. Propagate the "infinite" score to all reachable nodes using BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!is_inf[v]) {
                is_inf[v] = true;
                q.push(v);
            }
        }
    }

    // 5. Output logic
    // If the destination node N is affected by a positive cycle, score is infinite
    if (is_inf[n]) {
        cout << -1 << endl; 
    } else {
        // If dist[n] remains -INF, it means node n is unreachable
        if (dist[n] <= -1e15) cout << -1 << endl;
        else cout << dist[n] << endl;
    }

    return 0;
}