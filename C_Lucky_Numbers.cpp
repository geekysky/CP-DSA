#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    int ans = pow(2, n + 1);
    ans-=2;
    cout << ans << "\n";

    return 0;
}