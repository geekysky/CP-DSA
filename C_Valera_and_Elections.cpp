#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<pair<int, int>>> tree;
vector<int> ans;
map<pair<int, int>, int> bad_edges;

int dfs(int node, int par)
{
    // each node's DFS will return how many nodes have I chosen in it's subtree
    // excluding itself...
    // if the edge to it's parent is bad and if we have not chosen any node in it's subtree
    // choose as this is the best possible node to be chosen
    // else ignore as some node in it's tree will cover this bad edge on it's path to route...

    int chosen = 0;
    for (auto nb : tree[node])
    {
        int neighbor = nb.first;

        if (neighbor == par)
            continue;

        chosen += dfs(neighbor, node);
    }

    if (bad_edges[{node, par}] == 1)
    {
        if (chosen == 0)
        {
            // it's necesssary to pick this node as any node in it's subtree has not been chosen...
            chosen++;
            ans.push_back(node);
        }
    }

    return chosen;
}

signed main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    ans.clear();
    bad_edges.clear();

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        tree[u].push_back({v, w});
        tree[v].push_back({u, w});

        if (w == 2)
        {
            // bad bidirectional edge
            bad_edges[make_pair(u, v)] = 1;
            bad_edges[make_pair(v, u)] = 1;
        }
    }

    int root = dfs(1, -1);

    cout << ans.size() << endl;
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}