#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool wins(int pos, vector<pair<int,int>>& arr, int n) {
    int tokens = 0;
    for(int i = 0; i <= pos; i++) {
        tokens += arr[i].first;
    }
    
    for(int i = pos + 1; i < n; i++) {
        if(tokens < arr[i].first) return false;
        tokens += arr[i].first;
    }
    return true;
}

signed main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i + 1;  // store original position
        }
        
        sort(arr.begin(), arr.end());
        int low = 0, high = n-1;
        int first_win = n;  // first winning position
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(wins(mid, arr, n)) {
                first_win = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Collect winning positions
        vector<int> winners;
        for(int i = first_win; i < n; i++) {
            winners.push_back(arr[i].second);
        }
        
        // Sort winners in ascending order
        sort(winners.begin(), winners.end());
        
        // Output
        cout << winners.size() << "\n";
        for(int x : winners) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}