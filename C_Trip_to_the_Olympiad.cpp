#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int l, r;
    cin >> l >> r;
    
    if(r-l < 2) {
        cout << "0\n";
        return;
    }
    
    // Find highest power of 2 in range
    int pow2 = 1;
    while((pow2 << 1) <= r) pow2 <<= 1;
    
    // a = smallest number with consecutive 1s
    int a = (1 << (int)log2(l)) - 1;
    if(a < l) a = l;
    
    // b = largest power of 2
    int b = pow2;
    
    // c = number with mixed bits
    int c = (pow2 >> 1) | 1;
    
    if(min({a,b,c}) < l || max({a,b,c}) > r || 
       a == b || b == c || a == c) {
        cout << "0\n";
        return;
    }
    
    cout << a << " " << b << " " << c << "\n";
}

signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}