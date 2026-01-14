
#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> graph;
vector<int> out_degree,ans;
vector<int> largest_outgoing;
map<pair<int, int>, int> repeat_edges;
map<int,vector<int>> incoming_edges;
int n, m, label;

void kahn()
{
    priority_queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (out_degree[i] == 0)
        {
            q.push(-i);
        }
    }

    while (!q.empty())
    {   
        //largest wala pop hoga pehle with out degree 0 
        int current = -q.top();
        q.pop();

        ans[current]=label;
        label++;

        for (int neighbor : incoming_edges[current])
        {
            out_degree[neighbor]--;
            if (out_degree[neighbor] == 0)
            {
                q.push(-neighbor);
            }
        }
    }
}

signed main()
{
    cin >> n >> m;

    graph.resize(n + 1);
    out_degree.assign(n + 1, 0);
    ans.assign(n+1,0);
    label=1;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        // v -> u ek directed edge hai 
        if (repeat_edges[make_pair(u, v)] == 0)
        {
            graph[v].push_back(u);
            out_degree[v]++;
            incoming_edges[u].push_back(v);

            repeat_edges[make_pair(u, v)] = 1;
        }
    }
    
    kahn();

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}