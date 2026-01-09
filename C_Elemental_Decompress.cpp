#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // 1) Count frequencies to run the “missing‐value” check
        vector<int> freq(n+1, 0);
        for (int v : arr) {
            if (v <= n) {
                freq[v]++;
            }
        }

        int s = 0;
        for (int x = n; x >= 1; x--) {
            if (freq[x] == 0) {
                if (s < (n - x + 1)) {
                    s = -1;
                    break;
                }
            }
            s += freq[x];
        }
        if (s == -1) {
            cout << "NO\n";
            continue;
        }

        // 2) Build (value, original_index) pairs and sort DESC by value
        vector<pair<int,int>> A;
        A.reserve(n);
        for (int i = 0; i < n; i++) {
            A.emplace_back(arr[i], i);
        }
        sort(
            A.begin(),
            A.end(),
            [](const pair<int,int> &a, const pair<int,int> &b) {
                return a.first > b.first;
            }
        );

        // 3) Prepare p[ ] and q[ ] (still all zeros)
        vector<int> p(n, 0), q(n, 0);
        // used_in_p[x] == 1 once x is placed into some p[.] slot
        // used_in_q[x] == 1 once x is placed into some q[.] slot
        vector<char> used_in_p(n+1, 0), used_in_q(n+1, 0);

        // Distribute the largest‐to‐smallest values alternately into p or q,
        // but write to the original index!
        for (int i = 0; i < n; i++) {
            int val = A[i].first;
            int idx = A[i].second;  // original position of that value
            if (i % 2 == 0) {
                p[idx] = val;
                if (val <= n) used_in_p[val] = 1;
            } else {
                q[idx] = val;
                if (val <= n) used_in_q[val] = 1;
            }
        }

        // 4) Build sets of “currently unused” values in [1..n]
        set<int> freeP, freeQ;
        for (int x = 1; x <= n; x++) {
            if (!used_in_p[x]) freeP.insert(x);
            if (!used_in_q[x]) freeQ.insert(x);
        }

        // 5) Now fill the zero‐slots (for every original index i from 0..n-1):
        for (int i = 0; i < n; i++) {
            if (q[i] == 0) {
                // p[i] is nonzero. Find largest free ≤ p[i] in freeQ
                int limit = p[i];
                auto it = freeQ.upper_bound(limit);
                if (it != freeQ.begin()) {
                    --it;
                    q[i] = *it;
                    freeQ.erase(it);
                }
                // Note: if it == begin(), there's no valid candidate, but the missing‐check ensures this won't happen.
            }
            else if (p[i] == 0) {
                // q[i] is nonzero. Find largest free ≤ q[i] in freeP
                int limit = q[i];
                auto it = freeP.upper_bound(limit);
                if (it != freeP.begin()) {
                    --it;
                    p[i] = *it;
                    freeP.erase(it);
                }
            }
            // if both p[i] and q[i] are nonzero, nothing to do
        }

        // 6) Print results in the same order as the original array:
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
