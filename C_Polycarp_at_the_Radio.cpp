#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, changeSum = 0;
    cin >> n >> m;

    vector<int> a(n), f(m + 1);
    for (auto &i : a) cin >> i;

    vector<int> changes;

    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            changes.push_back(i);
        } else {
            if (f[a[i]] == n / m) {
                changes.push_back(i);
            } else {
                f[a[i]]++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        while (f[i] < n / m) {
            a[changes.back()] = i;
            changes.pop_back();
            changeSum++;
            f[i]++;
        }
    }

    cout << n / m << " " << changeSum << "\n";
    for (auto &i : a) cout << i << " ";
}
