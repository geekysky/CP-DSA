#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<int> sub_tree;

int dfs(int node, int par)
{
    int sz = 1;

    for (auto nb : tree[node])
    {
        if (nb == par)
            continue;

        sz += dfs(nb, node);
    }

    sub_tree[node] = sz;

    return sz;
}

signed main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;

        tree[i].push_back(x);
        tree[x].push_back(i);
    }

    sub_tree.assign(n + 1, 0);

    dfs(1,-1);

    for (int i = 1; i <= n; i++)
    {
        cout << sub_tree[i] - 1 << " ";
    }
    cout << endl;

    return 0;
}