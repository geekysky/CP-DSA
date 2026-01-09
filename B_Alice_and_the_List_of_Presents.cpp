#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9 + 7;

int power(int base, int exp) {
    int result = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

signed main(){
    int n, m;
    cin >> n >> m;
    
    // First calculate 2^m - 1
    int ways_per_gift = (power(2, m) - 1 + MOD) % MOD;
    
    // Then raise it to power n
    int answer = power(ways_per_gift, n);
    
    cout << answer << "\n";
    return 0;
}