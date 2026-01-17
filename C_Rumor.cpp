#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> components;
vector<int> min_cost_component;

void dfs(int node, int cc_no)
{
    components[node] = cc_no;

    for (auto nb : graph[node])
    {
        if (!components[nb])
        {
            dfs(nb, cc_no);
        }
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> costs;
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;

        costs.push_back(ele);
    }

    graph.resize(n + 1);
    components.assign(n + 1, 0);
    // visited.assign(n+1,0);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int comp_no = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!components[i])
        {
            comp_no++;
            dfs(i, comp_no);
        }
    }

    min_cost_component.assign(comp_no + 1, 1e9);
    for (int i = 1; i <= n; i++)
    {
        min_cost_component[components[i]] = min(min_cost_component[components[i]], costs[i - 1]);
    }

    int sum = 0;
    for (auto val : min_cost_component)
    {
        sum += val;
    }

    cout << sum - 1000000000 << endl;

    return 0;
}