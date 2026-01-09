#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


void CoderAbhi27() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 

    int ans = 0;
    for (int k = 0; k < min(n, m) / 2; k++) {
        vector<int> vec;
        for (int j = k; j < m - k; j++)
            vec.push_back(a[k][j] - '0');
        for (int i = k + 1; i < n - k - 1; i++)
            vec.push_back(a[i][m - k - 1] - '0');
        for (int j = m - k - 1; j >= k; j--)
            vec.push_back(a[n - k - 1][j] - '0');
        for (int i = n - k - 2; i >= k + 1; i--)
            vec.push_back(a[i][k] - '0');
        // O(sz)

        int sz = vec.size();

        for (int i = 0; i < sz; i++) {
            string s;
            for (int j = i; j < i + 4; j++) {
                s += vec[j % sz] + '0';
            }
            if (s == "1543")
                ans++;
        } // O(sz)
    } // O(n*m)

    cout << ans << '\n';
}

// tc -> O(n*m)
// sc -> O(n*m)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        CoderAbhi27();
    }
    return 0;
}