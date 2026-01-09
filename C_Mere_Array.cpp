#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n), sorted(n);
        
        int minElement = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sorted[i] = arr[i];
            minElement = min(minElement, arr[i]);
        }
        
        sort(sorted.begin(), sorted.end());
        bool possible = true;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != sorted[i]) {
                if(arr[i] % minElement != 0) {
                    possible = false;
                    break;
                }
            }
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}