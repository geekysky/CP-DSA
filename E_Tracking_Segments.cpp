#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool possible(int numqueries, vector<pair<int,int>> &segments, int arrelements, int tot_segments, vector<int> &changes) {
    // Check if for 'numqueries' queries, we can get a beautiful segment
    
    vector<int> ini_arr(arrelements, 0);

    for (int i = 0; i < numqueries; i++) {
        ini_arr[changes[i]] = 1;
    }

    vector<int> pref_sum(arrelements);
    pref_sum[0] = ini_arr[0];

    for (int i = 1; i < arrelements; i++) {
        pref_sum[i] = pref_sum[i - 1] + ini_arr[i];
    }

    // Now iterate through the segments...check whether any have become beautiful 
    for (int i = 0; i < tot_segments; i++) {
        int l = segments[i].first;
        int r = segments[i].second;

        int seg_size = r - l + 1;

        // Check if number of 1s in that segment (using pref_sum) > len/2 (i.e., the number of zeroes)
        int no_ones = pref_sum[r] - ((l > 0) ? pref_sum[l - 1] : 0);

        if (no_ones > (seg_size / 2)) {
            return true;
        }
    }

    // No beautiful segment found using 'numqueries' queries--let's try for better 
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> segments;
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            segments.push_back({l, r});
        }

        int q;
        cin >> q;

        vector<int> changes;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            
            x--;
            changes.push_back(x);
        }

        int lb = 1, ub = q;
        int ans = ub + 1;

        while (lb <= ub) {
            int mid = (lb + ub) / 2;

            if (possible(mid, segments, n, m, changes)) {
                ans = mid;
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        
        if(ans==(q+1))
        cout<<-1<<'\n';

        else
        cout << ans << "\n";

    }

    return 0;
}
