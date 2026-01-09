#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;

        set<int> ans;
        ans.insert(1);

        if (n >= 3)
        {
            ans.insert(3);
            ans.insert(7);
        }

        if (d % 10 == 0 or d % 10 == 5)
        {
            ans.insert(5);
        }

        if (n == 2 and d == 7)
        {
            ans.insert(7);
        }

        if (n == 2 and d == 3 or d == 6 or d == 9)
        {
            ans.insert(3);
        }

        if (n == 2 and d == 9)
        {
            ans.insert(9);
        }

        if ((n >= 3 and n <= 5) and (d == 3 or d == 6 or d == 9))
        {
            ans.insert(9);
        }

        if (n >= 6)
        {
            ans.insert(9);
        }

        for (auto res : ans)
        {
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}