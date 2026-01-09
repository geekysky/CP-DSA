#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    int max_ele = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_ele = max(max_ele, arr[i]);
    }

    while (q--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;


        if (l <= max_ele && max_ele <= r) {
            if (ch == '-')
                max_ele--;
            else
                max_ele++;
        }

        cout << max_ele << " ";
    }

    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
