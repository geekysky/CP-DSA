#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());
        int x = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            x = min(x, abs(arr[i] - arr[i + 1]));
        }

        if (k >= 3)
        {
            cout << 0 << "\n";
        }
        else if (k == 1)
        {
            cout<<x<<endl;
        }
        else
        { // k == 2
            for (int i = 0; i < n; i++)
                for (int j = 0; j < i; j++)
                {
                    int v = arr[i] - arr[j];
                    int p = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
                    if (p < n)
                        x = min(x, arr[p] - v);
                    if (p > 0)
                        x = min(x, v - arr[p - 1]);
                }
            cout << x << endl;
        }
    }

    return 0;
}
