#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        int lcm = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            lcm = (lcm * arr[i]) / __gcd(lcm, arr[i]);
        }

        vector<int> res;
        int sum = 0;
        int minimum = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            res.push_back(lcm / arr[i]);
            sum += res[i];
            minimum = min(minimum, res[i] * arr[i]);
        }
        if (sum < minimum)
        {
            for (int i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}