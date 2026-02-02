#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx(char c) {
    if (c == 'U') return -1;
    if (c == 'D') return 1;
    if (c == 'L') return 0;
    if (c == 'R') return 0;
    return 0;
}
int dy(char c) {
    if (c == 'U') return 0;
    if (c == 'D') return 0;
    if (c == 'L') return -1;
    if (c == 'R') return 1;
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int N = n * m;
        auto id = [&](int i, int j) {
            return i * m + j;
        };

        vector<vector<int>> rev(N);   // reverse graph
        vector<int> bad(N, 0);         // 1 = BAD (escapes), 0 = undecided/good
        vector<int> isQ(N, 0);         // is '?'

        queue<int> q;

        // Step 1: build reverse graph for fixed cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = id(i, j);
                if (a[i][j] == '?') {
                    isQ[u] = 1;
                    continue;
                }

                int ni = i + dx(a[i][j]);
                int nj = j + dy(a[i][j]);

                if (!inside(ni, nj)) {
                    // goes outside => BAD source
                    bad[u] = 1;
                    q.push(u);
                } else {
                    int v = id(ni, nj);
                    rev[v].push_back(u);
                }
            }
        }

        // Step 2: reverse BFS from BAD
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : rev[u]) {
                if (!bad[v]) {
                    bad[v] = 1;
                    q.push(v);
                }
            }
        }

        // Step 3: process '?' cells
        // A '?' is GOOD if it can point to any GOOD neighbor

        vector<int> degBad(N, 0); // how many neighbors are BAD
        vector<vector<int>> adj(N);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = id(i, j);
                if (!isQ[u]) continue;

                for (int d = 0; d < 4; d++) {
                    int ni = i + (int[]){-1,1,0,0}[d];
                    int nj = j + (int[]){0,0,-1,1}[d];
                    if (!inside(ni, nj)) continue;
                    int v = id(ni, nj);
                    adj[u].push_back(v);
                }
            }
        }

        queue<int> q2;

        for (int u = 0; u < N; u++) {
            if (!isQ[u]) continue;
            int cnt = 0;
            for (int v : adj[u]) {
                if (bad[v]) cnt++;
            }
            degBad[u] = cnt;
            if (cnt == (int)adj[u].size()) {
                // all neighbors bad => forced BAD
                if (!bad[u]) {
                    bad[u] = 1;
                    q2.push(u);
                }
            }
        }

        // Propagate forced BAD
        while (!q2.empty()) {
            int u = q2.front(); q2.pop();
            for (int v : rev[u]) {
                if (isQ[v] && !bad[v]) {
                    degBad[v]++;
                    if (degBad[v] == (int)adj[v].size()) {
                        bad[v] = 1;
                        q2.push(v);
                    }
                }
            }
        }

        // Count GOOD cells
        int ans = 0;
        for (int u = 0; u < N; u++) {
            if (!bad[u]) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
