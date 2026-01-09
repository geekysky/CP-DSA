#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, k;
    cin >> n >> k;

    if (n / k % 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}