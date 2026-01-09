#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            bool ok = true;

            while(!q.empty()) {
                int u = q.front(); q.pop();
                if(g[u].size() != 2) ok = false;

                for(int v : g[u]) {
                    if(!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            if(ok) ans++;
        }
    }

    cout << ans << "\n";
}
