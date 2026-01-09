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
        cin>>n;
        
        vector<int> arr(n), suffix(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        int ans = suffix[0];
        for (int i = 1; i < n; i++)
        {
            if (suffix[i] > 0)
            {
                ans += suffix[i];
            }
        }

        cout << ans << endl;
    }
    return 0;
}