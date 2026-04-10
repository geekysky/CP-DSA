#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Base cases
    if (n <= 2) {
        if (k > 0) cout << 0 << "\n";
        else cout << n << "\n";
        return;
    }

    // Push all initial leaves (degree <= 1) into the queue
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] <= 1) {
            q.push(i);
        }
    }

    int removed_count = 0;

    // Process layer by layer, up to k times
    while (!q.empty() && k > 0) {
        int layer_size = q.size();
        removed_count += layer_size;
        
        // Remove the current layer of leaves
        while (layer_size--) {
            int node = q.front();
            q.pop();

            // Decrease degree of neighbors
            for (int neighbor : adj[node]) {
                degree[neighbor]--;
                // If a neighbor becomes a leaf, queue it up for the next layer
                if (degree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }
        k--; // One operation complete
    }

    cout << n - removed_count << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}