#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int d[n + 1];
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        d[i] = (((d[i - 1] + d[i - 2]) % MOD) * (i - 1)) % MOD;
    }
    cout << d[n];
}