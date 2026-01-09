#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    const int N = 1e8;
    
    vector<int8_t> is_prime(N + 1, 1);  
    is_prime[0] = is_prime[1] = 0;
    
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + is_prime[i];
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        double pi_n = prefix[n];
        double approx = n / log(n);
        
        double error = (abs(pi_n - approx) / pi_n) * 100;

        cout << fixed << setprecision(1) << error << endl;
    }

    return 0;
}
