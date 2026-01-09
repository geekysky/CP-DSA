#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, x;
        cin >> n >> x;

        vector<ll> arr(n);
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        // Check if all elements are divisible by x
        bool all_ele_div = true;
        for(ll i = 0; i < n; i++){
            if(arr[i] % x != 0){
                all_ele_div = false;
                break;
            }
        }

        if(all_ele_div) {
            cout << -1 << "\n";
        } else if(sum % x != 0) {
            cout << n << "\n";
        } else {
            ll from_front = -1, from_back = -1;
            
            for(ll i = 0; i < n; i++){
                if(arr[i] % x != 0){
                    from_front = i + 1;  // 1-based index
                    break;
                }
            }

            for(ll i = n - 1; i >= 0; i--){
                if(arr[i] % x != 0){
                    from_back = i + 1;  // 1-based index
                    break;
                }
            }

            // Calculate the maximum length after removing elements from either front or back
            ll max_len = max(n - from_front, from_back - 1);

            cout << max_len << "\n";
        }
    }

    return 0;
}
