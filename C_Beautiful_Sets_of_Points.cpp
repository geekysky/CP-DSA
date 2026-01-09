#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool isPerfectSquare(int n)
{
    if (n < 0)
        return false;
    int low = 0, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sq = mid * mid;
        if (sq == n)
            return true;
        else if (sq < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    vector<pair<int, int>> res;
    cout << min(n, m) + 1 << endl;

    int cnt = 0, i = m;
    while (cnt < min(n, m) + 1)
    {
        cout << cnt << " " << i << endl;
        cnt++;
        i--;
    }

    return 0;
}