#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<int> freq;

void dfs(int node, int parent, int lv)
{
    freq[lv]++;

    for (auto nb : tree[node])
    {
        if (nb != parent)
        {
            dfs(nb, node, lv + 1);
        }
    }
}

signed main()
{
    int n;
    cin >> n;

    tree.assign(n+1,{});
    for (int i = 2; i <= n ; i++)
    {
        int par;
        cin >> par;

        tree[i].push_back(par);
        tree[par].push_back(i);
    }

    freq.assign(n + 1, 0);

    dfs(1, -1, 0);

    int ans = 0;

    for (auto &val : freq)
    {
        ans += (val % 2);
    }

    cout << ans << endl;

    return 0;
}