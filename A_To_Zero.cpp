#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        int largest_even, largest_odd;

        if (k % 2)
        {
            largest_odd = k;
            largest_even = k - 1;
        }
        else
        {
            largest_odd = k - 1;
            largest_even = k;
        }

        if (n % 2)
        {
            n -= largest_odd;
            ans++;
        }

        cout << ((n+(largest_even-1)) / largest_even) + ans << endl;
    }
    return 0;
}