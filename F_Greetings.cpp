#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        ordered_set<int> left, right;
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            arr[i] = {l, r};
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = arr[i].first;
            int r = arr[i].second;

            int cnt_left = left.order_of_key(l);
            int cnt_right = right.size() - right.order_of_key(r);

            ans += min(cnt_left, cnt_right);

            left.insert(l);
            right.insert(r);
        }

        cout << ans << endl;
    }

    return 0;
}
