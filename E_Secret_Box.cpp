#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll find_all(ll x, ll y, ll z, ll k) {
    ll total = 0;

    for (ll i = 1; i <= cbrt(k); i++) {
        if (k % i == 0) {
            for (ll j = 1; j <= sqrt(k / i); j++) {
                if ((k / i) % j == 0) {
                    ll curr = k / (i * j);

                    if (i <= x && j <= y &&  k<= z) {
                        total = max(total, (x - i + 1) * (y - j + 1) * (z - curr + 1));
                    }
                    if (i <= x && curr <= y && j <= z) {
                        total = max(total, (x - i + 1) * (y - curr + 1) * (z - j + 1));
                    }
                    if (j <= x && i <= y && curr <= z) {
                        total = max(total, (x - j + 1) * (y - i + 1) * (z - curr + 1));
                    }
                    if (j <= x && curr <= y && i <= z) {
                        total = max(total, (x - j + 1) * (y - curr + 1) * (z - i + 1));
                    }
                    if (curr <= x && i <= y && j <= z) {
                        total = max(total, (x - curr + 1) * (y - i + 1) * (z - j + 1));
                    }
                    if (curr <= x && j <= y && i <= z) {
                        total = max(total, (x - curr + 1) * (y - j + 1) * (z - i + 1));
                    }
                }
            }
        }
    }
    return total;
}

int main() {
    ll t;
    cin>>t;
    vector<ll> ans;
    while (t--) {
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        ll temp=find_all(x, y, z, k);
        ans.push_back(temp);
    }

    for (auto res : ans) {
        cout << res << "\n";
    }

    return 0;
}


