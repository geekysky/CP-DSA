#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool check_damage(vector<int> &arr, int n, int h, int mid) {
    int damage_received = 0;

    for (int i = 0; i < n; i++) {
        int last_second;
        if (i == n-1) {
            last_second = arr[i]+mid-1;  
        }
        else {
            last_second = min(arr[i] + mid - 1, arr[i+1] - 1);  
        }

        damage_received += (last_second - arr[i] + 1);
    }

    return damage_received >= h;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, h;
        cin >> n >> h;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int low = 1, high = 1e18;
        int k = high + 1;

        for (int i = 0; i < 100; i++) {
            int mid = (low + high) / 2;

            if (check_damage(arr, n, h, mid)) {
                k = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << k << "\n";
    }

    return 0;
}
