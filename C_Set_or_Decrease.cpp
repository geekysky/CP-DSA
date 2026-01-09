#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool possible(int mid, vector<int> &arr, int k, int sum) {
    if(mid >= sum - k) {
        return true;
    }  

    for(int i = arr.size() - 1; i >= max(1ll,(int) arr.size() - mid); i--) {
        sum -= arr[i];
        int ops_left = mid - (arr.size() - i);
        int curr_sum = sum - arr[0] + (arr.size() - i + 1) * (arr[0] - ops_left);

        if(curr_sum <= k) {
            return true;
        }
    }

    return false;
}

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(arr.begin(), arr.end());
        int low = 0, high = 1e18;
        int ans = high + 1;

        // Binary search
        while(low <= high) {
            int mid = (low + high) / 2;

            if(possible(mid, arr, k, sum)) {
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
