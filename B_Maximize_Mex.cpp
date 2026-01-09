#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        map<int, int> mp, mod_mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int i = 0;
        while (mp[i] > 0)
        {
            mp[i]--;
            mp[i + x] += mp[i];
            i++;
        }
        cout << i << endl;
    }
    return 0;
}
