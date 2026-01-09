#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        // 0 based
        // all even indices belong to alice
        // all odd indices belong to bob
        for (int i = 0; i < n; i += 2)
        {
            s[i] == 'a' ? s[i] = 'b' : s[i] = 'a';
        }

        for (int i = 1; i < n; i += 2)
        {
            s[i] == 'z' ? s[i] = 'y' : s[i] = 'z';
        }

        cout << s << endl;
    }
    return 0;
}