#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int gp_sum(int x) {
    // Geometric progression sum till x terms for 2^0 + 2^1 + 2^2 + ... + 2^(x-1)
    int temp = (1LL << x) - 1; // Using bitwise shift for power of 2
    return temp;
}

signed main() {
    ios::sync_with_stdio(false); // Faster I/O
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 2) {
            cout << 2 << '\n';
        } else if (n == 4) {
            cout << 6 << '\n';
        } else {
            int lar = (1LL << (n / 2)) * gp_sum(n / 2);
            int small = (1LL << n) + (2 * gp_sum(n / 2 - 1));
            cout << abs(lar - small) << '\n';
        }
    }
    return 0;
}
