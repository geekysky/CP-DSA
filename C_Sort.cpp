#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string a;
        string b;
        cin >> a >> b;

        int pref_a[n + 1][26] = {0};
        int pref_b[n + 1][26] = {0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                pref_a[i + 1][j] = pref_a[i][j];
                pref_b[i + 1][j] = pref_b[i][j];
            }
            pref_a[i + 1][a[i] - 'a']++;
            pref_b[i + 1][b[i] - 'a']++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; 

            int first[26] = {0};
            int second[26] = {0};

            for (int i = 0; i < 26; ++i) {
                first[i] = pref_a[r][i] - pref_a[l][i];
                second[i] = pref_b[r][i] - pref_b[l][i];
            }

            int min_ops = 0;
            for (int i = 0; i < 26; ++i) {
                min_ops += abs(first[i] - second[i]);
            }

            cout << min_ops / 2 << "\n";
        }
    }

    return 0;
}
