#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve(string &res, int num)
{
    if (num == 0)
    {
        return;
    }

    int rem = num % 2;
    res += ('0' + rem);
    num /= 2;
    solve(res, num);
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string ans = "";
        solve(ans, n);

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}