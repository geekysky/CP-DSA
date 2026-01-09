#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> result(n);
    int idx = 0;

    // Fill odd indices first
    for (int i = 1; i < n; i += 2) {
        result[i] = arr[idx];
        idx++;
    }

    // Fill even indices next
    //idx++;
    for (int i = 0; i < n; i += 2) {
        result[i] = arr[idx];
        idx++;
    }

    // Count the number of peaks
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (result[i] < result[i - 1] && result[i] < result[i + 1]) {
            ans++;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
