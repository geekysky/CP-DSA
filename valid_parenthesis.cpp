#include <bits/stdc++.h>
using namespace std;

int depth = 0;
vector<string> ans;
string cur = "";

void backtrack(int openRem, int closeRem, int k,int max_depth)
{   
    // if(max_depth>k or max_depth<k){
    //     return;
    // }

    //cout<<max_depth<<endl;

    if (openRem == 0 && closeRem == 0 && depth == 0 && max_depth==k)
    {
        ans.push_back(cur);
        return;
    }

    // Try '(' if we still have opens left.
    if (openRem > 0 and depth < k)
    {
        // adding '(' increases current depth by 1
        cur.push_back('(');
        depth++;
        int new_max = max(max_depth, depth);
        backtrack(openRem - 1, closeRem, k,new_max);

        cur.pop_back();
        depth--;
    }

    if (closeRem > 0 && depth > 0 && closeRem > openRem)
    {
        cur.push_back(')');
        depth--;

        backtrack(openRem, closeRem - 1, k,max_depth);
        cur.pop_back();
        depth++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k))
        return 0;

    n /= 2;
    string s = "";
    backtrack(n, n, k,0);

    // They are generated lexicographically because we try '(' before ')'.
    for (auto &s : ans)
        cout << s << '\n';

    return 0;
}
