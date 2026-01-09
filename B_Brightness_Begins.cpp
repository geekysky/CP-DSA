#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(int mid, int k) {
    int tot_on_bulbs = mid - (int)sqrt(mid);  
    return tot_on_bulbs >= k;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        int low = 1, high = LLONG_MAX;  
        int ans = high + 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  

            if (checker(mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
