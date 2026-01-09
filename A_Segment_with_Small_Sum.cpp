#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, sum = 0;
    int ans = 0;

    for (int r = 0; r < n; r++)
    {
        sum += arr[r];

        while (sum > s and l <= r)
        {
            sum -= arr[l];
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}