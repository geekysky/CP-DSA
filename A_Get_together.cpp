#include <bits/stdc++.h>
using namespace std;
#define int long long int

pair<double, double> intersection(pair<double, double> one, pair<double, double> two) {
    return {max(one.first, two.first), min(one.second, two.second)};
}

bool meeting_possible_for_time_t(vector<pair<double, double>> &people, double t) {
    pair<double, double> curr = {people[0].first - t * people[0].second, people[0].first + t * people[0].second};

    for (int i = 1; i < people.size(); i++) {
        pair<double, double> reach = {people[i].first - (t * people[i].second), people[i].first + (t * people[i].second)};
        
        curr = intersection(curr, reach);

        if (curr.first > curr.second) {
            // If any intersection is not possible, return false
            return false;
        }
    }

    return true;
}

signed main() {
    int n;
    cin >> n;
    
    vector<pair<double, double>> people;
    while (n--) {
        double x, v;
        cin >> x >> v;
        people.push_back({x, v});
    }

    // Binary search on time 
    int iterations = 100;
    double lb = 0, ub = 1e9;
    double ans = ub;
    double error=1e-6;

    for (int i = 0; i < iterations; i++) {
        double mid = (lb + ub) / 2;

        if (meeting_possible_for_time_t(people, mid)) {
            ans = mid;
            ub = mid-error; // Narrow down the upper bound
        } else {
            lb = mid+error; // Narrow down the lower bound
        }
    }

    cout << setprecision(7) << fixed << ans << "\n";

    return 0;
}
