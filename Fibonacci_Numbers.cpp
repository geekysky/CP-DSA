#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1000000007;

int fibonacci(int num, int mod){
    if(num == 0) return 0;
    if(num == 1) return 1;

    int a = 0, b = 1, c;
    for(int i = 2; i <= num; i++){
        c = (a + b) % mod;
        a = b;
        b = c;
    }
    return b;
}

signed main(){
    int n;
    cin >> n;

    int ans = fibonacci(n, mod);
    cout << ans << "\n";
    
    return 0;
}
