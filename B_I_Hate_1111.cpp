#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canMake(int x) {
    for(int i = 0; i * 11 <= x; i++) {
        if((x - i * 11) % 111 == 0){
            cout<<i<<" "<<(x - i * 11)<<"\n";
            return true;
        }
    }
    return false;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << (canMake(x) ? "YES" : "NO") << "\n";
    }
    return 0;
}