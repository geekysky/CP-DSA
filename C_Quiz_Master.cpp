#include <bits/stdc++.h>
using namespace std;

void backtrack(int open, int close, string &cur, vector<string> &res, int N) {
    if ((int)cur.size() == 2*N) {
        res.push_back(cur);
        return;
    }
    if (open < N) {
        cur.push_back('(');
        backtrack(open+1, close, cur, res, N);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        backtrack(open, close+1, cur, res, N);
        cur.pop_back();
    }
}

vector<string> generate_parentheses(int N) {
    vector<string> res;
    string cur;
    backtrack(0,0,cur,res,N);
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    auto ans = generate_parentheses(N);
    for(auto &s: ans) cout << s << '\n';
    return 0;
}
