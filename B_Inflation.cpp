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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int cost = 0;
        int prefix_sum = arr[0];
        for (int i = 1; i < n; i++)
        {

            int req_pref_sum = ((arr[i] * 100) + (k - 1)) / k;
            if (prefix_sum < req_pref_sum)
            {
                cost += abs(req_pref_sum - prefix_sum);
                prefix_sum += abs(req_pref_sum - prefix_sum);
            }
            prefix_sum += arr[i];
        }

        cout << cost << "\n";
    }

    return 0;
}