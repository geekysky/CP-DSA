#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int m, b;
    cin >> m >> b;

    int ans = -1;
    for (int x = 0; x <= (m * b); x++)
    {
        int y = (m * b - x) / m;

        if (y < 0 or ((m * b - x)) % m != 0)
            continue;

        int j = x + 1;
        int zero = ((y + 1) * (y)) / 2;
        int cd;
        if (j > 1)
        {
            int one = ((y + 1) * (2 + y)) / 2;
            cd = one - zero;
        }
        else
        {
            cd = zero;
        }

        int sum = (j * (zero * 2 + ((j - 1) * cd))) / 2;

        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}
