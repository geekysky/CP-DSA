#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        map<char, int> mp;
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        else if (n == 2)
        {
            mp[s[0]]++;
            mp[s[1]]++;
            cout << mp.size()+1 << "\n";
            continue;
        }
        
        mp.clear();
        mp[s[0]]++;
        mp[s[1]]++;

        int ans = 1;

        for (int i = 2; i < n; i++)
        {
            // mp.size() new strings at every stage of iteration
            ans += mp.size();
            mp[s[i]]++;
        }
        
        ans+=mp.size();
        cout << ans << endl;
    }
    return 0;
}