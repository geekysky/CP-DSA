#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> sz;

void dfs(int node,int par){

    sz[node]=1;
    for(auto nb:graph[node]){
        if(nb==par)
        continue;

        dfs(nb,node);
        sz[node]+=sz[nb];
    }

}

signed main()
{
    int n;
    cin >> n;

    graph.resize(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (n & 1)
    {
        cout << -1 << endl;
        return 0;
    }

    sz.assign(n+1,0);

    dfs(1,-1);

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(sz[i]%2==0){
            ans++;
        }
    }

    cout<<ans-1<<endl;

    

    return 0;
}