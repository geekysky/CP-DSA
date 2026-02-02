#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum > s)
        {
            cout << "NO" << endl;
            continue;
        }

        if ((s - sum) % x == 0)
        {
            // i can add x a couple of times to make sum exactly s
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}