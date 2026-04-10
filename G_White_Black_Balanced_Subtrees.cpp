#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ans;
vector<vector<int>> tree;

pair<int, int> dfs(int root, string &color)
{
    // base case leaf nodes
    int w = 0, b = 0;

    for (auto children : tree[root])
    {
        pair<int, int> cols = dfs(children, color);
        w+=cols.first;
        b+=cols.second;
    }

    // can this subtree be "GOOD" ?
    if (color[root-1] == 'B')
    {
        b++;
    }
    else
    {
        w++;
    }

    if (b == w)
    {
        ans++;
    }

    return {w,b};
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> parent(n + 1, -1);
        tree.assign(n + 1, {});

        for (int i = 2; i <= n; i++)
        {
            int ele;
            cin >> ele;

            parent[i] = ele;
        }

        string color;
        cin >> color;

        ans = 0;
        for (int i = 2; i <= n; i++)
        {
            tree[parent[i]].push_back(i);
        }

        auto res = dfs(1, color);

        cout << ans << endl;
    }
    return 0;
}