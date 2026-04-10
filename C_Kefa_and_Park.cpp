#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
int n,m;
int ans;

void dfs(int root,int par,int maxi,int ctr, vector<int> &cats){
    if(cats[root]==1){
        ctr++;
    }
    else{
        ctr=0;
    }

    maxi = max(maxi,ctr);

    int ch = 0;
    for(auto children:graph[root]){
        if(children!=par){
            ch++;
            dfs(children,root,maxi,ctr,cats);
        }
    }

    if(ch==0){
        //leaf node
        if(maxi <= m){
            ans++;
        }
    }

}

signed main(){
    
    cin>>n>>m;

    vector<int> cats(n+11,0);
    graph.assign(n+1,{});

    for(int i=1;i<=n;i++){
        int val;
        cin>>val;

        cats[i]=val;
    }
    
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    ans=0;
    dfs(1,-1,0,0,cats);

    cout<<ans<<endl;

    return 0;
    
}