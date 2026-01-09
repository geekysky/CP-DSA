#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int left = i + 1;
            int right = n - i - 1;

            auto one = lower_bound(arr.begin(), arr.end(), left);
            auto two = lower_bound(arr.begin(), arr.end(), right);

            if (one != arr.end() and two != arr.end())
            {
                int idx1 = one - arr.begin();
                int idx2 = two - arr.begin();

                if (idx1 <= idx2)
                {
                    // two options pick left from [idx1,idx2-1] and pick right from [idx2,arr.end())
                    // or pick both from [idx2,arr.end())
                    int c1 = idx2 - idx1;
                    int c2 = m - idx2;

                    int temp1 = c1 * c2;
                    int temp2 = c2 * (c2 - 1);

                    ans += temp1;
                    ans += temp2;
                }

                else
                {
                    // when idx1 > idx2
                    int c1 = m - idx1;
                    int c2 = idx1 - idx2;

                    int temp1 = c1 * c2;
                    int temp2 = c1 * (c1 - 1);

                    ans += temp1;
                    ans += temp2;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}