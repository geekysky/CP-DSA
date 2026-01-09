#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;         // Store the number of subarrays
    int left = 0;       // Left pointer for the window
    map<int, int> mp;   // To track the frequency of elements in the current window
    int distinct_count = 0;  // Track number of distinct elements

    // Sliding window logic
    for (int right = 0; right < n; right++) {
        // Add the element at 'right' to the window
        mp[arr[right]]++;
        if (mp[arr[right]] == 1) {  // New distinct element
            distinct_count++;
        }

        // Shrink the window from the left if there are more than `k` distinct elements
        while (distinct_count > k) {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0) {
                distinct_count--;   // One distinct element removed
            }
            left++;
        }

        // For every valid window, add all subarrays ending at `right`
        // All subarrays from `left` to `right` are valid
        ans += (right - left + 1);
    }

    cout << ans << "\n";

    return 0;
}
