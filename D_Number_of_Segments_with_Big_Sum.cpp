#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, sum = 0, ans = 0;

    for (int r = 0; r < n; r++)
    {
        sum += arr[r];

        while (sum >= k and l <= r)
        {
            sum -= arr[l];
            l++;
        }

        if (l > 0 and sum + arr[l - 1] >= k)
        {
            ans += l;
        }
    }

    cout << ans << endl;

    return 0;
}