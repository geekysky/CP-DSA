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

        vector<int> ans;

        for (int i = 1; i <= 18; i++)
        {
            int den = 1;
            for (int j = 1; j <= i; j++)
            {
                den *= 10;
            }

            den++;

            if (n % den == 0)
            {
                ans.push_back(n / den);
            }
        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        if (ans.size() == 0)
        {
            continue;
        }

        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}