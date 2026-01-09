#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            sum += arr[i];
        }

        sort(arr.begin(), arr.end());
        int one = sum - x;
        int two = sum - y;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            auto it2 = upper_bound(arr.begin() + (i + 1), arr.end(), one - arr[i]);
            auto it3 = lower_bound(arr.begin() + (i + 1), arr.end(), two - arr[i]);

            ans += (it2 - arr.begin()) - (it3 - arr.begin());
        }

        cout << ans << endl;
    }
    return 0;
}