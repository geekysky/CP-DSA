#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        vector<int> pos_values;
        set<int> temp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            temp.insert(arr[i]);
            pos_values.push_back(temp.size());
        }

        int l = n - 1, r = n - 1;

        set<int> curr;
        int ans = 0;
        while (l >= 0 )
        {
            curr.insert(arr[l]);

            if (curr.size() == pos_values[r])
            {
                // we found a valid segment
                ans++;
                set<int> nxt;
                curr = nxt;
                r = l - 1;
            }
            l--;
        }

        cout << ans << endl;
    }
    return 0;
}
