#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int,int>>> g;
vector<int> dis;
int n, m;

void BFS01(int sc)
{
    for (int i = 1; i <= n; i++)
        dis[i] = 1e18;

    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);

    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for (auto v : g[node])
        {
            int neigh = v.first;
            int wt = v.second;

            if (dis[neigh] > dis[node] + wt)
            {
                dis[neigh] = dis[node] + wt;
                if (wt == 0)
                    dq.push_front(neigh);
                else
                    dq.push_back(neigh);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    g.assign(n + 1, {});        
    dis.assign(n + 1, 1e18);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }

    BFS01(1);   

    if (dis[n] >= 1e18)
        cout << -1 << "\n";
    else
        cout << dis[n] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
