#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int m = 1e9 + 7;

int modPow(int a, int b, int m) {
    if(b == 0) {
        return 1;
    }
    int half = modPow(a, b / 2, m);
    int ans = (half * half) % m;
    if(b % 2 != 0) {
        ans = (ans * a) % m;
    }
    return ans;
}

signed main(){
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;   
        int power = modPow(b, c, m-1);
        int ans = modPow(a, power, m);

        cout << ans << "\n";
    }
    
    return 0;
}
