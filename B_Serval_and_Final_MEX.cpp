#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<pair<int, int>> op;
    int mid = n / 2;
    int r = n;

    // Check if 0 exists in second half [mid, n)
    bool zero_in_second_half = false;
    for (int i = mid; i < n; ++i) {
        if (a[i] == 0) {
            zero_in_second_half = true;
            break;
        }
    }
    if (zero_in_second_half) {
        op.push_back(make_pair(mid + 1, n));
        r -= (n - mid - 1);
    }

    // Check if 0 exists in first half [0, mid)
    bool zero_in_first_half = false;
    for (int i = 0; i < mid; ++i) {
        if (a[i] == 0) {
            zero_in_first_half = true;
            break;
        }
    }
    if (zero_in_first_half) {
        op.push_back(make_pair(1, mid));
        r -= (mid - 1);
    }

    op.push_back(make_pair(1, r));

    cout << op.size() << '\n';
    for (int i = 0; i < op.size(); ++i) {
        cout << op[i].first << " " << op[i].second << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
