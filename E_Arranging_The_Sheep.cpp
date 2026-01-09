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
        vector<int> locations;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                cnt++;
                locations.push_back(i);
            }
        }
        int ans = 0;

        if (cnt == 0 or cnt == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        if (cnt % 2)
        {
            // try to get the stars close to each other
            int mid = cnt / 2;
            int ideal=cnt-1;
            for (int i = 0; i < mid; i++)
            {
                int curr_diff =locations[cnt-i-1]-locations[i];
                ans+=curr_diff-ideal;
                ideal-=2;
            }

            cout<<ans<<"\n";
        }
        else{
            // try to get the stars close to each other
            int mid = cnt / 2;
            int ideal=cnt-1;
            for (int i = 0; i < mid; i++)
            {
                int curr_diff =locations[cnt-i-1]-locations[i];
                ans+=curr_diff-ideal;
                ideal-=2;
            }

            cout<<ans<<"\n";
        }
    }
    return 0;
}