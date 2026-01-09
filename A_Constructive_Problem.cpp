#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int mex = 0;
        while (mp.find(mex) != mp.end()) {
            mex++;
        }

        auto it = mp.find(mex + 1);
        map<int, int> two = mp;
        if (it != mp.end()) {
            vector<int> next;
            for (int i = 0; i < n; i++) {
                if (arr[i] == mex + 1) {
                    next.push_back(i);
                }
            }

            if (next.size() == 1) {
                cout << "Yes\n";
            } else {
                int imp = 0;
                for (int i = next[0]; i <= next.back(); i++) {
                    if (arr[i] < mex) {
                        if (two[arr[i]] > 1) {
                            two[arr[i]]--;
                        } else {
                            imp++;
                        }
                    }
                }

                cout << (imp > 0 ? "No" : "Yes") << "\n";
            }
        } else {
            bool possible = false;
            auto it = mp.begin();
            while (it != mp.end() && it->first < mex) {
                if (it->second >= 2) {
                    possible = true;
                    break;
                }
                it++;
            }

            if (!possible) {
                for (int i = 0; i < n; i++) {
                    if (arr[i] > mex + 1) {
                        possible = true;
                        break;
                    }
                }
            }

            cout << (possible ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}