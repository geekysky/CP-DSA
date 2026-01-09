#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mp;
    int ans = 1, idx = 0;

    for (int i = 0; i < n; i++)
    {
        // what is the last index the element is found at...
        mp[arr[i]] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        idx = max(mp[arr[i]], idx);

        if (idx == i)
        {
            // a new segment gets created from the next element with two choices
            // either bi = bi+1 or bi = bi -1
            ans = (ans * 2) % 998244353;
        }
    }

    cout << ans << "\n";

    return 0;
}