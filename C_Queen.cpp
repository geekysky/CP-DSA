#include <bits/stdc++.h>
using namespace std;
#define int long long int
using state = pair<int, int>;

signed main()
{
    int n;
    cin >> n;

    vector<vector<state>> graph(n + 1);
    vector<int> parent(n + 1);
    vector<int> one_edge_neighbors(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x, edge;
        cin >> x >> edge;

        parent[i] = x;

        if (x != -1)
        {
            graph[x].push_back(make_pair(i, edge));
            graph[i].push_back(make_pair(x, edge));

            if (edge == 1)
            {
                one_edge_neighbors[x]++;
                one_edge_neighbors[i]++;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (one_edge_neighbors[i] == graph[i].size() and parent[i] != -1)
        {
            // this node has to be deleted
            ans.push_back(i);

            // delete this node
            // deleting conditions are independent...no dependent values
            // the order is ascending in order...
        }
    }

    if (!ans.size())
    {
        cout << -1 << endl;
    }

    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}