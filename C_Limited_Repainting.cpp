#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(string s, vector<int> arr, int mid, int k)
{
    int n = arr.size();
    int segments = 0;
    int last = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            // the values must be correctly colored for mid to be the the maximum penalty
            if (s[i] == 'B')
            {
                if (last == -1)
                {
                    segments++;
                }
                else if (i - last > 1)
                {
                    segments++;
                }
                last = i;
            }
        }
    }

    return segments <= k;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int low = 0, high = 1e9;
        int ans = high + 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(s, arr, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}