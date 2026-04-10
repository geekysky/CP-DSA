#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<int> distfromroot;

void farthestfromroot(int node, int par)
{

    distfromroot[node] = distfromroot[par] + 1;

    for (auto nb : tree[node])
    {
        if (nb == par)
            continue;

        farthestfromroot(nb, node);
    }
}

signed main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    distfromroot.assign(n + 1, -1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    farthestfromroot(1, 0);
    int maxi = LLONG_MIN;
    int st = -1;
    for (int i = 1; i <= n; i++)
    {
        if (distfromroot[i] > maxi)
        {
            maxi = distfromroot[i];
            st = i;
        }
    }

    distfromroot.assign(n + 1, -1);
    farthestfromroot(st, 0);
    maxi = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, distfromroot[i]);
    }

    cout << maxi << endl;

    return 0;
}