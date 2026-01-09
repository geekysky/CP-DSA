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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2)
            {
                break;
            }
            else
            {
                ans++;
            }
        }

        // from end
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2)
            {
                break;
            }
            else
            {
                ans++;
            }
        }

        ans = min(ans, n);

        int ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                break;
            }
            else
            {
                ans2++;
            }
        }

        // from end
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == 0)
            {
                break;
            }
            else
            {
                ans2++;
            }
        }

        ans2 = min(ans2, n);

        cout << min(ans, ans2) << endl;
    }
    return 0;
}