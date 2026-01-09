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
        map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            index[arr[i]] = i + 1;
        }

        // now the map's size is at most 1000 because of atmost 1000 distinct elements

        int ans = -1;
        for (auto num = index.begin(); num != index.end(); num++)
        {
            for (auto it = index.begin(); it->first <= num->first; it++)
            {
                if (__gcd(num->first, it->first) == 1)
                {
                    ans = max(ans, it->second + num->second);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}