#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, d, l;
    cin >> n >> d >> l;

    if (l > n || d >= n || (n - d - 1) < (l - 2)) {
        cout << -1 << endl;
        return;
    }

    vector<pair<ll, ll>> edges;
    ll last = 1;
    for (ll i = 2; i <= d + 1; ++i) {
        edges.push_back({last, i});
        last = i;
    }
    ll ln = l - 2; 
    for (ll i = 2; i <= d + 1; ++i) {
        if (ln > 0) {
            edges.push_back({i, n});
            ln--;
        }
        if (ln == 0) break;
    }
    for (ll i = d + 2; i <= n - 1; ++i) {
        edges.push_back({1, i});
    }
    for (auto &e : edges) {
        cout << e.first << " " << e.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}