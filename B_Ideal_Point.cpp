#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(51, 0); // Initialize an array with 51 elements set to 0

        // Read n ranges
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;

            // Check if k is within the range [l, r]
            if (k >= l && k <= r) {
                for (int j = l; j <= r; j++) {
                    arr[j]++;
                }
            }
        }

        bool ans = true;
        int temp = arr[k];

        // Check if there's any other index with a count greater than or equal to arr[k]
        for (int i = 0; i < 51; i++) {
            if (i != k && arr[i] >= temp) {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
