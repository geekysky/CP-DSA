#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, q;
        cin >> n >> q;

        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<long long> k(q);
        for (int i = 0; i < q; i++) {
            cin >> k[i];
        }

        // To store the number of segments that cover each point
        unordered_map<long long, long long> segment_count;

        // Calculate the number of segments for each point
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long left = x[i];
                long long right = x[j];

                // Each point in [left, right] is covered by this segment
                for (long long point = left; point <= right; point++) {
                    segment_count[point]++;
                }
            }
        }

        // For each query, output how many points are covered by exactly 'k' segments
        for (int i = 0; i < q; i++) {
            long long segments = k[i];

            long long count = 0;
            // Count how many points are covered by exactly 'segments' segments
            for (auto& entry : segment_count) {
                if (entry.second == segments) {
                    count++;
                }
            }

            cout << count << " ";
        }

        cout << endl;
    }

    return 0;
}