#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 2 << endl;
        return 0;
    }

    int x = n, y = n, z = n;

    int ans = 0;

    // 21 21 18 grouping
    while (y >= 2)
    {
        y -= 2;
        z--;

        ans++;
    }

    // cout << ans << endl;
    // now either 21 1 or 0...
    //  and 18 left are n - ans
    if (y == 0)
    {
        // only 18s and 25s are left
        ans += (z + 2) / 3;

        int last_used_left = 60 - (18 * (z % 3));

        if (last_used_left == 0 or last_used_left==60)
        {
            // 25s are used for new block altogether
            ans += (x + 1) / 2;

            cout << ans << endl;
        }
        else
        {
            // can we accomodate a few 25s in this remaining slot ?
            x -= (last_used_left / 25);

            ans += (x + 1) / 2;

            cout << ans << endl;
        }
    }
    else
    {
        // a single 21 is left along with n-ans 18s and x 25s
        ans++;

        // two 18s get coupled with a 21 or if a single 18 were there it gets coupled with the single 21
        z = max(0ll, z - 2);
        y = 0;

        // now as above only 18s and 25s are left
        ans += (z + 2) / 3;

        int last_used_left = 60 - (18 * (z % 3));
        
        // cout<<ans<<endl;
        // cout<<last_used_left<<endl;
        if (last_used_left == 0 or last_used_left==60)
        {
            // 25s are used for new block altogether
            ans += (x + 1) / 2;

            cout << ans << endl;
        }
        else
        {
            // can we accomodate a few 25s in this remaining slot ?
            x -= (last_used_left / 25);

            ans += (x + 1) / 2;

            cout << ans << endl;
        }
    }
    return 0;
}