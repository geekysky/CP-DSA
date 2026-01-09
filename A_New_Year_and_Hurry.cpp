#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

        int ans = 0;
        bool present = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != k)
            {
                if (!present)
                {
                    ans++;
                    present = true;
                }
            }
            else
            {
                present = false;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}