#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> leaf_children;
vector<vector<int>> tree;

void dfs(int root,int par){
    if(tree[root].size()==0){
        //leaf node
        if(par!=0)
        leaf_children[par]++;

        return;
    }

    for(auto child:tree[root]){
        dfs(child,root);
    }
}

signed main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    leaf_children.assign(n + 1, 0);

    for (int i = 1; i <= n - 1; i++)
    {
        int par;
        cin >> par;

        tree[par].push_back(i + 1);
    }

    dfs(1,0);

    // for(auto val:leaf_children){
    //     cout<<val<<" ";
    // }
    // cout<<endl;

    for (int i = 1; i <= n; i++)
    {
        if (tree[i].size() > 0)
        {
            if (leaf_children[i] < 3)
            {
                // non leaf node has < 3 leaf children
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}