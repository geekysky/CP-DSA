#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_prime(int n) {
    if(n == 1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        if(4 > r) {
            cout << "-1\n";
            continue;
        }
        
        if(l == r) {
            if(is_prime(l)){
                cout<<-1<<"\n";
            }
            
            for(int i=2;i*i<=l;i++){
                if(l%i==0){
                    cout<<i<<" "<<l-i<<"\n";
                    break;
                }
            }
        }

        else if(l <= 4) {
            cout << "2 2\n";
        }
        else {
            if(l%2){
                if(l+1<=r){
                    cout<<2<<" "<<l-1<<"\n";
                }
                else{
                    cout<<"-1\n";
                }
            }
            else{
                cout<<"2 "<<l-2<<"\n";
            }
        }
    }
    return 0;
}