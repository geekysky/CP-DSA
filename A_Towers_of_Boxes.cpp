#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;

        int each_block_height = d / m + 1;

        cout << (n + (each_block_height - 1)) / each_block_height << endl;
    }
    return 0;
}