#include <bits/stdc++.h>
using namespace std;

unsigned int getBitmask(unsigned int m) {
    if (m <= 1) return 0;  
    int highestBit = 31 - __builtin_clz(m - 1); 
    return (1u << (highestBit + 1)) - 1;
}

void solve() {
    int n;
    unsigned int x;
    cin >> n >> x;

    int best_m = 0;
    for (int m = 1; m <= n; m++) {
        unsigned int mask = getBitmask(m);
        if ((mask & (~x)) == 0) best_m = m;
    }

    vector<unsigned int> result;
    for (int i = 0; i < best_m; i++) result.push_back(i);

    if (getBitmask(best_m) != x) result.push_back(x & ~getBitmask(best_m));

    // Ensure exactly `n` elements
    while ((int)result.size() < n) result.push_back(0);

    result.resize(n); // Trim any excess elements

    for (unsigned int num : result) cout << num << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
