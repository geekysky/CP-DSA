#include <bits/stdc++.h>
using namespace std;
#define int long long int

int substrings(int n)
{
    return n * (n + 1) / 2;
}

signed main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> valid;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        valid.insert(c);
    }

    int ans = 0;
    vector<int> invalid;
    for (int i = 0; i < n; i++)
    {
        if (valid.find(s[i]) == valid.end())
        {
            invalid.push_back(i + 1);
        }
    }

    // for(int i=0;i<invalid.size();i++){
    //     cout<<invalid[i]<<" ";
    // }
    // cout<<"\n";
    if (invalid.size() == 0)
    {
        cout << substrings(n) << "\n";
        return 0;
    }

    int idx = 1;
    for (int i = 0; i < invalid.size(); i++)
    {
        if (i == 0)
        {
            int len = invalid[i] - 1;
            ans += substrings(len);
            idx = invalid[i];
            continue;
        }
        int len = invalid[i] - idx - 1;
        ans += substrings(len);
        idx = invalid[i];
    }

    // now let's process the last valid substring
    int len = n - invalid[invalid.size() - 1];
    ans += substrings(len);

    cout << ans << "\n";

    return 0;
}