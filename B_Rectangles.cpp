#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Calculate nCr without computing full factorials
int combination(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;  // nCr = nC(n-r), use smaller r for efficiency
    
    int result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> rows(n), cols(m);
    for (int i = 0; i < n; i++) {
        int black = 0, white = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) white++;
            else black++;
        }
        rows[i] = {black, white};
    }

    for (int i = 0; i < m; i++) {
        int black = 0, white = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 0) white++;
            else black++;
        }
        cols[i] = {black, white};
    }

    int ans = n * m;
    // Add combinations for rows
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= rows[i].first; j++) {
            ans += combination(rows[i].first, j);
        }
        for (int j = 2; j <= rows[i].second; j++) {
            ans += combination(rows[i].second, j);
        }
    }

    // Add combinations for columns
    for (int i = 0; i < m; i++) {
        for (int j = 2; j <= cols[i].first; j++) {
            ans += combination(cols[i].first, j);
        }
        for (int j = 2; j <= cols[i].second; j++) {
            ans += combination(cols[i].second, j);
        }
    }

    cout << ans << "\n";
    return 0;
}