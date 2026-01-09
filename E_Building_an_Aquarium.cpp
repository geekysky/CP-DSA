#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool valid_height(int x, int arr[], int n, int k) {
    int tot_water_req = 0;
    for (int i = 0; i < n ; ++i) {

        if(tot_water_req>k)
        return false;

        tot_water_req += max((x - arr[i]),0ll);
        //if (tot_water_req > k) return false;
    }

    return tot_water_req <= k;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int lb = 0;
        int ub = 1e18;
        int ans = ub + 1;

        while (lb <= ub) {
            int mid = (lb + ub) / 2;
            if (valid_height(mid, arr, n, x)) {
                ans = mid;
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
