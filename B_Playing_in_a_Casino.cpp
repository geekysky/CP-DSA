#include<bits/stdc++.h>
using namespace std;
#define int long long int 

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
    
        int arr[n][m];  // Declare the array with correct dimensions
        for (int i = 0; i < n; i++) {  // Loop over rows
            for (int j = 0; j < m; j++) {  // Loop over columns
                cin >> arr[i][j];
            }
        }

        // Construct columns from input
        vector<vector<int>> cols;  // Initialize with size
        for (int j = 0; j < m; j++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(arr[i][j]);  // Transpose input into columns
            }
            cols.push_back(temp);
        }

        // Sort each column
        for (int i = 0; i < m; i++) {
            sort(cols[i].begin(), cols[i].end());
        }
    
        int ans = 0;
        for (int i = 0; i < m; i++) {  // Loop over each column
            vector<int> &curr_col = cols[i];  // Reference to current column
            vector<int> prefix(n);  // Prefix sum array for current column
            prefix[0] = curr_col[0];

            // Compute prefix sums
            for (int j = 1; j < n; j++) {
                prefix[j] = prefix[j - 1] + curr_col[j];
            }

            // Compute the contribution to the answer
            for (int j = 0; j < n; j++) {
                ans += (prefix[n - 1] - prefix[j]) - ((n - (j + 1)) * curr_col[j]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
