#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> graph;
vector<int> visited;
vector<int> component_size;

void dfs(int node,int component_no){
    visited[node]=component_no;

    for(auto nb:graph[node]){
        if(!visited[nb]){
            dfs(nb,component_no);
        }
    }
}


signed main(){
    int n,m;
    cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1,0);

    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        
        vector<int> nodes;
        for(int j=1;j<=k;j++){
            int ele;
            cin>>ele;

            nodes.push_back(ele);
        }

        for(int j=1;j<k;j++){
            int u=nodes[j-1];
            int v = nodes[j];

            //u aur v k beech m edge hai undirected and unweighted
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    //connected component ka size mang raha hai 
    int component=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            component++;

            dfs(i,component);
        }
    }

    component_size.resize(component+1);

    for(int i=1;i<=n;i++){
        component_size[visited[i]]++;
    }

    for(int i=1;i<=n;i++){
        cout<<component_size[visited[i]]<<" ";
    }
    cout<<endl;
   




    return 0;
}