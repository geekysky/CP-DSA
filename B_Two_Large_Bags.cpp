#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        if (mp.begin()->second == 1) {
            cout << "No\n";
            continue;
        }

        bool possible = true;
        while (!mp.empty()) {
            auto it = mp.begin();
            int key = it->first;
            int value = it->second;

            if (value == 1) {
                possible = false;
                break;
            }

            mp.erase(it); 

            if (value > 2) {
                mp[key + 1] += (value - 2);
            }
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }

    return 0;
}
