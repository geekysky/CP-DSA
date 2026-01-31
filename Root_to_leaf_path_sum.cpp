
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool possible;
int curr;

void dfs(Node* root,int sum){
    if(root==NULL){
        return;
    }

    curr += root->val;
    if(root->left == NULL and root->right == NULL){
        //leaf node

        if(curr==sum){
            possible=true;
        }
    }

    else{
        dfs(root->left,sum);
        dfs(root->right,sum);
    }

    curr-=root->val;
    return;

}

bool hasPathSum(Node* node, int sum)
{
    //Complete the function
    possible = false;
    curr = 0;
    dfs(node,sum);

    return possible;
}


Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        assert(n<=1000000);
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        if(hasPathSum(tree,sum))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
