#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> temp;
        int total = n * n;
        int till = total / 2;

        for (int i = 1; i <= till; ++i) {
            temp.push_back(i);
            temp.push_back((n * n + 1) - i);
        }

        if (n % 2 != 0) {
            temp.push_back(till + 1);
        }

        int ctr = 1;
        for (int i = 0; i < total; i += n) {
            vector<int> sub(temp.begin() + i, temp.begin() + i + n);

            if (ctr % 2 == 0) {
                reverse(sub.begin(), sub.end());
            }

            for (int j = 0; j < sub.size(); ++j) {
                cout << sub[j] << " ";
            }

            ctr++;
            cout << "\n";
        }
    }

    return 0;
}
