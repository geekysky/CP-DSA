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

    set<int> end_pts;

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
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

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (distfromroot[i] == maxi)
        {
            // one of the end points of any of the diameter
            ans[i]++;
        }
    }

    distfromroot.assign(n + 1, -1);
    farthestfromroot(st, 0);

    maxi = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (distfromroot[i] > maxi)
        {
            maxi = distfromroot[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (distfromroot[i] == maxi)
        {
            // second end point of any of the diameter
            ans[i]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
        {
            // one of the end points of the diamter , our answer will improve
            cout << maxi + 1 << endl;
        }
        else
        {
            cout << maxi << endl;
        }
    }
}