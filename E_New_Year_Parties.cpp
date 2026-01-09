#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> line(n + 2, 0);

    int maxi = 0, mini = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        line[x]++;
        mp[x]++;
    }

    // Make a copy of the original freq-map for later (when we do “minimize”).
    map<int,int> mp2 = mp;


    // ───── MAXIMIZE DISTINCT ─────
    // Instead of your old “if line[i-1]==0 / if mp[i]>1” logic,
    // we will do a three‐way check (x−1, x, x+1) for every copy of mp2[x].
    unordered_set<int> used; 
    for (auto &kv : mp2) {
        int x    = kv.first;
        int freq = kv.second;
        for (int copies = 0; copies < freq; copies++) {
            if (used.count(x - 1) == 0) {
                used.insert(x - 1);
            }
            else if (used.count(x) == 0) {
                used.insert(x);
            }
            else if (used.count(x + 1) == 0) {
                used.insert(x + 1);
            }
            // If all three (x-1, x, x+1) are already used, we cannot get
            // a new distinct slot from this copy, so do nothing.
        }
    }
    maxi = used.size();


    // ───── MINIMIZE (unchanged) ─────
    if (mp2.size() == 1) {
        // If there is only one distinct key overall, you can only end with 1 distinct.
        cout << 1 << " " << maxi << "\n";
        return 0;
    }

    // You already have a working “minimize” logic, so I leave it as-is:
    auto beg  = mp2.begin(); 
    beg++;
    auto prev = mp2.begin();
    int longest = 1;

    for (auto it = beg; it != mp2.end(); it++) {
        if (it->first - prev->first > 1) {
            // Gap of >1 → finalize the current consecutive chain “longest”.
            mini += (longest / 3);
            if (longest % 3) 
                mini++;
            longest = 1;
        }
        else {
            // Consecutive (difference == 1) → extend chain
            longest++;
        }
        prev = it;
    }
    // Don’t forget the last segment:
    mini += (longest / 3);
    if (longest % 3)
        mini++;

    cout << mini << " " << maxi << "\n";
    return 0;
}
