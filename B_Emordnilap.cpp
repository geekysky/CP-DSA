#include <bits/stdc++.h>
using namespace std;
#define int long long int 
const int mod = 1e9 + 7;

// Function to calculate modular exponentiation
int modExp(int base, int exp, int modulus) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with result
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus; // Square the base
        exp = exp / 2; // Reduce the exponent by half
    }
    return result;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 0 << '\n';
        } else {
            int part = n * (n - 1) % mod;
            part = (part * part) % mod;

            if (n > 2) {
                for(int i=n-2;i>=1;i--){
                    part=(part*i)%mod;
                }
            }

            cout << part << '\n';
        }
    }
    return 0;
}
