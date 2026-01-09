#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1000000007;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int D = 0, prefix = 0;
    for (int j = 0; j < n; j++)
    {
        D = (D + j * a[j] - prefix);
        prefix = (prefix + a[j]);
    }
    int A = prefix;

    int ans = 2 * D + A;

    cout << ans / __gcd(ans, n) << " " << n / __gcd(ans, n);
    return 0;
}
