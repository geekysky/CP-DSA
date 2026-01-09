#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
        int temp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int place = lower_bound(arr.begin(), arr.end(), arr[i] + arr[i + 1]) - arr.begin() - 1;
            temp = max(temp, place - i + 1);
        }

        cout << n - temp << "\n";
    }

    return 0;
    
}
