#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Corrected recursive get_value: (x, y) -> value
ll get_value(ll x, ll y, int size, ll offset) {
    if (size == 0)
        return offset + 1; // +1 because value starts from 1 not 0

    ll half = 1LL << (size - 1);           // 2^(size-1)
    ll block = 1LL << (2 * (size - 1));    // 4^(size-1)

    if (x <= half && y <= half) {
        // top-left
        return get_value(x, y, size - 1, offset + 0 * block);
    }
    else if (x <= half && y > half) {
        // top-right
        return get_value(x, y - half, size - 1, offset + 3 * block);
    }
    else if (x > half && y <= half) {
        // bottom-left
        return get_value(x - half, y, size - 1, offset + 2 * block);
    }
    else {
        // bottom-right
        return get_value(x - half, y - half, size - 1, offset + 1 * block);
    }
}

// Iterative version: value -> (x, y)
pair<ll,ll> get_coordinate(ll val, int n) {
    ll v0 = val - 1; // 0-based index
    ll x = 0, y = 0;

    for (int i = n; i >= 1; --i) {
        ll half  = 1LL << (i - 1);
        ll block = 1LL << (2 * (i - 1));
        ll idx   = v0 / block;
        v0       = v0 % block;

        if (idx == 1) {
            // bottom-right
            x += half;
            y += half;
        }
        else if (idx == 2) {
            // bottom-left
            x += half;
        }
        else if (idx == 3) {
            // top-right
            y += half;
        }
        // idx == 0 → top-left → no change
    }

    return make_pair(x + 1, y + 1); // +1 for 1-based coordinates
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < q; i++) {
            string op;
            cin >> op;

            if (op == "->") {
                ll x, y;
                cin >> x >> y;
                cout << get_value(x, y, n, 0) << "\n";
            } else {
                ll val;
                cin >> val;
                pair<ll, ll> coord = get_coordinate(val, n);
                cout << coord.first << " " << coord.second << "\n";
            }
        }
    }

    return 0;
}
