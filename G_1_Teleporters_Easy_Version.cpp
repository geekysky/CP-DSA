#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            arr[i] = (x + i + 1);
        }

        sort(arr.begin(), arr.end());
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        auto it = upper_bound(prefix.begin(), prefix.end(), c);
        cout << it - prefix.begin() << "\n";
    }
    return 0;
}