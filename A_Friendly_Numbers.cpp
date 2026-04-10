#include <bits/stdc++.h>
using namespace std;
#define int long long int

int digit_sum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (x % 9 != 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int ans = 0;
            for (int z = 1; z <= 90; z++)
            {
                int y = x + z;
                if (digit_sum(y) == z)
                {
                    ans++;
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}