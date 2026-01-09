#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        // count 2
        long long ans = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int diff = arr[n - 1] - arr[i] + 1;
            auto it = lower_bound(arr, arr + i, diff);
            if (it != (arr + i))
            {
                int idx = it - arr;
                ans += (i - idx);
            }
        }
        // cout<<ans<<endl;

        for (int i = n - 2; i >= 1; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int diff1 = arr[n - 1] - (arr[i] + arr[j]) + 1;
                int diff2 = arr[i] - arr[j] + 1;
                int need = max(diff1, diff2);
                auto it = lower_bound(arr, arr + j, need);
                if (it != arr + j)
                {
                    int idx = it - arr;
                    ans += (j - idx);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}