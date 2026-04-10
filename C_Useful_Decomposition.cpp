#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;
int more_than_one_degree;
vector<int> degree;

void dfs(int node, int par)
{
    int branches = 0;

    for (auto nb : tree[node])
    {
        if (nb == par)
        {
            continue;
        }

        branches++;
        dfs(nb, node);
    }

    if (branches > 1)
    {
        // potential issue
        more_than_one_degree++;
        degree.push_back(node);
    }
}

signed main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int hubs = 0;
    int hub = -1;
    vector<int> leaves;

    for (int i = 1; i <= n; i++)
    {
        if (tree[i].size() > 2)
        {
            // hub
            hubs++;
            hub = i;
        }
        if (tree[i].size() == 1)
        {
            // leaf node
            leaves.push_back(i);
        }
    }

    if (hubs > 1)
    {
        cout << "No" << endl;
    }
    else
    {
        // all paths from hub , hub -> leaf 1 , hub -> leaf 2
        cout << "Yes" << endl;
        if (hub == -1)
        {
            // linear tree
            cout << 1 << endl;
            cout << leaves[0] << " " << leaves[1] << endl;
        }
        else
        {
            cout << leaves.size() << endl;
            for (int i = 0; i < leaves.size(); i++)
            {
                cout << hub << " " << leaves[i] << endl;
            }
        }
    }

    return 0;
}