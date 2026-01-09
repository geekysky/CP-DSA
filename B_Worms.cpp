#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Comparator function to compare the first element of the pair with the target integer
bool cmp(const pair<int, int>& one, int target) {
    return one.first < target;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    int juicy_num[m];
    for (int i = 0; i < m; i++) {  // Corrected loop bound
        cin >> juicy_num[i];
    }

    vector<pair<int, int>> piles;
    int beg = 1;
    int end;
    
    // Construct the vector of pairs 'piles'
    for (int i = 0; i < n; i++) {
        end = beg + arr[i] - 1;
        piles.push_back({beg, end});
        beg = end + 1;
    }

    // Loop over all juicy_num elements to find their respective ranges in piles
    for (int i = 0; i < m; i++) {
        // Use lower_bound with a custom comparator using a lambda function
        auto it = lower_bound(piles.begin(), piles.end(), juicy_num[i], 
            [](const pair<int, int>& one, int target) {
                return one.second < target; // Compare based on the second element of the pair
            }
        );
        
        //cout<<it->first<<" "<<it->second<<endl;
        if (it != piles.end()) {
            cout << it - piles.begin() + 1 << "\n";  // Output 1-based index
        }
    }

    return 0;
}
