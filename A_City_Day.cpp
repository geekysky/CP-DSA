#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (ll i = 0; i <= (n - 1 ); i++) {
        ll ele = arr[i];

        bool left_found = true, right_found = true;

        for (ll j = i - 1; j >= (i - x) && j >= 0; j--) {
            if (arr[j] <= ele) {
                left_found = false;
                break;
            }
        }

        if (left_found) {
            for (ll k = i + 1; k <= (i + y) && k < n; k++) {
                if (arr[k] <= ele) {
                    right_found = false;
                    break;
                }
            }

            if (right_found) {
                cout<<i+1<<"\n";
                return 0; // exit after finding the first valid position
            }
        }
    }

    return 0;
}
