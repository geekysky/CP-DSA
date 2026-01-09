#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool mid_side_is_valid(int w, int h, int n, int mid) {
    int rows = mid / h;
    if (rows == 0) return false;  // If no row can fit even a single rectangle, return false
    
    int cols = mid / w;
    if (cols == 0) return false;  // If no column can fit even a single rectangle, return false
    
    // Check if the required number of rows can fit n rectangles without multiplying rows and cols
    return (rows >= (n + cols - 1) / cols);
}

signed main() {
    int w, h, n;
    cin >> w >> h >> n;

    int lb = 1;
    int ub = max(w, h) * n;  // Upper bound based on the maximum dimension and number of rectangles

    int ans = ub;

    while (lb <= ub) {
        int mid = (lb + ub) / 2;

        if (mid_side_is_valid(w, h, n, mid)) {
            ans = mid;
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
