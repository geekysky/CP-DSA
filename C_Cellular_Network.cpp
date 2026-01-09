#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Comparator to be used with lower_bound
bool cmp(pair<int, int> &one, int target) {
    return one.second < target;
}

// Function to check if all cities are covered within given radius r
bool all_cities_covered(vector<int> &cities, vector<int> &towers, int r) {
    vector<pair<int, int>> ranges;
    
    // Generate ranges from towers based on radius r
    for (int i = 0; i < towers.size(); i++) {
        ranges.push_back({towers[i] - r, towers[i] + r});
    }

    // Check if each city is covered by at least one range
    for (int i = 0; i < cities.size(); i++) {
        int city = cities[i];

        // Find the first range whose second value is >= city
        auto it = lower_bound(ranges.begin(), ranges.end(), city, cmp);

        if (it == ranges.end() || it->first > city) {
            return false; // City not covered by any range
        }
    }

    return true;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n), towers(m);

    // Reading input for cities and towers
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    // Binary search for minimum radius
    int lb = 0, ub = 2 * (1e9);
    int ans = ub + 1;

    while (lb <= ub) {
        int mid = (lb + ub) / 2;

        if (all_cities_covered(cities, towers, mid)) {
            ans = mid;
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
