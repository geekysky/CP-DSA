#include <bits/stdc++.h>

using namespace std;
const int N = 100000+5;

int main () {
    // L_i = gcd(A_1, A_2, A_3, ... A_i)
    // R_i = gcd(A_i, A_{i+1}, A_{i+1}, ..., A_n)
    int n;
    int A[N];
    int R[N];
    int L[N];

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> A[i];
        L[i] = A[i];
        R[i] = A[i];
    }

    // precomputing L[i]
    for (int i=1; i<=n; i++) {
        L[i] = __gcd(L[i], L[i-1]);
    }
    // precomputing R[i]
    for (int i=n; i>0; i--) {
        R[i] = __gcd(R[i], R[i+1]);
    }

    // computing each m_i and the max value
    int res = 0;
    for (int i=1; i<=n; i++) {
        int m = __gcd(L[i-1], R[i+1]);
        if (m > res) {
            res = m;
        }
    }

    cout << res;
    return 0;
}